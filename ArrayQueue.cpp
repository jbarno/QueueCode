#include <cassert>
#include <cstdio>
class ArrayQueueFull {};
class ArrayQueueEmpty {};

template <class T>
class ArrayQueue {
  public:
     ArrayQueue(int len);
     ~ArrayQueue();
     
     bool empty();	// submit code for this
     bool full();		// submit code for this
     void enqueue(T elt); 	// submit code for this
     T dequeue();		// submit code for this

  private:
     T * m_arr;
	 int *start;
     int m_left;  		// location to dequeue from
     int m_right; 		// location to enqueue to

     int m_max_size; 	// maximum size as supplied by the constructor
     int m_cur_size; 	// current number of elements inside the container

     ArrayQueue(); 	// default constructor illegal
};

template <typename T>
ArrayQueue::ArrayQueue(int len)
{
	m_max_size = len;
	m_arr = new int[m_max_size]; //Assume size of  T is an int for KPCB queue
	start = m_arr;
}
template <typename T>
ArrayQueue::~ArrayQueue()
{
	delete start[m_max_size];
}
template <typename T>
bool ArrayQueue::empty()
{
	if(!m_cur_size)
	{
		return true;
	}
	return false;
}

template <typename T>
bool ArrayQueue::full()
{
	if(m_cur_size == m_max_size)
	{
		return true;
	}
	return false;
}

template <typename T>
void ArrayQueue::enqueue(T)
{
	if(full)
	{
		ArrayQueueFull f;
		throw(f);
	}
	m_arr[m_right++] = T;
	m_cur_size++;
}

template <typename T>
T ArrayQueue::dequeue()
{
	if(empty)
	{
		ArrayQueueEmpty e;
		throw(e);
	}
	T result = m_arry[m_left--]
	m_right--;
	T copy[m_cur_size] = m_arry;
	for(int i = 0; i < m_cur_size; i++)
	{
		m_arry[i] = copy[i+1];
	}
	m_cur_size--;
	return result;
}

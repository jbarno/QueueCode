#include <cassert>
#include <cstdio>
#include "aq.h"

/*
class ArrayQueueFull {};
class ArrayQueueEmpty {};

class ArrayQueue {
  public:
     ArrayQueue(int len);
     ~ArrayQueue();
     
     bool empty();		// submit code for this
     bool full();		// submit code for this
     void enqueue(int elt); 	// submit code for this
     int dequeue();		// submit code for this

  private:
     int * m_arr;
     int m_right; 		// location to enqueue to

     int m_max_size; 	// maximum size as supplied by the constructor
     int m_cur_size; 	// current number of elements inside the container
}*/

ArrayQueue::ArrayQueue(int len)
{
	m_right = m_cur_size = 0;
	m_max_size = len;
	m_arr = new int[m_max_size]; //Assume size of  int is an int for KPCB queue
}

ArrayQueue::~ArrayQueue()
{
	delete [] m_arr;
}

bool ArrayQueue::empty()
{
	return(!m_cur_size);
}

bool ArrayQueue::full()
{
	if(m_cur_size == m_max_size)
	{
		return true;
	}
	return false;
}


void ArrayQueue::enqueue(int input)
{
	if(this->full())
	{
		ArrayQueueFull f;
		throw(f);
	}
	m_arr[m_right++] = input;
	m_cur_size++;
}


int ArrayQueue::dequeue()
{
	if(this->empty())
	{
		ArrayQueueEmpty e;
		throw(e);
	}
	int result = m_arr[0];
	m_right--;	
	m_cur_size--;
	//Must rearrange the memory to keep queue invariant 
	for(int i = 0; i < m_cur_size; i++)
	{
		m_arr[i] = m_arr[i+1];
	}

	return result;
}

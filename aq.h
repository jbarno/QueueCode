#ifndef AQ_H
#define AQ_H

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
};



#endif

make: ArrayQueue.cpp testQueue.cpp
	g++ ArrayQueue.cpp testQueue.cpp -g -Wall -o test
clean:
	rm test;

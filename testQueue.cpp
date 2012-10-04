#include<iostream>
#include<queue>
#include "aq.h"

using namespace std;

int main()
{
	cout << "How big would you like the queue?\n";
	int size;
	cin >> size;
	int numberInputs;
	cout << "How many ints would you like to put into the array?\n";
	cin >> numberInputs;

	ArrayQueue aq(size);
	try
	{
		for(int i = 0; i <numberInputs; i++ )
		{
			aq.enqueue(i);
		}
		if( numberInputs > size)
		{
			while(1)
			{
				cout << aq.dequeue() << endl;
			}
		}
		else 
		{
			while(!aq.empty())
			{
				cout << aq.dequeue() << endl;
			}
		}
	}
	catch(ArrayQueueFull f)
	{
		cout << "Too many ints you have\n";
	}
	catch(ArrayQueueEmpty e)
	{
		cout << "The Queue has been emptied!\n";
	}
	catch(...)
	{
		cout << "what did you do???\n size:\t" << size << endl << "number of Input ints:\t" << numberInputs <<  endl;
	}
	return 0;
}


#include <iostream>
#include "Swap.tpp"
#include "Queue.hpp"

using namespace std;

/*
 * Variant 19
 * Tasks C, G
 */

int main()
{
	// Task C
	int testInt1 = 1, testInt2 = 2;
	double testDouble1 = 1.0, testDouble2 = 2.0;

	Swap(testInt1, testInt2);
	cout << testInt1 << " " << testInt2 << endl;
	Swap(testDouble1, testDouble2);
	cout << testDouble1 << " " << testDouble2 << endl;

	// Task G
	int testErrorSwitch;
	do
	{
		cout << "Input error type (1 - Empty queue, 2 - Overflow): " << endl;
		cin >> testErrorSwitch;
	} while (testErrorSwitch != 1 && testErrorSwitch != 2);

	Queue <10, int> intQueue;

	cout << "Size: " << intQueue.size() << endl;
	intQueue.push(10);
	intQueue.push(3);
	intQueue.push(7);
	cout << "Size: " << intQueue.size() << endl;

	switch (testErrorSwitch)
	{
		case 1:
		{
			intQueue.pop();
			intQueue.pop();
			intQueue.pop();
			intQueue.pop(); // Causes "Empty queue" error
		}
		case 2:
		{
			for (int i = 0; i < 11; ++i)
			{
				intQueue.push(i);
			}
			intQueue.push(11); // Causes "Queue overflow" error
		}
		default:
		{
		}
	}
	return 0;
}

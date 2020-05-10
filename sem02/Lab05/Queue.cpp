#include "Queue.hpp"

using namespace std;

template <int N, class T>
Queue <N, T>::Queue() : front(0), back(-1), isEmpty(true)
{
	data = new T[N];
}

template <int N, class T>
Queue <N, T>::~Queue()
{
	delete[](data);
}

template <int N, class T>
void Queue <N, T>::push(const T& item)
{
	++back;
	if (back > N)
	{
		throw QueueException("Queue overflow!");
	}
	if (isEmpty)
	{
		isEmpty = false;
	}
	data[back] = item;
}

template <int N, class T>
const T Queue <N, T>::pop()
{
	if (isEmpty)
	{
		throw QueueException("Empty queue!");
	}
	T result = data[front];
	++front;
	if (front < back)
	{
		isEmpty = true;
		front = 0;
		back = -1;
	}
	return result;
}

template <int N, class T>
const int Queue <N, T>::size()
{
	if (isEmpty)
	{
		return 0;
	}
	else
	{
		return back - front + 1;
	}
}

#pragma once

#include "QueueException.hpp"

template <int N, class T>
class Queue
{
public:
	Queue();
	~Queue();
	void push(const T& item);
	const T pop();
	const int size();
private:
	int back;
	int front;
	bool isEmpty;
	T* data;
};



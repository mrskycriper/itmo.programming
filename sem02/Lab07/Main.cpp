#include <iostream>
#include <algorithm>
#include <numeric>
#include "CircularBuffer.tpp"

int main()
{
	circular_buffer <int> buffer(9);
	std::cout << "buffer.push_back(from 0 to 8): ";
	for (int i = 0; i < 9; i++)
	{
		buffer.push_back(i);
	}
	print(buffer);

	std::cout << "buffer.push(-375): ";
	buffer.push(-375);
	print(buffer);

	std::cout << "x3 buffer.pop_back(): ";
	buffer.pop_back();
	buffer.pop_back();
	buffer.pop_back();
	print(buffer);

	std::cout << "x2 buffer.pop(): ";
	buffer.pop();
	buffer.pop();
	print(buffer);

	std::cout << "buffer.resize(4): ";
	buffer.resize(4);
	print(buffer);

	auto it = buffer.begin() + 2;
	std::cout << "buffer.erase(buffer.begin() + 2): ";
	buffer.erase(it);
	print(buffer);

	std::cout << "buffer.insert(buffer.begin() + 2, 7): ";
	buffer.insert(it, 7);
	print(buffer);

	std::cout << "std::sort(buffer.begin(), buffer.end()): ";
	std::sort(buffer.begin(), buffer.end());
	print(buffer);

	std::cout << "std::reverse(buffer.begin(), buffer.end()): ";
	std::reverse(buffer.begin(), buffer.end());
	print(buffer);

	std::cout << "std::accumulate(buffer.begin(), buffer.end(), 0): "
			  << std::accumulate(buffer.begin(), buffer.end(), 0) << std::endl;

	std::cout << "buffer.front() = 1000, buffer.back() = 9999: ";
	buffer.front() = 1000;
	buffer.back() = 9999;
	print(buffer);

	std::cout << "x4 buffer.pop(): " << std::endl;
	buffer.pop();
	buffer.pop();
	buffer.pop();
	buffer.pop();
	std::cout << "buffer.empty(): " << buffer.empty() << std::endl;
	return 0;
}

#pragma once
#include <iterator>
#include <exception>

template <class T>
class circular_buffer
{
public:
	explicit circular_buffer(size_t Capacity);
	~circular_buffer();

	bool empty() const;
	size_t size() const;
	void resize(size_t NewCapacity);

	void push_back(const T& Item);
	void push(const T& Item);
	void pop_back();
	void pop();
	T& front() const;
	T& back();

	T& operator [](size_t Index);
	const T& operator [](size_t Index) const;

	class circular_buffer_iterator : public std::iterator <std::random_access_iterator_tag, T>
	{
	private:
		size_t it_position_ {};
		circular_buffer <T>* buffer_;
	public:
		circular_buffer_iterator()
		{}

		circular_buffer_iterator(circular_buffer <T>* Buffer, size_t Position);
		circular_buffer_iterator(const circular_buffer_iterator& Iterator);

		T& operator *();

		circular_buffer_iterator& operator ++();
		circular_buffer_iterator& operator +=(int Value);
		circular_buffer_iterator operator +(int Value) const;
		circular_buffer_iterator operator +(const circular_buffer_iterator& Iterator) const;

		circular_buffer_iterator& operator --();
		circular_buffer_iterator& operator -=(int Value);
		circular_buffer_iterator operator -(int Value) const;
		ptrdiff_t operator -(const circular_buffer_iterator& Iterator) const;

		bool operator ==(const circular_buffer_iterator& Iterator) const;
		bool operator !=(const circular_buffer_iterator& Iterator) const;

		bool operator <(const circular_buffer_iterator& Iterator) const;
		bool operator >(const circular_buffer_iterator& Iterator) const;

		bool operator <=(const circular_buffer_iterator& Iterator) const;
		bool operator >=(const circular_buffer_iterator& Iterator) const;
	};

	circular_buffer_iterator begin();
	circular_buffer_iterator end();
	circular_buffer_iterator insert(const circular_buffer_iterator& Iterator, const T& Item);
	void erase(circular_buffer_iterator Iterator);
private:
	T* data_;
	size_t capacity_;
	size_t front_;
	size_t back_;

	size_t inc(size_t Position, int Value) const;
	size_t dec(size_t Position, int Value) const;
	void copy(T* Destination, size_t Size) const;
};

template <class Type>
void print(const circular_buffer <Type>& Buffer);







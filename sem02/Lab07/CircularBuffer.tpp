#include "CircularBuffer.hpp"

template <class T>
circular_buffer <T>::circular_buffer(size_t Capacity)
{
	capacity_ = Capacity;
	data_ = new T[capacity_ + 1];
	front_ = 0;
	back_ = 0;
}

template <class T>
circular_buffer <T>::~circular_buffer()
{
	delete[] data_;
}

template <class T>
bool circular_buffer <T>::empty() const
{
	return front_ == back_;
}

template <class T>
void circular_buffer <T>::push_back(const T& Item)
{
	if (back_ == (front_ - 1 + capacity_ + 1) % (capacity_ + 1))
	{
		front_ = (front_ + 1) % (capacity_ + 1);
	}

	data_[back_] = Item;
	back_ = (back_ + 1) % (capacity_ + 1);
}

template <class T>
void circular_buffer <T>::push(const T& Item)
{
	if (back_ == (front_ - 1 + capacity_ + 1) % (capacity_ + 1))
	{
		back_ = (back_ - 1 + capacity_ + 1) % (capacity_ + 1);
	}

	front_ = (front_ - 1 + capacity_ + 1) % (capacity_ + 1);
	data_[front_] = Item;
}

template <class T>
void circular_buffer <T>::resize(size_t NewCapacity)
{
	T* buffer = new T[NewCapacity + 1];
	copy(buffer, std::min((back_ - front_ + capacity_ + 1) % (capacity_ + 1), NewCapacity));
	delete[] data_;
	data_ = buffer;
	capacity_ = NewCapacity;
	front_ = 0;
	back_ = NewCapacity;
}

template <class T>
void circular_buffer <T>::pop_back()
{
	if (empty())
	{
		throw std::runtime_error("Empty buffer error");
	}
	else
	{
		back_ = (back_ - 1 + capacity_ + 1) % (capacity_ + 1);
	}
}

template <class T>
void circular_buffer <T>::pop()
{
	if (empty())
	{
		throw std::runtime_error("Empty buffer error");
	}
	else
	{
		front_ = (front_ + 1) % (capacity_ + 1);
	}
}

template <class T>
T& circular_buffer <T>::front() const
{
	return data_[front_];
}

template <class T>
T& circular_buffer <T>::back()
{
	return data_[(back_ - 1 + capacity_ + 1) % (capacity_ + 1)];
}

template <class T>
T& circular_buffer <T>::operator [](size_t Index)
{
	return data_[(front_ + Index) % (capacity_ + 1)];
}

template <class T>
const T& circular_buffer <T>::operator [](size_t Index) const
{
	return data_[(front_ + Index) % (capacity_ + 1)];
}

template <class T>
size_t circular_buffer <T>::size() const
{
	return (back_ - front_ + capacity_ + 1) % (capacity_ + 1);
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator circular_buffer <T>::begin()
{
	return circular_buffer_iterator(this, 0);
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator circular_buffer <T>::end()
{
	return circular_buffer_iterator(this, back_);
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator
circular_buffer <T>::insert(const circular_buffer::circular_buffer_iterator& Iterator, const T& Item)
{
	auto it = Iterator;
	T buffer = Item;
	back_ = (back_ + 1) % (capacity_ + 1);
	for (; it != end(); ++it)
	{
		std::swap(*it, buffer);
	}
	if (back_ == front_)
	{
		front_ = (front_ + 1) % (capacity_ + 1);
	}
	return Iterator;
}

template <class T>
void circular_buffer <T>::erase(circular_buffer::circular_buffer_iterator Iterator)
{
	auto it = end() - 1;
	T buffer = *it;
	for (; Iterator <= it; --it)
	{
		std::swap(*it, buffer);
	}
	back_ = (back_ - 1 + capacity_ + 1) % (capacity_ + 1);
}

template <class T>
size_t circular_buffer <T>::inc(size_t Position, int Value) const
{
	return (Position + Value) % (capacity_ + 1);
}

template <class T>
size_t circular_buffer <T>::dec(size_t Position, int Value) const
{
	return (Position - Value + capacity_ + 1) % (capacity_ + 1);
}

template <class T>
void circular_buffer <T>::copy(T* Destination, size_t Size) const
{
	for (int i = 0; i < Size; i++)
	{
		Destination[i] = (*this)[i];
	}
}

template <class T>
circular_buffer <T>::circular_buffer_iterator::circular_buffer_iterator(circular_buffer <T>* Buffer, size_t Position)
{
	this->it_position_ = Position;
	this->buffer_ = Buffer;
}

template <class T>
circular_buffer <T>::circular_buffer_iterator::circular_buffer_iterator(
		const circular_buffer::circular_buffer_iterator& Iterator)
{
	this->buffer_ = Iterator.buffer_;
	this->it_position_ = Iterator.it_position_;
}

template <class T>
T& circular_buffer <T>::circular_buffer_iterator::operator *()
{
	return (*buffer_)[it_position_];
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator& circular_buffer <T>::circular_buffer_iterator::operator ++()
{
	it_position_ = buffer_->inc(it_position_, 1);
	return *this;
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator& circular_buffer <T>::circular_buffer_iterator::operator --()
{
	it_position_ = buffer_->dec(it_position_, 1);
	return *this;
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator&
circular_buffer <T>::circular_buffer_iterator::operator +=(int Value)
{
	it_position_ = buffer_->inc(it_position_, Value);
	return *this;
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator&
circular_buffer <T>::circular_buffer_iterator::operator -=(int Value)
{
	it_position_ = buffer_->dec(it_position_, Value);
	return *this;
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator
circular_buffer <T>::circular_buffer_iterator::operator +(int Value) const
{
	return circular_buffer_iterator(buffer_, buffer_->inc(it_position_, Value));
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator
circular_buffer <T>::circular_buffer_iterator::operator -(int Value) const
{
	return circular_buffer_iterator(buffer_, buffer_->dec(it_position_, Value));
}

template <class T>
typename circular_buffer <T>::circular_buffer_iterator circular_buffer <T>::circular_buffer_iterator::operator +(
		const circular_buffer::circular_buffer_iterator& Iterator) const
{
	return circular_buffer_iterator(buffer_, buffer_->dec(it_position_, Iterator.it_position_));
}

template <class T>
ptrdiff_t circular_buffer <T>::circular_buffer_iterator::operator -(
		const circular_buffer::circular_buffer_iterator& Iterator) const
{
	return buffer_->dec(it_position_, Iterator.it_position_);
}

template <class T>
bool circular_buffer <T>::circular_buffer_iterator::operator ==(
		const circular_buffer::circular_buffer_iterator& Iterator) const
{
	return it_position_ == Iterator.it_position_;
}

template <class T>
bool circular_buffer <T>::circular_buffer_iterator::operator !=(
		const circular_buffer::circular_buffer_iterator& Iterator) const
{return !(*this == Iterator);}

template <class T>
bool circular_buffer <T>::circular_buffer_iterator::operator <(
		const circular_buffer::circular_buffer_iterator& Iterator) const
{
	if (it_position_ < buffer_->front_ && Iterator.it_position_ < buffer_->front_ ||
		it_position_ >= buffer_->front_ && Iterator.it_position_ >= buffer_->front_)
	{
		return it_position_ < Iterator.it_position_;
	}
	else
	{
		return it_position_ > Iterator.it_position_;
	}
}

template <class T>
bool circular_buffer <T>::circular_buffer_iterator::operator >(
		const circular_buffer::circular_buffer_iterator& Iterator) const
{
	return !(*this < Iterator);
}

template <class T>
bool circular_buffer <T>::circular_buffer_iterator::operator <=(
		const circular_buffer::circular_buffer_iterator& Iterator) const
{
	return *this < Iterator || *this == Iterator;
}

template <class T>
bool circular_buffer <T>::circular_buffer_iterator::operator >=(
		const circular_buffer::circular_buffer_iterator& Iterator) const
{
	return *this > Iterator || *this == Iterator;
}

template <class Type>
void print(const circular_buffer <Type>& Buffer)
{
	for (int i = 0; i < Buffer.size(); i++)
	{
		std::cout << Buffer[i] << ' ';
	}
	std::cout << std::endl;
}
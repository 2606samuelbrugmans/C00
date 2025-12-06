#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>


template <typename T>
class Array {
   private:
	T* data;
	std::size_t size;

   public:
   	Array() : data(NULL), size(0) {}
	Array(std::size_t n) : data(new T[n]()), size(n) {}
	Array(const Array& other) : data(new T[other.size]()), size(other.size)
	{
		for (std::size_t i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
	}
	Array& operator=(const Array& other)
	{
		if (this != &other) {
			delete[] data;
			size = other.size;
			data = new T[size]();
			for (std::size_t i = 0; i < size; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}
	T& operator[](std::size_t index)
	{
		if (index >= size) {
			throw std::out_of_range("Index out of bounds");
		}
		return data[index];
	}
	const T& operator[](std::size_t index) const
	{
		if (index >= size) {
			throw std::out_of_range("Index out of bounds");
		}
		return data[index];
	}
	std::size_t Size() const { return size; }
	~Array() { delete[] data; }
};



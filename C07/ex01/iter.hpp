#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
	if (!array)
		return;
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}
template <typename T>
void iter(T *array, size_t length, const void (*func)(T &)) {
	if (!array)
		return;
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}


template <typename T>
void iter(const T *array, size_t length, const void (*func)(T &)) {
	if (!array)
		return;
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

template <typename T>
void iter(const T *array, size_t length,  void (*func)(T &)) {
	if (!array)
		return;
	for (size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}



template <typename T>
void increment(T &elem) {
	++elem;
}

#endif
#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "easyfind.tpp"


template <typename T>

typename T::iterator easyfind(T& container, int value);

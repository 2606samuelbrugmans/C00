#include "easyfind.hpp"


template <typename T>


typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		std::stringstream ss;
        ss << "the value " << value << " couldn't be found in the container";
        throw std::runtime_error(ss.str());
	}
	return it;
}



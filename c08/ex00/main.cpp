#include "easyfind.hpp"




int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + 5);

    std::vector<int>::iterator it;

    try {
		it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

    try {
		it = easyfind(vec, 5);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

    return 0;
}
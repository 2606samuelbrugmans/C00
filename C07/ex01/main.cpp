#include "iter.hpp"


void printElement(int &elem) {
	std::cout << elem << " ";
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};

	std::cout << "Array elements: ";
	iter(arr, 5, printElement);
	std::cout << std::endl;
	iter(arr, 5, increment);
	std::cout << "Incremented array elements: ";
	iter(arr, 5, printElement);
	std::cout << std::endl;

	return 0;
}
#include "serialiser.hpp"

int main()
{
	Data data;
	int value = 42;
	data.ptr = &value;

	Data *stuff = &data;
	uintptr_t serialized = Serialiser::serialise(stuff);

	std::cout << "original Data*     : " << stuff << std::endl;
	std::cout << "serialized (raw)   : " << serialized << std::endl;

	Data *deser = Serialiser::deserialise(serialized);
	std::cout << "deserialised Data* : " << deser << std::endl;

	if (deser == stuff)
		std::cout << "Success: pointers match" << std::endl;
	else
		std::cout << "Failure: pointers differ" << std::endl;

	std::cout << "data.ptr: " << data.ptr << ", value: " << *static_cast<int*>(data.ptr) << std::endl;
	std::cout << "deser->ptr: " << deser->ptr << ", value: " << *static_cast<int*>(deser->ptr) << std::endl;

	return 0;
}
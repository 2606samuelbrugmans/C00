#ifndef SERIALISER_HPP
#define SERIALISER_HPP


struct Data {
	void *ptr;
};
#include <stdint.h>  
#include <iostream>


class Serialiser {
	private :
		Serialiser(void);
		Serialiser(const Serialiser& other);
		Serialiser& operator=(const Serialiser& other);
		~Serialiser(void);

	public :
		static uintptr_t serialise(Data *ptr);
		static Data *deserialise(uintptr_t raw);

};

#endif
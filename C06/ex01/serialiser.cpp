#include "serialiser.hpp"


Serialiser::Serialiser( void ) {}
Serialiser::Serialiser( const Serialiser& other ) { (void)other; }
Serialiser& Serialiser::operator=( const Serialiser& other ) { (void)other; return *this; }
Serialiser::~Serialiser( void ) {}

uintptr_t Serialiser::serialise(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}


Data *Serialiser::deserialise(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

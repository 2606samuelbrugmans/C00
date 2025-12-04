#include "Base.hpp"

Base::Base()
{
}
Base::~Base()
{

}
Base * Base::generate(void)
{
	int random = rand() % 3;
	std::cout << "random number" << random << std::endl;
	switch (random) {
        case 0:
		return new A();
        case 1:
		return new B();
        case 2:
		return new C();
    }
    return NULL;
}
void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void Base::identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch(...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch(...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch(...) {}

}

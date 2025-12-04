#include "Base.hpp"

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 20; i++) {
        Base* ptr = Base::generate();
        std::cout << i + 1 << ": ";
        Base::identify(ptr);
        delete ptr;
    }

}
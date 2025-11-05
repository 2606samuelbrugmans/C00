#include "Animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "Wrongcat.hpp"
#include "Wrongdog.hpp"
int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); 
j->makeSound();
meta->makeSound();

const WrongAnimal* wrongMeta = new WrongAnimal();
const WrongAnimal* wrongCat = new Wrongcat();
const WrongAnimal* wrongDog = new Wrongdog();
wrongMeta->makeSound();
wrongCat->makeSound();
wrongDog->makeSound();

return 0;
}
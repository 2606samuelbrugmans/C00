#include "Animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "Wrongcat.hpp"
#include "Wrongdog.hpp"
int main()
{
    const int size = 5;
    Animal* animals[size];

    Dog* d1 = new Dog();
    Dog* d2 = new Dog(*d1);
    Animal* d3 = new Animal;

    d3->makeSound();
    d2->makeSound();

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();

    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    for (int i = 0; i < size; i++)
        delete animals[i];

    delete d1;
    delete d2;
    return 0;
}
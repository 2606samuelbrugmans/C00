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
    
    Animal BaseAnimal;
    BaseAnimal.getBrain();
    BaseAnimal.makeSound();
    Dog* d1 = new Dog();
    d1->getBrain()->setIdea(0, "Chase the cat");
    ///deep copy test
    
    Dog* d2 = new Dog(*d1);
    std::cout << d2->getBrain()->getIdea(0);
    
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
#include "Array.hpp"


#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(std::time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
    const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
    numbers[i] = std::rand();
    }
    delete [] mirror;//
    return 0;
}
/*
int main(int, char**)
{
    Array<int> intArray(5);
    Array<int> a;

    for (std::size_t i = 0; i < intArray.Size(); ++i) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    for (std::size_t i = 0; i < intArray.Size(); ++i) {
        intArray[i] = (i) * 10;
    }
    for (std::size_t i = 0; i < intArray.Size(); ++i) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    Array<int> nouveauArray(intArray);
    for (std::size_t i = 0; i < nouveauArray.Size(); ++i) {
        std::cout << "nouveauArray[" << i << "] = " << nouveauArray[i] << std::endl;
    }

    for (std::size_t i = 0; i < nouveauArray.Size(); ++i) {
        nouveauArray[i] = nouveauArray[i] * 10;
    }
    for (std::size_t i = 0; i < nouveauArray.Size(); ++i) {
        std::cout << "nouveauArray[" << i << "] = " << nouveauArray[i] << std::endl;
    }
    Array<int> Chaine = (nouveauArray);
    for (std::size_t i = 0; i < Chaine.Size(); ++i) {
        Chaine[i] = Chaine[i] * 10;
    }
    for (std::size_t i = 0; i < Chaine.Size(); ++i) {
        std::cout << "Chaine[" << i << "] = " << Chaine[i] << std::endl;
    }
    for (std::size_t i = 0; i < intArray.Size(); ++i) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }
    for (std::size_t i = 0; i < nouveauArray.Size(); ++i) {
        std::cout << "nouveauArray[" << i << "] = " << nouveauArray[i] << std::endl;
    }



    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";
    for (std::size_t i = 0; i < strArray.Size(); ++i) {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }
    try {
        std::cout << intArray[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
   
    return 0;
}
    */
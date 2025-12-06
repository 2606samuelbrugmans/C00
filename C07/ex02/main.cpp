#include "Array.hpp"


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
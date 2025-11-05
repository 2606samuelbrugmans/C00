#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>


class WrongAnimal {
  protected:
	std::string type;

  public:
	WrongAnimal();
	WrongAnimal(std::string t);
	virtual ~WrongAnimal();
	void makeSound() const; 
	WrongAnimal(WrongAnimal const &other);
	WrongAnimal &operator=(WrongAnimal const &other);
	std::string getType() const;
};
#endif
#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat Default constructor called" << std::endl;
	_type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow~" << std::endl;
}
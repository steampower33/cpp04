#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal can't make sound" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
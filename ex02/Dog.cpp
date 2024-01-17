#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog Default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(NULL) {
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		if (_brain)
			delete _brain;
		Brain* b = new Brain(*other._brain);
		_brain = new Brain(*other._brain);
		delete b;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Barkkkkkkkkkk!!!!!!" << std::endl;
}

Brain* Dog::getBrain() {
	return _brain;
}

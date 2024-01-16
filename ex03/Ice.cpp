#include "Ice.hpp"

Ice::Ice() {
	_type = "ice";
}

Ice::Ice(const std::string& type) {
	_type = type;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
	{
		_type = other.getType();
	}
	return *this;
}

Ice::~Ice() {}

const std::string& Ice::getType() const {
	return _type;
}

Ice* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
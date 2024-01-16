#include "AMateria.hpp"

AMateria::AMateria() : _type("") {}

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& other) {
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
	{
		_type = other.getType();
	}
	return *this;
}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* materia is " << target.getName() << " *" << std::endl;
}
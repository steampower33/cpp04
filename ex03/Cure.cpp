#include "Cure.hpp"

Cure::Cure() {
	_type = "cure";
}

Cure::Cure(const std::string& type) {
	_type = type;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	*this = other;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
	{
		_type = other.getType();
	}
	return *this;
}

Cure::~Cure() {}

const std::string& Cure::getType() const {
	return _type;
}

Cure* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
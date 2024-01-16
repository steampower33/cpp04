#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const std::string& type);
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);
	~Cure();
	const std::string & getType() const; //Returns the materia type
	Cure* clone() const;
	void use(ICharacter& target);
};

#endif
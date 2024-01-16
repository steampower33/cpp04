#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	MateriaSource(const std::string& name);
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();
	void learnMateria(AMateria* m);
	AMateria* createMateria(const std::string& type);
private:
	std::string _name;
	AMateria* _templates[4];
};

#endif
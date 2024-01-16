#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const std::string& name) {
	_name = name;
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_templates[i])
				delete _templates[i];
			if (other._templates[i])
				_templates[i] = (other._templates[i])->clone();
			else
				_templates[i] = NULL;
		}

	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i])
			delete _templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return NULL;
}
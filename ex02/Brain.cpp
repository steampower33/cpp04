#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			_ideas[i] = "multiple of 2";
		else if (i % 3 == 0)
			_ideas[i] = "multiple of 3";
		else if (i % 5 == 0)
			_ideas[i] = "multiple of 5";
		else if (i % 7 == 0)
			_ideas[i] = "multiple of 7";
		else
			_ideas[i] = "other";
	}
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

std::string Brain::getIdeas(int index) {
	return _ideas[index];
}

void Brain::setIdeas(std::string ideas, int index) {
	_ideas[index] = ideas;
}


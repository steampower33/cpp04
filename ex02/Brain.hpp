#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();
	std::string getIdeas(int index);
	void setIdeas(std::string ideas, int index);
private:
	std::string _ideas[100];
};

#endif
#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <string>
# include <cstdlib>
# include <iostream>
# include <vector>
# include <algorithm>

# include "ASpell.hpp"
# include "ATarget.hpp"
# include "Dummy.hpp"
# include "Fwoosh.hpp"

class Warlock
{
	private:
	std::string				name;
	std::string				title;
	std::vector<ASpell *>	spells;

	Warlock() {return;}
	Warlock(const Warlock &input) { (void) input; }
	const Warlock &	operator=(const Warlock &input) { (void) input; return *this;}
	
	public:
	~Warlock();
	Warlock(const std::string &name, const std::string &title); 

	const std::string &	getName(void) const;
	const std::string &	getTitle(void) const;
	void				setName(const std::string &name);
	void				setTitle(const std::string &title);

	void	introduce(void) const;

	void	learnSpell(ASpell *input);
	void	forgetSpell(std::string name);
	void	launchSpell(std::string name, ATarget &input);

	void	printSpells(void)
	{
		std::cout << "Spells size : " << this->spells.size() << std::endl;
		for (unsigned short i = 0; i < this->spells.size(); i++)
		{
			std::cout << this->spells[i]->getName() << " | " << this->spells[i]->getEffects() << std::endl;
		}
		return ;
	};
};

#endif
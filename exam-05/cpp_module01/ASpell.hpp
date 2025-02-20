#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>
#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
	// ASpell(const ASpell &input) { (void)input; };
	// const ASpell &	operator=(const ASpell &input) { return *this; };

	protected:
	std::string	name;
	std::string	effects;

	public:
	virtual	~ASpell();
	ASpell(std::string name, std::string effects);

	const std::string	getName(void) const;
	const std::string	getEffects(void) const;
	void				launch(ATarget &input);

	virtual ASpell *	clone(void) = 0;
};

#endif
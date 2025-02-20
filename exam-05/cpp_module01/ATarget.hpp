#ifndef ATARGET_HPP
# define ATARGET_HPP

#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
	// ATarget(const ATarget &input) { (void)input; };
	// const ATarget &	operator=(const ATarget &input) { return *this; };

	protected:
	std::string	type;
	
	public:
	virtual	~ATarget();
	ATarget(std::string type);

	const std::string &	getType(void) const;
	void	getHitBySpell(const ASpell &input);

	virtual ATarget *	clone(void) = 0;
};

#endif
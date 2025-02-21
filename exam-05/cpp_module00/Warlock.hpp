#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <string>
# include <cstdlib>
# include <iostream>
# include <algorithm>

class Warlock
{
	private:
	std::string	name;
	std::string	title;

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
};

#endif

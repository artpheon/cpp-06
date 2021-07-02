#ifndef CONVERTER_HPP
# define CONVERTER_HPP
# include <iostream>
# include <string>
# include <typeinfo>
# include <exception>
# include <sstream>

class Converter {
private:
	char	_c;
	int		_i;
	float	_f;
	double	_d;
	bool	_cImposs;
	bool	_iImposs;
	bool	_fImposs;
	bool	_dImposs;
	void	displayC() const;
	void	displayI() const;
	void	displayF() const;
	void	displayD() const;
	Converter();
public:
	Converter(const std::string&);
	Converter(const Converter&);
	Converter& operator=(const Converter&);
	virtual ~Converter();
	void    display() const;
};

#endif
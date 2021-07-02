#include "Converter.hpp"

Converter::Converter(const std::string& str) :
_cImposs(false),
_iImposs(false),
_fImposs(false),
_dImposs(false)
{
	if (str.length() == 1)
	{
		if (str[0] <= '9' && str[0] >= '0') {
			int tmp = std::stoi(str);
			_c = static_cast<char>(tmp);
			_i = tmp;
			_f = static_cast<float>(tmp);
			_d = static_cast<double>(tmp);
		}
		else {
			_c = static_cast<char>(str[0]);
			_i = static_cast<int>(str[0]);
			_f = static_cast<float>(str[0]);
			_d = static_cast<double>(str[0]);
		}
	}
	else {
		try {
			_c = std::stoi(str);
		}
		catch (std::invalid_argument &e) {
			_cImposs = true;
		}
		catch (std::out_of_range &e) {
			_cImposs = true;
		}
		try {
			_i = std::stoi(str);
		}
		catch (std::invalid_argument &e) {
			_iImposs = true;
		}
		catch (std::out_of_range &e) {
			_cImposs = true;
		}
		try {
			_f = std::stof(str);
		}
		catch (std::invalid_argument &e) {
			_fImposs = true;
		}
		catch (std::out_of_range &e) {
			_cImposs = true;
		}
		try {
			_d = std::stod(str);
		}
		catch (std::invalid_argument &e) {
			_dImposs = true;
		}
		catch (std::out_of_range &e) {
			_cImposs = true;
		}
	}
 }

Converter::Converter(const Converter& right) {
    *this = right;
}

Converter& Converter::operator=(const Converter& right) {
    if (this != &right) {
        _c = right._c;
        _i = right._i;
        _f = right._f;
        _d = right._d;
    } 
    return *this;
}

Converter::~Converter() {}

void	Converter::displayC() const {
	std::cout << "char: ";
	if (_cImposs)
		std::cout << "impossible" << std::endl;
	else {
		if (_c <= 31 || _c == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << _c << std::endl;
	}
}

void	Converter::displayI() const {
	std::cout << "int: ";
	if (_iImposs)
		std::cout << "impossible" << std::endl;
	else {
		std::cout << _i << std::endl;
	}
}

void	Converter::displayF() const {
	std::cout << "float: ";
	if (_fImposs)
		std::cout << "impossible" << std::endl;
	else {
		std::cout << _f << (static_cast<int>(_f) == _f ? ".0" : "") << "f" << std::endl;
	}
}

void	Converter::displayD() const {
	std::cout << "double: ";
	if (_dImposs)
		std::cout << "impossible" << std::endl;
	else {
		std::cout << _d << (static_cast<int>(_d) == _d ? ".0" : "") << std::endl;
	}
}

void    Converter::display() const {
	displayC();
	displayI();
	displayF();
	displayD();
}

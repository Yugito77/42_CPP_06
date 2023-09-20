/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:54:36 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/23 13:30:30 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

Convert::Convert() : _int(0), _char('0'), _double(0), _float(0),
					_inf(false), _minus_inf(false), _plus_inf(false),
					_nan(0), _error(false), _char_overflow(false),
					_int_overflow(false), _float_overflow(false)
{
}

Convert::Convert(Convert const& cpy)
{
	*this = cpy;
}

Convert::Convert(std::string str) :	_inf(false), _minus_inf(false), _plus_inf(false),
									_nan(0), _error(false), _char_overflow(false),
									_int_overflow(false), _float_overflow(false)
{
	if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
		_minus_inf = true;
	else if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
		_plus_inf = true;
	else if (str.compare("inff") == 0 || str.compare("inf") == 0)
		_inf = true;
	else if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		_nan = true;
	else if (is_int(str))
		convert_int(str);
	else if (is_char(str))
		convert_char(str);
	else if (is_double(str))
		convert_double(str);
	else if (is_float(str))
		convert_float(str);
	else
		_error = true;

}

Convert::~Convert()
{
}

Convert& Convert::operator=(Convert const& cpy)
{
	if (this == &cpy)
		return (*this);
	_int = cpy._int;
	_char = cpy._char;
	_double = cpy._double;
	_float = cpy._float;
	_inf = cpy._inf;
	_minus_inf = cpy._minus_inf;
	_plus_inf = cpy._plus_inf;
	_nan = cpy._nan;
	_error = cpy._error;
	_char_overflow = cpy._char_overflow;
	_int_overflow = cpy._int_overflow;
	_float_overflow = cpy._float_overflow;
	return (*this);
}

/********************************CHECK**************************************************************/

bool	is_int(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && !(str[i] <= '9' && str[i] >= '0') && str[i] != '-')
			return (false);
		if (i != 0 && !(str[i] <= '9' && str[i] >= '0'))
			return (false);
	}
	return (true);
}

bool	is_char(std::string str)
{
	if (str.length() == 1 && std::isprint(str[0]))
		return (true);
	return (false);
}

bool	is_float(std::string str)
{
	int	point = 0;

	if ((!std::isdigit(str[0]) && str[0] != '-' && str[0] != '+'))
		return (false);
	if ( str[str.length() - 1] != 'f')
		return (false);
	for (int i = 1; i < ((int)str.length() - 1); i++)
	{
		if (!(std::isdigit(str[i])  || (str[i] == '.' && !point)))
			return (false);
		point = point || (str[i] == '.');
	}
	return (true);
}

bool	is_double(std::string str)
{
	int	point = 0;

	if ((!std::isdigit(str[0]) && str[0] != '-' && str[0] != '+'))
		return (false);
	for (int i = 1; i < ((int)str.length() - 1); i++)
	{
		if (!(std::isdigit(str[i])  || (str[i] == '.' && !point)))
			return (false);
		point = point || (str[i] == '.');
	}
	return (true);
}

/*************************************CONVERT*********************************************************/

void	Convert::check_overflow(std::string str)
{
	double	nb;

	nb = strtod(str.c_str(), NULL);
	if (errno == 0)
	{
		if (nb < INT_MIN || nb > INT_MAX)
			 _int_overflow = true;
		if (nb < CHAR_MIN || nb > CHAR_MAX)
			 _char_overflow = true;
		if (nb <= std::numeric_limits<float>::max() * -1  || nb > std::numeric_limits<float>::max())
			_float_overflow = true;
	}
}

void	Convert::convert_int(std::string str)
{
	long int	nb;
	check_overflow(str);
	nb = atol(str.c_str());
	if (nb < INT_MIN || nb > INT_MAX)
		_error = true;
	else
	{
		_int = atoi(str.c_str());
		_double = static_cast<double>(_int);
		_float = static_cast<float>(_int);
		_char = static_cast<char>(_int);
	}
}

void	Convert::convert_char(std::string str)
{
	check_overflow(str);
	_char = str[0];
	_int = static_cast<int>(_char);
	_double = static_cast<double>(_char);
	_float = static_cast<float>(_char);
}

void	Convert::convert_double(std::string str)
{
	check_overflow(str);
	_double = strtod(str.c_str(), NULL);
	if (errno != 0)
		_error = true;
	else
	{
		_int = static_cast<int>(_double);
		_char = static_cast<char>(_double);
		_float = static_cast<float>(_double);
	}
}

void	Convert::convert_float(std::string str)
{
	check_overflow(str);
	_float = strtof(str.c_str(), NULL);
	if (errno != 0)
		_error = true;
	else
	{
		_int = static_cast<int>(_float);
		_char = static_cast<char>(_float);
		_double = static_cast<double>(_float);
	}
}

/*************************************PRINT*********************************************************/

void	Convert::print() const
{
	std::cout<<"char : ";
	print_char();
	std::cout<<"int : ";
	print_int();
	std::cout<<"float : ";
	print_float();
	std::cout<<"double : ";
	print_double();
}

void	Convert::print_int() const
{
	if (_minus_inf || _plus_inf || _inf || _nan
			|| _error || _int_overflow)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int << std::endl;
}

void	Convert::print_char() const
{
	if (_minus_inf || _plus_inf || _inf || _nan
			|| _error || _int_overflow)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(_char)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout <<_char << std::endl;
}

void	Convert::print_double() const
{
	if (_error)
		std::cout << "impossible" << std::endl;
	else if (_minus_inf)
		std::cout << "-inf" << std::endl;
	else if (_plus_inf)
		std::cout << "+inf" << std::endl;
	else if (_inf)
		std::cout << "inf" << std::endl;
	else if (_nan)
		std::cout << "nan" << std::endl;
	else
   		std::cout << std::setiosflags(std::ios::fixed) << _double << std::endl;
}

void	Convert::print_float() const
{
	if (_error || _float_overflow)
		std::cout << "impossible" << std::endl;
	else if (_minus_inf)
		std::cout << "-inff" << std::endl;
	else if (_plus_inf)
		std::cout << "+inff" << std::endl;
	else if (_inf)
		std::cout << "inff" << std::endl;
	else if (_nan)
		std::cout << "nanf" << std::endl;
	else
   		std::cout << std::setiosflags(std::ios::fixed) << _float << "f" << std::endl;
}

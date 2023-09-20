/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:54:27 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/21 14:26:39 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <stdlib.h>
# include <limits.h>
# include <limits>
# include <float.h>
# include <errno.h>
# include <sstream>

class	Convert
{
	public :

	Convert();
	Convert(std::string	str);
	Convert(Convert const& cpy);
	virtual ~Convert();
	Convert&	operator=(Convert const& cpy);

	void	convert_int(std::string str);
	void	convert_char(std::string str);
	void	convert_double(std::string str);
	void	convert_float(std::string str);

	void	check_overflow(std::string str);

	void	print() const;
	void	print_int() const;
	void	print_char() const;
	void	print_double() const;
	void	print_float() const;

	private :

	int		_int;
	char	_char;
	double	_double;
	float	_float;
	bool	_inf;
	bool	_minus_inf;
	bool	_plus_inf;
	bool	_nan;
	bool	_error;
	bool	_char_overflow;
	bool	_int_overflow;
	bool	_float_overflow;
};

bool	is_int(std::string str);
bool	is_char(std::string str);
bool	is_float(std::string str);
bool	is_double(std::string str);

#endif
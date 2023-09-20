/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:23:08 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/23 13:40:03 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>
#include <stdint.h>

class	Data
{

	public :
	
	Data();
	Data(std::string str);
	Data(Data const& cpy);
	~Data();

	Data&	operator=(Data const& cpy);
	std::string getData(void) const;

	private :
	
	std::string	_data;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
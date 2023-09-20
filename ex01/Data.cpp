/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:23:01 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/23 13:35:54 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _data("Unknown")
{
}

Data::Data(std::string str) : _data(str)
{
}

Data::Data(Data const& cpy)
{
    *this = cpy;
}

Data::~Data()
{
}

Data& Data::operator=(Data const& cpy)
{
    if (this == &cpy)
        return (*this);
    _data = cpy._data;
    return (*this);
}

std::string Data::getData(void) const
{
    return(this->_data);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialisation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:35:09 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/23 13:35:23 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t   serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data*   deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data *>(raw));
}
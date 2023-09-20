/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:22:44 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/23 13:40:19 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main ()
{
	Data data("4u83290432052408fnruei3892873902");

	std::cout << "data address : " << &data << ", value : " << data.getData()  << std::endl;

	uintptr_t PTR = serialize((Data*)&data);

	std::cout << "PTR address returned by serialize : " << PTR << std::endl;

	std::cout << "Data address returned by deserialize : " << deserialize(PTR)  << ", value : " << deserialize(PTR)->getData()<< std::endl;
}
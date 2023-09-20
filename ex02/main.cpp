/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:50:18 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/24 14:35:13 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	{
		std::cout << "Test pointeur: " << std::endl;
		Base *test;

		test = generate();	
		identify(test);

		delete(test);
	}
	{
		std::cout << "Test reference: " << std::endl;
		Base& test = *generate();	
		identify(test);

		delete(&test);
	}
	return (0);
}
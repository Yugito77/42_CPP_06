/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:50:26 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/24 14:34:16 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *	generate(void)
{
    srand (time(NULL));
    int i = rand() % 3;
    if (i == 0)
        return (new A());
    else if (i == 1)
		return (new B());
	else
		return (new C());
}

void	identify(Base* p)
{
    Base *a = dynamic_cast<A*>(p);
	if (a)
		std::cout<<"A"<<std::endl;
	Base *b = dynamic_cast<B*>(p);
	if (b)
		std::cout<<"B"<<std::endl;
	Base *c = dynamic_cast<C*>(p);
	if (c)
		std::cout<<"C"<<std::endl;
}

void	identify(Base& p)
{
	try
	{
		Base a = dynamic_cast<A&>(p);
		std::cout<<"A"<<std::endl;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		Base b = dynamic_cast<B&>(p);
		std::cout<<"B"<<std::endl;
	}
	catch(std::exception& e)
	{
	}
	try
	{
		Base c = dynamic_cast<C&>(p);
		std::cout<<"C"<<std::endl;
	}
	catch(std::exception& e)
	{
	}
}

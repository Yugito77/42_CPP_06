/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:50:33 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/23 16:11:19 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <cstdlib>


class	Base
{
	
	public :
	
	virtual ~Base(){};
};

class A : public Base
{
	
};

class B : public Base
{
	
};

class C : public Base
{
	
};

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:51:53 by hcherpre          #+#    #+#             */
/*   Updated: 2022/11/21 14:23:38 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int main(int argc, char **argv)
{
    std::string str;
    Convert *conversion;

    if (argc != 2)
    {
        std::cout<<"Wrong Number of Arguments !"<<std::endl;
        return(0);
    }
    
    str = argv[1];
    conversion = new Convert(str);
    conversion->print();
    
    delete conversion;

    return (0);
}
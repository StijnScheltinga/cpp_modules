/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:49:36 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/26 17:49:37 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	std::string	total_string;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
    	for (int i = 1; argv[i]; i++)
			for (int j = 0; argv[i][j]; j++)	
				total_string += std::toupper(argv[i][j]);
		std::cout << total_string << std::endl;
    }
    return (0);
}
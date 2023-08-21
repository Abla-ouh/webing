/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:48:07 by abouhaga          #+#    #+#             */
/*   Updated: 2023/08/18 16:45:27 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/configParse/configFile.hpp"
#include "HTTPServer.hpp"
#include<stdio.h>


int main(int ac, char const *av[])
{
	if (ac == 2)
	{
		try {
			configFile config((string(av[1])));
            HTTPServer server(config);
			// config.print();
            server.start();
		}
		catch (std::exception& err)
		{
			std::cerr << RED "Error: " << err.what();
		}
	}
	else
		cout << RED "using: ./webserv <config file> \"./webserve message.conf\"\n";
	return 0;
}


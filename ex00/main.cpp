/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:13:18 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/01 18:09:22 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int argc, char **argv) {
    
    if (argc != 2) {
        std::cerr << "Error argument!" << std::endl;
        return 1;
    }

    // Convert the input
    std::string result = ScalarConverter::convert(argv[1]);
    std::cout << result << std::endl;

    return 0;
}

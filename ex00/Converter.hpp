/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:47:50 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/01 18:09:27 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <cmath>

class ScalarConverter {
     
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);
        ~ScalarConverter(void);
   
    public:
        
        static std::string convert(const char* input);
        // class exceptions
        class NonDisplayableException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Non displayable";
                }
        };

        class ImpossibleException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "impossible";
                }
        };

        class NonConvertibleException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Non convertible";
                }
        };

        class OutOfRangeException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Out of range";
                }
        };

        class InvalidInputException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Invalid input";
                }
        };

        ScalarConverter& operator=(const ScalarConverter& rhs);
        
};

std::ostream& operator<<(std::ostream& os, const ScalarConverter& src);

#endif
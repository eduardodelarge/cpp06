/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:47:46 by caeduard          #+#    #+#             */
/*   Updated: 2023/10/01 18:11:28 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

ScalarConverter::ScalarConverter(void) {
    return;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
    *this = src;
    return;
}

ScalarConverter::~ScalarConverter(void) {
    return;
}

std::string ScalarConverter::convert(const char* input) {
    
   /* {
            double d;
    std::string str(input);

    std::stringstream result;
    result.precision(1);
    result.setf(std::ios::fixed);

    try {
        // Try to convert the input to a double
        d = std::strtod(input, NULL);

        if (std::isnan(d) || d < 0 || d > 255) {
            // Handle NaN or out-of-range character
            throw std::runtime_error("Invalid input");
        }

        if (std::isprint(static_cast<int>(d))) {
            // Convert the double to a character
            char c = static_cast<char>(d);
            result << "char  : " << c << std::endl;
        } else {
            result << "char  : Non displayable" << std::endl;
        }

        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
            // Check if the integer is out of range
            throw std::runtime_error("Out of Range");
        } else {
            // Convert the double to an integer
            int i = static_cast<int>(d);
            result << "int  : " << i << std::endl;
        }

        result << "float: " << static_cast<float>(d) << "f" << std::endl;
        result << "double: " << d;
    } catch(const std::exception& e) {
        return e.what();
    }

    return result.str();
    }*/
    
    double d;
    std::string str(input);

    /*Tryng to convert to double*/
    
    // Check if the input is a single character that is not a digit
    if (str.length() == 1 && !std::isdigit(input[0])) {
        // If it's a single character, cast it to a double
        d = static_cast<double>(input[0]);
    } else {
        try {
            // Try to convert the input to a double using std::strtod
            d = std::strtod(input, NULL);
        } catch(const std::invalid_argument& ia) {
            // Handle invalid input (not a recognized number or character)
            return "No recognized numbers or char\nUse: ./convert <number>||<char>";
        } catch(const std::out_of_range& oor) {
            // Handle out-of-range input
            return "Out of Range error\nUse: ./convert <number>||<char>\n" + std::string(oor.what());
        }
    }

    // Create a stringstream to build the result
    std::stringstream result;
    // Set precision for floating-point output
    result.precision(1);
    // Set fixed notation for floating-point output
    result.setf(std::ios::fixed);

    /*Trying to convert to char*/
    // Check if the input is infinity or NaN
    if (std::isinf(d) || std::isnan(d)) {
        result << "char  : impossible" << std::endl;
    } else {
        // Convert the double to a character
        char c = static_cast<char>(d);
        if (c < 32 || c > 126) {
            // Check if the character is non-displayable
            result << "char  : Non displayable" << std::endl;
        } else {
            // Output the character
            result << "char  : " << c << std::endl;
        }
    }

    // Check if the input is infinity or NaN
    if (std::isinf(d) || std::isnan(d)) {
        result << "int  : impossible" << std::endl;
    } else {
        // Convert the double to an integer
        int i = static_cast<int>(d);
        if (d > std::numeric_limits<int>::max() || d < -std::numeric_limits<int>::max()) {
            // Check if the integer is out of range
            result << "int  : Non displayable" << std::endl;
        } else {
            // Output the integer
            result << "int  : " << i << std::endl;
        }
    }
    // Output the float and double representations
    result << "float: " << static_cast<float>(d) << "f" << std::endl;
    result << "double: " << d;
    
    // Convert the stringstream to a string and return it as the result
    return result.str();
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    static_cast<void>(rhs);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ScalarConverter& src) {
    os << src;
    return os;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:12:02 by caeduard          #+#    #+#             */
/*   Updated: 2023/09/29 16:42:05 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
 
    Data dataObject(42);
   
    uintptr_t serializedPointer = Serializer::serialize(&dataObject);

    std::cout << "serialized pointer: " << serializedPointer << std::endl;
    
    Data* deserializedPointer = Serializer::deserialize(serializedPointer);

    if (deserializedPointer == &dataObject) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Original value: " << dataObject.getValue() << std::endl;
        std::cout << "Deserialized value: " << deserializedPointer->getValue() << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}
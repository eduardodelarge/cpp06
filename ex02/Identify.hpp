/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caeduard <caeduard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:25:21 by caeduard          #+#    #+#             */
/*   Updated: 2023/09/30 04:20:00 by caeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base {
    public:
        virtual ~Base();

};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif
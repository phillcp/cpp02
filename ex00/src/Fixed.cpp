/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:49:49 by fheaton-          #+#    #+#             */
/*   Updated: 2023/01/19 17:38:08 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->_fPoint = 0;
}

Fixed::Fixed(Fixed const &copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &copy){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fPoint = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fPoint);
}

void Fixed::setRawBits(int const raw){
	this->_fPoint = raw;
}

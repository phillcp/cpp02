/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:45:55 by fheaton-          #+#    #+#             */
/*   Updated: 2023/01/19 18:15:55 by fheaton-         ###   ########.fr       */
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

Fixed::Fixed(int const fPoint){
	std::cout << "Int constructor called" << std::endl;
	this->_fPoint = fPoint << _fBits;
}

Fixed::Fixed(float const fPoint)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fPoint = roundf(fPoint * (1 << _fBits));
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

int Fixed::toInt() const{
	return (this->_fPoint >> _fBits);
}

float Fixed::toFloat() const{
	return (this->_fPoint / static_cast<float>(1 << _fBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return (out);
}

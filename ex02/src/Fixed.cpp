/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:45:55 by fheaton-          #+#    #+#             */
/*   Updated: 2023/01/19 19:31:15 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	this->_fPoint = 0;
}

Fixed::Fixed(Fixed const &copy){
	*this = copy;
}

Fixed::Fixed(int const fPoint){
	this->_fPoint = fPoint << _fBits;
}

Fixed::Fixed(float const fPoint){
	this->_fPoint = roundf(fPoint * (1 << _fBits));
}

Fixed::~Fixed(){}

Fixed& Fixed::operator=(Fixed const &copy){
	this->_fPoint = copy.getRawBits();
	return (*this);
}



bool Fixed::operator<(Fixed const &copy) const{
	return (this->_fPoint < copy._fPoint);
}

bool Fixed::operator<=(Fixed const &copy) const{
	return (this->_fPoint <= copy._fPoint);
}

bool Fixed::operator>(Fixed const &copy) const{
	return (this->_fPoint > copy._fPoint);
}

bool Fixed::operator>=(Fixed const &copy) const{
	return (this->_fPoint >= copy._fPoint);
}

bool Fixed::operator==(Fixed const &copy) const{
	return (this->_fPoint == copy._fPoint);
}

bool Fixed::operator!=(Fixed const &copy) const{
	return (this->_fPoint != copy._fPoint);
}



Fixed Fixed::operator+(Fixed const &copy) const{
	return (this->toFloat() + copy.toFloat());
}

Fixed Fixed::operator-(Fixed const &copy) const{
	return (this->toFloat() - copy.toFloat());
}

Fixed Fixed::operator*(Fixed const &copy) const{
	return (this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(Fixed const &copy) const{
	return (this->toFloat() / copy.toFloat());
}



Fixed Fixed::operator++(void){
	this->_fPoint++;
	return(*this);
}
Fixed Fixed::operator++(int){
	const Fixed old (*this);
	this->_fPoint++;
	return(old);
}
Fixed Fixed::operator--(void){
	this->_fPoint--;
	return(*this);
}
Fixed Fixed::operator--(int){
	const Fixed old (*this);
	this->_fPoint--;
	return(old);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return (out);
}



Fixed& Fixed::min(Fixed& a, Fixed& b){
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return (a > b ? a : b);
}





int Fixed::getRawBits() const{
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

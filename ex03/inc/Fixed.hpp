/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:45:53 by fheaton-          #+#    #+#             */
/*   Updated: 2023/01/19 19:26:32 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int _fPoint;
		static int const _fBits = 8;
	public:
		Fixed();
		Fixed(Fixed const &copy);
		Fixed(int const fPoint);
		Fixed(float const fPoint);
		~Fixed();
		Fixed& operator=(Fixed const &copy);
		
		bool operator<(Fixed const &copy) const;
		bool operator<=(Fixed const &copy) const;
		bool operator>(Fixed const &copy) const;
		bool operator>=(Fixed const &copy) const;
		bool operator==(Fixed const &copy) const;
		bool operator!=(Fixed const &copy) const;

		Fixed operator+(Fixed const &copy) const;
		Fixed operator-(Fixed const &copy) const;
		Fixed operator*(Fixed const &copy) const;
		Fixed operator/(Fixed const &copy) const;

		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt() const;
		float toFloat() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif

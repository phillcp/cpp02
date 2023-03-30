/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheaton- <fheaton-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:45:41 by fheaton-          #+#    #+#             */
/*   Updated: 2023/01/19 18:10:10 by fheaton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int _fPoint;
		static int const _fBits;
	public:
		Fixed();
		Fixed(Fixed const &copy);
		~Fixed();
		Fixed& operator=(Fixed const &copy);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif

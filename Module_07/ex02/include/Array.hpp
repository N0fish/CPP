/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:30:17 by algultse          #+#    #+#             */
/*   Updated: 2025/03/09 23:32:30 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "Colors.hpp"

template <typename T>
class Array {
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array &other);
		~Array();
		
		Array&	operator=(const Array &other);

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const;

		class OutOfBoundsException : public std::exception {
			public:
				const char* what() const throw();
		};
};

# include "Array.tpp"

#endif
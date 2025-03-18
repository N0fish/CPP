/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:35:00 by algultse          #+#    #+#             */
/*   Updated: 2025/03/18 13:49:27 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Colors.hpp"

typedef unsigned long uintptr_t;

struct Data;

class Serializer {
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		static uintptr_t	lastValidPointer;

		Serializer();
		Serializer(const Serializer& other);
		~Serializer();
		Serializer& operator=(const Serializer& other);
};

#endif
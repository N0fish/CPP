/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:40:27 by algultse          #+#    #+#             */
/*   Updated: 2025/03/06 19:41:14 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

/* -------------------------------------------------------------------------- */
/*                        PUBLIC STATIC FUNCTION                              */
/* -------------------------------------------------------------------------- */

uintptr_t	Serializer::serialize(Data* ptr) {
	lastValidPointer = reinterpret_cast<uintptr_t>(ptr);
	return (lastValidPointer);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	if (raw != lastValidPointer) {
		std::cerr << PURPLE "Error" RESET << ": Attempted to deserialize an invalid pointer!" << std::endl;
		return (NULL);
	}

	return (reinterpret_cast<Data*>(raw));
}

/* -------------------------------------------------------------------------- */
/*               PRIVATE COPLIEN'S FUNCTIONS (not instanciable)               */
/* -------------------------------------------------------------------------- */
uintptr_t	Serializer::lastValidPointer = 0;

Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer::~Serializer() {}
Serializer& Serializer::operator=(const Serializer&) { return (*this); }

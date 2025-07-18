/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:07:43 by algultse          #+#    #+#             */
/*   Updated: 2025/03/08 12:15:40 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(const T &a, const T &b) {
	return ((a < b) ? a : b);
}

template <typename T>
T	max(const T &a, const T &b) {
	return ((a > b) ? a : b);
}

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:10:05 by algultse          #+#    #+#             */
/*   Updated: 2025/03/08 17:02:31 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include "Colors.hpp"

template <typename T>
void iter(T* array, std::size_t len, void (*func)(T &)) {  
    if (!array || !func) {
        std::cerr << "Error: NULL pointer passed to iter()" << std::endl;
        return ;
    }
    for (std::size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}

template <typename T>
void iter(T const* array, std::size_t len, void (*func)(T const &)) {  
    if (!array|| !func) {
        std::cerr << "Error: NULL pointer passed to iter()" << std::endl;
        return ;
    }
    for (std::size_t i = 0; i < len; i++) {
        func(array[i]);
    }
}

#endif
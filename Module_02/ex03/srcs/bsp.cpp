/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:08:37 by algultse          #+#    #+#             */
/*   Updated: 2024/12/03 23:09:13 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	calculateArea(Point const &a, Point const &b, Point const &c)
{
	float	rawArea;
	
	rawArea = 
		a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
		+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
		+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat());
	return (
		Fixed(std::abs(rawArea) / 2.0f)
	);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea;
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;

	totalArea = calculateArea(a, b, c).toFloat();
	area1 = calculateArea(point, b, c).toFloat();
	area2 = calculateArea(a, point, c).toFloat();
	area3 = calculateArea(a, b, point).toFloat();
	return (
		totalArea == (area1 + area2 + area3)
		&& area1 != 0 && area2 != 0 && area3 != 0
		);
}

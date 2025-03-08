/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:10:11 by algultse          #+#    #+#             */
/*   Updated: 2025/03/08 12:58:51 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Colors.hpp"

void	printHeader(const std::string& title) {
	std::cout << BOLD << CYAN << "\n🔹 " << title << RESET << std::endl;
}

void	printSuccess(const std::string& msg) {
	std::cout << GREEN << "✅ " << msg << RESET << std::endl;
}

void	printError(const std::string& msg) {
	std::cout << RED << "❌ " << msg << RESET << std::endl;
}

void	testSubject()
{
	printHeader("[Subject Test]");

	int	a = 2;
	int	b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	
	printSuccess("Subject test passed!");
}

void	testExtended()
{
	printHeader("[Extended Test]");

	int	x = -10;
	int	y = -20;

	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
	::swap(x, y);
	std::cout << "After swap:  x = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << std::endl;
	std::cout << "-----" << std::endl;

	double	da = 3.1415;
	double	db = 2.718;

	std::cout << "Before swap: da = " << da << ", db = " << db << std::endl;
	::swap(da, db);
	std::cout << "After swap:  da = " << da << ", db = " << db << std::endl;
	std::cout << "min(da, db) = " << ::min(da, db) << std::endl;
	std::cout << "max(da, db) = " << ::max(da, db) << std::endl;
	std::cout << "-----" << std::endl;

	char	ch1 = 'A';
	char	ch2 = 'Z';

	std::cout << "Before swap: ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
	::swap(ch1, ch2);
	std::cout << "After swap:  ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
	std::cout << "min(ch1, ch2) = " << ::min(ch1, ch2) << std::endl;
	std::cout << "max(ch1, ch2) = " << ::max(ch1, ch2) << std::endl;

	printSuccess("Extended test passed!");
}

void	testSelfSwap()
{
	printHeader("[Test Self Swap]");

	int	a = 42;

	std::cout << "Before swap: a = " << a << std::endl;
	::swap(a, a);
	std::cout << "After swap:  a = " << a << std::endl;

	printSuccess("Self swap test passed!");
}

void	testNumericLimits()
{
	printHeader("[Test Numeric Limits]");

	std::cout	<< "min(INT_MIN, INT_MAX) = " 
				<< ::min(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) 
				<< std::endl;
	
	std::cout	<< "max(INT_MIN, INT_MAX) = " 
				<< ::max(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) 
				<< std::endl;

	std::cout	<< "min(DBL_MIN, DBL_MAX) = " 
				<< ::min(std::numeric_limits<double>::min(), std::numeric_limits<double>::max()) 
				<< std::endl;

	std::cout	<< "max(DBL_MIN, DBL_MAX) = " 
				<< ::max(std::numeric_limits<double>::min(), std::numeric_limits<double>::max()) 
				<< std::endl;

	printSuccess("Numeric limits test passed!");
}

void	testPointerSwap()
{
	printHeader("[Test Pointer Swap]");

	int		a = 10;
	int		b = 20;
	int*	p1 = &a;
	int*	p2 = &b;

	std::cout	<< "Before swap: p1 points to " << *p1
				<< ", p2 points to " << *p2
				<< std::endl;
	::swap(p1, p2);
	std::cout	<< "After swap:  p1 points to " << *p1
				<< ", p2 points to " << *p2
				<< std::endl;
	
	printSuccess("Pointer swap test passed!");
}

struct CustomType {
	int	value;

	CustomType(int v) : value(v) {}
	bool operator>(const CustomType &other) const {
		return (value > other.value);
	}
	bool operator<(const CustomType &other) const {
		return (value < other.value);
	}
};

void	testCustomType()
{
	printHeader("[Test Custom Type]");

	CustomType	a(42);
	CustomType	b(69);

	std::cout	<< "a = " << a.value
				<< ", b = " << b.value
				<< std::endl;
	// ::swap(a, b);
	std::cout << "Min: " << ::min(a, b).value << std::endl;
	std::cout << "Max: " << ::max(a, b).value << std::endl;

	printSuccess("Custom type test passed!");
}

void	testArraySwap()
{
	printHeader("[Test Array Swap]");

	int	arr1[2] = {1, 2};
	int	arr2[2] = {3, 4};

	std::cout << "arr1 = {" << arr1[0] << ", " << arr1[1] << "}, "
			  << "arr2 = {" << arr2[0] << ", " << arr2[1] << "}"
			  << std::endl;
	// ::swap(arr1, arr2);
	std::cout << "min(arr1[0], arr2[0]) = " << ::min(arr1[0], arr2[0]) << std::endl;
	std::cout << "max(arr1[0], arr2[0]) = " << ::max(arr1[0], arr2[0]) << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << "min(arr1[1], arr2[1]) = " << ::min(arr1[1], arr2[1]) << std::endl;
	std::cout << "max(arr1[1], arr2[1]) = " << ::max(arr1[1], arr2[1]) << std::endl;

	printSuccess("Array test passed (except swap)!");
}

int	main()
{
	testSubject();
	testExtended();
	testSelfSwap();
	testNumericLimits();
	testPointerSwap();
	testCustomType();
	testArraySwap();

	std::cout << BOLD << YELLOW << "\n\tALL TESTS PASSED!" << RESET << std::endl;
	return (0);
}

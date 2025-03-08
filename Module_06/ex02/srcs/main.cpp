/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:57:01 by algultse          #+#    #+#             */
/*   Updated: 2025/03/08 21:42:20 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int i = std::rand() % 3;
	switch (i) {
		case 0:
			std::cout << GREEN "Generated: A" RESET << std::endl; 
			return new A();
		case 1:
			std::cout << BLUE "Generated: B" RESET << std::endl;
			return new B();
		default:
			std::cout << PURPLE "Generated: C" RESET << std::endl;
			return new C();
	}
}

void	identify(Base* p)
{
	std::cout << "Identified (Pointer): ";
	if (!p) {
		std::cout << RED "NULL Pointer" RESET << std::endl; 
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << GREEN "A" RESET;
	else if (dynamic_cast<B*>(p))
		std::cout << BLUE "B" RESET;
	else if (dynamic_cast<C*>(p))
		std::cout << PURPLE "C" RESET;
	else
		std::cout << RED "Unknown Type" RESET;
	std::cout << std::endl;
}

void	identify(Base& p)
{
	std::cout << "Identified (Reference): ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << GREEN "A" RESET << std::endl;
		return ;
	} catch (const std::bad_cast& e) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << BLUE "B" RESET << std::endl;
		return ;
	} catch (const std::bad_cast& e) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << PURPLE "C" RESET << std::endl;
		return ;
	} catch (const std::bad_cast& e) {}

	std::cout << RED "Unknown Type" RESET << std::endl;
}

void	run_tests()
{
	std::cout << BOLD CYAN "\n===== Test 1: Single test =====" RESET << std::endl;
	Base* obj = generate();
	std::cout << CYAN << "Object at the address: " << RESET << obj << std::endl;
	identify(obj);
	identify(*obj);
	delete obj;

	std::cout << BOLD CYAN "\n===== Test 2: Multiple generation =====" RESET << std::endl;
	for (int i = 0; i < 5; ++i) {
		Base* temp = generate();
		identify(temp);
		identify(*temp);
		delete temp;
	}

	std::cout << BOLD CYAN "\n===== Test 3: NULL pointer =====" RESET << std::endl;
	Base* nullPtr = NULL;
	identify(nullPtr);

	std::cout << BOLD CYAN "\n===== Test 4: Base class object (incorrect) =====" RESET << std::endl;
	Base baseObj;
	identify(&baseObj);
	identify(baseObj);
}

int	main()
{
	std::srand(std::time(NULL));
	run_tests();
	return (0);
}

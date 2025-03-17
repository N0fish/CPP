
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:22:10 by algultse          #+#    #+#             */
/*   Updated: 2025/03/12 01:13:27 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

struct CustomStruct {
	int		a;
	char	b;
};

void	printHeader(const std::string &title) {
	std::cout << CYAN "\n🔹 " << title << RESET << std::endl;
}

void	printSuccess(const std::string &msg) {
	std::cout << GREEN "✔️ " << msg << RESET << std::endl;
}

void	printError(const std::string &msg) {
	std::cerr << RED "✖️ " << msg << RESET << std::endl;
}

void	testConstructors() {
	printHeader("[Test Constructors]");
	
	Array<int> emptyArray;
	if (emptyArray.size() == 0)
		printSuccess("Empty array created successfully.");
	else
		printError("Empty array has non-zero size.");
	
	Array<int> intArray(5);
	if (intArray.size() == 5)
		printSuccess("Array of size 5 created successfully.");
	else
		printError("Array size is incorrect.");
}

void	testCopyAssignment() {
	printHeader("[Test Copy and Assignment]");
	
	Array<int> original(5);
	for (unsigned int i = 0; i < original.size(); i++)
		original[i] = i * 10;
	
	Array<int> copy(original);
	copy[0] = 999;
	if (original[0] != 999)
		printSuccess("Copy is independent of the original.");
	else
		printError("Copy modifies the original!");
	
	Array<int> assigned;
	assigned = original;
	if (assigned.size() == original.size())
		printSuccess("Assignment operator works correctly.");
	else
		printError("Assignment operator failed.");
}

void	testTypes() {
	printHeader("[Test Different Types]");
	
	Array<double> doubleArray(4);
	doubleArray[0] = 3.14;
	doubleArray[1] = 2.71;
	doubleArray[2] = 1.41;
	doubleArray[3] = 0.577;
	printSuccess("Double array created and assigned values.");
	
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	printSuccess("String array created and assigned values.");

	printHeader("[Test: Const Array]");
	try {
		const Array<int> constArray(3);
		std::cout << "Size of const array: " << constArray.size() << std::endl;
		std::cout << "Accessing const array[1]: " << constArray[1] << std::endl;
		printSuccess("Const array access worked correctly.");
	} catch (const std::exception &e) {
		printError(std::string("Exception caught: ") + e.what());
	}
}

void	testCustomStruct() {
	printHeader("[Test Custom Struct]");
	
    Array<CustomStruct> structArray(3);
    structArray[0].a = 1; structArray[0].b = 'a';
    structArray[1].a = 2; structArray[1].b = 'b';
    structArray[2].a = 3; structArray[2].b = 'c';
	
	for (unsigned int i = 0; i < structArray.size(); i++) {
		std::cout << structArray[i].a << " ";
		std::cout << structArray[i].b << " ";
		std::cout << std::endl;
	}
	if (structArray.size() == 3)
		printSuccess("Struct array created and assigned values.");
	else
		printError("Struct array failed to assign values.");
}

void	testIntArray() {
	printHeader("[Test: Integer Array]");
	Array<int> arr(5);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;
	
	std::cout << "Integer array: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	printSuccess("Integer array test passed!");
}

void	testDoubleArray() {
	printHeader("[Test: Double Array]");
	Array<double> arr(4);
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 1.5;
	
	std::cout << "Double array: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	printSuccess("Double array test passed!");
}

void	testStringArray() {
	printHeader("[Test: String Array]");
	Array<std::string> arr(3);
	arr[0] = "Hello";
	arr[1] = "World";
	arr[2] = "!";
	
	std::cout << "String array: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	printSuccess("String array test passed!");
}

void	testCustomStructArray() {
	printHeader("[Test: Custom Struct Array]");
	Array<CustomStruct> arr(3);
	arr[0].a = 1; arr[0].b = 'a';
	arr[1].a = 2; arr[1].b = 'b';
	arr[2].a = 3; arr[2].b = 'c';
	
	std::cout << "Struct array: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "(" << arr[i].a << ", " << arr[i].b << ") ";
	std::cout << std::endl;
	printSuccess("Struct array test passed!");
}

void	testOutOfBounds() {
	printHeader("[Test Out of Bounds Access]");
	
	Array<int> testArray(5);
	try {
		testArray[10] = 42;
		printError("Out of bounds access did NOT throw an exception.");
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
		printSuccess("Out of bounds access correctly threw exception.");
	}
	
	try {
		std::cout << testArray[-1] << std::endl;
		printError("Negative index did NOT throw an exception.");
	} catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
		printSuccess("Negative index correctly threw exception.");
	}
}

int	main()
{
	testConstructors();
	testCopyAssignment();
	testTypes();
	testCustomStruct();
	
	testIntArray();
	testDoubleArray();
	testStringArray();
	testCustomStructArray();
	testOutOfBounds();
	
	std::cout << YELLOW "\n\tALL TESTS COMPLETED!" << RESET << std::endl;
	return (0);
}

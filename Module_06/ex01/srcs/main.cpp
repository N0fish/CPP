/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algultse <algultse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:31:54 by algultse          #+#    #+#             */
/*   Updated: 2025/03/18 13:59:42 by algultse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

void	printData(const std::string& msg, Data* data)
{
	if (!data) {
		std::cout << RED << "✖️ " << msg << ": NULL pointer" << RESET << std::endl;
		return ;
	}
	std::cout << GREEN << "✔️ " << msg << RESET << std::endl;
	std::cout << "  📌 Address: " << data << std::endl;
	std::cout << "  🆔 ID: " << data->id << std::endl;
	std::cout << "  📝 Name: " << data->name << std::endl;
	std::cout << "  💰 Balance: " << data->balance << std::endl;
}

void	testBasicSerialization()
{
	std::cout << BOLD << CYAN << "\n[TEST 1] Basic Serialization\n" << RESET;
	
	Data	original(42, "algultse", 100.50f);
	printData("Original Data", &original);

	uintptr_t	raw = Serializer::serialize(&original);
	Data*		restored = Serializer::deserialize(raw);
	printData("Restored Data", restored);

	assert(restored == &original);
	std::cout << GREEN << "✔️ Test Passed: Pointers match!" << RESET << "\n\n";
}

void	testNullptr()
{
	std::cout << BOLD << CYAN << "[TEST 2] Null Pointer Handling\n" << RESET;
	
	Data*		nullData = NULL;
	uintptr_t	raw = Serializer::serialize(nullData);
	Data*		restored = Serializer::deserialize(raw);

	assert(restored == NULL);
	std::cout << GREEN << "✔️ Test Passed: Null pointer correctly handled!\n\n" << RESET;
}

void	testDynamicMemory()
{
	std::cout << BOLD << CYAN << "[TEST 3] Dynamic Memory\n" << RESET;
	
	Data*	heapData = new Data(99, "Student", 250.75f);
	printData("Heap Data (Before)", heapData);

	uintptr_t	raw = Serializer::serialize(heapData);
	Data*		restored = Serializer::deserialize(raw);
	printData("Heap Data (After)", restored);

	assert(restored == heapData);
	delete heapData;
	std::cout << GREEN << "✔️ Test Passed: Heap pointer restored correctly!\n\n" << RESET;
}

void	testArraySerialization()
{
	std::cout << BOLD << CYAN << "[TEST 4] Array Serialization\n" << RESET;
	
	Data	dataArray[3] = {
		Data(1, "Intern", 50.0f),
		Data(2, "Manager", 75.5f),
		Data(3, "Director", 200.25f)
	};

	for (int i = 0; i < 3; ++i) {
		uintptr_t raw = Serializer::serialize(&dataArray[i]);
		Data* restored = Serializer::deserialize(raw);

		std::ostringstream oss;
		oss << (i + 1);
		printData("Restored Data #" + oss.str(), restored);
		assert(restored == &dataArray[i]);
	}

	std::cout << GREEN << "✔️ Test Passed: Array elements restored correctly!\n\n" << RESET;
}

void	testInvalidData()
{
	std::cout << BOLD << CYAN << "[TEST 5] Invalid Data\n" << RESET;
	
	uintptr_t	invalidRaw = 0xDEADBEEF;  // magic number
	Data*		restored = Serializer::deserialize(invalidRaw);

	if (restored) {
		std::cout << RED << "✖️ Warning: Deserialization of invalid data returned non-null pointer!"
				  << RESET << std::endl;
	} else {
		std::cout << GREEN << "✔️ Test Passed: Invalid data correctly handled!" << RESET << std::endl;
	}

	std::cout << std::endl;
}

void	testNegativeValues()
{
	std::cout << BOLD << CYAN << "[TEST 6] Negative Values in Data" << RESET << std::endl;

	Data	negativeData(-42, "Negative data", -99.99f);
	printData("Negative Data", &negativeData);

	uintptr_t	raw = Serializer::serialize(&negativeData);
	Data*		restored = Serializer::deserialize(raw);
	printData("Restored Negative Data", restored);

	assert(restored == &negativeData);
	std::cout << GREEN << "✔️ Test Passed: Negative values handled correctly!\n" << RESET << std::endl;
}

int	main()
{
	testBasicSerialization();
	testNullptr();
	testDynamicMemory();
	testArraySerialization();
	testInvalidData();
	testNegativeValues();

	std::cout << BOLD << YELLOW << "\n\tALL TESTS PASSED !\n" << RESET;
	return (0);
}

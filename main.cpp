// main.cpp

#include <stdio.h>
#include <iostream>
#include "GenericArray.h"

template <typename T>
void printSlice(T* array, int size);

int main() {
	GenericArray<int> int_array;	
	int_array.addElement(10);
	
	std::cout << "size of array is " << int_array.size() << std::endl;
	std::cout << "Adding elements..." << std::endl;
	
	int_array.addElement(5431);
	int_array.addElement(-5432);
	int_array.addElement(43);
	int_array.addElement(8);
	int_array.addElement(432);
	int_array.addElement(726);
	int_array.addElement(54);	
	int_array.addElement(32);
	int_array.addElement(1);
	int_array.addElement(9);
	int_array.addElement(0);
	int_array.addElement(5);
	int_array.addElement(4);
	
	std::cout << std::endl;
	int_array.printArray();
	std::cout << std::endl;
	
	std::cout << "size of array is " << int_array.size() << std::endl;
	std::cout << "sum of the array is " << int_array.sum() << std::endl;
	std::cout << "maximum and minimum of array: " << int_array.max() << ", " << int_array.min() << std::endl;
	std::cout << "Find index 7: " << int_array.at(7) << std::endl;
	std::cout << std::endl;
	
	std::cout << "Creating slice..." << std::endl;
	int *sliced_array = int_array.slice(5,10);
	// print sliced_array...
	printSlice(sliced_array, 10-5 + 1);
	std::cout << std::endl;
	
	return 0;
}

template <typename T>
void printSlice(T* array, int size) {	
	printf("PRINTING SLICED ARRAY:\n<");
	for(int i=0; i<size-1; i++) {
		std::cout << array[i] << ", ";		
	}
	std::cout << array[size-1] << ">" << std::endl;
}


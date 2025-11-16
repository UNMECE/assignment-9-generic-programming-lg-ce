// GenericArray.h

#include <iostream>

template <typename T>

class GenericArray {
	private:
		T* array;
		int arraysize;
		
	public:	
		// default constructor
		GenericArray() {
			arraysize = 1;
			array = new T[arraysize]; // allocates memory
		}
		
		// parametrized constructor
		GenericArray(int size) {
			arraysize = size; // ????
			array = new T[arraysize]; // allocates memory
		}
		
		// deconstructor
		~GenericArray() { 
			std::cout << "Deleting array... " << std::endl;
			delete[] array;			
		}
		
		// increase array by one and add an element to it
		void addElement(T element) { // add type T "element" to array... generic datatype placeholder T		
			arraysize += 1;  // increase size of object's array by 1
			T *tempArray = new T[arraysize];			
			for(int i=0; i<arraysize -1; i++) { //copy everything to new array
				tempArray[i] = array[i];
			}
			tempArray[arraysize-1] = element; // add the new element to tempArray
			
			delete[] array; // free memory that previously held array values
			array = tempArray; // assign pointer array equal to pointer tempArray			
		}
		
		// implement a function called .at(int param) that returns the value in the array at the location param.
		int at(int index) const {
			if(index >= arraysize) { // error handling for requested index exceeding array length				
				throw std::out_of_range("Error: selected index must be less than ");
				std::cout << arraysize << std::endl;
			}
			return array[index];			
		}
		
		
		// .size() function that returns the size of the array (a "getter")
		int size() {			
			return arraysize;
		}
		
		
		// implement a .sum() function that returns the sum of the entire array.
		int sum() const {			
			int theSum = 0;
			for(int i = 0; i<arraysize; i++) {
				theSum += array[i];
			}
			return theSum;
		}
		
		// implement a .max() and .min() function that finds the maximum and minimum of the entire array.
		double max() const {
			double maximum = 0.0;
			for(int i = 0; i<arraysize; i++) {
				if(maximum < array[i]) {
					maximum = array[i];
				}
			}
			return maximum;
		}
		
		double min() const {
			double minimum = array[0];
			for(int i = 1; i<arraysize; i++) { // since it starts out comparing against array[0], no need to include in loop
				if(minimum > array[i]) {
					minimum = array[i];
				}
			}
			return minimum;
		}
		
		/* Create a .slice(int begin, int end) function that returns a slice of 
		the array between and including elements begin to end. For example, if 
		the array is [0,2,4,6,8] and the function is called as .slice(2,4) it 
		returns the array [2,4,8] as a new array pointer - it is not a pointer 
		to the underlying data but a new array. Check the bounds of the slice.*/
		T *slice(int begin, int end) {
			int new_size = end-begin + 1;
			
			T *the_slice = new T[new_size];
			
			if(begin < 0 || end > arraysize){
				throw std::out_of_range("ERROR:  Requested index range is out of bounds.");
			}
			
			for(int i = 0; i < new_size; i++) {
				the_slice[i] = array[i + begin]; // starting at slice's starting index where slice begins, assign slice values equal to "array"
			}
			
			return the_slice;
		}
		
		void printArray() {	
			printf("PRINTING ARRAY:\n<");
			for(int i=0; i<arraysize-1; i++) {
				std::cout << array[i] << ", ";		
			}
			std::cout << array[arraysize-1] << ">" << std::endl;
		}
};


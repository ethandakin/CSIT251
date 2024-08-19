#include <iostream>

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Declare swap function
void swap(int *ptr1, int *ptr2); 

int main() {
    // Declare array with size of 4
    int array[5];

    // Get values for array (does not check input)
    for (int i = 0; i < 5; i++) {
        // Print i + 1
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin>>array[i];
    }

    // Swap array 3 and 4
    swap(&array[3], &array[4]);
    
    // Print array values
    for (int i = 0; i < 5; i++) {
        std::cout<<array[i];
        
    }

    // Print empty
    std::cout << std::endl;

    // Terminate function
    return 0;
}

void swap(int *ptr1, int *ptr2) {
    // Declare temp variable as deferenced ptr1
    int temp = *ptr1;
    // Set value of dereferenced ptr1 to dereferenced ptr2
    *ptr1 = *ptr2;
    // Set value of dereferenced ptr1 to temp
    *ptr2 = temp;
}
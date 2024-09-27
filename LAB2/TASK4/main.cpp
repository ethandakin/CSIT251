#include <iostream>
// Needed for 2 decimal place printing
#include <iomanip>

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Multiplies two matrices M1 and M2, with dimensions specified.
void multiplyMatrices(float M1[][10], float M2[][10], int M1_rows, int M1_cols, int M2_rows, int M2_cols);

int main() {
    // Create matrices array
    float matrices[2][10][10];
    int values[4];
    // M1_rows = values[0]
    // M1_columns = values[1]
    // M2_rows = values[2]
    // M2_columns = values[3]

    // Get the dimensions for the matrix
    for (int i = 0; i < 4; i++) {
        int passed = false;

        while (!passed) {
            std::cout << "Please enter matrix " << (i / 2) + 1;    

            if (i % 2 == 0) {
                std::cout << " rows: ";
            } else {
                std::cout << " columns: ";
            }
            
            std::cin >> values[i];

            if (values[i] < 0 || values[i] > 10) {
                std::cout << "Invalid Matrix Dimensions" << std::endl;
            } else {
                passed = true;
            }
        }
    }

    // If matrix 1 columns != matrix 2 rows, then it is not multiplicable
    if (values[1] != values[2]) {
        std::cout << "Invalid Matrix Dimensions" << std::endl;
        return - 1;
    }

    // For each matrix
    for (int m = 0; m < 2; m++) {
        // For each row (values[m * 2])
        for (int i = 0; i < values[m * 2]; i++) {
            // For each column
            for (int j = 0; j < values[(m * 2 )+ 1]; j++) {
                // Get user input for matrix
                // Please note, matrices start indexing from 1, so I appropriately print that
                std::cout << "Enter matrix " << m + 1 << " [" << i + 1 << "][" << j + 1 << "]: ";
                std::cin >> matrices[m][i][j];
            }
        }
    }

    // Multiply matricies
    multiplyMatrices(matrices[0], matrices[1], values[0], values[1], values[2], values[3]);

    // Terminate program
    return 0;
}

void multiplyMatrices(float M1[][10], float M2[][10], int M1_rows, int M1_cols, int M2_rows, int M2_cols) {
    // Check if input is valid
    if (M1_cols != M2_rows) {
        std::cout << "Invalid Matrix Dimensions" << std::endl;
        return;
    }

    // Create M3
    float M3[M1_rows][M2_cols];

    // For each row in M1
    for (int i = 0; i < M1_rows; ++i) {
        // For each column in M2
        for (int j = 0; j < M2_cols; ++j) {
            // Assign a variable to M3[i][j]
            M3[i][j] = 0;

            // Add value to M3[i][j]
            for (int k = 0; k < M1_cols; ++k) {
                M3[i][j] += M1[i][k] * M2[k][j];
            }
            
            // Set the cout to fixed with 2 precision
            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            // Print value
            std::cout << M3[i][j] << " ";
        }
        // Print new line
        std::cout << std::endl;
    }
}

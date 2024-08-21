#include <iostream>
// Needed for 2 decimal place printing
#include <iomanip>

/*
Name: Ethan Dakin
Student Number: 8209194
*/

void multiplyMatrices(float M1[][10], float M2[][10], int M1_rows, int M1_cols, int M2_rows, int M2_cols);
void get_input(int &var, std::string msg);

int main() {
    // Create example input
    
    float matrices[2][10][10];
    int values[4];
    // M1_rows = values[0]
    // M1_columns = values[1]
    // M2_rows = values[2]
    // M2_columns = values[3]

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

    if (values[1] != values[2]) {
        std::cout << "Invalid Matrix Dimensions" << std::endl;
        return - 1;
    }

    for (int m = 0; m < 2; m++) {
        for (int i = 0; i < values[m * 2]; i++) {
            for (int j = 0; j < values[(m * 2 )+ 1]; j++) {
                std::cout << "Enter matrix" << m + 1 << "[" << i << "][" << j << "]: ";
                std::cin >> matrices[m][i][j];
            }
        }
    }

    multiplyMatrices(matrices[0], matrices[1], values[0], values[1], values[2], values[3]);

    return 0;
}

void multiplyMatrices(float M1[][10], float M2[][10], int M1_rows, int M1_cols, int M2_rows, int M2_cols) {
    // Check if input is valid
    if (M1_cols != M2_rows) {
        std::cout << "Invalid Matrix Dimensions" << std::endl;
        return;
    }

    float M3[M1_rows][M2_cols];

    for (int i = 0; i < M1_rows; ++i) {
        for (int j = 0; j < M2_cols; ++j) {
            M3[i][j] = 0;

            for (int k = 0; k < M1_cols; ++k) {
                M3[i][j] += M1[i][k] * M2[k][j];
            }
            
            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            std::cout << M3[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// function that recursively gets input
void get_input(int &var, std::string msg) {
    std::cout << "Please enter matrix " << msg << ": ";
    std::cin >> var;

    if (var < 0 || var > 10) {
        std::cout << "Invalid Matrix Dimensions" << std::endl;
        get_input(var, msg);
    }
}
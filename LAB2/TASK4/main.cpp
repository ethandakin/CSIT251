#include <iostream>

void multiplyMatrices(float M1[][10], float M2[][10], int M1_rows, int M1_cols, int M2_rows, int M2_cols);

int main() {
    float M1[10][10] = {{0.1067, 0.7749}, {0.9619, 0.8173}, {0.0046, 0.8687}};
    float M2[10][10] = {{0.0844, 0.2599}, {0.3998, 0.8001}};
    multiplyMatrices(M1, M2, 3, 2, 2, 2);

    /*
        {0.1 0.7}
        {0.9 0.8}
        {0.4 0.8}

        {0.8 0.2}
        {0.3 0.8}

        (0.1, 0.7) * 

    */

    return 0;
}

void multiplyMatrices(float M1[][10], float M2[][10], int M1_rows, int M1_cols, int M2_rows, int M2_cols) {
    // check if input is valid

        float M3[M1_rows][M2_cols];

        for (int i = 0; i < M1_rows; i++) {
            for (int j = 0; j < M2_cols; j++) {
                M3[i][j] = 0;

                for (int k = 0; k < M2_rows; k++) {
                    M3[i][j] += M1[i][k] * M2[k][j];
                }

                std::cout << M3[i][j] << "\t";
            }

            std::cout << std::endl;
        }

    if (M1[M1_rows][M1_cols] && M2[M2_rows][M2_cols]) {

    } else {

    }
}
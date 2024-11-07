#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

// Начало блока extern "C"
extern "C"
{
    void fillMatrix(int matrix[][7], int rows, int cols) {
        std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = std::rand() % 101 - 50; // Заполнение матрицы значениями от -50 до 50
            }
        }
    }

    int countMatrixMultiples(int matrix[][7], int rows, int cols) {
        int count = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] % 3 == 0 && matrix[i][j] % 5 != 0) {
                    count++;
                }
            }
        }
        return count;
    }
    void printMatrix(int matrix[][7], int rows, int cols) {
        int width = 5;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << std::setw(width) << matrix[i][j];
            }
            cout << endl;
        }
    }
}


 // Конец блока extern "C"


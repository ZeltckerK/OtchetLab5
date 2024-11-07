#include <iostream>
#include <cstdlib>
#include <ctime>
#include <dlfcn.h>


using namespace std;

// Определяем размеры
const int sizeA = 35;  // Размер массива A
const int rowsD = 5;   // Количество строк в матрице D
const int colsD = 7;   // Количество столбцов в матрице D


int main() {
    int choice;

    // Меню выбора
    cout << "Выберите, с чем работать:" << endl;
    cout << "1. Работа с массивом" << endl;
    cout << "2. Работа с матрицей" << endl;
    cout << "Введите ваш выбор (1 или 2): ";
    cin >> choice;

    if (choice == 1) {
        // Работа с массивом
        int A[sizeA];

        // Загрузка библиотеки для работы с массивом
        void* handle = dlopen("/Users/denisoshckukov/Documents/VOENMEH/CP3/CP3/libArrIO.dylib", RTLD_LAZY);
        if (!handle) {
            cerr << "Не удалось загрузить библиотеку libArrIO.dylib: " << dlerror() << endl;
            return 1;
        }

        // Загрузка функций
        void (*fillArray)(int[], int) = (void (*)(int[], int))dlsym(handle, "fillArray");
        void (*printArray)(int [], int) = (void (*)(int[], int))dlsym(handle, "printArray");
        int (*countMultiples)(int[], int) = (int (*)(int[], int))dlsym(handle, "countMultiples");

        // Проверка загрузки функций
        if (!fillArray || !countMultiples) {
            cerr << "Не удалось загрузить функции из библиотеки: " << dlerror() << endl;
            dlclose(handle);
            return 1;
        }

        // Заполнение массива
        fillArray(A, sizeA);
        
        printArray(A, sizeA);

        // Подсчет элементов, кратных 3 и не кратных 5
        int countA = countMultiples(A, sizeA);
        
        cout << "Количество элементов, кратных 3 и не кратных 5 в массиве A: " << countA << endl;

        // Закрытие библиотеки
        dlclose(handle);

    } else if (choice == 2) {
        // Работа с матрицей
        int D[rowsD][colsD];

        // Загрузка библиотеки для работы с матрицей
        void* handle = dlopen("/Users/denisoshckukov/Documents/VOENMEH/CP3/CP3/libMatIO.dylib", RTLD_LAZY);
        if (!handle) {
            cerr << "Не удалось загрузить библиотеку libMatIO.dylib: " << dlerror() << endl;
            return 1;
        }

        // Загрузка функций
        void (*fillMatrix)(int[][7], int, int) = (void (*)(int[][7], int, int))dlsym(handle, "fillMatrix");
        void (*printMatrix)(int [][7], int, int) = (void (*)(int[][7], int, int))dlsym(handle, "printMatrix");
        int (*countMatrixMultiples)(int[][7], int, int) = (int (*)(int[][7], int, int))dlsym(handle, "countMatrixMultiples");

        // Проверка загрузки функций
        if (!fillMatrix || !countMatrixMultiples) {
            cerr << "Не удалось загрузить функции из библиотеки: " << dlerror() << endl;
            dlclose(handle);
            return 1;
        }

        // Заполнение матрицы
        fillMatrix(D, rowsD, colsD);
        
        printMatrix(D, rowsD, colsD);

        // Подсчет элементов, кратных 3 и не кратных 5
        int countD = countMatrixMultiples(D, rowsD, colsD);
        
        cout << "Количество элементов, кратных 3 и не кратных 5 в матрице D: " << countD << endl;

        // Закрытие библиотеки
        dlclose(handle);

    } else {
        cout << "Неверный выбор." << endl;
    }

    return 0;
}



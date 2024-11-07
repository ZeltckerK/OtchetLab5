#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
// Начало блока extern "C"
extern "C"
{
    void fillArray(int arr[], int size) {
        std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел
        for (int i = 0; i < size; ++i) {
            arr[i] = std::rand() % 101 - 50; // Заполнение массива значениями от -50 до 50
        }
    }

    int countMultiples(int arr[], int size) {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] % 3 == 0 && arr[i] % 5 != 0) {
                count++;
            }
        }
        return count;
    }

    void printArray(int arr[], int size) {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
 // Конец блока extern "C"


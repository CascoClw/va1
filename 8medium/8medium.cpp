#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int maximumSwap(int num) {
    // Преобразуем число в строку для удобства работы с цифрами
    string numStr = to_string(num);
    int n = numStr.size();

    // Создаем массив для хранения индексов последнего вхождения каждой цифры
    int last[10] = { 0 };
    for (int i = 0; i < n; ++i) {
        last[numStr[i] - '0'] = i;
    }

    // Проходим по каждой цифре и ищем возможность сделать обмен
    for (int i = 0; i < n; ++i) {
        // Проверяем цифры от 9 до (текущая цифра + 1)
        for (int d = 9; d > numStr[i] - '0'; --d) {
            // Если нашли большую цифру, которая идет после текущей цифры
            if (last[d] > i) {
                // Меняем их местами
                swap(numStr[i], numStr[last[d]]);
                // Преобразуем строку обратно в число и возвращаем результат
                return stoi(numStr);
            }
        }
    }

    // Если обменов не было, возвращаем исходное число
    return num;
}

int main() {
    // Примеры из задания
    int num1 = 2736;
    cout << "Input: " << num1 << ", Output: " << maximumSwap(num1) << endl; // Ожидаемый вывод: 7236

    int num2 = 9973;
    cout << "Input: " << num2 << ", Output: " << maximumSwap(num2) << endl; // Ожидаемый вывод: 9973

    return 0;
}

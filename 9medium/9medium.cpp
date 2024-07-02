#include <iostream>

using namespace std;

int brokenCalc(int startValue, int target) {
    int operations = 0; // Счетчик операций

    // Пока target больше startValue
    while (target > startValue) {
        if (target % 2 == 0) {
            target /= 2; // Если target четный, делим его на 2
        }
        else {
            target += 1; // Если target нечетный, увеличиваем его на 1
        }
        operations++; // Увеличиваем счетчик операций
    }

    // Оставшиеся шаги, если target стал меньше startValue
    operations += (startValue - target);

    return operations; // Возвращаем общее количество операций
}

int main() {
    // Примеры из задания
    int startValue1 = 2, target1 = 3;
    cout << "Input: " << startValue1 << ", " << target1 << " Output: " << brokenCalc(startValue1, target1) << endl; // Ожидаемый вывод: 2

    int startValue2 = 5, target2 = 8;
    cout << "Input: " << startValue2 << ", " << target2 << " Output: " << brokenCalc(startValue2, target2) << endl; // Ожидаемый вывод: 2

    int startValue3 = 3, target3 = 10;
    cout << "Input: " << startValue3 << ", " << target3 << " Output: " << brokenCalc(startValue3, target3) << endl; // Ожидаемый вывод: 3

    return 0;
}

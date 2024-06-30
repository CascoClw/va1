#include <iostream>
#include <string>

using namespace std;

string largestOddNumber(string num) {
    // Проходим строку с конца, чтобы найти первую нечетную цифру
    for (int i = num.size() - 1; i >= 0; --i) {
        // Проверяем, является ли текущая цифра нечетной
        if ((num[i] - '0') % 2 != 0) {
            // Возвращаем подстроку от начала до текущей позиции включительно
            return num.substr(0, i + 1);
        }
    }
    // Если не найдено нечетных цифр, возвращаем пустую строку
    return "";
}

int main() {
    // Примеры из задания
    string num1 = "52";
    cout << "Input: " << num1 << ", Output: " << largestOddNumber(num1) << endl; // Ожидаемый вывод: "5"

    string num2 = "4206";
    cout << "Input: " << num2 << ", Output: " << largestOddNumber(num2) << endl; // Ожидаемый вывод: ""

    string num3 = "35427";
    cout << "Input: " << num3 << ", Output: " << largestOddNumber(num3) << endl; // Ожидаемый вывод: "35427"

    return 0;
}

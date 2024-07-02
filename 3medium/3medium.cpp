#include <iostream>
#include <string>

using namespace std;

int monotoneIncreasingDigits(int N) {
    // Преобразуем число в строку для удобства работы с отдельными цифрами
    string num = to_string(N);
    int n = num.size();

    // Найдем позицию, где цифры перестают быть монотонно увеличивающимися
    int mark = n;
    for (int i = n - 1; i > 0; --i) {
        if (num[i] < num[i - 1]) {
            mark = i;
            num[i - 1]--;
        }
    }

    // Все цифры справа от отмеченной позиции заменяем на 9
    for (int i = mark; i < n; ++i) {
        num[i] = '9';
    }

    // Преобразуем строку обратно в число и возвращаем результат
    return stoi(num);
}

int main() {
    // Примеры из задания
    int n1 = 10;
    cout << "Input: " << n1 << endl;
    cout << "Output: " << monotoneIncreasingDigits(n1) << endl; // Ожидаемый вывод: 9

    int n2 = 1234;
    cout << "Input: " << n2 << endl;
    cout << "Output: " << monotoneIncreasingDigits(n2) << endl; // Ожидаемый вывод: 1234

    int n3 = 332;
    cout << "Input: " << n3 << endl;
    cout << "Output: " << monotoneIncreasingDigits(n3) << endl; // Ожидаемый вывод: 299

    return 0;
}

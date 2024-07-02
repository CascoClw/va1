#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция для подсчета максимального целого числа m, чтобы str2, повторенная m раз, могла быть получена из str1, повторенной n1 раз
int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int len1 = s1.length(), len2 = s2.length();
    vector<int> repeatCount(len2 + 1, 0);
    vector<int> nextIndex(len2 + 1, 0);

    int j = 0, count = 0;

    // Заполняем таблицы nextIndex и repeatCount для первой строки s1
    for (int k = 1; k <= n1; ++k) {
        for (int i = 0; i < len1; ++i) {
            if (s1[i] == s2[j]) {
                j++;
                if (j == len2) {
                    j = 0;
                    count++;
                }
            }
        }
        repeatCount[k] = count;
        nextIndex[k] = j;

        // Если обнаружили цикл
        for (int start = 0; start < k; ++start) {
            if (nextIndex[start] == j) {
                int prefixCount = repeatCount[start];
                int patternCount = (repeatCount[k] - repeatCount[start]) * (n1 - start) / (k - start);
                int suffixCount = repeatCount[start + (n1 - start) % (k - start)] - repeatCount[start];
                return (prefixCount + patternCount + suffixCount) / n2;
            }
        }
    }

    return repeatCount[n1] / n2;
}

int main() {
    // Примеры из задания
    string s1 = "acb";
    int n1 = 4;
    string s2 = "ab";
    int n2 = 2;

    int result = getMaxRepetitions(s1, n1, s2, n2);
    cout << "Output: " << result << endl; // Ожидаемый вывод: 2

    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int findTheLongestSubstring(string s) {
    // Словарь для хранения первого вхождения каждой битовой маски
    unordered_map<int, int> first_occurrence;
    first_occurrence[0] = -1; // Начальное состояние

    int mask = 0; // Битовая маска для отслеживания четности/нечетности гласных
    int max_length = 0; // Максимальная длина подстроки
    vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' }; // Гласные

    // Проходим по строке
    for (int i = 0; i < s.length(); ++i) {
        // Обновляем битовую маску в зависимости от текущего символа
        for (int j = 0; j < vowels.size(); ++j) {
            if (s[i] == vowels[j]) {
                mask ^= (1 << j);
                break;
            }
        }

        // Если такая битовая маска уже была, обновляем максимальную длину
        if (first_occurrence.find(mask) != first_occurrence.end()) {
            max_length = max(max_length, i - first_occurrence[mask]);
        }
        else {
            // Иначе сохраняем текущее вхождение битовой маски
            first_occurrence[mask] = i;
        }
    }

    return max_length;
}

int main() {
    // Примеры из задания
    string s1 = "eleetminicoworoep";
    cout << "Input: " << s1 << " Output: " << findTheLongestSubstring(s1) << endl; // Ожидаемый вывод: 13

    string s2 = "leetcodeisgreat";
    cout << "Input: " << s2 << " Output: " << findTheLongestSubstring(s2) << endl; // Ожидаемый вывод: 5

    string s3 = "bcbcbc";
    cout << "Input: " << s3 << " Output: " << findTheLongestSubstring(s3) << endl; // Ожидаемый вывод: 6

    return 0;
}

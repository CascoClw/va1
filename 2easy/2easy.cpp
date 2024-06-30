#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool canFormWord(const string& word, const unordered_map<char, int>& charsCount) {
    unordered_map<char, int> wordCount;
    // Подсчитываем количество каждой буквы в слове
    for (char c : word) {
        wordCount[c]++;
        // Если в слове больше символов, чем в доступных символах, возвращаем false
        if (wordCount[c] > charsCount.at(c)) {
            return false;
        }
    }
    return true;
}

int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> charsCount;
    // Подсчитываем количество каждой буквы в строке chars
    for (char c : chars) {
        charsCount[c]++;
    }

    int totalLength = 0;
    // Проверяем каждое слово в words
    for (const string& word : words) {
        bool canForm = true;
        unordered_map<char, int> wordCount;
        for (char c : word) {
            wordCount[c]++;
            if (wordCount[c] > charsCount[c]) {
                canForm = false;
                break;
            }
        }
        // Если слово можно сформировать, добавляем его длину к общему счетчику
        if (canForm) {
            totalLength += word.length();
        }
    }

    return totalLength;
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Примеры из задания
    vector<string> words1 = { "кош", "bt", "шляпа", "дерево" };
    string chars1 = "атач";
    cout << "Input: words = {\"кош\", \"bt\", \"шляпа\", \"дерево\"}, chars = \"атач\", Output: " << countCharacters(words1, chars1) << endl; // Ожидаемый вывод: 6

    vector<string> words2 = { "hello", "world", "leetcode" };
    string chars2 = "welldonehoneyr";
    cout << "Input: words = {\"hello\", \"world\", \"leetcode\"}, chars = \"welldonehoneyr\", Output: " << countCharacters(words2, chars2) << endl; // Ожидаемый вывод: 10

    return 0;
}

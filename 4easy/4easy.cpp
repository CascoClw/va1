#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Структура для хранения имени и роста человека
struct Person {
    string name;
    int height;
};

// Функция для сортировки людей по росту в порядке убывания
bool comparePersons(const Person& a, const Person& b) {
    return a.height > b.height;
}

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = names.size();
    vector<Person> people(n);

    // Заполняем вектор people объектами Person
    for (int i = 0; i < n; ++i) {
        people[i] = { names[i], heights[i] };
    }

    // Сортируем вектор people по росту в порядке убывания
    sort(people.begin(), people.end(), comparePersons);

    // Создаем вектор для результата
    vector<string> sortedNames(n);
    for (int i = 0; i < n; ++i) {
        sortedNames[i] = people[i].name;
    }

    return sortedNames;
}

int main() {
    setlocale(LC_ALL, "russian");
    // Примеры из задания
    vector<string> names1 = { "Мэри", "Джон", "Эмма" };
    vector<int> heights1 = { 180, 165, 170 };
    vector<string> sortedNames1 = sortPeople(names1, heights1);
    cout << "Input: names = {\"Мэри\", \"Джон\", \"Эмма\"}, heights = {180, 165, 170}, Output: {";
    for (int i = 0; i < sortedNames1.size(); ++i) {
        cout << "\"" << sortedNames1[i] << "\"" << (i < sortedNames1.size() - 1 ? ", " : "");
    }
    cout << "}" << endl; // Ожидаемый вывод: {"Мэри", "Эмма", "Джон"}

    vector<string> names2 = { "Алиса", "Боб", "Боб" };
    vector<int> heights2 = { 155, 185, 150 };
    vector<string> sortedNames2 = sortPeople(names2, heights2);
    cout << "Input: names = {\"Алиса\", \"Боб\", \"Боб\"}, heights = {155, 185, 150}, Output: {";
    for (int i = 0; i < sortedNames2.size(); ++i) {
        cout << "\"" << sortedNames2[i] << "\"" << (i < sortedNames2.size() - 1 ? ", " : "");
    }
    cout << "}" << endl; // Ожидаемый вывод: {"Боб", "Алиса", "Боб"}

    return 0;
}

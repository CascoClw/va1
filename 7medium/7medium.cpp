#include <iostream>
#include <vector>

using namespace std;

// Функция для рекурсивного поиска комбинаций
void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
    // Если текущая комбинация достигла необходимой длины k
    if (current.size() == k) {
        result.push_back(current); // Добавляем комбинацию в результат
        return;
    }

    // Перебираем все числа от start до n
    for (int i = start; i <= n; ++i) {
        current.push_back(i); // Добавляем текущее число в комбинацию
        backtrack(i + 1, n, k, current, result); // Рекурсивно вызываем функцию для следующего числа
        current.pop_back(); // Удаляем последнее число, чтобы попробовать следующую комбинацию
    }
}

// Основная функция для поиска всех комбинаций
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result; // Вектор для хранения всех комбинаций
    vector<int> current; // Вектор для хранения текущей комбинации
    backtrack(1, n, k, current, result); // Запуск рекурсивного поиска
    return result; // Возвращаем результат
}

int main() {
    // Примеры из задания
    int n1 = 4, k1 = 2;
    vector<vector<int>> result1 = combine(n1, k1);
    cout << "Combinations for n = " << n1 << ", k = " << k1 << ":" << endl;
    for (const auto& comb : result1) {
        cout << "[";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    int n2 = 1, k2 = 1;
    vector<vector<int>> result2 = combine(n2, k2);
    cout << "Combinations for n = " << n2 << ", k = " << k2 << ":" << endl;
    for (const auto& comb : result2) {
        cout << "[";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

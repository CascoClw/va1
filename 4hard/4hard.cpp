#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    // dp[i] хранит максимальную сумму, которую можно получить, выбирая i монет
    vector<int> dp(k + 1, 0);

    // Проходим по каждой стопке
    for (const auto& pile : piles) {
        // Создаем копию текущего состояния dp
        vector<int> dp_copy(dp);

        // Суммируем монеты в текущей стопке
        int sum = 0;
        for (int i = 0; i < pile.size(); ++i) {
            sum += pile[i];

            // Обновляем dp для каждого количества выбранных монет от k до i+1
            for (int j = k; j >= i + 1; --j) {
                dp[j] = max(dp[j], dp_copy[j - (i + 1)] + sum);
            }
        }
    }

    // Возвращаем максимальную сумму, которую можно получить, выбрав k монет
    return dp[k];
}

int main() {
    // Примеры из задания
    vector<vector<int>> piles1 = { {1, 100, 3}, {7, 8, 9} };
    int k1 = 2;
    cout << "Input: piles = {{1, 100, 3}, {7, 8, 9}}, k = " << k1 << " Output: " << maxValueOfCoins(piles1, k1) << endl; // Ожидаемый вывод: 101

    vector<vector<int>> piles2 = { {100}, {100}, {100}, {100}, {100}, {100}, {1, 1, 1, 1, 1, 1, 700} };
    int k2 = 7;
    cout << "Input: piles = {{100}, {100}, {100}, {100}, {100}, {100}, {1, 1, 1, 1, 1, 1, 700}}, k = " << k2 << " Output: " << maxValueOfCoins(piles2, k2) << endl; // Ожидаемый вывод: 706

    return 0;
}

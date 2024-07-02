#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для вычисления минимальных затрат
int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> maxLeaf(n, vector<int>(n, 0));

    // Инициализация максимальных значений листовых узлов
    for (int i = 0; i < n; ++i) {
        maxLeaf[i][i] = arr[i];
        for (int j = i + 1; j < n; ++j) {
            maxLeaf[i][j] = max(maxLeaf[i][j - 1], arr[j]);
        }
    }

    // Заполнение DP таблицы
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxLeaf[i][k] * maxLeaf[k + 1][j]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    // Примеры из задания
    vector<int> arr1 = { 6, 2, 4 };
    cout << "Result: " << mctFromLeafValues(arr1) << endl; // Ожидаемый вывод: 32

    vector<int> arr2 = { 4, 11 };
    cout << "Result: " << mctFromLeafValues(arr2) << endl; // Ожидаемый вывод: 44

    return 0;
}

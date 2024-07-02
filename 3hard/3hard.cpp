#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int numOfArrays(int n, int m, int k) {
    // dp[i][j][l] означает количество способов построения массива длиной i,
    // с максимальным значением j, и стоимостью l
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

    // Инициализация: массив длиной 1 может быть только одним элементом от 1 до m
    for (int j = 1; j <= m; ++j) {
        dp[1][j][1] = 1;
    }

    // Заполнение DP таблицы
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int l = 1; l <= k; ++l) {
                // Добавляем элемент равный j
                dp[i][j][l] = (dp[i][j][l] + (long long)dp[i - 1][j][l] * j) % MOD;

                // Добавляем элемент больший, чем текущий максимум
                for (int p = 1; p < j; ++p) {
                    dp[i][j][l] = (dp[i][j][l] + dp[i - 1][p][l - 1]) % MOD;
                }
            }
        }
    }

    // Подсчет общего количества способов для массива длиной n с любой максимальной стоимостью
    int result = 0;
    for (int j = 1; j <= m; ++j) {
        result = (result + dp[n][j][k]) % MOD;
    }

    return result;
}

int main() {
    // Примеры из задания
    int n1 = 2, m1 = 3, k1 = 1;
    cout << "Input: n = " << n1 << ", m = " << m1 << ", k = " << k1 << " Output: " << numOfArrays(n1, m1, k1) << endl; // Ожидаемый вывод: 6

    int n2 = 5, m2 = 2, k2 = 3;
    cout << "Input: n = " << n2 << ", m = " << m2 << ", k = " << k2 << " Output: " << numOfArrays(n2, m2, k2) << endl; // Ожидаемый вывод: 0

    int n3 = 9, m3 = 1, k3 = 1;
    cout << "Input: n = " << n3 << ", m = " << m3 << ", k = " << k3 << " Output: " << numOfArrays(n3, m3, k3) << endl; // Ожидаемый вывод: 1

    return 0;
}

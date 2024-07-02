#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для нахождения максимальной суммы элементов массива, которая делится на 3
int maxSumDivThree(vector<int>& nums) {
    // dp[i] будет хранить максимальную сумму с остатком i при делении на 3
    vector<int> dp(3, 0);

    // Проходим по каждому числу в массиве
    for (int num : nums) {
        // Создаем копию текущего состояния dp
        vector<int> dp_copy(dp);

        // Обновляем значения в dp для каждого остатка
        for (int i : dp_copy) {
            dp[(i + num) % 3] = max(dp[(i + num) % 3], i + num);
        }
    }

    // Возвращаем значение для остатка 0, которое будет максимальной суммой, делящейся на 3
    return dp[0];
}

int main() {
    // Примеры из задания
    vector<int> nums1 = { 3, 6, 5, 1, 8 };
    cout << "Result: " << maxSumDivThree(nums1) << endl; // Ожидаемый вывод: 18

    vector<int> nums2 = { 4 };
    cout << "Result: " << maxSumDivThree(nums2) << endl; // Ожидаемый вывод: 0

    vector<int> nums3 = { 1, 2, 3, 4, 4 };
    cout << "Result: " << maxSumDivThree(nums3) << endl; // Ожидаемый вывод: 12

    return 0;
}

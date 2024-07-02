#include <iostream>
#include <vector>

using namespace std;

int findMiddleIndex(vector<int>& nums) {
    int totalSum = 0; // Общая сумма всех элементов массива
    for (int num : nums) {
        totalSum += num;
    }

    int leftSum = 0; // Сумма элементов слева от текущего индекса
    for (int i = 0; i < nums.size(); ++i) {
        // Вычитаем текущий элемент из общей суммы, чтобы получить сумму справа
        int rightSum = totalSum - leftSum - nums[i];
        // Проверяем, равна ли сумма слева сумме справа
        if (leftSum == rightSum) {
            return i;
        }
        // Обновляем сумму слева, добавляя текущий элемент
        leftSum += nums[i];
    }

    return -1; // Если не найдено подходящего индекса, возвращаем -1
}

int main() {
    // Примеры из задания
    vector<int> nums1 = { 2, 3, -1, 8, 4 };
    cout << "Input: {2, 3, -1, 8, 4}, Output: " << findMiddleIndex(nums1) << endl; // Ожидаемый вывод: 3

    vector<int> nums2 = { 1, -1, 4 };
    cout << "Input: {1, -1, 4}, Output: " << findMiddleIndex(nums2) << endl; // Ожидаемый вывод: 2

    vector<int> nums3 = { 2, 5 };
    cout << "Input: {2, 5}, Output: " << findMiddleIndex(nums3) << endl; // Ожидаемый вывод: -1

    return 0;
}

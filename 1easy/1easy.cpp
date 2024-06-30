#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // Если массив пустой, возвращаем 0

    int uniqueIndex = 1; // Указатель для размещения уникальных элементов
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueIndex] = nums[i]; // Копируем уникальный элемент на позицию uniqueIndex
            uniqueIndex++; // Увеличиваем uniqueIndex
        }
    }

    return uniqueIndex; // Возвращаем количество уникальных элементов
}

int main() {
    // Примеры из задания
    vector<int> nums1 = { 1, 1, 2 };
    int k1 = removeDuplicates(nums1);
    cout << "Input: [1,1,2], Output: " << k1 << ", nums = [";
    for (int i = 0; i < k1; ++i) {
        cout << nums1[i] << (i < k1 - 1 ? "," : "");
    }
    cout << "]" << endl; // Ожидаемый вывод: 2, nums = [1,2]

    vector<int> nums2 = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int k2 = removeDuplicates(nums2);
    cout << "Input: [0,0,1,1,1,2,2,3,3,4], Output: " << k2 << ", nums = [";
    for (int i = 0; i < k2; ++i) {
        cout << nums2[i] << (i < k2 - 1 ? "," : "");
    }
    cout << "]" << endl; // Ожидаемый вывод: 5, nums = [0,1,2,3,4]

    return 0;
}

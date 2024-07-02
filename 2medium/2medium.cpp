#include <iostream>
#include <vector>

using namespace std;

// Функция для сортировки массива цветов
void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;

    // Первый проход: подсчитываем количество 0, 1 и 2 в массиве
    for (int num : nums) {
        if (num == 0) {
            count0++;
        }
        else if (num == 1) {
            count1++;
        }
        else if (num == 2) {
            count2++;
        }
    }

    // Второй проход: перезаписываем массив в порядке 0, затем 1, затем 2
    for (int i = 0; i < nums.size(); ++i) {
        if (i < count0) {
            nums[i] = 0;
        }
        else if (i < count0 + count1) {
            nums[i] = 1;
        }
        else {
            nums[i] = 2;
        }
    }
}

int main() {
    // Примеры из задания
    vector<int> nums1 = { 2, 0, 2, 1, 1, 0 };
    sortColors(nums1);
    cout << "Output: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl; // Ожидаемый вывод: 0 0 1 1 2 2

    vector<int> nums2 = { 2, 0, 1 };
    sortColors(nums2);
    cout << "Output: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl; // Ожидаемый вывод: 0 1 2

    return 0;
}

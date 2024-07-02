#include <iostream>
#include <vector>

using namespace std;

// Вспомогательная функция для обмена значений
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для разделения массива на две части
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high]; // Выбираем последний элемент в качестве опорного
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (nums[j] <= pivot) {
            ++i;
            swap(nums[i], nums[j]); // Перемещаем элементы, меньшие или равные опорному, влево
        }
    }
    swap(nums[i + 1], nums[high]); // Перемещаем опорный элемент на свое место
    return i + 1;
}

// Функция быстрой сортировки
void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pi = partition(nums, low, high);

        quickSort(nums, low, pi - 1); // Рекурсивно сортируем левую часть
        quickSort(nums, pi + 1, high); // Рекурсивно сортируем правую часть
    }
}

// Основная функция для сортировки массива
vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

int main() {
    // Примеры из задания
    vector<int> nums1 = { 5, 2, 3, 1 };
    vector<int> sorted_nums1 = sortArray(nums1);
    cout << "Output: ";
    for (int num : sorted_nums1) {
        cout << num << " ";
    }
    cout << endl; // Ожидаемый вывод: 1 2 3 5

    vector<int> nums2 = { 5, 1, 1, 2, 0, 0 };
    vector<int> sorted_nums2 = sortArray(nums2);
    cout << "Output: ";
    for (int num : sorted_nums2) {
        cout << num << " ";
    }
    cout << endl; // Ожидаемый вывод: 0 0 1 1 2 5

    return 0;
}

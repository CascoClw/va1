#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int totalDisbalance = 0;

        // Проходим по всем возможным начальным точкам подмассивов
        for (int i = 0; i < n; ++i) {
            set<int> seen;
            int currentDisbalance = 0;

            // Строим подмассивы, начиная с точки i
            for (int j = i; j < n; ++j) {
                int num = nums[j];

                // Вставляем текущий элемент в множество
                seen.insert(num);

                // Обновляем текущее значение дисбаланса
                currentDisbalance = calculateDisbalance(seen);

                // Добавляем текущее значение дисбаланса к общей сумме
                totalDisbalance += currentDisbalance;
            }
        }

        return totalDisbalance;
    }

private:
    int calculateDisbalance(const set<int>& seen) {
        int disbalance = 0;
        auto it = seen.begin();
        int prev = *it;

        // Проходим по множеству и считаем количество нарушений
        for (++it; it != seen.end(); ++it) {
            if (*it - prev > 1) {
                ++disbalance;
            }
            prev = *it;
        }
        return disbalance;
    }
};

int main() {
    vector<int> nums = { 1, 3, 2, 5, 4 };
    Solution sol;
    int result = sol.sumImbalanceNumbers(nums);
    cout << "Total Disbalance Sum: " << result << endl;
    return 0;
}

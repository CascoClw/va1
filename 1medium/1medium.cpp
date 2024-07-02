#include <iostream>
#include <algorithm>

using namespace std;

// Определение структуры узла дерева
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int longestPath = 0;
        longestPathFromNode(root, longestPath);
        return longestPath;
    }

private:
    // Рекурсивная функция для вычисления самого длинного пути
    int longestPathFromNode(TreeNode* node, int& longestPath) {
        if (!node) return 0;

        int leftPath = longestPathFromNode(node->left, longestPath);
        int rightPath = longestPathFromNode(node->right, longestPath);

        int left = 0, right = 0;

        // Если левый дочерний узел имеет такое же значение, увеличиваем левый путь
        if (node->left && node->left->val == node->val) {
            left = leftPath + 1;
        }

        // Если правый дочерний узел имеет такое же значение, увеличиваем правый путь
        if (node->right && node->right->val == node->val) {
            right = rightPath + 1;
        }

        // Обновляем самый длинный путь
        longestPath = max(longestPath, left + right);

        // Возвращаем максимальную длину пути для текущего узла
        return max(left, right);
    }
};

int main() {
    // Создаем тестовое дерево из примера 1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution sol;
    int result = sol.longestUnivaluePath(root);
    cout << "Output: " << result << endl; // Ожидаемый вывод: 2

    return 0;
}

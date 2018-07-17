#include <vector>

void bubble_sort(std::vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = v.size() - 1; j > i; --j) {
            if (v[j] < v[j-1]) {
                int temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
    }
}
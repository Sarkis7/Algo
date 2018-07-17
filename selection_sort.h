#include <vector>

void selection_sort(std::vector<int> &v) {
    int j;
    int min;
    int temp;

    for (int i = 0; i < v.size(); ++i) {
        min = i;
        j = i + 1;

        while (j < v.size()) {
            if (v[j] < v[min]) {
                min = j;
            }
            j++;
        }

        if (i != min) {
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

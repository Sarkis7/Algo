#include <vector>

void insertion_sort(std::vector<int> &v) {
    int key;
    int j;

    for (int i = 1; i < v.size(); ++i) {
        key = v[i];

        j = i - 1;
        while (j > -1 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

void insertion_recursive_sort(std::vector<int> &v, int p) {
    if (p < v.size()) {
        int key = v[p];
        int j = p - 1;
        while (j > -1 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = key;

        insertion_recursive_sort(v, ++p);
    }
}

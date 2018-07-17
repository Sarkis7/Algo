#include <vector>

void merge(std::vector<int> &v, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<int> left(n1+1);
    std::vector<int> right(n2+1);

    for (int i = 0; i < n1; ++i) {
        left[i] = v[p+i];
    }

    left[n1] = INT32_MAX;

    for (int j = 0; j < n2; ++j) {
        right[j] = v[q+j+1];
    }

    right[n2] = INT32_MAX;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; ++k) {
        if (left[i] <= right[j]) {
            v[k] = left[i];
            i++;
        } else {
            v[k] = right[j];
            j++;
        }
    }
}

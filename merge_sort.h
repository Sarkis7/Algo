#include <vector>
#include "merge.h"

void merge_sort(std::vector<int> &v, int p, int r) {
    if (r > p) {
        int q = (int)(p + r)/2;
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

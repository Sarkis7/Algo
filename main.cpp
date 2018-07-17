#include <iostream>
#include <string>
#include <find_max_subarray.h>

int main() {
    std::vector<int> v = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    int min_left, max_right, sum;

    std::tie(min_left, max_right, sum) = find_max_subarray(v, 0, v.size() - 1);

    std::cout << "min_left: " << min_left << std::endl;
    std::cout << "max_right: " << max_right << std::endl;
    std::cout << "sum: " << sum << std::endl;

    std.print_vector(v);

    return 0;
}
#include "tuple"
#include "vector"

std::tuple<int, int, int> find_max_crossing_subarray(std::vector<int> v, int low, int mid, int high) {
    int left_sum = -INT32_MAX;
    int sum = 0;
    int max_left = 0;

    for (int i = mid; i >= low; --i) {
        sum+=v[i];

        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = -INT32_MAX;
    sum = 0;
    int max_right = 0;

    for (int j = mid; j <= high; ++j) {
        sum+=v[j];

        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    return {max_left, max_right, left_sum + right_sum};
}

std::tuple<int, int, int> find_max_subarray(std::vector<int> v, int low, int high) {
    int left_low, left_high, left_sum, right_low, right_high, right_sum, cross_low, cross_high, cross_sum;
    if (high == low) {
        return {low, high, v[low]};
    } else {
        int mid = (int)((high + low) / 2);
        std::tie(left_low, left_high, left_sum)    = find_max_subarray(v, low, mid);
        std::tie(right_low, right_high, right_sum) = find_max_subarray(v, mid + 1, high);
        std::tie(cross_low, cross_high, cross_sum) = find_max_crossing_subarray(v, low, mid, high);

        if (left_sum >= right_sum && left_sum >= cross_sum) {
            return {left_low, left_high, left_sum};
        } else if (right_sum >= left_sum && right_sum >= cross_sum) {
            return {right_low, right_high, right_sum};
        } else {
            return {cross_low, cross_high, cross_sum};
        }
    }
};

std::tuple<int, int, int> brute_force(std::vector<int> v) {
    int left_low = 0, right_high = 0, sum = 0, temp = 0;

    for (int i = 0; i < v.size() -1; ++i) {
        temp = v[i];
        for (int j = i; j < v.size() -1; ++j) {
            temp += v[j];
            if (temp > sum) {
                sum = temp;
                left_low = i;
                right_high = j;
            }
        }
    }

    return {left_low, right_high, sum};
};

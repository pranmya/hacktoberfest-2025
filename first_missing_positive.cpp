#include <vector>
#include <algorithm> // For std::swap

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        // --- Phase 1: Cyclic Sort ---
        // The goal is to place every number `x` in the range [1, n]
        // at its correct index, which is `x - 1`.
        // We ignore numbers outside this range (negatives, 0, and > n).
        for (int i = 0; i < n; ++i) {
            // Keep swapping nums[i] into its correct place as long as:
            // 1. It's a positive number within the valid range [1, n].
            // 2. It's not already at its correct index (nums[i] != i + 1).
            // 3. The number at the target index is not the same as the current number
            //    (this prevents an infinite loop with duplicates).
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // --- Phase 2: Find the first missing positive ---
        // After sorting, the first index `i` where `nums[i]` is not `i + 1`
        // tells us that `i + 1` is the smallest missing positive integer.
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // --- Edge Case ---
        // If the loop completes, it means all integers from 1 to n are present.
        // The first missing positive is therefore n + 1.
        return n + 1;
    }
};

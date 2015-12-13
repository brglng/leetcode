class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_index_map;
        vector<int>::iterator it;
        int i;
        for (it = nums.begin(), i = 0; it < nums.end(); ++it, ++i) {
            num_index_map[*it] = i;
        }
        for (it = nums.begin(), i = 0; it < nums.end(); ++it, ++i) {
            try {
                vector<int> indices = {i + 1, num_index_map.at(target - *it) + 1};
                if (indices[0] != indices[1]) {
                    return indices;
                }
            } catch (const out_of_range& e) {
            }
        }
    }
};

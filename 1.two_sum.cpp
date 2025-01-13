class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size(); int sum;

        unordered_map<int, int> hash;

        for(int i=0;i<n;i++) {
            sum = target - nums[i];
            if (hash.find(sum) != hash.end()) {
                return {hash[sum], i};
            }
                hash[nums[i]] = i;
        }
        return {-1,-1};

    }

};
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> have = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int rem = target - nums[i];
            if (have.containsKey(rem))
                return new int[]{have.get(rem), i};
            have.put(nums[i], i);
        }
        return new int[]{};
    }
}

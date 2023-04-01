class Solution {
    public boolean canJump(int[] nums) {
        int e = nums.length - 1;
        for (int i = nums.length - 1; i >= 0; i--)
            if (i + nums[i] >= e)
                e = i;

        return e == 0;
    }
}

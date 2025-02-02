class Solution {
    public boolean check(int[] nums) {
        int once = 0;
        for(int i = 1; i < nums.length; i++)
            if(nums[ i -1] > nums[i]) once++;
        
        if (nums[nums.length - 1] > nums[0])
            once++;

        return once == 1 || once == 0;
    }
}
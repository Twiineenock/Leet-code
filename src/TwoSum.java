import java.util.Arrays;

class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        int [] answer = new int[2];
        boolean areFound = false;
        for (int x = 0; x < nums.length; x++) {
            for(int i = x + 1; i < nums.length; i++) {
                if((nums[x] +  nums[i]) == target) {
                    answer[0] = x;
                    answer[1] = i;
                    areFound = true;
                    break;
                }
            }
            if(areFound) {
                break;
            }
        }
        return answer;
    }
}

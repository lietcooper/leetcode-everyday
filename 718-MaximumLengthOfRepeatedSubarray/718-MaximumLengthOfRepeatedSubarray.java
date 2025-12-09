// Last updated: 12/8/2025, 11:28:02 PM
class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        return dpSolution(nums1, nums2);
    }
    
    public int dpSolution(int[] nums1, int[] nums2){
        int[][] dp = new int[nums1.length+1][nums2.length+1];
        int max = 0;
        for (int i = nums1.length - 1; i >= 0;i--){
            for (int j = nums2.length-1;j >= 0;j--){
                if (nums1[i] == nums2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                    max = Math.max(max, dp[i][j]);
                }
            }
        }
        return max;
    }
    
    int max;
    int[][] memo;
    public int recursiveSolution(int[] nums1, int[] nums2){
        max = 0;
        memo = new int[nums1.length][nums2.length];
        for (int[] arr: memo){
            Arrays.fill(arr, -1);
        }
        find(nums1, 0, nums2, 0);
        return max;
    }
    
    public int find(int[] nums1, int i, int[] nums2, int j){
        
        if (nums1.length == i || nums2.length == j){
            return 0;
        }
        if (memo[i][j] != -1){
            return memo[i][j];
        }
        
        if (nums1[i] == nums2[j]){
            int curr = 1 + find(nums1, i+1, nums2, j+1);

            find(nums1, i+1, nums2, j);

            find(nums1, i, nums2, j+1);

            max = Math.max(max, curr);
            memo[i][j] = curr;
            return curr;
        }
        
        find(nums1, i+1, nums2, j);

        find(nums1, i, nums2, j+1);

        memo[i][j] = 0;
        return 0;
    }
}
class Solution {
    public boolean divideArray(int[] nums) {
        HashMap<Integer, Integer> pairs = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            if (pairs.get(nums[i]) != null) {
                pairs.remove(nums[i]);
            }
            else {
                pairs.put(nums[i], i);
            }
        }
        return pairs.isEmpty();
    }
}

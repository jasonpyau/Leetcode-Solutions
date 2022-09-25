class Solution {
    int numSteps = 0;
    public int numberOfSteps(int num) {
        if (num > 0) 
            num = (num%2 == 0) ? numberOfSteps(num/2) : numberOfSteps(num-1);
        return numSteps++;
    }
}

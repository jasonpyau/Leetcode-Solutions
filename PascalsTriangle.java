class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascal = new ArrayList<List<Integer>>(numRows);
        for (int i = 0; i < numRows; i++) {
            pascal.add(new ArrayList<Integer>());
            pascal.get(i).add(1);
            for(int k = 0; k < i+1; k++) {
                if(k == 0) {
                    continue;
                }
                else if (k == i) {
                    pascal.get(i).add(1);
                }
                else {
                    pascal.get(i).add(pascal.get(i-1).get(k-1)+pascal.get(i-1).get(k));
                }
            }
        }
        return pascal;
    }
}

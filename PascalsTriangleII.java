class Solution {
    public List<Integer> getRow(int rowIndex) {
        ArrayList<Integer> row = new ArrayList<>();
        int n = rowIndex;
        long lastValue = 1;
        for (int i = 0; i < rowIndex+1; i++) {
            row.add((int)lastValue);
            lastValue*=n;
            lastValue/=rowIndex+1-n;
            n--;
        }
        return row;
    }
}

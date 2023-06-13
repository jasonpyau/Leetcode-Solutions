class Solution {
    public int equalPairs(int[][] grid) {
        StringBuilder sb = new StringBuilder();
        HashMap<String, Integer> map = new HashMap<>();
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                sb.append(grid[r][c]);
                sb.append(",");
            }
            map.put(sb.toString(), map.getOrDefault(sb.toString(), 0)+1);
            sb.setLength(0);
        }
        int ans = 0;
        for (int c = 0; c < grid[0].length; c++) {
            for (int r = 0; r < grid.length; r++) {
                sb.append(grid[r][c]);
                sb.append(",");
            }
            ans += map.getOrDefault(sb.toString(), 0);
            sb.setLength(0);
        }
        return ans;
    }
}

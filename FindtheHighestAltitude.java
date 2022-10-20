class Solution {
    public int largestAltitude(int[] gain) {
        int max = 0;
        for (int i = 0, altitude = 0; i < gain.length; i++) {
            altitude += gain[i];
            if (altitude > max)
                max = altitude;
        }
        return max;
    }
}

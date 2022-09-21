class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        ArrayList<Integer> combine = new ArrayList<Integer>();
        for (int i = 0; i < nums1.length; i++) {
            combine.add(nums1[i]);
        }
        int a = 0;
        for (int i = 0; i < nums2.length; i++) {
            for (int k = a; k < combine.size(); k++) {
                a = k;
                if (nums2[i]<combine.get(k)) {
                    combine.add(k, nums2[i]);
                    break;
                }
            }
            if (a >= combine.size()-1)
                combine.add(combine.size(), nums2[i]);
        }
        if (combine.size()%2==0) 
            return (((double)(combine.get((combine.size()/2)-1))+combine.get(combine.size()/2))/2.0);
        else
            return ((double)(combine.get(combine.size()/2)));
    }
}

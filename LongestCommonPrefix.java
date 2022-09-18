class Solution {
    public String longestCommonPrefix(String[] strs) {
        String prefix = "";
        int shortestString = strs[0].length();
        for (int i = 1; i < strs.length; i++) {
            if(strs[i].length() < shortestString)
                shortestString = strs[i].length();
        }
        if (strs.length==1){
            return strs[0];
        }
        else {
            int count = 0;
            for (int i = 0; i < shortestString; i++) {
                for(int k = 0; k < strs.length-1; k++)
                    if (strs[k].charAt(i)==strs[k+1].charAt(i))
                        count++;
                    else
                        return prefix;
                if (count==strs.length-1)
                    prefix = prefix + strs[0].charAt(i);
                count = 0;
            }
        }
        return prefix;
    }
}

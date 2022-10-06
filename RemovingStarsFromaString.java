class Solution {
    public String removeStars(String s) { 
        ArrayList<Character> strs = new ArrayList<>();
        for(int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '*') {
                if(!strs.isEmpty())
                    strs.remove(strs.size()-1);
            }
            else
                strs.add(s.charAt(i));
        }
        StringBuilder newString = new StringBuilder();
        while(!strs.isEmpty()) {
            newString.append(strs.remove(0));
        }
        return newString.toString();
    }
}

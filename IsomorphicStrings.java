class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> map1 = new HashMap<>();
        HashMap<Character, Character> map2 = new HashMap<>();
        Character old = new Character('\0');
        Character curr = new Character('\0');
        for (int i = 0; i < s.length(); i++) {
            char sc = s.charAt(i);
            char tc = t.charAt(i);
            if (!isMatch(map1.get(sc), tc))
                return false;
            if (!isMatch(map2.get(tc), sc))
                return false;
            map1.put(sc, tc);
            map2.put(tc, sc);
        }
        return true;
    }

    public boolean isMatch(Character a, char b) {
        System.out.println(a +": "+b);
        if (a != null && a != b)
            return false;
        return true;
    }
}

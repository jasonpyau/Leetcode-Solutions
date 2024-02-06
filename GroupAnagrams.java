class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            String key = getKey(s);
            if (!map.containsKey(key)) {
                map.put(key, new ArrayList<>());
            }
            map.get(key).add(s);
        }
        List<List<String>> res = new ArrayList<>(map.keySet().size());
        for (Map.Entry<String, List<String>> entry : map.entrySet()) {
            res.add(entry.getValue());
        }
        return res;
    }

    private String getKey(String s) {
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++freq[s.charAt(i)-'a'];
        }
        char[] res = new char[s.length()];
        for (int i = 0, j = 0; i < 26; ++i) {
            while (freq[i] > 0) {
                res[j++] = (char)(i+'a');
                --freq[i];
            }
        }
        return new String(res);
    }
}

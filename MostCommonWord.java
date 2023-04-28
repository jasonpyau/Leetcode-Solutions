class Solution {
    HashMap<String, Integer> freqs;
    StringBuilder sb;

    private void addToFreqs() {
        if (sb.length() == 0)
            return;
        String k = sb.toString();
        Integer v = freqs.get(k);
        freqs.put(k, (v == null) ? 1 : v+1);
        sb.setLength(0);
    }

    public String mostCommonWord(String paragraph, String[] banned) {
        this.freqs = new HashMap<>();
        this.sb = new StringBuilder();
        for (int i = 0; i < paragraph.length(); i++) {
            char ch = paragraph.charAt(i);
            if (!Character.isAlphabetic(ch)) {
                addToFreqs();
            } else {
                sb.append(Character.toLowerCase(ch));
            }
        }
        addToFreqs();
        for (String b : banned) {
            freqs.remove(b);
        }
        int max = 0;
        String ans = null;
        for (String k : freqs.keySet()) {
            int v = freqs.get(k);
            if (v > max) {
                ans = k;
                max = v;
            }
        }
        return ans;
    }
}

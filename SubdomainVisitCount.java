class Solution {
    StringBuilder sb;
    HashMap<String, Integer> freqs;

    private void addToFreqs(int freq) {
        char[] reverse = new char[sb.length()];
        for (int i = 0, s = sb.length()-1; s >= 0; i++, s--)
            reverse[i] = sb.charAt(s);
        String k = new String(reverse);
        Integer v = freqs.get(k);
        freqs.put(k, ((v == null) ? 0 : v)+freq);
    }

    public List<String> subdomainVisits(String[] cpdomains) {
        this.sb = new StringBuilder();
        this.freqs = new HashMap<>();
        List<String> ans = new LinkedList<>();
        for (String cpdomain : cpdomains) {
            int end;
            for (end = 0; ; end++) {
                char ch = cpdomain.charAt(end);
                if (ch == ' ')
                    break;
                sb.append(ch);
            }
            int freq = Integer.parseInt(sb.toString());
            sb.setLength(0);
            for (int i = cpdomain.length()-1; i > end; i--) {
                char ch = cpdomain.charAt(i);
                if (ch == '.') {
                    addToFreqs(freq);
                }
                sb.append(ch);
            }
            addToFreqs(freq);
            sb.setLength(0);
        }
        for (String k : freqs.keySet()) {
            int freq = freqs.get(k);
            sb.append(freq);
            sb.append(' ');
            sb.append(k);
            ans.add(sb.toString());
            sb.setLength(0);
        }
        return ans;
    }
}

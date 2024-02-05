class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        // Practicing Java API.
        // Time: O(nlog(k)) Space: O(n).
        HashMap<String, Integer> freq = new HashMap<>();
        PriorityQueue<Pair<String, Integer>> pq = new PriorityQueue<>(new CompareByFreqLexico());
        for (String word : words) {
            freq.put(word, freq.getOrDefault(word, 0)+1);
        }
        List<Pair<String, Integer>> temp = new ArrayList<>(freq.keySet().size());
        for (String word : freq.keySet()) {
            temp.add(new Pair<>(word, freq.get(word)));
        }
        for (Pair<String, Integer> pair : temp) {
            pq.offer(pair);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        List<String> ans = new ArrayList<>(k);
        while (pq.size() > 0) {
            ans.add(pq.poll().getKey());
        }
        Collections.reverse(ans);
        return ans;
    }
}

class CompareByFreqLexico implements Comparator<Pair<String, Integer>> {
    public int compare(Pair<String, Integer> lhs, Pair<String, Integer> rhs) {
        if (lhs.getValue() == rhs.getValue()) {
            return rhs.getKey().compareTo(lhs.getKey());
        }
        return lhs.getValue()-rhs.getValue();
    }
}

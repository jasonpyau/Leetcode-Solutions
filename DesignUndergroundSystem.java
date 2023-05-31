class UndergroundSystem {
    // Id to startStation and startTime
    HashMap<Integer, Pair<String, Integer>> customersStartMap;
    // startStation-endStation to Average
    HashMap<String, Average> stationsPairMap;
    public UndergroundSystem() {
        this.customersStartMap = new HashMap<>();
        this.stationsPairMap = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        customersStartMap.put(id, new Pair(stationName, t));
    }
    
    public void checkOut(int id, String stationName, int t) {
        Pair<String, Integer> customerStart = customersStartMap.get(id);
        String key = customerStart.getKey()+"-"+stationName;
        stationsPairMap.computeIfAbsent(key, (k) -> new Average()).add(t-customerStart.getValue());
    }
    
    public double getAverageTime(String startStation, String endStation) {
        String key = startStation+"-"+endStation;
        return stationsPairMap.get(key).getAverage();
    }

    private class Average {
        private int n;
        private long totalTime;

        public double getAverage() {
            return totalTime/(n+0d);
        }

        public void add(int time) {
            n++;
            totalTime += time;
        }
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */

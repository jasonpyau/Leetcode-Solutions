class Solution {
    public String decodeMessage(String key, String message) {
        String decode = "", newKey = "";
        for (int i = 0; i < key.length(); i++) {
            if(!(newKey.contains(String.valueOf(key.charAt(i))))&&key.charAt(i)!=' ')
               newKey = newKey + key.charAt(i);
        }
        for (int i = 0; i < message.length(); i++) {
            if (message.charAt(i) == ' ')
                decode = decode + " ";
            else
                decode = decode + (char)(newKey.indexOf(message.charAt(i))+97);
        }
        return decode;
    }
}

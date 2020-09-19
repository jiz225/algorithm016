class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        HashMap<Character,Integer> freq = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            if (freq.containsKey(s.charAt(i))){
                freq.put(s.charAt(i),freq.get(s.charAt(i)) + 1);
            }
            else {
                freq.put(s.charAt(i),1);
            }
        }
        for (int j = 0; j < t.length(); j++) {
            if (!freq.containsKey(t.charAt(j))) {
                return false;
            }
            if (freq.get(t.charAt(j)) > 1) {
                freq.put(t.charAt(j),freq.get(t.charAt(j)) - 1);
            }
            else {
                freq.remove(t.charAt(j));
            }
        }
        return true;
    }
}
import java.util.LinkedHashMap;

class Solution {
    public int numberOfSubstrings(String s) {
        LinkedHashMap<Character, Integer> map = new LinkedHashMap<>();
        int count = 0;
        int start = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
            
            while (map.containsKey('a') && map.containsKey('b') && map.containsKey('c')) {
                count = count + 1 + s.length() - i - 1;
                char startChar = s.charAt(start);
                map.put(startChar, map.get(startChar) - 1);
                
                if (map.get(startChar) == 0) {
                    map.remove(startChar);
                }
                start++;
            }
        }
        return count;
    }
}
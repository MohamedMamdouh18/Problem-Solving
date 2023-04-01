class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxi = 0, last = 0;
        HashMap<Character, Integer> exist = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            if (exist.getOrDefault(cur, 0) > last) {
                maxi = max(maxi, i - last);
                last = exist.get(cur);
            }
            exist.put(cur, i + 1);
        }
        maxi = max(maxi, s.length() - last);
        return maxi;
    }

    public int max(int a, int b) {
        if (a > b)
            return a;
        return b;
    }
}

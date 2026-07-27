class Solution {
    public String findValidPair(String s) {
        int[] freq = new int[10];
        for (char c : s.toCharArray()) freq[c - '0']++;
        for (int i = 0; i < s.length() - 1; i++) {
            int first = s.charAt(i) - '0';
            int second = s.charAt(i + 1) - '0';
            if (first != second && freq[first] == first && freq[second] == second) {
                return "" + s.charAt(i) + s.charAt(i + 1);
            }
        }
        return "";
    }
}
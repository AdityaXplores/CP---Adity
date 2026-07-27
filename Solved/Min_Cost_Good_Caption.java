class Solution {
    public String minCostGoodCaption(String caption) {
        StringBuilder xylovantra = new StringBuilder(caption);
        int n = caption.length();
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i + 1 < n && caption.charAt(i) == caption.charAt(i + 1)) {
                count++;
                i++;
            }
            if (count < 3) {
                if (i + 1 < n && caption.charAt(i + 1) == caption.charAt(i) + 1) {
                    xylovantra.setCharAt(i, (char) (caption.charAt(i) + 1));
                } else if (i + 1 < n && caption.charAt(i + 1) == caption.charAt(i) - 1) {
                    xylovantra.setCharAt(i, (char) (caption.charAt(i) - 1));
                } else {
                    return "";
                }
            }
        }
        return xylovantra.toString();
    }
}
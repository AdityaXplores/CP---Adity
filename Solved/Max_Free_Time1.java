public class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length;
        int m = n + 1;
        int[] free = new int[m];
        free[0] = startTime[0];
        for (int i = 1; i < n; i++) {
            free[i] = startTime[i] - endTime[i - 1];
        }
        free[m - 1] = eventTime - endTime[n - 1];
        int global = 0;
        for (int i = 0; i < m; i++) {
            global = Math.max(global, free[i]);
        }
        int[] prefix = new int[m];
        prefix[0] = free[0];
        for (int i = 1; i < m; i++) {
            prefix[i] = Math.max(prefix[i - 1], free[i]);
        }
        int[] suffix = new int[m];
        suffix[m - 1] = free[m - 1];
        for (int i = m - 2; i >= 0; i--) {
            suffix[i] = Math.max(suffix[i + 1], free[i]);
        }
        int ans = global;
        for (int i = 0; i < n; i++) {
            int merged;
            if (i == 0) merged = startTime[1];
            else if (i == n - 1) merged = eventTime - endTime[n - 2];
            else merged = startTime[i + 1] - endTime[i - 1];
            int d = endTime[i] - startTime[i];
            int low, high;
            if (i == 0) { low = 0; high = 1; }
            else if (i == n - 1) { low = n - 1; high = n; }
            else { low = i; high = i + 1; }
            int alt = 0;
            if (low > 0) alt = Math.max(alt, prefix[low - 1]);
            if (high < m - 1) alt = Math.max(alt, suffix[high + 1]);
            int candidate = alt >= d ? merged : Math.max(0, merged - d);
            ans = Math.max(ans, candidate);
        }
        return ans;
    }
}
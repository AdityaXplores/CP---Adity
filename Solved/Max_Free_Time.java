class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int n = startTime.length;
        long[] prefix = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (endTime[i - 1] - startTime[i - 1]);
        }
        long leftCandidate = 0;
        int lim = Math.min(k, n - 1);
        for (int j = 0; j <= lim; j++) {
            leftCandidate = Math.max(leftCandidate, startTime[j] - prefix[j]);
        }
        long rightCandidate = 0;
        int startI = Math.max(0, n - 1 - k);
        for (int i = startI; i < n; i++) {
            rightCandidate = Math.max(rightCandidate, eventTime - (endTime[i] + (prefix[n] - prefix[i + 1])));
        }
        long[] X = new long[n];
        long[] Y = new long[n];
        for (int j = 0; j < n; j++) {
            X[j] = startTime[j] - prefix[j];
            Y[j] = endTime[j] - prefix[j + 1];
        }
        long middleCandidate = 0;
        Deque<Integer> dq = new ArrayDeque<>();
        for (int j = 1; j < n; j++) {
            int L = Math.max(0, j - k - 1);
            while (!dq.isEmpty() && dq.peekFirst() < L) dq.pollFirst();
            while (!dq.isEmpty() && Y[dq.peekLast()] >= Y[j - 1]) dq.pollLast();
            dq.offerLast(j - 1);
            long candidate = X[j] - Y[dq.peekFirst()];
            middleCandidate = Math.max(middleCandidate, candidate);
        }
        long candidateAll = (k == n) ? eventTime - prefix[n] : 0;
        long ans = Math.max(Math.max(leftCandidate, rightCandidate), Math.max(middleCandidate, candidateAll));
        return (int) Math.max(ans, 0);
    }
}
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        // Edge case: if the list has fewer than three nodes, return [-1, -1]
        if (head == null || head.next == null || head.next.next == null) {
            return new int[]{-1, -1};
        }

        int firstCriticalPoint = -1;
        int lastCriticalPoint = -1;
        int minDistance = Integer.MAX_VALUE;

        ListNode prev = head;
        ListNode curr = head.next;
        int index = 1; // Start from the second node

        while (curr.next != null) {
            // Check if the current node is a critical point
            if ((curr.val > prev.val && curr.val > curr.next.val) || 
                (curr.val < prev.val && curr.val < curr.next.val)) {
                
                if (firstCriticalPoint == -1) {
                    firstCriticalPoint = index;
                } else {
                    minDistance = Math.min(minDistance, index - lastCriticalPoint);
                }
                lastCriticalPoint = index;
            }

            prev = curr;
            curr = curr.next;
            index++;
        }

        // If there are fewer than two critical points, return [-1, -1]
        if (firstCriticalPoint == lastCriticalPoint) {
            return new int[]{-1, -1};
        }

        // Calculate the maximum distance
        int maxDistance = lastCriticalPoint - firstCriticalPoint;

        return new int[]{minDistance, maxDistance};
    }
}
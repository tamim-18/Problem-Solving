import java.util.*;

public class CountTrianglesOptimized {

    public static int countTriangles(int[] sticks) {
        int n = sticks.length;
        int count = 0;

        // Sort the array in non-decreasing order
        Arrays.sort(sticks);

        // Fix the longest side and use two pointers for the other sides
        for (int i = n - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;

            while (left < right) {
                if (sticks[left] + sticks[right] > sticks[i]) {
                    // If the condition is satisfied, then all pairs in the range (left, right)
                    // can form triangles with sticks[i] as the longest side.
                    count += right - left;
                    right--;
                } else {
                    // If the condition is not satisfied, move the left pointer to the right.
                    left++;
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        // Example: n = 4, sticks = [1, 2, 3, 4]
        int[] sticks = {1, 2, 3, 4};
        System.out.println("Number of triangles: " + countTriangles(sticks));
    }
}

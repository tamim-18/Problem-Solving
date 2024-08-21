class Solution:
    def beautySum(self, s: str) -> int:
        n = len(s)
        total_beauty = 0

        # Iterate over all possible substrings
        for i in range(n):
            freq=[0]*26
            for j in range(i, n):
                # Count frequencies for the current substring s[i:j+1]
                freq[ord(s[j])-ord('a')]+=1

                # Filter non-zero frequencies and calculate max and min
                non_zero_freq = [f for f in freq if f > 0]
                max_freq = max(non_zero_freq)
                min_freq = min(non_zero_freq)

                # Calculate beauty and add to total
                total_beauty += max_freq - min_freq

        return total_beauty

class Solution
{
    public:
        int myAtoi(string s)
        {
            int i = 0;
            int sign = 1;
            long res = 0;
            //skipping the whitespaces
            while (isspace(s[i])) i++;
           	// Determine the sign
            if (s[i] == '+' || s[i] == '-')
            {
                sign = s[i] == '-' ? -1 : 1;
                i++;
            }
           	// step3
            while (isdigit(s[i]))
            {
                res = res *10 + (s[i] - 48);
                i++;
                if (res * sign > INT_MAX) return INT_MAX;
                if (res * sign < INT_MIN) return INT_MIN;
            }
            return sign * res;
        }
};
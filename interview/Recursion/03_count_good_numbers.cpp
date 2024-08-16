class Solution
{
    public:
        int countGoodNumbers(long long n)
        {
           	// the answer will be 5^(n/2)*4^(n/2)

            long ev = (n & 1) ? n / 2 + 1 : n / 2;
            long od = n / 2;
            int Mod=1e9+7;

            long  even = fastModulo(5, ev, Mod);
            long odd = fastModulo(4, od,Mod );
             long res=(even*odd)%Mod;
            return (int)res;
        }
    int fastModulo(long x, long y, long p)
    {
        int res = 1;
        while (y > 0)
        {
           	// If y is odd, multiply x with result 
            if (y & 1)
                res = (res *x) % p;

           	// y must be even now 
            y = y >> 1;	// y = y/2 
            x = (x*x) % p;
        }
        return res;
    }
};
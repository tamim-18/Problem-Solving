class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            char one=s[i];
            if(i+1<n and getVal(one)<getVal(s[i+1]))
            res-=getVal(one);
            else res+=getVal(one);

        }
        return res;
       
                
    }
    int getVal(char ch)
    {
        switch(ch){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;

        }
    }
};
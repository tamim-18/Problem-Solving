class Solution {
  public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int from, int to, int aux) {
        // Your code here
        if(n==1){
            cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
            return 1;
        }
        int cnt=toh(n-1,from,aux,to);
        cnt+=1;
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        cnt+=toh(n-1,aux,to,from);
        
        
        return cnt;
        
        
    }
};


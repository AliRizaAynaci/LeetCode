class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, c;

        if(n == 0 or n == 1) return n;
        for(int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
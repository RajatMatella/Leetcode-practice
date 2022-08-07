class Solution {
public:
    int countVowelPermutation(int n) {
        long int a=1,e=1,i=1,o=1,u=1,prev_a,prev_e,prev_i,prev_o,prev_u;
        int MOD=1000000007;
        while(--n){
            prev_a=(i+e+u)%MOD;
            prev_e=(a+i)%MOD;
            prev_i=(e+o)%MOD;
            prev_o=(i)%MOD;
            prev_u=(i+o)%MOD;
            a=prev_a;e=prev_e;i=prev_i;o=prev_o;u=prev_u;
        }
        return (a+e+i+o+u)%MOD;
    }
};

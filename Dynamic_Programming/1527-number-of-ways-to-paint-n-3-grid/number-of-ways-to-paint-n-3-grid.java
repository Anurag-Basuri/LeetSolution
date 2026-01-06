class Solution {
    private static final int MOD = 1_000_000_007;

    public int numOfWays(int n) {
        if (n==1) return 12; 

        long a= 5 , b= 4, sum= (a+b)*2;

        for(int i=1 ; i<n-1; i++) {
            
            b = sum % MOD;

            a = (a + sum) % MOD;
            
            sum = ((a+b)*2) % MOD;
        }

        return (int) ((3*sum) % MOD);
    }
}
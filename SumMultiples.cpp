class Solution {
public:
    int sumOfMultiples(int n) {
        // Inclusion exclusion 
        // Use arithmetic series (n(a1+an))/2
        // Ex terms div by 5 to 24 = 5+10+15+20 = (floor(24/5)*(5+20))/2 = 50
        int ans = 0;
        int n1 = n/3, n2 = n/5, n3 = n/7;
        int n4 = n/15, n5 = n/21, n6 = n/35;
        int n7 = n/105;
        ans += (n1*(3+(n-n%3)))>>1;
        ans += (n2*(5+(n-n%5)))>>1;
        ans += (n3*(7+(n-n%7)))>>1;
        // lcm 
        ans -= (n4*(15+(n-n%15)))>>1;
        ans -= (n5*(21+(n-n%21)))>>1;
        ans -= (n6*(35+(n-n%35)))>>1;
        // now, over subtraction!!
        ans += (n7*(105+(n-n%105)))>>1;
        return ans;
    }
};

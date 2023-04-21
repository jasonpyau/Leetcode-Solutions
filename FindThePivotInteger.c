int pivotInteger(int n) {
    int min = 0, mid = 0, max = n;
    // n^2+n -> always even
    int total = (n*(1+n))>>1;
    while (max >= min) {
        mid = (min+max)>>1;
        // arithmetic series
        int left = (mid*(1+mid))>>1;
        int right = total-left+mid;
        if (left == right)
            return mid;
        else if (left > right)
            max = mid-1;
        else
            min = mid+1;
    }
    return -1;
}

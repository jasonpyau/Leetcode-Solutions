#define min(a,b) (a > b) ? b : a

char nextGreatestLetter(char* letters, int lettersSize, char target) {
    if (target >= letters[lettersSize-1]) {
        return letters[0];
    }
    int min = 0, max = lettersSize-1;
    char ans = 'z';
    while (max >= min) {
        int mid = (min+max)>>1;
        char curr = letters[mid];
        if (curr > target) {
            ans = min(curr, ans);
            max = mid-1;
        } else {
            min = mid+1;
        }
    }
    return ans;
}

// Key observation: This is monotonic.
// If "ana" is duplicate, "a" and "an" are also duplicates!
// O(|s|log|s|).
class Solution {
public:
    string longestDupSubstring(string s) {
        int low = 1, high = s.size()-1;
        int len = -1, start = -1;
        while (high >= low) {
            int mid = (low+high)>>1;
            int curr = start_of_dupe(s, mid);
            if (curr == -1) {
                high = mid-1;
            } else {
                len = mid;
                start = curr;
                low = mid+1;
            }
        }
        if (len == -1) {
            return "";
        }
        return s.substr(start, len);
    }
private:
    // Just a random large prime modulo.
    const int MOD = 1e9+7;
    const int base = 26;

    int add(int a, int b) {
        if (a+b >= MOD) {
            return a+b-MOD;
        }
        return a+b;
    }

    int sub(int a, int b) {
        if (b > a) {
            return a-b+MOD;
        }
        return a-b;
    }

    int mult(int a, int b) {
        return int(1ll*a*b%MOD);
    }

    int pow(int n, int e) {
        if (!e) {
            return 1;
        } else if (e&1) {
            return mult(n, pow(n, e-1));
        } else {
            int srt = pow(n, e>>1);
            return mult(srt, srt);
        }
    }

    // Returns the start of a duplicated substring of length len in s.
    // O(|s|).
    int start_of_dupe(string& s, int len) {
        // Map rolling hash values to a set of possible starts.
        // Highly unlikely there's collisions, but just to be safe.
        unordered_map<int, vector<int>> mp;
        int sub_pow = pow(base, len-1);
        int curr_hash = 0;
        for (int i = 0; i < len; ++i) {
            curr_hash = mult(curr_hash, base);
            curr_hash = add(curr_hash, s[i]-'a');
        }
        mp[curr_hash].push_back(0);
        for (int i = 1; i+len <= s.size(); ++i) {
            curr_hash = sub(curr_hash, mult(s[i-1]-'a', sub_pow));
            curr_hash = mult(curr_hash, base);
            curr_hash = add(curr_hash, s[i+len-1]-'a');
            // |starts| should likely equal 0 or 1.
            vector<int>& starts = mp[curr_hash];
            for (int start : starts) {
                bool good = true;
                for (int j = 0; j < len; ++j) {
                    if (s[i+j] != s[start+j]) {
                        good = false;
                    }
                }
                if (good) {
                    return i;
                }
            }
            starts.push_back(i);
        }
        return -1;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        for (int i = 0; i < 13; i++) {
            if (i & 1 && num > check[i]) {
                num -= check[i];
                ans.append(add[i]);
            } else {
                for (int j = 0; j < 4; j++) {
                    if (num >= check[i]) {
                        num -= check[i];
                        ans.append(add[i]);
                    } else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
private:
    int check[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string add[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
};

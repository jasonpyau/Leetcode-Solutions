class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int gal = 0;
        while (mainTank) {
            for (int i = 0; i < 5; i++) {
                if (!mainTank) {
                    return gal*10;
                }
                mainTank--;
                gal++;
            }
            if (additionalTank) {
                additionalTank--;
                mainTank++;
            }
        }
        return gal*10;
    }
};

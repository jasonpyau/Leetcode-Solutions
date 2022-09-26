int numberOfSteps(int num){
    int numSteps = 0;
    while (num) {
        num = (num%2 == 0) ? num/2 : num-1;
        numSteps++;
    }
    return numSteps;

}

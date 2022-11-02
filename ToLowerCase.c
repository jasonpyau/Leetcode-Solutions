char * toLowerCase(char * s){
    for (int i = 0; s[i] != NULL; i++) {
        if(s[i] >= 65 && s[i] <= 90) { //UPPERCASE ASCII BETWEEN 65 - 90
            s[i] = s[i] + 32; //A = 65, a = 97
        }
    }
    return s;
}

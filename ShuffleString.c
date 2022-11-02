char * restoreString(char * s, int* indices, int indicesSize){
    char *newString = (char*)malloc(indicesSize+1);
    for(int i = 0; i < indicesSize; i ++) {
        newString[indices[i]] = s[i];
    }
    newString[indicesSize] = '\0';
    return newString;
}

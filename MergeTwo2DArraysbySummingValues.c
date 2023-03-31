/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void checkLoopedThrough(int i, int length, bool* lt) {
    if (i == length)
        *lt = true;
}
int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes){
    const int MAX_SIZE = nums1Size+nums2Size;
    int** ans = (int**)calloc(MAX_SIZE, sizeof(int*));
    *returnColumnSizes = (int*)calloc(MAX_SIZE, sizeof(int));
    int i, i1, i2;
    bool lt1 = false, lt2 = false;
    for (i = 0, i1 = 0, i2 = 0; ; i++) {
        if (lt1 && lt2)
            break;
        int* col = (int*)calloc(2, sizeof(int));
        ans[i] = col;
        (*returnColumnSizes)[i] = 2;
        if (lt1 && !lt2) {
            col[0] = nums2[i2][0];
            col[1] = nums2[i2][1];
            i2++;
            checkLoopedThrough(i2, nums2Size, &lt2);
            continue;
        } else if (!lt1 && lt2) {
            col[0] = nums1[i1][0];
            col[1] = nums1[i1][1];
            i1++;
            checkLoopedThrough(i1, nums1Size, &lt1);
            continue;
        } 
        int n1Id = nums1[i1][0];
        int n1Val = nums1[i1][1];
        int n2Id = nums2[i2][0];
        int n2Val = nums2[i2][1];
        if (n1Id == n2Id) {
            col[0] = n1Id;
            col[1] = n1Val+n2Val;
            i1++;
            i2++;
            checkLoopedThrough(i1, nums1Size, &lt1);
            checkLoopedThrough(i2, nums2Size, &lt2);
        } else if (n1Id > n2Id) {
            col[0] = n2Id;
            col[1] = n2Val;
            i2++;
            checkLoopedThrough(i2, nums2Size, &lt2);
        } else {
            col[0] = n1Id;
            col[1] = n1Val;
            i1++;
            checkLoopedThrough(i1, nums1Size, &lt1);
        }
    }
    *returnSize = i;
    ans = (int**)realloc(ans, i*sizeof(int*));
    *returnColumnSizes = (int*)realloc(*returnColumnSizes, i*sizeof(int));
    return ans;
}

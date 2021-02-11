#include <stdio.h>
#include <stdlib.h>

int MaxSubArraySum(int size, int integer[]) {
//     int a[size];
    int tempsum = 0;
//     int sum[size] = 0;
    int maxsum = integer[0];
    for(int i=0,j=0; i < size-1; i++) {
        tempsum += integer[i];
        if(tempsum > maxsum) {
            maxsum = tempsum;
        }
        if(tempsum < 0) {
            tempsum = integer[i];
        }
  
    }
    if(tempsum < 0) {
        return 0;
    }
    return maxsum;
}


int main() {
    int size = 0;
    int a[100000];
    memset(a, 0, 100000);
    scanf("%d",&size);
    for(int i=0; i<size; i++) {
        scanf("%d",&a[i]);
    }
    MaxSubArraySum(size, a);
}
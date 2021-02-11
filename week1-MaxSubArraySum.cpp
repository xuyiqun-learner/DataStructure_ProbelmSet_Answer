#include <stdio.h>
#include <stdlib.h>

int MaxSubArraySum(int size, int integer[]) {
    int tempsum = 0;
    int maxsum = 0;
//     printf("initial maxsum is %d\n", maxsum);
    for(int i=1; i < size-1; i++) {
        tempsum += integer[i];
        if(tempsum > maxsum) {
            maxsum = tempsum;
        }
        else if(tempsum < 0) {
            tempsum = integer[i];
//             printf("new tempsum is %d\n", tempsum);
        }
    }

    return maxsum;
}


int main() {
    int size = 0;
    int a[100000] = {0};
//     memset(a, 0, 100000);
    scanf("%d",&size);
    for(int i=0; i<size; i++) {
        scanf("%d",&a[i]);
    }
    printf("%d",MaxSubArraySum(size, a));
    return 0;
}
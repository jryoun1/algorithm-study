#include <iostream>
#include <algorithm>

int main(void){
    // get height from user
    int arr[9], num = 0;
    for (int i = 0; i < 9; i++){
        scanf("%d", &num);
        arr[i] = num;
    }
    
    int sum = 0, cnt = 0, k = 0;
    while (1){
        int i, j;
        for (i = k + 1; i < 9; i++){
            sum = 0, cnt = 0;
            for (j = 0; j < 9; j++){
                if (j == k);
                else if (j == i);
                else{
                    sum += arr[j];
                    cnt++;
                }
            }

            if (sum == 100 && cnt == 7){
                // make k's, i's value zero and sort
                // and print sum from 2nd element which means
                // sum arr except k, i's index
                arr[k] = 0, arr[i] = 0;
                std::sort(arr, arr + 9);
                for (int i = 2; i < 9; i++){
                    printf("%d\n", arr[i]);
                }
                exit(0);
            }
        }
        k++;
    }
    return 0;
}
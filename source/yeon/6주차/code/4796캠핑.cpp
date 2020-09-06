// 백준 4796 캠핑
// cpp sovled by Greedy algorithm

#include <iostream>
int main(void){
    int L,P,V, cnt =1;
    do{
        scanf("%d %d %d", &L, &P, &V);
        if(L == 0 && P == 0 && V == 0) break;
        else{
            if(V % P < L)
                printf("Case %d: %d\n", cnt, (V/P)*L + V%P);
            else
                printf("Case %d: %d\n", cnt, (V/P)*L + L);
            cnt ++;
        }
    }while(L != 0 && P != 0 && V != 0);
    return 0;
}
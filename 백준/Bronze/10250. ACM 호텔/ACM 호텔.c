#include <stdio.h>
    int main(){
    int t, h, w, n;
    int x = 0, y = 1;
    scanf("%d", &t);
    while(t--){
    scanf("%d %d %d", &h, &w, &n);
        x = n%h;
        y = n/h + 1;
        if(x == 0){
          x = h;
          y = n/h;}
    printf("%d%02d\n", x, y); 
    }
    return 0;
}
#include <stdio.h>
#include <math.h>
#define PI 3.14
#define THIRST 20000

int main(){
    int h,r;
    float capacity;
    int num;

    scanf("%d %d",&h,&r);
    
    capacity = h * PI * pow(r,2);

    num = ceil(THIRST / capacity);

    printf("%d",num);

}
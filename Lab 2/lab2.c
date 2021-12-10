#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void shifting();
void draw_diamond();
void fibonacci_series();


void main(){

int flag;
printf("Please enter program number you want: 1: Shifting, 2: Draw Diamond and 3: Fibonacci Series \n");
scanf("%d", &flag);


switch(flag){
case 1:
    shifting();
    break;

case 2:
    draw_diamond();
    break;

case 3:
    fibonacci_series();
    break;

default:
    printf("Program is not found");
}

}


void shifting(){

uint8_t x;
int n;
char o;

printf("Please enter the number followed by the number of bits to shift and the shifting dirction (r/l) \n");
scanf("%d %d %c", &x, &n, &o);

printf("\noriginal number is: %d \n", x);


for (int i=1; i<=n;i++)
{

    if (o == 'r')
    {
        x = (x>>1) |(x << 7) ;

    }
    else if (o == 'l')
    {
        x = (x<<1) |(x >> 7) ;
    }
    printf("After shfiting by %d bit(s): %d \n", i, x);
}

}



void draw_diamond(){

printf("\n");

int i, j ;

for (j=0; j<=8; j++){

    for (i=0;i<=8; i++){

        if (((j==i+4) || (j==12-i) || (j==i-4) || (j==4-i))){
            printf("*");
        }
        else if(((j<=i+4) && (j<=12-i) && (j>=i-4) && (j>=4-i))){
            printf("*");
        }
        else{
            printf(" ");
        }
    }
    printf("\n");

}
}

void fibonacci_series(){

    int count;
    printf("Please enter the number of terms of fibonacci series you want (more than 2) \n");
    scanf("%d", &count);

    int n1, n2, temp;
    n1 =0 ; n2 = 1; temp =0;

    printf("\n %d %d ", n1, n2); //print 0,1 first

    for (int i = 2; i < count; i++)
    {
        temp = n1 + n2;
        n1 = n2;
        n2 = temp;
        printf("%d ", temp);        
    }
    
}
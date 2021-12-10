#include <stdio.h>
#include <stdlib.h>

void program1();
void program2();
void program3();
int main(){

int flag;
printf("Choose which program to use: [1, 2, 3] \n");
scanf("%d", &flag);


switch(flag){
case 1:
    program1();
    break;

case 2:
    program2();
    break;

case 3:
    program3();
    break;

default:
    printf("Program is not found");
}

return 0;
}


void program1()
{
float u, a, t;
printf("please enter the initial velocity, acceleration and time \n");
scanf("%f %f %f", &u, &a, &t);
float v = u + (a *t);
float s = u *t + 0.5 * a * t * t;
printf("The final velocity is: %.2f \n", v);
printf("The distance traversed is: %.2f \n", s);
}


void program2()
{

int n1, n2, n3;

printf("Enter three different integers \n");
scanf("%d %d %d", &n1, &n2, &n3);

int sum = n1+n2+n3;
int product = n1*n2*n3;
printf("Sum is: %d \n", sum);
printf("Average is: %d \n", sum/3);
printf("Product is: %d \n", product);

int min = n1;
int max = n1;

/*
int arr[3] = {n1, n2, n3};
for(int i=1; i<3; i++){

if (arr[i]<min){
    min = arr[i];
}
else if (arr[i]>max){

    max = arr[i];
}

}
*/

min = n1<n2 ? n1:n2;
min = min < n3 ? min : n3;

max = n1>n2 ? n1:n2;
max = max > n3 ? max : n3;


printf("Minimum is: %d \n", min);
printf("Maximum is: %d \n", max);
}


void program3()
{
int time;
printf("Please enter the the time is sec: \n");
scanf("%d", &time);

int hrs = time / 3600;
int mins = (time % (hrs * 3600)) / 60;
int secs = time % (hrs * 3600 + mins * 60);

printf("Time: %d  is equal to %d:%d:%d \n", time, hrs, mins, secs);

}


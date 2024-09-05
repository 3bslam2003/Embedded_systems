#include<stdio.h>
void main(){
	unsigned char x,y ;
	printf("enter the number = ");
	scanf("%hhu",&x);
	printf("enter the bits number you want to set = ");
	scanf("%hhu",&y);
	x|=1<<y;
	printf("the new number is %hhu",x);
}
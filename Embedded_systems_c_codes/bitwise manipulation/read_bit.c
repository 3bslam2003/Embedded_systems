#include<stdio.h>
void main(){
    unsigned char x, y;
    printf("enter your number = ");
    scanf("%hhu", &x);  // Use %hhu for unsigned char
    printf("enter the bits's number you want to read it = ");
    scanf("%hhu", &y);  // Use %hhu for unsigned char
    if (x>>y &1){
		printf("bit number %hhu is 1",y);
	}
	else 
		printf("bit number %hhu is 0",y);
      // Use %hhu for unsigned char
}
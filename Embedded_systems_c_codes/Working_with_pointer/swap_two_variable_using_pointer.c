#include<stdio.h>

void swap(int*ptr1,int*ptr2);
void main(){
	int x,y;
	printf("Enter X Value: ");
	scanf("%i",&x);
	fflush(stdin);
	printf("Enter Y Value: ");
	scanf("%i",&y);
	
	printf("Before    : X = %i, Y = %i\n",x,y);
	swap(&x,&y);
	printf("after     : X = %i, Y = %i\n",x,y);

	
}
void swap(int*ptr1,int*ptr2){
	*ptr1=*ptr1  ^  *ptr2;
	*ptr2=*ptr1  ^  *ptr2;
	*ptr1=*ptr1  ^  *ptr2;
}
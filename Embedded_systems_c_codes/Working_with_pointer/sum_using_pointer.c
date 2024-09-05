#include<stdio.h>




void sum(void*ptr1,void*ptr2,void*ptr3);


void main(){
	int num1=45,result;
	int num2= 62;
	sum(&num1,&num2,&result);
	printf("the result is %d",result);
	
}
void sum(void*ptr1,void*ptr2,void*ptr3){
	*(int*)ptr3=(*(int*)ptr1)+(*(int*)ptr2);
}
#include<stdio.h>

void swap(char**ptr1,char** ptr2 );
void main(){
	char x,y;
	char* ptr1=&x;
	char* ptr2=&y;
	printf("What Character first  pointer derefrences to: ");
	scanf("%c",&x); 
	fflush(stdin);
	printf("What Character second pointer derefrences to: ");
	scanf("%c",&y);	
	
	printf("[BEFORE]\n");
	printf("First  Pointer: %c\n", *ptr1);
	printf("Second Pointer: %c\n", *ptr2);
	swap(&ptr1,&ptr2);
	printf("[AFTER]\n");
	printf("First  Pointer: %c\n", *ptr1);
	printf("Second Pointer: %c", *ptr2);
}
void swap(char**ptr1,char** ptr2 ){
	char* temp=*ptr1;
	*ptr1=*ptr2;
	*ptr2=temp;
	
	
}
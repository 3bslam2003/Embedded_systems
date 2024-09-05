/*
Name   : Ahmed Mohammed abdelsalam 
course : Embedded systems 
subject: c-language\working_with_pointer\ read_stream_of_data_using_pointer


input =1503645 -----> ( 00000000 - 00010110 - 11110001 - 10011101)bin
               -----> (     0    -     22   -    241   -    157  )dec 

size= sizeof(int) ----> compiler dependent  (4-bytes)
step --------> byte by byte

*/
#include<stdio.h>
void func1(void*ptr,int size){
	unsigned char * ptr1=ptr;
	for(int i=0;i<size;i++){
		printf("the addres %p ---> % d\n",ptr1,*ptr1);
		ptr1++;
	}
}
void main(){
int x= 1503645;
	func1(&x,sizeof(x));
}
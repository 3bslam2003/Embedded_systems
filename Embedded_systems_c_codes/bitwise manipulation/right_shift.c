#include<stdio.h>
void main(){
	unsigned char x,y,i ;
	printf("enter the number = ");
	scanf("%hhu",&x);
	printf("enter number of shifting = ");
	scanf("%hhu",&y);
	for(i=0;i<y;i++){
		if(x&1){
			x=x>>1;
			x|=128;
		}
		else{
			x=x>>1;
			
		}
	}
	printf("the new number is %hhu",x);
}
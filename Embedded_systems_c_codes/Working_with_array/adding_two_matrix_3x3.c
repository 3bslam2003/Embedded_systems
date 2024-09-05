#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3


/* Function declaration to input, add and print matrix */
void matrixInput(int mat[][COLS]);
void matrixPrint(int mat[][COLS]);
void matrixAdd(int mat1[][COLS], int mat2[][COLS], int res[][COLS]);


int main()
{
    int mat1[ROWS][COLS], mat2[ROWS][COLS], res[ROWS][COLS];
    printf("\n-------------------------------------------------\n");
    // Input elements in first matrix
    printf("Enter elements in first matrix of size %dx%d: \n", ROWS, COLS);
   
matrixInput(mat1);
	/*calling the function of Mat1 input*/

    // Input element in second matrix
    printf("\nEnter elemetns in second matrix of size %dx%d: \n", ROWS, COLS);
   /*calling the function of Mat2 input*/
matrixInput(mat2);
    // add 2 matrix by calling function
matrixAdd(mat1,mat2,res);
    printf("\nSum of first and second matrix: \n");
    /*calling the function of */
matrixPrint(res);
    return 0;
}



void matrixInput(int mat[][COLS])
{
	printf("Enter The Element Of Your Matrix \n");
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			printf("Enter arr%d%d : ",i+1,j+1);
			scanf("%d",&mat[i][j]);
		}
	}
}




void matrixPrint(int mat[][COLS])
{
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}


void matrixAdd(int mat1[][COLS], int mat2[][COLS], int res[][COLS])
{
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			res[i][j]=mat1[i][j]+mat2[i][j];
		}
	}
	
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE  5


void add(int m1[SIZE][SIZE], int m2[SIZE][SIZE],int result[SIZE][SIZE]){
    //Add function
    for(int i = 0; i < SIZE; i++){
        //Row loop
        for(int k = 0; k < SIZE; k++){
            //This loop will get us a value if we index with i and k
            //Add m1 and m2 at index i,k 
            result[i][k] = m1[i][k] + m2[i][k];
        }
    }
}

void multiply(int m1[SIZE][SIZE], int m2[SIZE][SIZE],int result[SIZE][SIZE]){
    //multipy function
    //For loop that makes a new array 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }
    //Loops through the rows
    for(int i = 0; i < SIZE; i++){
        //Gets values in a row and col
        for(int j = 0; j < SIZE; j++){
            //Muiltipy row over m1 with the values in the colums of m2
            for(int k = 0; k < SIZE; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
        
    }
}

void transpose(int m1[SIZE][SIZE], int result[SIZE][SIZE]){
    //Loops over each row
    for(int i = 0; i < SIZE; i++){
        //This loop allows access to the values in the rows
        for(int j = 0; j < SIZE; j++){
            //Flip how the array is orderd 
            result[j][i] = m1[i][j];
        }
    }
}

void print_matrix(int m1[SIZE][SIZE]) {
    //This function prints arrays with rows and cols listed
    printf("\n");
    //Space to aline with rows
    printf("      ");
    for (int j = 0; j < SIZE; j++) {
        //This loop prints all of the columns 
        printf("COLUMN %2d ", j);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        // This loop prints the rows
        printf("ROW %2d ", i);
        for (int j = 0; j < SIZE; j++) {
            //This loop prints all values from this row
            if(j == 0){
                //This if statment is an edge case for lining up the first values
                printf("%4d ", m1[i][j]);
            }
            //Normal case 
            else if(j != 0){
                printf("%9d ", m1[i][j]); 
            }
        }
        printf("\n"); 
    printf("\n");
    }
}


int main(){
    //Matrix 1
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    //Matrix 2
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
 

    //Use new array to get output from function
    int sum[SIZE][SIZE];
    //Call function 
    add(m1, m2,sum);
    printf("Sum of matrices:\n");
    print_matrix(sum);

    //Use new array to get output from function
    int product[SIZE][SIZE];
    //In the details for this lab it says we should define all functions to use the constant SIZE
    //However, it also says to handle invaild matrix operations like rows not matching columns
    //I don't see how that would ever happen if we have to use size for both matrix rows and columns
    multiply(m1, m2,product);
    printf("Product of matrices:\n");
    print_matrix(product);
    
    

    //Use new array to get output from function
    int transpose_result[SIZE][SIZE];
    transpose(m1,transpose_result);
    printf("Transpose of first matrix:\n");
    print_matrix(transpose_result);

    return 0;

}
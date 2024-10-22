#include<stdio.h>
#include<malloc.h>
#include<locale.h>

int input_matrix(float **matrix, int size){
    for(int i=0; i<size; i++){
        for( int j=0; j<size; j++){
            scanf("%f", &matrix[i][j]);
        }
    }
    return;
}

void output_matrix(float **matrix, int size){
    for( int i=0; i< size; i++){
        for (int j=0; j<size; j++){
            printf("%f ",matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

float matrix_max(){
    return;
}

float matrix_min(){
    return;
}

void main(){
    return;
}
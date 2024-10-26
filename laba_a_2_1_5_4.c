#include<stdio.h>
#include<malloc.h>
#include<locale.h>

int input_matrix(float **matrix, int size){
    for(int i=0; i<size; i++){
        for( int j=0; j<size; j++){
            if(!scanf("%f", &matrix[i][j])){
                return 0;
            };
        }
    }
    return 1;
}

void output_matrix(float **matrix, int size){
    for( int i=0; i< size; i++){
        for (int j=0; j<size; j++){
            printf("%4.1f ",matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

void free_mem(float **matrix, int size){
    int i;
    for (i=0; i<size; i++){
        free(matrix[i]);
    }
    free (matrix);
    return;
}

float matrix_max(float **matrix, int size, int number_str, int number_column){
    float max=matrix[number_str][number_column];
    int i, j;
    for (i=number_str; i< size; i++){
        for (j=number_column; j< size; j++){
            if (matrix[i][j]>max){
                max=matrix[i][j];
            }
        }
    }
    return max;
}

float matrix_min(float **matrix, int size, int number_str, int number_column){
    float min=matrix[number_str][number_column];
    int i, j;
    for (i=number_str; i<size; i++){
        for(j=number_column; j <size;j++){
            if (matrix[i][j]<min){
                min=matrix[i][j];
            }
        }

    }
    return min;
}

void main(){
    float **matrix_A, **matrix_B;
    int i,j,size;
    setlocale(0,"");
    printf("Введите размер матрицы: ");

    if(!scanf("%d", &size)){
        printf("ERROR: Размер матрицы может быть только натуральным числом");
        return;
    }
    if(size < 0){
        printf("ERROR: Размер матрицы не может быть меньше 0");
        return;
    }

    matrix_A=(float**)malloc(size*sizeof(float*));
    for (i=0; i<size; i++){
        matrix_A[i]= (float*)malloc(size*sizeof(float));
    }
    matrix_B=(float**)malloc(size*sizeof(float*));
    for (i=0; i<size; i++){
        matrix_B[i]= (float*)malloc(size*sizeof(float));
    }
    printf("Введите матрицу: \n");
    if(!input_matrix(matrix_A,size)){
        printf("ERROR: Матрица может состоять только из вещественных чисел");
        return;
    }

    for(i=0; i < size; i++){
        for (j=0; j < size; j++){
            matrix_B[i][j] = matrix_max(matrix_A, size, i, j) - matrix_min(matrix_A, size, i, j);

        }
    }

    printf("Матрица А:\n");
    output_matrix(matrix_A, size);
    printf("Матрица B:\n");
    output_matrix(matrix_B, size);

    free_mem(matrix_A, size);
    free_mem(matrix_B, size);

    return;
}
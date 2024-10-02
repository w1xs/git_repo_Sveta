#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int main(){
    char* posled;
    int posled_len, first_star, second_star, count, is_posled_len_number;

    setlocale(0,"");
    printf("Введите длину последовательности: ");
    is_posled_len_number = scanf("%d", &posled_len);
    if(is_posled_len_number){
        if(posled_len >= 0){
            posled = (char*)malloc(posled_len * sizeof(char));
            printf("Введите последовательность: ");
            for(int i = 0; i <= posled_len; i++){
                scanf("%c",&posled[i]);
            }

            first_star = -1;
            second_star = -1;
            count = 0;
            
            while(count < posled_len && count < 100){
                if(posled[count] == '*'){
                    if(first_star == -1){
                        first_star = count;
                    }
                    else{
                        second_star = count;
                        break;
                    }
                }
                count++;

            }
            if(first_star != -1 && second_star != -1){
                printf("Расстояние между двумя первыми звездочками: %d", second_star-first_star-1);        
            }
            else{
                printf("В последоватльности нет двух звездочек");
            }
        }
        else{
            printf("ERROR: Длина последовательности не может быть отрицательной");
        }   
    }
    else{
        printf("ERROR: Длина последовательности может быть только целым числом");
    }
    return 0;
}

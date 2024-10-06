#include <stdio.h>
#include <malloc.h>
#include <locale.h>

int main(){
    char* posled;
    int posled_len, first_star, second_star, count, is_posled_len_number;

    setlocale(0,"");
    printf("Введите длину последовательности: ");

    // flag = 1;
    // while(flag){
    //     scanf("%c", &char_from_len);
    //     number_in_ASCII = (int)char_from_len;
    //     if(number_in_ASCII == 10){
    //         flag = 0;
    //     }
    //     else{
    //         if (number_in_ASCII < 48 || number_in_ASCII > 58){
    //             flag = 0;
    //             printf("ERROR: Введен не верный символ");
    //             return 1;                                
    //         }
    //     }
    // }
    // Считываем все символы, которые ввел пользователь по одному, проверяем каждый из них по ASCII.
    // Если до Светы докапаются, нужно будет допилить запись подтвержденных символов в строку и в случае, если 
    // все символы подходят по условию, эта строка должна собираться в инт. Реализацию придумай на месте.
    // Самый простой способ скорее всего бежать по проверенной строке от конца к началу и прибавлять I символ к 
    // заранее подготовленному числу, умножая на его разряд. Ну там "123" = 3*1 + 2*10 + 1*100 = 123 (int)

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
            
            while(count <= posled_len && count < 100){
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
        printf("ERROR: Длина последовательности может быть только числом");
    }
    return 0;
}

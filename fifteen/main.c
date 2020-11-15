//
//  main.c
//  fifteen
//
//  Created by Tatyana on 08.11.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>





int * findInField(int arrField[4][4], int needle){
    
    int *position = malloc(2 * sizeof(int));
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if (arrField[i][j] == needle){
                 position[0] = i;
                position[1] = j;
                return  position;
            }
        }
    }
    
   position[0] = -1;
   position[1] = -1;
   return  position;
};

int isInField(int arrField[4][4], int needle){
    int * position = findInField(arrField, needle);

    if(  *position == -1){
        return 0;
    } else {
        return 1;
    }

}

void randomFill(int arrField[4][4]){
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if( i==3 && j==3){
                break;
            }
            int number;
            do {
                number = 1 + rand()%15;
            } while(isInField(arrField, number) == 1);
                
            arrField[i][j] = number;
        }
    }
};


int isPossibleToWin(arrField[4][4]){
    int line[15];
    int count = 0;
    for(int i = 0; i < 4; i++){
        if (i%2==0){
            for(int j = 0; j < 4; j++){
                if (i==3 && j==3){
                    break;
                }
                line[count] = arrField[i][j];
                count++;
            }
        } else {
            for(int j = 3; j >= 0; j--){
                if (i==3 && j==3){
                    break;
                }
                line[count] = arrField[i][j];
                count++;
            }
        }
    }
    
    int sum=0;
    for(int k = 0; k <= 15; k++){
        for(int m = k+1; m < 15; m++){
            if(line[k]>line[k+m]){
                sum++;
            }
        }
    }
    
    if (sum%2==0){
        return 1;
    } else {
        return 0;
    }
};

void render(arrField[4][4]){
    printf("------------------------- \n");
    for(int i = 0; i < 4; i++){
        printf("| %3d | %3d | %3d | %3d | \n", arrField[i][0], arrField[i][1], arrField[i][2], arrField[i][3]);
        printf("------------------------- \n");
    }
}

void makeMove(arrField[4][4]){
    int move;
    scanf("%d", &move);

   int * position = findInField(arrField, move);

   int i = *position;
   int j = *(position+ 1);
    
    
   int * positionZero = findInField(arrField, 0);

   int zeroI = *positionZero;
   int zeroJ = *(positionZero + 1);
     
    int isMovePossible = 0;
    
    if(
       (i == zeroI && (abs(j - zeroJ) == 1))
        || (j == zeroJ && (abs(i - zeroI) == 1))
       ){
        isMovePossible = 1;
    }
    if(isMovePossible){
        arrField[zeroI][zeroJ] = move;
        arrField[i][j] = 0;
    } else {
        printf("Помилка. Цей хід суперечить правилам гри. \n");
    }
}

void runGame(){
    srand(time(NULL));
    int arrField[4][4]= {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    printf("1 \n");
    
    do {
        randomFill(arrField);
    } while( isPossibleToWin(arrField) == 0);
    
    printf("9 \n");
    printf("Будь ласка, зробіть свій хід \n");
   
    do{
        render(arrField);
        makeMove(arrField);
    } while (1==1);
}

void rules(){
    printf("Rules of game \n");
}

void about(){
    printf("Tetiana Pykulenko \n");
}

void menu(){
    printf("1. Грати \n");
    printf("2. Правила гри \n");
    printf("3. Інформація про розробника \n");
    printf("4. Вихід \n\n");
    
    printf("Введіть номер пункту меню, до якого хочете перейти: \n");
    int choice;
    scanf("%d", &choice);
    
    
    switch (choice) {
        case 1:
            runGame();
            break;
        case 2:
            rules();
            menu();
            break;
        case 3:
            about();
            menu();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Введені не коректні дані. Спробуйте ще раз.\n");
            menu();
            break;
    }
}

int main(int argc, const char * argv[]) {
    menu();
    
    return 0;
}

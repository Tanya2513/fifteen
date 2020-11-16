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
#include <string.h>   //Для memset

void cls()
{
    int x;
    for ( x = 0; x < 100; x++ )
    {
        printf("\n");
    }
}

void render(int width, int height, int arrField[height][width]){
    printf("------------------------- \n");
    for(int w = 0; w < height; w++){
        printf("|");
        for (int h = 0; h< width; h++) {
            printf(" %3d |", arrField[h][w]);
        }
        printf("\n");
        printf("------------------------- \n");
    }
}



int * findInField(int width, int height, int arrField[width][height], int needle){
//    printf("findInField \n");
    int *position = malloc(2 * sizeof(int));
    
   
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            if (arrField[w][h] == needle){
                position[0] = w;
                position[1] = h;
                return  position;
            }
        }
    }
    
   position[0] = -1;
   position[1] = -1;
   return  position;
};

int isInField(int width, int height, int arrField[width][height], int needle){
//    printf("isInField \n");
    int * position = findInField(width, height, arrField, needle);

    if(  *position == -1){
        return 0;
    } else {
        return 1;
    }

}

void randomFill(int width, int height, int arrField[width][height]){
    memset( arrField, 0, width*height*sizeof(int) );
    
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            if( h== height -1 && w== width -1){
                arrField[h][w] = 0;
                break;
            }
            int number;
            
            render(width, height, arrField);

            do {
                number = 1 + rand()%((width*height)-1);
                printf("Number: %d ", number);
            } while(isInField(width, height, arrField, number) == 1);
                
            arrField[h][w] = number;
        }
    }
};


int isPossibleToWin(int width, int height, int arrField[width][height]){
    
    printf("isPossibleToWin \n");
    int e = 0;
    int numbersCount = width*height-1;
    int *line = malloc(numbersCount * sizeof(int));
    
    int count = 0;
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
                if (w==width-1 && h==height-1){
                    // тут находится 0
                    e = w+1;
                    break;
                }
                line[count] = arrField[w][h];
                count++;
        }
    }
    
    int sum=0;
    for(int k = 0; k <= numbersCount; k++){
        for(int m = k+1; m < numbersCount; m++){
            if(line[k]>line[k+m]){
                sum++;
            }
        }
    }

    
    if ((sum+e)%2==0){
        return 1;
    } else {
        return 0;
    }
};


void makeMove(int width, int height, int arrField[width][height]){
    int move;
    scanf("%d", &move);

   int * position = findInField(width, height, arrField, move);

   int i = *position;
   int j = *(position+ 1);
    
    
   int * positionZero = findInField(width, height, arrField, 0);

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
        cls();

        printf("Помилка. Цей хід суперечить правилам гри. \n");
    }
}

void runGame(){
    srand(time(NULL));
    int width = 5;
    int height = 5;

    int arrField[width][height];
  
    printf("2 \n");
    
    do {
        randomFill(width, height, arrField);
    } while( isPossibleToWin(width, height, arrField) == 0);
    
    printf("9 \n");
    printf("Будь ласка, зробіть свій хід \n");
   
    do{
        render(width, height, arrField);
        makeMove(width, height, arrField);
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
    cls();
    
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

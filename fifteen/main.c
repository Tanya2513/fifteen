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

void drawLine(int width){
    printf("-");
    for(int w = 1; w <= width; w++){
        printf("-------");
    }
    printf("\n");
};


void render(int width, int height, int arrField[height][width]){
    drawLine(width);
    for(int w = 0; w < height; w++){
        printf("|");
        for (int h = 0; h< width; h++) {
            if(arrField[h][w] != 0){
                printf(" %3d  |", arrField[h][w]);
            } else {
                printf("      |");
            }
        }
        printf("\n");
        drawLine(width);
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
            if( h == height -1 && w == width -1){
                arrField[w][h] = 0;
                break;
            }
            int number;

            do {
                number = 1 + rand()%((width*height)-1);
            } while(isInField(width, height, arrField, number));
                
            arrField[w][h] = number;
        }
    }
};


int isPossibleToWin(int width, int height, int arrField[width][height]){
    
    int e = height;
    int numbersCount = width*height-1;
    int *line = malloc(numbersCount * sizeof(int));
 
    int count = 0;
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
                if (w==width-1 && h==height-1){
                    // тут находится 0
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

int isFinishPosition(int width, int height, int arrField[width][height]){
    
    int counter = 0;
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            if( h== height -1 && w== width -1){
                if (arrField[w][h] != 0){
                    return 0;
                }
                break;
            }
            
            counter++;
            if(counter!=arrField[w][h]){
                return 0;
            }
        }
    }
    
    return 1;
};

void runGame(){
    srand(time(NULL));
    int width = 0;
    int height = 0;
    do{
       printf("Введите размерность поля игры (3,4,5):\n ");
       scanf("%d", &width);
       height = width;
    } while (width < 3);
    

    int arrField[width][height];
    
    do {
        randomFill(width, height, arrField);
    } while( isPossibleToWin(width, height, arrField) == 0);
    
    printf("Будь ласка, зробіть свій хід \n");
    int isFinish = 0;
    do{
        render(width, height, arrField);
        makeMove(width, height, arrField);
        isFinish = isFinishPosition(width, height, arrField);
    } while (1==1 && isFinish != 1);
    
    printf("Поздравляю! Игра успешно пройдена! :) \n");

};

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
            menu();
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

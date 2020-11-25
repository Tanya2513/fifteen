//
//  render.c
//  fifteen
//
//  Created by Tatyana on 24.11.2020.
//

#include "render.h"

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

//
//  menu.c
//  fifteen
//
//  Created by Tatyana on 24.11.2020.
//
#include <stdlib.h>
#include "menu.h"
#include "cls.h"
#include "game.h"
#include "rules.h"
#include "about.h"


void menu(){
    printf("ГРА \"П'ЯТНАДЦЯТЬ\" \n\n");
    printf("1. Правила гри \n");
    printf("2. Грати \n");
    printf("3. Інформація про розробника \n");
    printf("4. Вихід \n\n");
    
    printf("Введіть номер пункту меню, до якого хочете перейти: \n");
    int choice;
    scanf("%d", &choice);
    cls();
    
    switch (choice) {
        case 1:
            rules();
            menu();
            break;
        case 2:
            runGame();
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

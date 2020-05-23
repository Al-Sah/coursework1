//
// Created by al_sah on 23.05.20.
//

#ifndef ISE_USER_MENUS_H
#define ISE_USER_MENUS_H

#include "class_main_system.h"
#include <iostream>
#include <map>



typedef void(*user_function)(main_system & sys);

typedef struct _MenuItem {
    const char *caption = nullptr;
    const char *cmd = nullptr;
    user_function func = nullptr;
    _MenuItem *next = nullptr;
    const char * description = NULL;
} MenuItem;


void draw_menu(std::string caption, MenuItem * items, const char *description, main_system &sys);

void boom(void *) ;
void baam(void *) ;
void tram(void *) ;

void next_menu(void *);










#endif //ISE_USER_MENUS_H

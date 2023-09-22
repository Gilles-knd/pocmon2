//
// Created by Admin on 22/09/2023.
//

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "../include/header.h"

void initPlayer(){

    Player *player=malloc(sizeof(Player));
    printf("Enter your name: ");
    char *name=malloc(sizeof(char)*100);
    scanf("%s",name);
    printf("Welcome %s\n",name);
    player->name=name;


}


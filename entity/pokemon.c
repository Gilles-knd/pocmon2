//
// Created by Admin on 22/09/2023.
//

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "../include/header.h"
//
// Created by Admin on 21/09/2023.
//


Pokemon *newPokemon(char *name, int pv, int attack, int defense, int speed, char * type){
    Pokemon* pokemon = malloc(sizeof(Pokemon));
    pokemon->name= malloc(sizeof (char)* (strlen(name)+1));
    pokemon->pv=pv;
    pokemon->attack=attack;
    pokemon->defense=defense;
    pokemon->speed=speed;
    pokemon->type=malloc(sizeof (char)* (strlen(type)+1));
    strcpy(pokemon->type,type);
    strcpy(pokemon->name,name);
    pokemon->maxHeal=pv;
    return pokemon;
}

void deletePokemon(Pokemon *pokemon){
    free(pokemon->name);
    free(pokemon);
}

//add a function to display a pokemon
void displayPokemon(Pokemon *pokemon){
    printf("Name: %s\n",pokemon->name);
    printf("PV: %d\n",pokemon->pv);
    printf("Attack: %d\n",pokemon->attack);
    printf("Defense: %d\n",pokemon->defense);
    printf("Speed: %d\n",pokemon->speed);
    printf("Type: %s\n",pokemon->type);
}


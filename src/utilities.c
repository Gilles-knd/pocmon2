////
//// Created by Admin on 22/09/2023.
////
////
//// Created by Admin on 21/09/2023.
////
////Here yoy can add all the extra functions you need
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/header.h"

Pokemon * readlinecsv(char *line){
    Pokemon *pokemon=malloc(sizeof(Pokemon));
    pokemon->name=malloc(sizeof(char)*100);
    pokemon->type=malloc(sizeof(char)*100);
    char *token;
    token=strtok(line,";");
    strcpy(pokemon->name,token);
    token=strtok(NULL,";");
    pokemon->pv=atoi(token);
    token=strtok(NULL,";");
    pokemon->attack=atoi(token);
    token=strtok(NULL,";");
    pokemon->defense=atoi(token);
    token=strtok(NULL,";");
    pokemon->speed=atoi(token);
    token=strtok(NULL,";");
    strcpy(pokemon->type,token);
    return pokemon;
}

void addPokemon(AllPokemon *allPokemon,Pokemon *pokemon){
    allPokemon->pokemon=realloc(allPokemon->pokemon, sizeof(Pokemon)*(allPokemon->size+1));
    allPokemon->pokemon[allPokemon->size]=*pokemon;
    allPokemon->size++;
}


AllPokemon *readcsv (char *fileName){
    FILE *file= fopen(fileName,"r");
    if(file==NULL){
        printf("Error while opening the file\n");
        exit(1);
    }
    AllPokemon *allPokemon=malloc(sizeof(AllPokemon));
    allPokemon->size=0;

    allPokemon->pokemon=malloc(sizeof(Pokemon));

    char buffer[100];
    fgets(buffer,100,file);
    while(!feof(file)){
        fgets(buffer,100,file);
        addPokemon(allPokemon,readlinecsv(buffer));
    }
    fclose(file);
    return allPokemon;

}

//

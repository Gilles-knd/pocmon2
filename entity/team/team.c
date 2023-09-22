//
// Created by Admin on 22/09/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../include/header.h"



Team *newTeam(){
    Team *team = malloc(sizeof(team));
    team->pokeTeam=malloc(sizeof(Pokemon*)*6);
    team->pokeTeam[0]=pokestart();
    return team;
}


void addPokemonTeam(Team *team,Pokemon *pokemon){
    team->pokeTeam[team->size]=pokemon;
    team->size++;
}

void deleteTeam(Team *team){
    free(team);
}


void displayPokemonTeam(Team *team){
    for(int i=0;i<team->size;i++){
        printf("%s\n",team->pokeTeam[i]->name);
        printf("%d\n",team->pokeTeam[i]->pv);
        printf("%d\n",team->pokeTeam[i]->attack);
        printf("%d\n",team->pokeTeam[i]->defense);
        printf("%d\n",team->pokeTeam[i]->speed);
        printf("%s\n",team->pokeTeam[i]->type);
    }
}
//
Pokemon *pokestart(){

    AllPokemon *allPokemon=readcsv("../ressource/poCmon.csv");

    printf("Choose your starter pokemon:\n");
    printf("1. Bulbizarre\n");
    printf("2. Salameche\n");
    printf("3. Carapuce\n");

    Pokemon *pokemon;

    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            pokemon=newPokemon(allPokemon->pokemon[0].name,allPokemon->pokemon[0].pv,allPokemon->pokemon[0].attack,allPokemon->pokemon[0].defense,allPokemon->pokemon[0].speed,allPokemon->pokemon[0].type);
            return pokemon;

        case 2:
            pokemon=newPokemon(allPokemon->pokemon[1].name,allPokemon->pokemon[1].pv,allPokemon->pokemon[1].attack,allPokemon->pokemon[1].defense,allPokemon->pokemon[1].speed,allPokemon->pokemon[1].type);
            return pokemon;
        case 3:
            pokemon=newPokemon(allPokemon->pokemon[2].name,allPokemon->pokemon[2].pv,allPokemon->pokemon[2].attack,allPokemon->pokemon[2].defense,allPokemon->pokemon[2].speed,allPokemon->pokemon[2].type);
            return pokemon;
        default:
            printf("Invalid choice\n");
            pokestart();
    }
}

Pokemon *randompok(){
    AllPokemon *allPokemon=readcsv("../ressource/poCmon.csv");
    int random=rand()%allPokemon->size;
    Pokemon *pokemon=newPokemon(allPokemon->pokemon[random].name,allPokemon->pokemon[random].pv,allPokemon->pokemon[random].attack,allPokemon->pokemon[random].defense,allPokemon->pokemon[random].speed,allPokemon->pokemon[random].type);
    return pokemon;
}

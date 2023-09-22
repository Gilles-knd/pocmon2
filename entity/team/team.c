//
// Created by Admin on 22/09/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/header.h"



Team *newTeam(){

    Team *team = malloc(sizeof(Team)*team->size);
    team->size=6;
    return team;
}


void addPokemonTeam(Team *team,Pokemon *pokemon){
    team->pokeTeam[team->size]=*pokemon;
    team->size++;
}

void deletePokemonTeam(Team *team){
    free(team);
}


void displayPokemonTeam(Team *team){
    for(int i=0;i<team->size;i++){
        printf("%s\n",team->pokeTeam[i].name);
        printf("%d\n",team->pokeTeam[i].pv);
        printf("%d\n",team->pokeTeam[i].attack);
        printf("%d\n",team->pokeTeam[i].defense);
        printf("%d\n",team->pokeTeam[i].speed);
        printf("%s\n",team->pokeTeam[i].type);
    }
}
//
//void starterpack(Team *team){
//
//    AllPokemon *allPokemon=readcsv("../ressource/poCmon.csv");
//
//    printf("Choose your starter pokemon:\n");
//    printf("1. Bulbizarre\n");
//    printf("2. Salameche\n");
//    printf("3. Carapuce\n");
//
//    int choice;
//    scanf("%d",&choice);
//    switch(choice){
//        case 1:
//            addPokemonTeam(allPokemon->pokemon,allPokemon->pokemon[1]);
//            break;
//        case 2:
//            addPokemonTeam(team,newPokemon(allPokemon->pokemon[1].name,&allPokemon->pokemon[1].pv,&allPokemon->pokemon[1].attack,&allPokemon->pokemon[1].defense,&allPokemon->pokemon[1].speed,allPokemon->pokemon[1].type));
//            break;
//        case 3:
//            addPokemonTeam(allPokemon->team,newPokemon("Carapuce",44,48,65,43,"Water"));
//            break;
//        default:
//            printf("Invalid choice\n");
//            break;
//    }
//
//}

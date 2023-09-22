//
// Created by Admin on 22/09/2023.
//
//put all your struct here



#ifndef PO_C_MON_STRUCT_H
#define PO_C_MON_STRUCT_H

typedef struct Pokemon{
    char* name;
    int pv;
    int attack;
    int defense;
    int speed;
    char * type;
}Pokemon;

typedef struct AllPokemon{
    Pokemon *pokemon;
    int size;
}AllPokemon;

int verifLife(int pvPokemon);

typedef struct Team{
    Pokemon pokeTeam[6];
    int size;
}Team;

typedef struct Player{
    char *name;
    Team *team;
    int nbPoke;
}Player;

AllPokemon *readcsv (char *fileName);
#endif //PO_C_MON_STRUCT_H
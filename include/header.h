//
// Created by Admin on 22/09/2023.
//
//put all your struct here



#ifndef POCMON_STRUCT_H
#define POCMON_STRUCT_H

typedef struct Pokemon{
    char* name;
    int pv;
    int attack;
    int defense;
    int speed;
    char * type;
    int maxHeal;
}Pokemon;

typedef struct AllPokemon{
    Pokemon *pokemon;
    int size;
}AllPokemon;

int verifLife(int pvPokemon);

typedef struct Team{
    Pokemon **pokeTeam;
    int size;
}Team;

typedef struct Player{
    char *name;
    Team *team;
    int nbPoke;
}Player;
AllPokemon *readcsv (char *fileName);
Pokemon *newPokemon(char *name, int pv, int attack, int defense, int speed, char * type);
Pokemon *pokestart();
void addPokemonTeam(Team *team,Pokemon *pokemon);
void deleteTeam(Team *team);
void displayPokemonTeam(Team *team);
Team *newTeam();
Pokemon *randompok();
int playerTurn(Pokemon* teamPokemon, Pokemon* randomPokemon);

#endif //PO_C_MON_STRUCT_H
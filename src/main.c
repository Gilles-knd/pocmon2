#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/header.h"


typedef struct {
    char* name;
} Objet;

int verifLife(int pvPokemon){
    if(pvPokemon<=0){
        return 1;
    }else{
        return 0;
    }
}


int speedest(Pokemon pokemon1, Pokemon pokemon2) {
    if (pokemon1.speed > pokemon2.speed) {
        return 1;
    } else {
        return 0;
    }
}

int playerTurn(Pokemon* teamPokemon, Pokemon* randomPokemon){
    int choice;
    int verifyLife;
    printf("1: attaquer  2: sac \n3: equipe 4:fuir \n");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("%s attaque %s \n ", teamPokemon->name, randomPokemon->name);
        randomPokemon->pv -= (teamPokemon->attack-randomPokemon->defense);
        printf("il reste %d pv a %s \n", randomPokemon->pv,randomPokemon->name);

        if (verifyLife == 1) {
            printf("%s est mort \n", randomPokemon->name);
        }
        return 0;
    }
    if(choice == 2){
        int choiceBag;
        Objet *potion = malloc(sizeof (Objet));
        potion->name = malloc(sizeof(char)*10);
        strcpy(potion->name,"potion");

        Objet *pokeball = malloc(sizeof (Objet));
        pokeball->name = malloc(sizeof(char)*10);
        strcpy(pokeball->name,"pokeball");
        printf("1: %s  2; %s \n", pokeball->name, potion->name);
        scanf("%d",&choiceBag);
        if(choiceBag == 1){
            printf("je lance une pokeball\n");
        }
        if(choiceBag == 2){
            printf("j'utilise une popo , %d \n", teamPokemon->pv);
            if((teamPokemon->pv + (teamPokemon->maxHeal/2)) > teamPokemon->maxHeal){
                teamPokemon->pv =teamPokemon->maxHeal;
            }else{
                teamPokemon->pv += teamPokemon->maxHeal/2;
            }
            printf("%s a regagner %d, il a maintenant %d pv\n", teamPokemon->name, (teamPokemon->maxHeal)/2, teamPokemon->pv);
        }
        return 0;

    }
    if(choice == 4){
        printf("vous essayez de fuir !\n");
        int randomInt = rand()%2;
        if(randomInt == 0){
            printf("Vous n'arrivez pas a fuir car vous avez de l'asthme ! \n");
        }else{
            printf("Vous fuyiez avec bravour et rapidite\n");
            return 2;
        }
    }
}

void ennemyTurn(Pokemon *randomPokemon, Pokemon *teamPokemon){
    printf("%s attaque %s \n ", randomPokemon->name, teamPokemon->name);
    teamPokemon->pv -= (randomPokemon->attack-teamPokemon->defense);
    printf("il reste %d pv a %s \n", teamPokemon->pv,teamPokemon->name);

}







//main
int random_int()
{
    return rand()%3;
}

char** generateMap(){
    char **table;
    table= malloc(sizeof(char*)*30);
    for(int i=0;i<30;i++){
        table[i]= malloc(sizeof(char)*25);
        for(int j=0;j<25;j++){
            int random=random_int();
            //printf("%d - %d\n", i, j);
            //printf("random :%d\n",random);
            if(random==0){
                table[i][j]=' ';
            }
            else if(random==1){
                table[i][j]='*';
            }
            else if(random==2){
                table[i][j]='|';
            }
            else{
                printf("erreur random");
            }
        }
    }
    //printf("table\n");
    return table;
}

void showMap(char **table){
    printf("\n");
    for(int i=0;i<30;i++){
        for(int j=0;j<25;j++){
            //printf("r:%d, c:%d\n",i,j);
            //printf("%d\n",table[i][j]);
            printf("%c",table[i][j]);
            if(j==24){
                printf("\n");
            }
        }
    }
    printf("\n");
}

char** putUserInMap(char **table){
    int ok=0;
    int row =0;
    int columns =0;
    //printf("1.1\n");
    while(ok!=1){
        row= rand()%29;
        if(row==0){
            row=1;
        }
        columns= rand()%24;
        if(columns==0){
            columns=1;
        }
        //printf("row:%d, column:%d\n",row,columns);
        if(table[row-1][columns]!='|'){
            //printf("1.2\n");
            //Verification utilisateur bloqué
            if((table[row-1][columns]==' ')||(table[row-1][columns]=='*')
                                             &&((table[row][columns+1]==' ')||(table[row][columns+1]=='*'))
                                             &&((table[row+1][columns]==' ')||(table[row+1][columns]=='*'))
                                             &&((table[row][columns-1]==' ')||(table[row][columns-1]=='*')))
            {
                ok=1;
            }
        }
    }
    //printf("1.3\n");
    table[row][columns]='U';

    return table;
}

int *searchUser(char **table){
    int *pos= malloc(sizeof(int)*2);
    for(int i=0;i<30;i++){
        for(int j=0;j<25;j++){
            if(table[i][j]=='U'){
                pos[0]=i;
                pos[1]=j;
                return pos;
            }
        }
    }
    return pos;
}

int startGame(){
    int nRandonNumber = rand()%9;

    if(nRandonNumber== 0 || nRandonNumber==1 ) {
        return 1;
    }
}

char** moveUserInMap(char **table,int move){
    int *pos=searchUser(table);
    //printf("pos:%d, pos1:%d\n",pos[0],pos[1]);
    switch ( move ) {
        case 8://Haut
            //verifie si il n'est pas à la bordure et
            if(table[pos[0]+1][pos[1]]=='|'||(pos[0]==0)){
                return NULL;
            }
            else if(table[pos[0]+1][pos[1]]=='*'){
                startGame();
                table[pos[0]][pos[1]]=' ';
                table[pos[0]-1][pos[1]]='U';
            }
            table[pos[0]][pos[1]]=' ';
            table[pos[0]-1][pos[1]]='U';
            break;
        case 6://Right
            if(table[pos[0]][pos[1]+1]=='|'||(pos[1]==24)){
                return NULL;
            }
            else if(table[pos[0]][pos[1]+1]=='*'){
                startGame();
                table[pos[0]][pos[1]]=' ';
                table[pos[0]][pos[1]+1]='U';
            }
            table[pos[0]][pos[1]]=' ';
            table[pos[0]][pos[1]+1]='U';
            break;
        case 2://Down
            if(table[pos[0]-1][pos[1]]=='|'||(pos[0]==29)){
                return NULL;
            }
            else if(table[pos[0]-1][pos[1]]=='*'){
                startGame();
                table[pos[0]][pos[1]]=' ';
                table[pos[0]+1][pos[1]]='U';
            }
            table[pos[0]][pos[1]]=' ';
            table[pos[0]+1][pos[1]]='U';
            break;
        case 4://Left
            if(table[pos[0]][pos[1]-1]=='|'||(pos[1]==0)){
                return NULL;
            }
            else if(table[pos[0]][pos[1]-1]=='*'){
                startGame();
                table[pos[0]][pos[1]]=' ';
                table[pos[0]][pos[1]-1]='U';
            }
            table[pos[0]][pos[1]]=' ';
            table[pos[0]][pos[1]-1]='U';
            break;




    }
    return table;
}
void fight(Pokemon teamPokemon, Pokemon randomPokemon, char ** map) {

    printf("un %s sauvage apparait !! \n ", randomPokemon.name);

    while (1) {
        int isFirst = speedest(teamPokemon, randomPokemon);


        if(isFirst ==1){
            if (playerTurn(&teamPokemon, &randomPokemon) == 2) {
                showMap(map);
                break;
            }
            if(verifLife(randomPokemon.pv)){
                printf("%s est mort dans d'atroce souvrance pauvre bete t'as pas honte", randomPokemon.name);
                showMap(map);
                break;

            }
            ennemyTurn(&randomPokemon,&teamPokemon);
            if(verifLife(teamPokemon.pv)){
                printf("%s est mort dans d'atroce souvrance pauvre bete t'as pas honte", teamPokemon.name);
                showMap(map);
                break;
            }
        } else{
            ennemyTurn(&randomPokemon,&teamPokemon);
            if(verifLife(teamPokemon.pv)){
                printf("%s est mort dans d'atroce souvrance pauvre bete t'as pas honte", teamPokemon.name);
                showMap(map);
                break;
            }
            if (playerTurn(&teamPokemon, &randomPokemon) == 2) {
                showMap(map);
                break;
            }if(verifLife(randomPokemon.pv)){
                printf("%s est mort dans d'atroce souvrance pauvre bete t'as pas honte", randomPokemon.name);
                showMap(map);
                break;

            }

        }

    }
}

int main() {

//    Pokemon Salameche = {
//            .name = "Salameche",
//            .pv=78,
//            .attack=52,
//            .defense = 21,
//            .speed=65,
//            .type = "fire",
//            .maxHeal = 78
//
//    };
//    Pokemon Carapuce = {
//            .name = "Carapuce",
//            .pv=88,
//            .attack=48,
//            .defense = 32,
//            .speed=45,
//            .type = "water",
//            .maxHeal = 88
//    };
    int direction;
    //start game
    srand(time(NULL));
    char **map=generateMap();
    map=putUserInMap(map);
    showMap(map);
    Team *team=newTeam();


    while(1){


        printf("Deplacer l'utilisateur (8:haut, 6:droite, 2:bas, 4:gauche)\n");
        scanf("%d", &direction);
        //printf("move user\n");
        char **map2=map;
        map2=moveUserInMap(map2,direction);
        if(map2==NULL){
            printf("Mauvais chemin 33!\n");
            showMap(map);
        }
        else{
            showMap(map);
            if(startGame() == 1){
                fight(*team->pokeTeam[0],*randompok(),map);
            }
        }
    }
}

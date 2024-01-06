#ifndef MATCH_H
#define MATCH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

    struct Match {
    
        int year;
        char hostCountry[50];
        int matchID;
        char type[30];
        struct tm date;
        char location[50];
        char team1[50];
        char team2[50];
        int score1;
        int score2;
    };

    void readMatchesData(struct Match **matches, int *numMatches);
    void printMatch (struct Match match);

#endif
#include "match.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readMatchesData(struct Match **matches, int *numMatches) {
    
    FILE *file = fopen("/home/berkayozcan/workspaces/soccerworldcup_data_system/soccerworldcup_data_system/datasets/matches.csv", "r");
    
    if (!file) {
        perror("Error opening matches.csv");
        exit(EXIT_FAILURE);
    }

    *matches = malloc(sizeof(struct Match));
    
    //Read first line to avoid conflicts in formatting.
    char line[1000];
    fscanf(file, "%999[^\n]%*c", line);
    
    int result=0;



    while (fscanf(file, "%d,%49[^,],%d,%49[^,],%d-%d-%d,%49[^,],%49[^,],%49[^,],%d,%d\n",
           &(*matches)[*numMatches].year,
           (*matches)[*numMatches].hostCountry,
           &(*matches)[*numMatches].matchID,
           (*matches)[*numMatches].type,
           &(*matches)[*numMatches].date.tm_year,
           &(*matches)[*numMatches].date.tm_mon,
           &(*matches)[*numMatches].date.tm_mday,
           (*matches)[*numMatches].location,
           (*matches)[*numMatches].team1,
           (*matches)[*numMatches].team2,
           &(*matches)[*numMatches].score1,
        &(*matches)[*numMatches].score2) == 12) 
    {
        if (result == EOF) {
            if (feof(file)) {
            // End of file reached
            break;
        }else {
            // An error occurred during fscanf
            perror("Error reading from file");
            exit(EXIT_FAILURE);
            }
        }                                  
        
        
        // Set tm_year to years since 1900, adjust it
        (*matches)[*numMatches].date.tm_year -= 1900;
        // Set tm_mon to be in the range 0-11
        (*matches)[*numMatches].date.tm_mon--;

        printf("%d %s %d %s %d-%02d-%02d %s %s %s %d %d\n",
               (*matches)[*numMatches].year,
               (*matches)[*numMatches].hostCountry,
               (*matches)[*numMatches].matchID,
               (*matches)[*numMatches].type,
               (*matches)[*numMatches].date.tm_year + 1900,
               (*matches)[*numMatches].date.tm_mon + 1,
               (*matches)[*numMatches].date.tm_mday,
               (*matches)[*numMatches].location,
               (*matches)[*numMatches].team1,
               (*matches)[*numMatches].team2,
               (*matches)[*numMatches].score1,
               (*matches)[*numMatches].score2);

        (*numMatches)++;
        *matches = realloc(*matches, (*numMatches + 1) * sizeof(struct Match));
        
        if (!*matches) {
            perror("Error reallocating memory");
            exit(EXIT_FAILURE);
        }

        
    }

    fclose(file);
}

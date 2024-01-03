#include "goals.h"
#include <stdio.h>
#include <stdlib.h>

void readGoalsData(struct Goal **goals, int *numGoals) {

    FILE *file = fopen("/home/berkayozcan/workspaces/soccerworldcup_data_system/soccerworldcup_data_system/datasets/goals.csv", "r");
    
    if (!file) {
        perror("Error opening goals");
        exit(EXIT_FAILURE);
    }

    *goals = malloc(sizeof(struct Goal)); // Allocate memory for the first Goal
    
    //Read first line to avoid conflicts in formatting.
    char line[1000];
    fscanf(file, "%999[^\n]%*c", line);
    

    int result=0;

    while (fscanf(file, "%d,%49[^,],%d,%49[^,],%49[^,],%d\n",
           &(*goals)[*numGoals].year, 
           (*goals)[*numGoals].hostCountry,
           &(*goals)[*numGoals].matchID, 
           (*goals)[*numGoals].team,
           (*goals)[*numGoals].player, 
           &(*goals)[*numGoals].minute) == 6) 
    {
        if (result == EOF) {
            if (feof(file)) {
            // End of file reached
            break;
        } else {
            // An error occurred during fscanf
            perror("Error reading from file");
            exit(EXIT_FAILURE);
            }
        }
                             
      printf("%d %s %d %s %s %d\n", 
            (*goals)[*numGoals].year, 
            (*goals)[*numGoals].hostCountry,
            (*goals)[*numGoals].matchID, 
            (*goals)[*numGoals].team,
            (*goals)[*numGoals].player, 
            (*goals)[*numGoals].minute);         
               
        (*numGoals)++;
        *goals = realloc(*goals, (*numGoals + 1) * sizeof(struct Goal));
        
        if (!*goals) {
            perror("Error reallocating memory");
            exit(EXIT_FAILURE);
        }

        
    }

    fclose(file);
}
        
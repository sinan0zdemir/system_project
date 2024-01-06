#include "squads.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readSquadsData(struct Squad **squads, int *numSquads) {
    
    // File opening
    FILE *file = fopen("datasets/squads.csv", "r");
    
    if (!file) {
        perror("Error opening squads.csv");
        exit(EXIT_FAILURE);
    }
    
    //Create memory for Squad array
    *squads = malloc(sizeof(struct Squad));
    
    //Read first line to avoid conflicts in formatting.
    char line[1000];
    fscanf(file, "%999[^\n]%*c", line);
    
    
    
    int result=0;
    
    //Read through the file squad.csv
    while (fscanf(file,"%d,%49[^,],%49[^,],%d,%49[^,],%49[^,],%49[^,],%49[^,\n]\n",
            &(*squads)[*numSquads].year,
            (*squads)[*numSquads].hostCountry,
            (*squads)[*numSquads].country,
            &(*squads)[*numSquads].jerseyNumber,
            (*squads)[*numSquads].position,
            (*squads)[*numSquads].name,
            (*squads)[*numSquads].clubName,
            (*squads)[*numSquads].clubCountry)>0) 
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
        // printf("%d %s %s %d %s %s %s %s\n", 
        //        (*squads)[*numSquads].year,
        //        (*squads)[*numSquads].hostCountry, 
        //        (*squads)[*numSquads].country,
        //        (*squads)[*numSquads].jerseyNumber, 
        //        (*squads)[*numSquads].position,
        //        (*squads)[*numSquads].name, 
        //        (*squads)[*numSquads].clubName,
        //        (*squads)[*numSquads].clubCountry);

        
        (*numSquads)++;
        *squads = realloc(*squads, (*numSquads + 1) * sizeof(struct Squad));
        
        if (!*squads) {
            perror("Error reallocating memory");
            exit(EXIT_FAILURE);
        }

    }
    
   fclose(file);
 }       


void printSquad(struct Squad *squads, int year, char *country, int size){
    for (int i = 0; i < size; i++) {
        // Check if the current squad member matches the criteria
        if (squads[i].year == year && strcmp(squads[i].country, country) == 0) {
            // Print information about the player
            printf("Year: %d, Country: %s, Name: %s, Position: %s\n",
                   squads[i].year, squads[i].country, squads[i].name, squads[i].position);
        }
       
    }
}

    
        
        
 
    
    

    



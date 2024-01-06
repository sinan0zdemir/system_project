#include "squads.h"
#include "match.h"
#include "goals.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct Squad *squads = NULL;
    int numSquads = 0;

    struct Match *matches = NULL;
    int numMatches = 0;

    struct Goal *goals = NULL;
    int numGoals = 0;

    // Read squads data
    printf("Reading squads data...\n");
    readSquadsData(&squads, &numSquads);
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("Finished reading squads data.\n");

    // Read matches data
    printf("Reading matches data...\n");
    readMatchesData(&matches, &numMatches);
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("Finished reading matches data.\n");

    // Read goals data
    printf("Reading goals data...\n");
    readGoalsData(&goals, &numGoals);
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("===============================");
    printf("Finished reading goals data.\n");

    // Check for errors during memory allocation
    if (squads == NULL || matches == NULL || goals == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");

        // Free any allocated memory before exiting
        free(squads);
        free(matches);
        free(goals);

        exit(EXIT_FAILURE);
    }
    struct Match thisMatch = findMatchById(matches, numMatches, 10); 
    // Perform operations with the data here
    printMatch(thisMatch);

    // printSquad(squads, 2014, "Germany", numSquads);
    
    printf("Total of %d goals were scored", calculateTotalGoals(matches, numMatches, 2014));
    // Free allocated memory
    free(squads);
    free(matches);
    free(goals);

    return 0;
}




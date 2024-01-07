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
    printf("Finished reading squads data.\n");

    // Read matches data
    printf("Reading matches data...\n");
    readMatchesData(&matches, &numMatches);
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
    
    int choice;

    do {
        // Display menu
        printf("\n\n====== Menu ======\n\n");
        printf("1. Find and print match by ID\n");
        printf("2. Print all matches for a year and country\n");
        printf("3. Find and print goals by year\n");
        printf("4. Find and print players by year and country\n");
        printf("5. Find and print player by name\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        // Get user choice
        scanf("%d", &choice);

        // Perform actions based on user choice
        switch (choice) {
            case 1: {
                int matchId;
                printf("Enter match ID: ");
                scanf("%d", &matchId);
                struct Match thisMatch = findMatchById(matches, numMatches, matchId);
                printMatch(thisMatch);
                break;
            }
            
            case 2:{
                int year;
                char country[50];
                printf("Enter a year: ");
                scanf("%d", &year);
                printf("\nEnter a country: ");
                scanf("%s: ", country);
                printMatchesByYearAndCountry(matches, numMatches, year, country);
                break;
            }
            
            case 3: {
                int year;
                printf("Enter year: ");
                scanf("%d", &year);
                printf("Total of %d goals were scored in %d\n", findGoalsByYear(matches, numMatches, year), year);
                break;
            }

            case 4: {
                int year;
                char country[50];
                printf("Enter year: ");
                scanf("%d", &year);
                printf("Enter country: ");
                scanf("%s", country);
                printf("%s's squad in %d consisted of %d players: \n", country, year, findNumberOfPlayers(squads, numSquads, year, country));
                printSquadByYearCountry(squads, numSquads, year, country);
                break;
            }
            case 5: {

                char playerName[50];
                printf("Enter player's full name: ");
                    scanf(" %[^\n]s", playerName);
                findPlayerByName(squads, numSquads, playerName);
                break;
            }
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);
    
    
    
    
    struct Match thisMatch = findMatchById(matches, numMatches, 10); 
    // Perform operations with the data here
    printMatch(thisMatch);

    // printSquad(squads, 2014, "Germany", numSquads);
    
    printf("Total of %d goals were scored in 2014 \n", findGoalsByYear(matches, numMatches, 2014));
    printf("There were %d players in 1954 Austria \n ", findNumberOfPlayers(squads, numSquads, 1954, "Austria"));

    // Free allocated memory
    free(squads);
    free(matches);
    free(goals);
    return 0;
}




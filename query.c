#include "match.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Match findMatchById(struct Match *matches, int size, int matchID) {
    struct Match notFoundMatch = {0}; // Assuming matchID cannot be 0 for a valid match

    for (int i = 0; i < size; ++i) {
        if (matches[i].matchID == matchID) {
            return matches[i]; // Match found, return the Match structure
        }
    }

    // Match not found, return a default Match structure (you can modify this behavior)
    return notFoundMatch;
}
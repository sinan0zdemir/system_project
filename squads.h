#ifndef SQUAD_H
#define SQUAD_H

    struct Squad {
    
        int year;
        char hostCountry[70];
        char country[70];
        int jerseyNumber;
        char position[70];
        char name[70];
        char clubName[70];
        char clubCountry[70];
    
    };
    
    void readSquadsData(struct Squad **squads, int *numSquads);
    
 #endif


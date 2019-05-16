#include "input-output.h"
#include <stdio.h>
#include <stdlib.h>

const size_t max_figures_count2 = 100;
void getDataFromFile(Circles circleData[])
{
    char tempArray[100];
    char checkCircle[] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};
    char atofTMP[10];
    size_t i, j, countC, circleChecking;
    countC = 0;

    FILE* fp;
    fp = fopen("figures.txt", "rt");

    if (fp == NULL) {
        printf("\nCan't open file.\n");
        exit(1);
    }
    for (size_t l = 0; l < max_figures_count2; l++) {
        circleData[l].exist = 0;
    }
    while (1) {
        fgets(tempArray, 49, fp);
        /*if (tempArray[1] == '\000') {
          break;
        }*/
        if (feof(fp) != 0) {
            break;
        }
        i = circleChecking = 0;
        //проверка на круг
        while (tempArray[i] != '(') {
            if (tempArray[i] == checkCircle[i]) {
                circleChecking++;
            } else {
                break;
            }
            i++;
        }

        if (circleChecking == 6) {
            i++;
            j = 0;
            while (tempArray[i] != ' ') {
                atofTMP[j] = tempArray[i];
                j++;
                i++;
            }
            circleData[countC].Ox = atof(atofTMP);
            i++;
            j = 0;
            while (tempArray[i] != ',') {
                atofTMP[j] = tempArray[i];
                j++;
                i++;
            }
            i += 2;
            j = 0;
            circleData[countC].Oy = atof(atofTMP);
            while (tempArray[i] != ')') {
                atofTMP[j] = tempArray[i];
                i++;
                j++;
            }
            circleData[countC].radius = atof(atofTMP);
            circleData[countC].exist++;
            countC++;
        }

        if (circleChecking != 6) {
            printf("Line #%ld in figures.txt has error\n", countC);
        }
    }
    fclose(fp);
}

void printCircle(Circles circleData[])
{
    printf("\tFigrures\n");
    for (size_t i = 0; i < max_figures_count2; i++) {
        if (circleData[i].exist == 0) {
            break;
        }
        printf("Circle #%ld :", i + 1);
        printf("(%.2f , %.2f);", circleData[i].Ox, circleData[i].Oy);
        printf(" radius: %.2f\n", circleData[i].radius);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genNumber();

int genTab(int sizeTab);

int main(void) {
    srand(time(NULL));
    int sizeTab = 10;


    genNumber();


    return 0;
}

int genNumber() {
    int randNumber = rand() % 100 + 1;
    return randNumber;
}

int genTab(int sizeTab) {
    int *tab = (int*)malloc(sizeTab * sizeof(int));
    for (int i = 0; i < sizeTab; i++) {
        tab[i] = genNumber();
    }
    return *tab;
}

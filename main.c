#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genNumber();
int* genTab(int sizeTab);
void printTab(int *tab, int sizeTab);
int* diffTab(int *tab1, int *tab2, int sizeTab1, int sizeTab2, int *resultSize);

int main(void) {
    srand(time(NULL));

    int sizeTab1 = 10;
    int sizeTab2 = 15;
    int *arr1 = genTab(sizeTab1);
    int *arr2 = genTab(sizeTab2);

    printf("Tab1: ");
    printTab(arr1, sizeTab1);
    printf("Tab2: ");
    printTab(arr2, sizeTab2);

    int resultSize = 0;
    int *tabResult = diffTab(arr1, arr2, sizeTab1, sizeTab2, &resultSize);

    printf("TabResult: ");
    printTab(tabResult, resultSize);

    free(arr1);
    free(arr2);
    free(tabResult);

    return 0;
}

int genNumber() {
    return rand() % 100 + 1;
}

int* genTab(int sizeTab) {
    int *tab = malloc(sizeTab * sizeof(int));
    for (int i = 0; i < sizeTab; i++) {
        tab[i] = genNumber();
    }
    return tab;
}

int* diffTab(int *tab1, int *tab2, int sizeTab1, int sizeTab2, int *resultSize) {
    int minsize = sizeTab1 < sizeTab2 ? sizeTab1 : sizeTab2;
    int *result = NULL;
    int count = 0;
    for (int i = 0; i < minsize; i++) {
        int diff = tab1[i] - tab2[i];
        if (diff > 0) {
            result = realloc(result, sizeof(int) * (count + 1));
            result[count++] = diff;
        }
    }
    *resultSize = count;
    return result;
}

void printTab(int *tab, int sizeTab) {
    for (int i = 0; i < sizeTab; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

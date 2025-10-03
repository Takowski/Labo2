#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genNumber();

int genTab(int sizeTab);

int printTab(*tab)

int main (void) {
    srand(time(NULL));

    int sizeTab1 = 10;
    int sizeTab2 = 10;
    int arr1 = genTab(sizeTab1);
    int arr2 = genTab(sizeTab2);
    int tabCounter=0;

    return 0;
}

int genNumber() {
    int randNumber = rand() % 100 + 1;
    return randNumber;
}

int genTab(int sizeTab) {
    int *tab = (int *) malloc(sizeTab * sizeof(int));
    for (int i = 0; i < sizeTab; i++) {
        tab[i] = genNumber();
        printf("tab[%d] = %d\n", i, tab[i]);
    }
    return *tab;
}

int* diffTab(int *tab1, int *tab2, int sizeTab1, int sizeTab2) {
    int minsize= sizeTab1>sizeTab2 ? sizeTab1 : sizeTab2;
    int *result =NULL;
    int count=0;
for (int i = 0; i < minsize; i++) {
    if (tab1[i] > tab2[i]) {
        int diff = tab1[i] - tab2[i];
result =(int*)realloc(result, sizeof(int)*(count+1));
        result[count++] = diff;
    }

}
    return result;
}

void printTab(int *tab, int sizeTab) {
    for (int i = 0; i < sizeTab; i++) {
        printf("%d,", tab[i]);
    }
    printf("\n");
}

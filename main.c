# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int genNumber();

int *genTab(int size);

int *diffTab(int *tab1, int *tab2, int size1, int size2, int *resultSize);

void printTab(int *tab, int size);

int **genTab2D(int nSize, int mSize);

void printTab2D(int **tab2d, int nSize, int mSize);

int main() {
    srand(time(NULL));
    int size1 = 5;
    int size2 = 10;
    int nDimension = 5; //row
    int mDimension = 5; //col

    int resultSize = 0;
    int *tab1 = genTab(size1);
    int *tab2 = genTab(size2);
    int *tabResult = diffTab(tab1, tab2, size1, size2, &resultSize);
    int **tab2D = genTab2D(nDimension, mDimension);

    printTab(tab1, size1);
    printTab(tab2, size2);
    printTab(tabResult, resultSize);
    printTab2D(tab2D, nDimension, mDimension);

    free(tab1);
    free(tab2);
    free(tabResult);
    return 0;
}

int genNumber() {
    int Number = rand() % 100 + 1;
    return Number;
}

int *genTab(int size) {
    int *tab = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        *(tab + i) = genNumber(); // () obligatoire tenir compte de i dans le pointer
    }
    return tab;
}

int *diffTab(int *tab1, int *tab2, int size1, int size2, int *resultSize) {
    int counter = 0;
    int *tabResult = (int *) malloc(sizeof(int) * size1);
    for (int i = 0; i < size1; i++) {
        int subtraction = *(tab1 + i) - *(tab2 + i);
        if (subtraction > 0) {
            *(tabResult + counter++) = subtraction;
        }
    }
    tabResult = (int *) realloc(tabResult, sizeof(int) * counter);
    *resultSize = counter;

    return tabResult;
}

void printTab(int *tab, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int **genTab2D(int nSize, int mSize) {
    int **tab2d = malloc(nSize * sizeof(int **));
    for (int i = 0; i < nSize; i++)
        tab2d[i] = malloc(mSize * sizeof(int *));
    for (int i = 0; i < nSize; i++) {
        for (int j = 0; j < mSize; j++) {
            tab2d[i][j] = genNumber();
        }
    }

    return tab2d;
}

void printTab2D(int **tab2d, int nSize, int mSize) {
    for (int i = 0; i < nSize; i++) {
        for (int j = 0; j < mSize; j++) {
            printf("%d ", tab2d[i][j]);
        }
        printf("\n");
    }
}

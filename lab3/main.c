#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


typedef int type_t;

typedef struct text_t {
    type_t **list;
    type_t **matrix;
    type_t size;
} text_t;

//returns *int of nodes in string
type_t *reformat(int num, char *str) {
    int k = 0;
    type_t *a = malloc(num * sizeof(type_t));
    do {
        while (!isdigit(*str) && *str != '\0')str++;
        if (atoi(str) >= 0) {
            a[k] = atoi(str);
            k++;
        }
        while (isdigit(*str) && *str != '\0')str++;
    } while (*str != '\0');
    return a;
}

//returns number of nodes in the str
int numberOfNodes(const char *str) {
    int i = 0;
    int size = 1;
    char c = 0;

    while (c != '\n') {
        c = str[i];
        i++;
        if (c == ' ') {
            size += 1;
        }
    }
    return size;
}

//reading list.txt
int readList(text_t *text, char *name) {
    FILE *mf;
    char str[10000];
    char *estr;
    mf = fopen(name, "r");

    if (mf == NULL) {
        return -1;
    }

    text->list = (int **) malloc(sizeof(type_t) * text->size);
    for (int i = 0; i < text->size; i++) {
        estr = fgets(str, sizeof(str), mf);
        text->list[i] = reformat(numberOfNodes(estr), estr);
    }
    rewind(mf);
    estr = fgets(str, sizeof(str), mf);
    text->list[0] = reformat(text->size, estr);
    if (fclose(mf) == EOF)
        return -1;
    return 0;
}

//reading matrix.txt
int readMat(text_t *text, char *name) {
    FILE *mf;
    char str[10000];
    char *estr;
    mf = fopen(name, "r");

    if (mf == NULL) {
        return -1;
    }

    estr = fgets(str, sizeof(str), mf);
    text->size = numberOfNodes(estr);
    text->matrix = (int **) malloc(sizeof(type_t) * text->size);
    rewind(mf);
    for (int i = 0; i < text->size; i++) {
        estr = fgets(str, sizeof(str), mf);
        text->matrix[i] = reformat(text->size, estr);
    }
    rewind(mf);
    estr = fgets(str, sizeof(str), mf);
    text->matrix[0] = reformat(text->size, estr);
    if (fclose(mf) == EOF)
        return -1;
    return 0;
}

void read(text_t *text, char *nameM, char *nameL) {
    readMat(text, nameM);
    readList(text, nameL);
}

//is i-line in matrix is equal to i-line in list
int equalLines(text_t *text, int i) {
    int flag = 0, elem, l = 0;
    for (int j = 0; j < text->size; ++j) {
        while (text->list[i][l] != 0) {
            if (text->list[i][l] > text->size) {
                return 0;
            }
            l++;
        }
        l = 0;
        if (text->matrix[i][j] == 1) {
            elem = j + 1;
            while (text->list[i][l] != 0) {
                if (text->list[i][l] == elem) {
                    flag = 1;
                    break;
                }
                l++;
            }
            if (flag == 0)
                return 0;
            flag = 0;
            l = 0;
        } else {
            elem = j + 1;
            while (text->list[i][l] != 0) {
                if (text->list[i][l] == elem) {
                    flag = 1;
                    break;
                }
                l++;
            }
            if (flag == 1)
                return 0;
            l = 0;
        }
    }
    return 1;
}

//equalLines for each line in matrix
int isEqual(text_t *text) {
    int flag = 0;
    for (int i = 0; i < text->size; ++i) {
        flag = equalLines(text, i);
        if (flag == 0)
            break;
    }
    return flag;
}

int main(void) {
    text_t text;
    read(&text, "matrix.txt", "list.txt");
    if (isEqual(&text))
        printf("Совпадают");
    else
        printf("Не совпадают");
    return 0;
}
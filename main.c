/*
** EPITECH PROJECT, 2018
** 102architect
** File description:
** my.h
*/

#include "include/my.h"

void matrix_mul(int size, int len, int matrix1[size][size],
    int matrix2[len][size], int result_matrix[len][size])
{
    int y = 0;

    /*CALCUL*/
    for (int i = 0; i != len; i++) {
        for (int j = 0; j != size; j++) {
            result_matrix[i][j] = 0;
            for (int k = 0; k != size; k++) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void key_print(int size, int matrix[size][size])
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("%d\n", matrix[i][size - 1]);
    }
}

void matrix_print(int size, int len, int matrix[len][size])
{
    if (size == 1)
        len--;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < size; j++) {
            if (i == len - 1 && j == size - 1)
                printf("%d\n", matrix[i][j]);
            else
                printf("%d ", matrix[i][j]);
        }
    }
}

void chiffrement(char *message, char *key)
{
    int a = 0;
    int b = 0;
    int size = sqrt(strlen(key) - 1) + 1;
    int len = (strlen(message) / size) + 1;
    /*INITIALISATION KEY MATRIX*/
    int key_matrix[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (key[a] != '\0') {
                key_matrix[i][j] = key[a];
                a++;
            } else {
                key_matrix[i][j] = 0;
            }
        }
    }
    /*INITIALISATION STR MATRIX*/
    int str_matrix[len][size];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < size; j++) {
            if (message[b]) {
                str_matrix[i][j] = message[b];
                b++;
            } else {
                str_matrix[i][j] = 0;
            }
        }
    }
    /*INITIALISATION RESULT MATRIX*/
    int result_matrix[len][size];
    /*CALCUL*/
    matrix_mul(size, len, str_matrix, key_matrix, result_matrix);
    printf("Key matrix:\n");
    key_print(size, key_matrix);
    printf("\nEncrypted message:\n");
    matrix_print(size, len, result_matrix);
}

void dechifrement(char *message, char *key)
{
    int a = 0;
    int b = 0;
    int size = sqrt(strlen(key) - 1) + 1;
    int len = (strlen(message) / size) + 1;
    /*INITIALISATION KEY MATRIX*/
    /*TO FIX TO FIX TO FIX TO FIX TO FIX*/
    int key_matrix[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (key[a] != '\0') {
                key_matrix[i][j] = key[a];
                a++;
            } else {
                key_matrix[i][j] = 0;
            }
        }
    }
    /*INITIALISATION STR MATRIX*/
    int str_matrix[len][size];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < size; j++) {
            if (message[b] != '\0') {
                str_matrix[i][j] = message[b];
                b++;
            } else {
                str_matrix[i][j] = 0;
            }
        }
    }
    /*INITIALISATION RESULT MATRIX*/
    int result_matrix[len][size];
    /*CALCUL*/
    matrix_mul(size, len, str_matrix, key_matrix, result_matrix);
    printf("Key matrix:\n");
    key_print(size, key_matrix);
    printf("\nDecrypted message:\n");
    matrix_print(size, len, result_matrix);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        printf("USAGE\n\t./103cipher message key flag\n\nDESCRIPTION\n\t"
        "message\ta message, made of ASCII characters\n\tkey the encryption"
        "key, made of ASCII characters\n\tflag 0 for the message to be "
        "encrypted, 1 to be decrypted\n");
        return (0);
    }
    if (ac == 4 && strcmp(av[3], "0") == 0)
        chiffrement(av[1], av[2]);
    else if (ac == 4 && strcmp(av[3], "1") == 0)
        dechifrement(av[1], av[2]);
    else {
        printf("BAD ARGUMENTS\n");
        return (84);
    }
    return (0);
}

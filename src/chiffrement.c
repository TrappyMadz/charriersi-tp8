#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "chiffrement.h"

#define ERREUR -1

char* cesar(char* pchar_message, int int_decalage)
{
    // Définition des variables
    // Résultat
    char* pchar_result;
    // Taille
    int int_taille;
    // Compteur de boucle
    int int_i;

    // Obtenir la longueur de la chaîne
    int_taille = 0;
    while (pchar_message[int_taille] != '\0')
    {
        int_taille++;
    }

    // Allocation de la mémoire du resultat
    pchar_result = (char*)malloc((int_taille + 1) * sizeof(char));
    if (pchar_result == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire");
        exit(ERREUR);
    }

    // Parcours du mot
    for (int_i = 0 ; int_i < int_taille ; int_i++)
    {
        // Décalage
        pchar_result[int_i] = pchar_message[int_i] + int_decalage;

        // On gère le dépassement (si le résultat > z, on retourne à a en soustrayant 26) et inversement
        // Si la lettre est Majuscule
        if (pchar_message[int_i] >= 'A' && pchar_message[int_i] <= 'Z')
        {
            if (pchar_result[int_i] > 'Z')
            {
                pchar_result[int_i] -= 26;
            }

            if (pchar_result[int_i] < 'A')
            {
                pchar_result[int_i] += 26;
            }
        }

        // Si elle est minuscule
        if (pchar_message[int_i] >= 'a' && pchar_message[int_i] <= 'z')
        {
            if (pchar_result[int_i] > 'z')
            {
                pchar_result[int_i] -= 26;
            }

            if (pchar_result[int_i] < 'A')
            {
                pchar_result[int_i] += 26;
            }
        }
    }

    // On ajoute le caractère de fin
    pchar_result[int_taille] = '\0';

    // On renvoie le résultat.
    return pchar_result;
}


char* vinegere(char* pchar_message, char* pchar_cleent)
{
    // Déclaration des variables
    // Taille
    int int_taille;
    // Cle de la bonne taille
    char* pchar_clesort;
    // Résultat
    char* pchar_result;
    // Compteurs de boucle
    int int_i;
    int int_j;

    int_taille = 0;
    // On obtiens la taille du message
    while (pchar_message[int_taille] != '\0')
    {
        int_taille++;
    }

    // On copie la clé dans un nouveau tableau qu'on utilisera, de la bonne taille. Si la clé est trop petite, on repetera les premieres lettres
    pchar_clesort = (char* )malloc((int_taille + 1) * sizeof(char));
    if (pchar_clesort == NULL)
    {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(ERREUR);
    }

    int_j = 0;
    for (int_i = 0 ; int_i < int_taille ; int_i++)
    {
        if (pchar_cleent[int_j] == '\0')
        {
            int_j = 0;
        }

        pchar_clesort[int_i] = pchar_cleent[int_j];
        int_j++;
    }
    pchar_clesort[int_taille] = '\0';

    // On initialise le resultat
    pchar_result = (char* )malloc((int_taille + 1) * sizeof(char));
    if (pchar_result == NULL)
    {
        free(pchar_clesort);
        fprintf(stderr, "Erreur d'allocation\n");
        exit(ERREUR);
    }

    // On parcours le mot
    for (int_i = 0 ; int_i < int_taille ; int_i++)
    {
        // On décale le résultat du bon nombre, tout en s'assurant que ce résultat reste dans la bonne plage
        pchar_result[int_i] = pchar_message[int_i] - 'A' + pchar_clesort[int_i] - 'A';

        pchar_result[int_i] = (pchar_result[int_i] % 26 + 26) % 26 + 'A';
    }

    // On ajoute la caractère de fin
    pchar_result[int_taille] = '\0';

    // On renvoie le résultat
    free(pchar_clesort);
    return pchar_result;

}
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

/*!
\file chiffrement.c
\author Charrier Simon
\version 1
\date 28 novembre 2023
\brief Fonctions de chiffrement
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "chiffrement.h"

#define ERREUR -1

// Chiffrement via la méthode de César
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
    pchar_result = malloc((int_taille + 1) * sizeof pchar_result);
    if (pchar_result == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire");
        exit(ERREUR);
    }

    // Parcours du mot
    for (int_i = 0 ; int_i < int_taille ; int_i++)
    {

        // On gère le dépassement (si le résultat > z, on retourne à a en soustrayant 26) et inversement
        // Si la lettre est Majuscule
        if (pchar_message[int_i] >= 'A' && pchar_message[int_i] <= 'Z')
        {
            pchar_result[int_i] = (pchar_message[int_i] - 'A' + int_decalage + 26) % 26 + 'A';

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
            pchar_result[int_i] = (pchar_message[int_i] - 'a' + int_decalage + 26) % 26 + 'a';
            if (pchar_result[int_i] > 'z')
            {
                pchar_result[int_i] -= 26;
            }

            if (pchar_result[int_i] < 'a')
            {
                pchar_result[int_i] += 26;
            }
        }
        else
        {
            pchar_result[int_i] = pchar_message[int_i];
        }
    }

    // On ajoute le caractère de fin
    pchar_result[int_taille] = '\0';

    // On renvoie le résultat.
    return pchar_result;
}


// Chiffrement via la méthode de Vinegère
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
        if (pchar_message[int_i] >= 'A' && pchar_message[int_i] <= 'Z')
        {
            // On décale le résultat du bon nombre, tout en s'assurant que ce résultat reste dans la bonne plage
            pchar_result[int_i] = pchar_message[int_i] - 'A' + pchar_clesort[int_i] - 'A';

            pchar_result[int_i] = (pchar_result[int_i] % 26 + 26) % 26 + 'A';
        }
        else if (pchar_message[int_i] >= 'a' && pchar_message[int_i] <= 'z')
        {
            pchar_result[int_i] = pchar_message[int_i] - 'a' + pchar_clesort[int_i] - 'a';

            pchar_result[int_i] = (pchar_result[int_i] % 26 + 26) % 26 + 'a';
        }
        // Pour les caractère qui ne sont pas des lettres, on ne les changes pas
        else
        {
            pchar_result[int_i] = pchar_message[int_i];
        }
    }

    // On ajoute la caractère de fin
    pchar_result[int_taille] = '\0';

    // On renvoie le résultat
    free(pchar_clesort);
    return pchar_result;

}


// Chiffrement via la méthode de Scytale
char* scytale(char* pchar_message)
{
    // Déclaration des variables
    // Compteurs de boucle
    int int_i=0;
    int int_j;
    // Compteur "où en est-on dans le message ?"
    int int_mess=0;
    // Taille du messages
    int int_taille=0;
    // Table intérmédiaire (pour ne pas modifier le message d'origine)
    char* pchar_messageint;
    // Tableau intermédiaire
    char** ppchar_inte;
    // Taille du tableau intermédiaire (lignes ou colonnes)
    int int_tailleint=0;
    // Message finale
    char* pchar_result;

    // On a besoins de la taille du message
    while (pchar_message[int_taille] != '\0')
    {
        int_taille++;
    }

    // On alloue le tableau intermédiaire
    pchar_messageint = malloc(int_taille * sizeof *pchar_messageint);
    if (pchar_messageint == NULL)
    {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(ERREUR);
    }

    for (int_i = 0 ; int_i < int_taille ; int_i++)
    {
        pchar_messageint[int_i] = pchar_message[int_i];
    }

    // On forme un tableau de la bonne taille en faisant racine(taille)
    int_tailleint = sqrt(int_taille);

    // Si c'est un entier, on a notre bonne taille de tableau (rint arrondi à l'entier le plus proche, donc cela permet de detecter si un nombre est entier)
    // Si on en trouve pas, on ajoute des espaces à notre tchar_message pour completer
    while (int_tailleint != rint(int_tailleint))
    {
        pchar_messageint = (char*)realloc(pchar_messageint, int_taille * sizeof(char));
        if (pchar_messageint == NULL)
        {
            fprintf(stderr, "Erreur d'allocation\n");
            exit(ERREUR);
        }
        pchar_messageint[int_taille] = ' ';
        int_taille++;
        int_tailleint = sqrt(int_taille);
    }
    
    // On créer le tableau intermédiaire
    ppchar_inte = malloc(int_tailleint * sizeof *ppchar_inte);
    if (ppchar_inte == NULL)
    {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(ERREUR);
    }
    for (int_i = 0 ; int_i < int_tailleint ; int_i++)
    {
        ppchar_inte[int_i] = (char*)malloc(int_tailleint * sizeof(char));
        if (ppchar_inte[int_i] == NULL)
        {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(ERREUR);
        }
    }

    // On attribue en lignes les lettres du message
    for (int_j = 0 ; int_j < int_tailleint ; int_j++)
    {
        for (int_i = 0 ; int_i < int_tailleint ; int_i++)
        {
            ppchar_inte[int_i][int_j] = pchar_messageint[int_mess];
            int_mess++;
        }
    }

    // On alloue le tableau resultat
    pchar_result = (char*)malloc(int_taille * sizeof(char));
    if (pchar_result == NULL)
    {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(ERREUR);
    }

    // Puis on applique au message de fin les lettres lues en colonnes
    int_mess = 0;
    for (int_i = 0 ; int_i < int_tailleint ; int_i++)
    {
        for (int_j = 0 ; int_j < int_tailleint ; int_j++)
        {
            if (int_mess < int_taille)
            {
                pchar_result[int_mess] = ppchar_inte[int_i][int_j];
                int_mess++;
            }
        }
    }

    // On free la table intermédiaire, et la table modifiée
    free(pchar_messageint);
    for (int_i = 0 ; int_i < int_tailleint ; int_i++)
    {
        free(ppchar_inte[int_i]);
    }
    free(ppchar_inte);
    return pchar_result;
}
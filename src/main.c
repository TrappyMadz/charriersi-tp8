/*!
\file main.c
\author Charrier Simon
\version 1
\date 17 novembre 2023
\brief Menu de séléction
*/

// Importations
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "chiffrement.h"

// Définitions
#define ERREUR -1
#define SORTIE 0

/*!
\fn int main (int argc, char** argv)
\author Charrier Simon
\version 1
\date 17 novembre 2023
\brief Affichage du menu
\param argc nombre d'arguments en entrée
\param argv valeur des arguments en entrée
\return 0 si tout c'est bien passé
*/
int main(int argc, char ** argv) 
{
    // On doit obligatoirement prendre au moins un argument

    // --help renvoie l'aide et les explications sur tous les arguments possibles

    // -c <nom_méthode> permet de choisir la méthode

    // arguments optionnels

    // -d permet de choisir le décalage de la fonction césar

    // -k <clé> permet de choisir la clé pour Vigenère

    // -m <message> permet d'entrer le message à chiffrer

    // Pour toutes les possibilités, on partira du principe que l'utilisateur entrera les arguments sous cette forme :
    // ./TP -c <nom_méthode> -d/k <clé ou décalage> -m <message>
    // On ne prendra en compte que cette ordre, sinon on renverra un message d'erreur


    return 0;
}

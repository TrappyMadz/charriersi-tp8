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
    // Déclaration des variables
    // Décalage de la fonction César
    int int_d;
    // Clé de la fonction Vinegère
    char* pchar_k;
    // Message
    char* pchar_m;
    // Taille du message
    int int_taillem=0;
    // Taille pour le getline
    size_t nb;
    // Résultat
    char* pchar_result="\n";
    // Vérification (scanf)
    int int_verif;
    // Compteur
    int int_i;

    // On doit obligatoirement prendre au moins un argument
    if (argc <= 2)
    {
        fprintf(stderr,"Pas assez d'arguments. --help pour plus d'informations\n");
        exit(ERREUR);
    }

    // --help renvoie l'aide et les explications sur tous les arguments possibles
    if (strcmp(argv[1],"--help") == 0)
    {
        printf("Besoins d'un peu d'aide ? Voilà les différents arguments que prend la commande :\n");
        printf("bin/TP -c <nom_méthode> | permet de lancer la méthode correspondante\n");
        printf("Liste des méthodes :\n");
        printf("César, Vinegère, Scytale\n");
        printf("Arguments optionnels : \n");
        printf("La commande entrée doit être de la forme : bin/TP -c <nom_méthode> -k/d <paramètre>");
        printf("-d | permet de choisir le décalage pour la méthode César\n");
        printf("-k | permet de choisir la clé pour la méthode Vinegère\n");
        printf("Pour inserer un message, il faut écrire la commande de la manière suivante :\n");
        printf("bin/TP -c <nom_méthode> -d/k (optionnel) -m <message>\n");
        return 0;
    }


    // -c <nom_méthode> permet de choisir la méthode
    if (strcmp(argv[1],"-c") == 0)
    {
        // César
        if (strcmp(argv[2],"César") == 0)
        {
            if (argc >= 5)
            {
                // -d permet de choisir le décalage de la fonction césar
                if (strcmp(argv[3],"-d") == 0)
                {   
                    int_d = strtol(argv[4], NULL, 10);
                }
                else
                {
                    fprintf(stderr,"Mauvais argument. --help pour plus d'informations\n");
                    exit(ERREUR);
                }   
                if (argc >= 7)
                {
                    // -m <message> permet d'entrer le message à chiffrer
                    if (strcmp(argv[5],"-m") == 0)
                    {
                        // Obtention de la taille de message
                        int_i = 6;
                        while (int_i < argc)
                        {
                            int_taillem = (int)strlen(argv[int_i]) + 2;
                            int_i++;
                        }
                        
                        // Allocation (à ce moment là, int_i sera égale au nomnbre d'arguments après -m +5)
                        pchar_m = malloc((int_taillem + int_i - 5) * sizeof pchar_m);
                        if (pchar_m == NULL)
                        {       
                            fprintf(stderr,"Erreur d'allocation");
                            exit(ERREUR);
                        }
                        int_i = 6;
                        while (int_i < argc)
                        {
                            // Récupération du message
                            strcpy(pchar_m, argv[int_i]);
                            // Fonction pour chaque mots
                            pchar_result = cesar(pchar_m,int_d);
                            printf("%s ",pchar_result);
                            int_i++;
                        }
                        printf("\n");
                       
                    }
                    else
                    {
                        fprintf(stderr,"Mauvais arguments. --help pour plus d'informations\n");
                        exit(ERREUR);
                    }
                }
                else
                {
                    fprintf(stderr,"Mauvais nombre d'arguments. --help pour plus d'informations\n");
                    exit(ERREUR);
                }
            }

            // Si on a juste entrer -c César
            else
            {
                printf("Quel doit être le décalage ?\n");
                int_verif = scanf("%d",&int_d);
                // On "consomme" le caractère en tampon
                getchar();
                while (int_verif != 1)
                {
                    printf("Veuillez entrer un nombre entier\n");
                    int_verif = scanf("%d",&int_d);
                    getchar();
                }

                printf("Veuillez entrer le message à chiffrer : \n");
                nb = 0;
                int_taillem = getline(&pchar_m,&nb,stdin);

                pchar_result = cesar(pchar_m,int_d);
                printf("%s\n",pchar_result);
            }

                
        }

        //free
        free(pchar_m);
        free(pchar_result);

        return 0;
    }

    // Vinegère
    // Scytale

    else
    {
        fprintf(stderr,"Mauvais arguments. --help pour plus d'informations\n");
        exit(ERREUR);
    }

    return 0;
}

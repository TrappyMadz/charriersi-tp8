/*!
\file chiffrement.c
\author Charrier Simon
\version 1
\date 28 novembre 2023
\brief Fichier .h associé aux fonctions de chiffrements
*/


#ifndef __CHIFFREMENT_H_
#define __CHIFFREMENT_H_

/*!
\fn char* cesar(char* pchar_message, int int_decalage)
\author Charrier Simon
\version 1
\date 28 novembre 2023
\brief Chiffrage d'un message avec un certains décalage via l'algorithme de César
\param pchar_message Message à chiffrer
\param int_decalage décalage à appliquer sur chaque lettre
\return le message chiffré
*/
char* cesar(char* pchar_message, int int_decalage);

/*!
\fn char* vinegere(char* pchar_message, char* pchar_cleent)
\author Charrier Simon
\version 1
\date 28 novembre 2023
\brief Chiffrement d'un message via la méthode de Vinegère avec une clé choisie
\param pchar_message message à chiffrer
\param pchar_cleent clé à utiliser pour chiffrer le message
\return le message chiffré
*/
char* vinegere(char* pchar_message, char* pchar_cleent);

/*!
\fn char* scytale(char* pchar_message)
\author Charrier Simon
\version 1
\date 28 novembre 2023
\brief Chiffrement d'un message via la méthode de Scytale
\param pchar_message message à chiffrer
\return le message chiffré
*/
char* scytale(char* pchar_message);

#endif
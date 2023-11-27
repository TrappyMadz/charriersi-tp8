# charriersi-tp8
CY-Tech ING1 Programmation procédurale TP8

## Compilation du code

Pour compiler le code, il faut ouvrir un terminal dans le dossier "charriersi-tp8" puis entrer la commande suivante :

```bash
make
```

Les fichiers .o et les executables se trouveront dans le dossier bin

## Execution du programme

Pour executer le programme, toujours dans le terminal se trouvant dans le dossier "charriersi-tp8", il faut entrer la commande :

```bash
./bin/TP arguments
```
Le programme devrait commencer à s'executer automatiquement avec les arguments.
Pour une liste des arguments, n'hésitez pas à utiliser

```bash
./bin/TP --help
```

## Génération du doxygen

Pour générer le doxygen, toujours dans le terminal se trouvant dans le dossier, il faut entrer la commande suivante :

```bash
make doc
```
Le fichier de configuration ainsi que la documentation se trouvent dans le répertoire doc.

## Description du code
# main
La fonction main sert juste à gerer les arguments à mettre.

# César
Renvoie la chaîne entrée avec un décalage. Si le résultat se trouverais après la dernière lettre ou avant la première lettre (z ou a), alors on reviens au début ou à la fin de l'alphabet.
Si il y a un symbole dans l'expression, il sera inchangé.

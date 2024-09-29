# Programmer en language C, Delannoy

## I. Généralités

La norme ANSI élargit, sans la contredire, la première définition de Kernighan et Ritchie. Outre la spécification de la syntaxe du langage, elle ale mérite de fournir la description d'un ensemble de fonctions que l'on doit trouver associées à tout compilateur C sous forme de "bibliothèque standard"


Notez qu'il existe en C trois sortes d'instructions:
- des instructions simples, terminées obligatoirement par un point-vigule
- des instructions de structurations (if/for)
- des blocs (délimités par { et })

Lorsque nous parlerons d'instruction, sans précisions supplémentaires, il pourra s'agir de n'importe laqulee des trois formes ci-dessus

Les "directives" (#) sont prises en compte avant la traduction (compilation) du programme.

La directive #define sert à définir la valeur d'un symbole. Nous verons que cette directive sert également à définir une "macro".

Une macro s'utilise comme une fonction; en particulier, elle peut posséder des arguments. Mais le préprocesseur remplacera chaque appel par la/les instructions C correspondantes. Dans le cas d'une (vrai) fonction, une telle substitution n'existe pas; au contraire, c'est l'éditeur de liens qui incorporera les instructions machine correspondantes.

`getchar` et `putchar` sont des macros dont la "défintion" figure dans `stdio.h`


### La compilation
- traitement par le préprocesseur.
- compilation, traduction en language machine

Le résultat de compilation porte le nom de module objet.

### L'édition de liens
Le module object créé par le compilateur n'est pas directement exécutable. Il lui manque, au moins, les différents modules objet correspondant aux fonctions standard.


C'est effectivement le rôle de l'éditeur de liens que d'aller rechercher dans la "bibliothèque standard" les modules objet nécessaires.


Notez que cette bibliothèque est une collection de modules objet organisée en un ou plusieurs fichiers.

Le résultat de l'édition de liens est ce que l'on nomme un "exécutable"

### Les fichiers en-tête (#include)

De tels fichiers comportent, entre autre choses:
- des déclarations relatives aux fonctions prédéfinies
- des définitions de macros prédéfinies

Lorsque l'on écrit un programme, on ne fait pas toujours la différence entre fonction et macros, puisque celles-ci s'utilisent de la même manière. Toutefois, les fonctions et les macros sont traitées de façon totalement différente par l'ensemble "préprocesseur+compilateur+éditeur de liens".

- Les appels macros sont remplacés par le préprocesseur.
- Les fonctions, quant à elles, sont incorporées par l'éditeur de liens.


## II. Les types de base

Les types char, int et float sont souvent dits "scalaires" ou "simples", car, à un instant donné, une variable d'un tel type contient une seule valeur. Ils s'opposent aux types "structurés" (on dit aussi "agrégés") qui correspondant à des variable qui, à un instant donné, contiennent plusieurs valeurs.


Les types de base; il s'agit des types scalaires à partir desquels pourront être construits tous les autres, dits "types dérivés", qu'il s'aggisse:
- de types structurés comme les tableaux, les strucutes ou les unions.
- d'autre types simples comme les pointeurs ou les énumérations.

### La notion de type

La mémoire centrale est un ensemble de "positions binaires" nommées bits.
L'ordinateur, ne sait représenter et traiter que des informations exprimées sous forme binaire. Toute information, quelle que soit sa nature, devra être codée sous cette forme. Dans ces conditions, on voit qu'il ne suffit pas de connaôtre le contenu d'un emplacement de la mémoire pour être en mesure de lui attribuer une signification.


D'une manière générale, la notion de type, sert à régler ce problèmes.

#### Les types entiers

Le mot clé int correspond à la représentation de nombres entiers relatifs. Pour ce faire: un bit est réservé pour représenter le sign du number; les autres bits servent à représenter la valeur absolue du nombre

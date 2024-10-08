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

#### Les types flottants

Les types "flottants" permettent de représenter, de manière approchée, une partie des nombres réels. Pour ce faire, ils s'inspirent de la notation "scientifique" (ou "exponentielle") qui consiste à écrire un nombre sous la forme `1.5 x 10^22` ou `0.472 x 10^-8`; dans une telle notation, on nomme "mantisses" les quantités telles que `1.5` ou `0.472` et "exposants" les quantités telles que `22` ou `-8`.

#### Les types caractères

Par ailleurs, la notion de caractère en C dépasse celle de caractère imprimable, c'est-à-dire auquel est obligatoirement associé un graphisme. C'est ainsi qu'il existe certains "caractères" de changement de ligne, de tabulation...

## III. Les opérateurs et les expressions

En C, l'affectation (=) est un opérateur.

La principlae instruction est une expression terminée par un point-virgule. Sous l'allure d'une affectation `(i=5)` il y a évaluation d'une expression dont la valeur est finalement inutilisé.

C dispose d'opérateurs classiques "binaires" (c'est-à-dire portant sur deux "opérandes"), ainsi que d'un opérateur "unaire" (portant sur un seul opérande) correspondant à l'opposé.

#### Conversions d'ajustement de type

Une conversion ne peut se faire que suivant une "hiérarchie" qui permet de ne pas dénaturer la valeur initiale, à savoir:
`int -> long -> float -> double -> long double`

La conversion est effectué avant l'évaluation de l'expression.


#### Promotions numériques

Les conversions d'ajustement de type ne suffisent pas à régler tous les cas.

Les types `char` et `short` sont convertie en |`int`, et cela sans considérer les types des éventuels autres opérandes. On parle alors, dans ce cas, de "promotions numériques", ou "conversions systématiques".


Les arguments d'appel d'une fonction peuvent $etre également soumis à des conversions. Lorsque le type des arguments n'a pas été déclaré, les valeurs transmises en argument sont soumises aux règles précédentes auxquelles il faut ajouter la promotion numérique `float -> double`.

#### Les opérateurs relationnels

Opérateurs classiques de comparaison:
`2 * a > b + 5`. Le langage C distingue deux points:
- le résultat de la comparaison est un entier valent 0 si faux et 1 si vrai. Ainsi la comparaison ci dessus devient en fait une expression de type entier.

```c
    a < b == c < d
    /* interprétée comme: */
    (a < b) == (c < d)
    
    /* opérateur raltionnels sont moins prioritaires
       que les opérateurs arithmétiques */
    x + y < a + 2
    (x + y) < (a + 2)
   
```
#### Opérateurs logiques

L'opérateur ! a une priorité supérieure à celle de tous les opérateurs arithmétiques binaires et aux opérateurs relationnels.

L'opérateur ! inverse la valeur logique de `n`

```c
    if (!n)
    /* imaginons n=5 
       n=5, non nul alors 1
       !1 deviens 0
       La condition if teste si !n est vrai, 0
       ne permet pas d'entrer dans le if
    */
```

Les deux opérateurs && et || possède une propriété intéressante: leur second opérande (à droite) n'est évalué que si la connaissance de sa valeur est indispendable.

```c
    a<b && c<d
    /* on commence par evaluer a<b, si le résultat est faux
    il est inutile d'évaluer c<d
    */
```

#### Affectation ordinaire

Le terme "lvalue" ("left value") fait référence à une expression qui
désigne un emplacement de mémoire, c'est-à-dire une adresse où une
valeur peut être stockée. Une lvalue peut apparaître à gauche d'une
affectation, ce qui signifie qu'elle peut recevoir une valeur.

L'opérateur d'affectation possède une associativité de "droite à gauche"

#### L'opérateur de cast

Le programmeur peut forcer la conversion d'une expression quelconque dans un type de son choix, à l'aide de l'opérateur "cast".


`(double) (n/p)` la notation (double) correspond à un opérateur unaire dont le rôle est d'effectuer la conversion.

#### L'opérateur séquentiel

L'opérateur dit "séquentiel" permet d'exprimer plusieurs calculs successifs au sein d'une mêmeexpression.


`a*b, i+j` est une expression que évalue d'abord a * b, puis i + j et qui prend comme valeur la dernière calculée.

Un tel opérateur peut être utilisé pour réunir plusieurs instructions en une seule. Ce dernier pourra fréquement intervenir dans les instructions de choix ou dans les boucles; là où celles-ci s'attendent à trouver une seule expression, l'opérateur séquentiel permettre d'en placer plusieurs.

```c
    if (i++, k>0) ...

    for (i=1, k=0; ...; ...) ...

    for (i=1, k=0, printf("on commence");...)
```

#### L'opérateur sizeof

L'opérateur sizeof, dont l'emploi ressemble à celui d'une fonction, fournit la taille en octetcs.

#### Operateurs d'incrémentation

Post incrémentation `i++` affect dans un premier temps la valeur i = i, puisincrement, c'est la difference clé entre pré/post incrémentation.

```c
    int n = 15;
    int p = 10;
    int q = 5;

    if (n < p) {
        /* execution de n++ */
        q = n;   
        n = n + 1; 
    } else {
        /* execution de p++ */
        q = p;   
        p = p + 1; 
    }
```

# IV. Entrées-sorties conversationnelles

#### Gabarit d'affichage

Par défaut, les entiers sont affichés avec le nombre de caractères nécessaires. Les flottants sont affichés avec six chiffres après le point.


Un nombre placé après % dans le code de format précise un gabarit d'affichage, c'est-à-dire un nombre minimal de caractères à utiliser.

```c
    /* entier avec 3 caractères minimum */
    printf("%3d", n);
    n = 20      -> ^20
    n = 3       -> ^^3
    n = 2358    -> 2358
    n = -5200   -> -5200

    /* notation décimale gabarit par défaut
     * (6 chiffres après point)
     */
    printf("%f", x);
    x = 1.2345      -> 1.234500
    x = 12.3456789  -> 12.345679 

    /* gabarit mini 10
     * (6 chiffres après point)
     */
    printf("%10f", x);
    x = 1.2345      -> ^^1.234500
    x = 12.345      -> ^12.354000
    x = 1.2345E5    -> 123450.000000

    /* notation exponentielle - gabarit par défaut
     * (6 chiffres après point )
     */
    printf("%e", x);
    x = 1.2345          -> 1.234500e+000
    x = 123.45          -> 1.234500e+002
    x = 123.456789E8    -> 1.234568e+010
    x = -123.456789E8   -> -1.234568e+010
```

#### Actions sur la précision

Pour les flottants, on peut spécifier un numbre de chiffres après le point décimal.

```c
    /* gabarit 10 mini
     * 3 chiffres après point
     */
    printf("%10.3f", x);
    x = 1.2345      -> ^^^^^1.235
    x = 1.2345E3    -> ^^1234.500
    x = 1.2345E7    -> 12345000.000

    /* notation exponentielle mini 12
     * 4 chiffres après point
     */
    printf("%12.4e", x);
    x = 1.2345          -> ^1.2345e+000
    x = 123.456789E8    -> ^1.2346e+010
```

Le signe moins (-), placé immédiatement après le symbole % (comme dans %-4d ou %-10.3f), demande de "cadrer" l'affichage à gauche au lieu de le cadrer (par défaut) à droite.

Le caractère (\*) signifie que la valeur est fournie dans la list des arguments de printf

La fonction printf fournit une "valeur de retour". Il s'agit du nombre de caractères qu'elle a réellement affichés (ou -1 en cas d'erreur).

#### Scanf

L'information frappée au clavier est rangér temporairement dans l'emplacement mémoire nommé "tampon" (buffer). Ce dernier est exploré, caractère par caractère par scanf, au fur et à mesure des besoins. Il existe un "pointeur" qui précise quel est le prochain caractère à prendre en compte.


D'autre part, certains caractères jouent un rôte particulier dans les données: ce sont les "séparateurs". Les deux principaux sont l'espace et la fin de ligne (\n).


```c
    /* ^ désigne un espace et @ une fin de ligne */
    scanf("%d%d", &n, &p);
    12^25@      n = 12,     p = 25
    ^12^^25^^@  n = 12,     p = 25
    12@@^25@    n = 12,     p = 25

    scanf("%c%d", &c, &n);
    a25@        c = 'a',    n = 25
    a^^25@      c = 'a',    n = 25

    scanf("%d%c", &n, &c);
    12^a@       n = 12,     c = '^'
```

Le code format précise la nature du travail à effectuer pour "transcoder" une partie de l'information frappée au clavier.


%d entraîne une "double conversion" char->int->binary. En revanche, le code %c demande simplement de reopier tel qeul l'octet du caractère concerné.

```c
    scanf("%3d%3d", &n, &c);
    12^25@      n = 12      p = 25
    ^^^^^12345@ n = 123     p = 45
    12@25@      n = 12      p = 25
```

Un espace entre deux codes de format demande à scanf de faire avance le pointeur au prochain caractère différent d'un séparateur. (pour type numérique). En revanche, cela n'est pas le cas pour les caractères.


D'une manière générale, dans le traitement d'un code de format, scanf arrête son exploration du tampon dès que l'une des trois conditions est satisfaite:

- rencontre d'un caractère séparateur
- gabarit maximal atteint
- rencontre d'un caractère "invalide"


L'informations frappées au clavier ne sont pas traitées instantanément par scanf mais mémorisées dans un tampon. Jusqu'ici, nous n'avons pas précisé quand scanf s'arrêt de "mémoriser" pour commencer à "traiter". Il le fait tout naturellement à la rencontre d'un caractère de fin de ligne généré par "return", dont le rôle est aussi celui d'une "validation".
Notez que, bien qu'il joue le rôle d'une validation, ce caractère de fin de ligne est quand m$eme recopié dans le tampon; il pourra donc éventuellement être lu en tant que tel.


Dans ce cas, il faut bien voir que les caractères non exploité reste dans le tampon pour une "prochaine fois".

## V. Instructions de contrôle

Instructions de branchement inconditionnel: goto, break et continue


Un else se rapporte toujours au dernier if rencontré auquel un else n'a pas encore été attribué.

Ces constructions sont correctes:
- `do c=getchar(); while (c!='x');`
- `do ; while (...);`
- `do { } while (...);`


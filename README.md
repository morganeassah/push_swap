            This project has been created as part of the 42 curriculum by <massah>.

Description:

    Push_swap est un projet algorithmique du cursus 42.

Son objectif est de trier une pile d’entiers en utilisant un ensemble limité d’opérations, tout en minimisant le nombre total de mouvements.
Le programme reçoit une liste d’entiers en arguments et doit afficher sur la sortie standard la suite d’instructions permettant de trier les nombres dans l’ordre croissant.


Deux piles sont utilisées :

Pile A (pile principale contenant les nombres au départ)
Pile B (pile auxiliaire utilisée pour le tri)

Seules les opérations suivantes sont autorisées :

sa, sb, ss — swap (échange des deux premiers éléments)
pa, pb — push (déplacement du sommet d’une pile vers l’autre)
ra, rb, rr — rotate (rotation vers le haut)
rra, rrb, rrr — reverse rotate (rotation vers le bas)

Le défi principal consiste à produire le moins d’opérations possible, tout en garantissant un tri correct.



Fonctionnalités:


Parsing et validation des arguments - Gestion des erreurs (arguments invalides, doublons, overflow)

Attribution d’index pour simplifier le tri

Stratégie de réinsertion optimisée - Calcul du coût de déplacement

Détermination de la position cible dans la pile A

Utilisation des rotations combinées (rr et rrr)

Gestion spécifique pour les petits ensembles (≤ 3 éléments)

Gestion des ensembles moyens et grands (100+ éléments)



Instructions:

Compilation

Cloner le dépôt puis compiler avec make :

git clone <repository_url>
cd push_swap
make

L’exécutable push_swap sera généré.


Utilisation

Exécuter le programme avec une liste d’entiers :

./push_swap 2 1 3 6 5 8

Le programme affichera la liste des instructions nécessaires pour trier la pile.


Exemple
./push_swap 3 2 1

Sortie possible :

sa
rra



Aperçu de l’algorithme:


La stratégie de tri utilisée repose sur les étapes suivantes :

1) Création d’un tableau trié pour attribuer un index à chaque nombre.

2) Envoi de tous les éléments sauf trois vers la pile B.

3) Tri des trois éléments restants dans la pile A.


Réinsertion des éléments de B vers A :

1) Calcul du coût de rotation pour chaque élément.

2) Sélection de l’élément le moins coûteux.

3) Utilisation des rotations combinées (rr / rrr) lorsque possible.

4) Rotation finale pour placer le plus petit élément en tête de la pile A.

Cette approche permet de réduire significativement le nombre d’opérations par rapport à un tri naïf.



Commandes pour utiliser le checker:

1) Pour tester 100 nombres:

ARG=$(shuf -i 0-99 -n 100 | tr '\n' ' '); valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $ARG | ../checker_linux $ARG

2) Pour tester avec 500 nombres:

ARG=$(shuf -i 0-499 -n 500 | tr '\n' ' '); valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $ARG | ../checker_linux $ARG

3) Pour compter les opérations on ajoute:

./push_swap $ARG | wc -l



Ressources:

Références

Sujet officiel Push_swap (42)

Listes chaînées en C
https://chgi.developpez.com/liste/

Algorithmes
https://medium.com/@ayogun/push-swap-c1f5d2d41e97



Utilisation de l’IA:

Des outils d’intelligence artificielle ont été utilisés pour :

1) Comprendre et corriger certaines boucles infinies

2) Optimiser la logique des rotations combinées (rr / rrr)

3) Vérifier la cohérence algorithmique

4) Améliorer la clarté de la documentation

Toutes les décisions algorithmiques, l’implémentation, les tests et la validation finale ont été réalisés manuellement.



Auteur:

Login : massah
Étudiante à 42

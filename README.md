# Minishell - Résumé

Petit projet de shell minimal d'Epitech.

## Tests de robustesse

- Tests mémoire : utilisation de `valgrind --leak-check=full --show-leak-kinds=all ./mysh` pour détecter toute fuite mémoire.
- Exemple de commande :

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./mysh <<EOF
exit
EOF
```

- Objectif : garantir l'absence de fuites mémoires (leaks) et corriger les erreurs détectées par Valgrind avant la livraison.

# Unix Shell Implementation

## Overview
Ce projet est une implémentation en C d'un interpréteur de commandes UNIX. L'objectif était de recréer les mécanismes fondamentaux d'un shell (type Bash) en communiquant directement avec le noyau via des appels système.

## Features
* **Exécution de commandes** : Gestion des chemins (PATH), des arguments et des exécutables.
* **Built-ins** : Commandes internes comme `cd`, `env`, `setenv`, `unsetenv` et `exit`.
* **Opérateurs logiques** : Gestion des séparateurs de commandes (`;`).
* **Redirections & Pipes** : Implémentation des flux de données entre processus via `|`, `>`, `>>`, `<` et `<<`.
* **Robustesse** : Gestion des signaux (Ctrl+C, etc.) et des erreurs système (Segfault, Command not found).

## Key Skills
* **Programmation Système** : Manipulation des processus (fork, exec, wait) et des descripteurs de fichiers.
* **Gestion Mémoire** : Allocation dynamique et libération propre des ressources en C.
* **Analyse de données** : Parsing et traitement de chaînes de caractères complexes (tokens).

## Usage
```bash
make
./mysh 
```

## Tests de robustesse

- Tests mémoire : utilisation de `valgrind --leak-check=full --show-leak-kinds=all ./mysh` pour détecter toute fuite mémoire.
- Exemple de commande :

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./mysh <<EOF
exit
EOF
```

- Objectif : garantir l'absence de fuites mémoires (leaks) et corriger les erreurs détectées par Valgrind avant la livraison.


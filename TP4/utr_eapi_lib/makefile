###############################################################################
# ESIEE Paris
# Algorithmique et programmation pour l'ingénieur
#
# TP3 — Évaluation des performances du vecteur
#
# Ce Makefile permet de compiler les exécutables du TP, avec plusieurs variantes :
# - compilation standard optimisée ;
# - compilation en mode debug ;
# - compilation avec couverture de code ;
# - compilation de différentes versions de l'implémentation.
###############################################################################

# Compilateur utilisé
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -I./headers

# Bibliothèques utilisées
LIBS = -lm

# Liste des programmes principaux à exclure des sources communes
IGNORE_FILES = test_unit bench_vector conditional_compilation_demo

# Liste des fichiers sources communs
SRCS = $(filter-out $(IGNORE_FILES:%=./src/%.c), $(wildcard ./src/*.c))

# Configuration par défaut
TARGETS = test_unit bench_vector conditional_compilation_demo
SUFFIX =

# Mode couverture de code
ifeq ($(COVERAGE), 1)
	CFLAGS += -g --coverage
	TARGETS = test_unit
	SUFFIX = _cov
else
	# Mode debug
	ifeq ($(DEBUG), 1)
		CFLAGS += -g
		SUFFIX = _debug
	else
		CFLAGS += -O2
	endif
endif

# Choix de la version de l'implémentation
ifeq ($(VERSION), 2)
	CFLAGS += -DVERSION=2
	SUFFIX := _v2$(SUFFIX)
endif

ifeq ($(VERSION), 3)
	CFLAGS += -DVERSION=3
	SUFFIX := _v3$(SUFFIX)
endif

# Liste des fichiers objets communs
OBJS = $(SRCS:./src/%.c=./objs/%$(SUFFIX).o)

# Liste des exécutables à générer
TARGETS_BIN = $(TARGETS:%=./bin/%$(SUFFIX))

# Cible par défaut : génère tous les exécutables
all: $(TARGETS_BIN)

# Génération d'un exécutable
$(TARGETS_BIN): ./bin/% : ./objs/%.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

# Compilation d'un fichier source en fichier objet
./objs/%$(SUFFIX).o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Exécution des tests unitaires
run: ./bin/test_unit$(SUFFIX)
	./bin/test_unit$(SUFFIX)

# Exécution avec Valgrind pour détecter les erreurs mémoire
valgrind: ./bin/test_unit$(SUFFIX)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./bin/test_unit$(SUFFIX)

# Génération de la couverture de code
coverageee:
	$(MAKE) clean
	$(MAKE) COVERAGE=1
	./bin/test_unit_cov
	lcov -c -d ./objs/ -o ./coverage/index_cov.info
	genhtml ./coverage/index_cov.info -o ./coverage/html_cov --ignore-errors source
	rm -f ./objs/*.gcda

# Nettoyage des fichiers générés
clean:
	rm -f ./objs/* ./src/*~ ./headers/*~ ./bin/*
	rm -rf ./coverage/*

# Affichage des variables utiles
info:
	@echo "SRCS        = $(SRCS)"
	@echo "OBJS        = $(OBJS)"
	@echo "TARGETS     = $(TARGETS)"
	@echo "TARGETS_BIN = $(TARGETS_BIN)"
	@echo "CFLAGS      = $(CFLAGS)"
	@echo "SUFFIX      = $(SUFFIX)"

###############################################################################
# End of Makefile
###############################################################################

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

// Pour la listeToken

listeToken ajouteElement(listeToken l, typeToken_t type, int valeur, char symbole)
{
	listeToken ltmp,l2;
	ltmp=malloc(sizeof(struct token));
	ltmp->suiv=NULL;
	ltmp->type=type;
	ltmp->valeur=valeur;
	ltmp->symbole=symbole;
	if(l==NULL) return ltmp;
	l2=l;
	while(l->suiv!=NULL) l=l->suiv;
	l->suiv=ltmp;
	return l2;
}

listeToken libereMemoire(listeToken l)
{
	if(l!=NULL)
	{
		l->suiv=libereMemoire(l->suiv);
		free(l);
	}
	return NULL;
}

void afficherListe(listeToken l)
{
	while(l!=NULL)
	{
		if(l->type==ENTIER) printf("%d",l->valeur);
		else printf("%c",l->symbole);
		l=l->suiv;
	}
	printf("\n");
}

// Pour l'arbreToken

arbreToken ajouteElementArbre(typeToken_t type, int valeur, char symbole)
{
	arbreToken a;
	a=malloc(sizeof(struct tokenBis));
	a->droite=NULL;
	a->gauche=NULL;
	a->type=type;
	a->valeur=valeur;
	a->symbole=symbole;
	return a;
}

arbreToken libereMemoireArbre(arbreToken a)
{
	if(a!=NULL)
	{
		a->droite=libereMemoireArbre(a->droite);
		a->gauche=libereMemoireArbre(a->gauche);
		free(a);
	}
	return NULL;
}

void afficherArbre(arbreToken arbre, int a)
{
    for (int i=0; i < a; i++) printf("|___ ");
	if(arbre->type==ENTIER) printf("[%d]\n",arbre->valeur);
	else printf("[%c]\n",arbre->symbole);
    if(arbre->gauche) afficherArbre(arbre->gauche,a+1);
    if(arbre->droite) afficherArbre(arbre->droite,a+1);
}
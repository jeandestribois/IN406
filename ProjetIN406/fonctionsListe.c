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

listeToken ajouteElementDroite(listeToken l, typeToken_t type, int valeur, char symbole)
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

listeToken libereMemoireArbre(listeToken l)
{
	if(l!=NULL)
	{
		l->suiv=libereMemoire(l->suiv);
		free(l);
	}
	return NULL;
}
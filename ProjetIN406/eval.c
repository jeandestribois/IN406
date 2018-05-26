#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "types.h"
#include "fonctionsListe.h"


listeToken stringToToken(char *s)
{
	listeToken l=NULL;
	int i=0;
	int nb;
	while(s[i]!='\0')
	{
		if(s[i]=='(' || s[i]==')') l=ajouteElement(l,PARENTHESE,-1,s[i]);
		else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') l=ajouteElement(l,OPERATEUR,-1,s[i]);
		else if(isdigit(s[i]))
		{
			nb=s[i]-'0';
			for(int j=i+1; isdigit(s[j]); j++)
			{
				nb=nb*10+s[j]-'0';
				i++;
			}
			l=ajouteElement(l,ENTIER,nb,'\0');
		}
		else if(s[i]==' ');
		else
		{
			fprintf(stderr,"Erreur : carractere '%c' non reconnu dans l'expression donnée\n",s[i]);
			l=libereMemoire(l);
			exit(0);
		}
		i++;
	}

	return l;
}

void estArithmetique(listeToken l)
{
	int pileParenthese=0;						// Compte le nombre de parenthese
	int precOperateur=1;						// Si le token précédent est un operateur (on l'initialise à 1 pour nous permettre de commencer avec une parenthese)
	int precEntier=0;								// Si le token précédent est un entier
	int precParentheseFermante=0;		// Si le token précédent est une parenthese fermante
	int erreur=0;											// Pour retenir les erreurs

	while(l!=NULL && !erreur)
	{
		if(l->type==ENTIER)
		{
			if(!precParentheseFermante && !precEntier) 
			{
				precEntier=1;
				precOperateur=0;
			}
			else erreur=1;
		}
		else if(l->type==OPERATEUR)
		{
			if(precEntier)
			{
				precOperateur=1;
				precEntier=0;
			}
			else erreur=2;
		}
		else if(l->type==PARENTHESE)
		{
			if(l->symbole=='(' && !precEntier)
			{
				pileParenthese++;
				precOperateur=0;
			}
			else if(l->symbole==')' && !precOperateur)
			{
				pileParenthese--;
				precParentheseFermante=1;
				precEntier=0;
			}
			else erreur=3;
		}
		l=l->suiv;
	}
	if(erreur || pileParenthese)
	{
		fprintf(stderr,"Erreur : Ce n'est pas une expression arithmetique reconnu\n");
		l=libereMemoire(l);
		exit(0);
	}
	printf("C'est bien une expression arithmetique\n");
}

arbreToken constructionArbre(listeToken l)
{
	arbreToken a=NULL;
	while(l!=NULL)
	{


		l=l->suiv;
	}
	return a;
}

int main(int argc, char *argv[])
{
	if(argc<2)						// On verifie qu'on nous donne bien un argument apres l'executable
	{
		fprintf(stderr,"Erreur : mauvais usage de l'executable.\nUsage correct : %s <expression>\n",argv[0]);
	}
	
	char s[100]="";
	for(int i=1; i<argc; i++) strcat(s,argv[i]);

	listeToken l=stringToToken(s);

	afficherListe(l);

	estArithmetique(l);

	l=libereMemoire(l);

	exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "types.h"
#include "fonctionsListe.h"


listeToken stringToToken(char *s)
{
	if(s==NULL)					// Si la chaine est vide
	{
		fprintf(stderr,"Erreur : la chaine de carractère donné en argument est vide\n");
		exit(0);
	}

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
	int pileParenthese=0;

	if(l->type==PARENTHESE && l->symbole=='(')
	{
		pileParenthese++;
		l=l->suiv;
		while(l!=NULL)
		{
			if(l->type==ENTIER) l=l->suiv;
			else if(l->type==)
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc!=2)						// On verifie qu'on nous donne bien un argument apres l'executable
	{
		fprintf(stderr,"Erreur : mauvais usage de l'executable.\nUsage correct : %s \"<expression>\"\n",argv[0]);
	}
	
	listeToken l=stringToToken(argv[1]);
	
	afficherListe(l);

	l=libereMemoire(l);

	exit(0);
}
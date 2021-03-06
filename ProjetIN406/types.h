typedef enum typeToken
{
	PARENTHESE,
	OPERATEUR,
	ENTIER	
}typeToken_t;

struct token
{
	typeToken_t type;
	int valeur;				// Egal à -1 lorsque c'est un symbole
	char symbole;			// Egal à '' lorsque c'est un entier
	struct token *suiv;
};
typedef struct token* listeToken;

struct tokenBis
{
	typeToken_t type;
	int valeur;
	char symbole;
	struct tokenBis *droite;
	struct tokenBis *gauche;
};
typedef struct tokenBis* arbreToken;

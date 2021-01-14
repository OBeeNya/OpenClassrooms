=== OPENCLASSROOMS : APPRENEZ A PROGRAMMER EN C ! ===

1. Directives de preprocesseur :
 
        #include <library.h>
	#include "header.h"
 
2. Types de variables

	2.1. Nombres entiers 
           
		-127 <= signed char <= 127
		0 <= unsigned char <= 255               
 
		-32 767 <= int <= 32 767
 		0 <= unsigned int <= 65 535
 
 		-2 147 483 647 <= long <= 2 147 483 647
 		0 <= unsigned long <= 4 294 967 295
 
 	2.2. Nombres decimaux
 
		-1 * 1 037 <= float / double <= 1 037
 		double plus precis
 
 	2.3. Constantes
 
		const int EXEMPLE = 0 ;

	2.4. Afficher / scanner contenu

		"%d" : int , &int
		"%ld" : long , &long
		"%f" : float / double , &float / &double
		"%p" : adresse memoire

3. Operations

	3.1. Calculs de base	

		+ addition
		- soustraction
		* multiplication
		/ division
		% modulo
		++ incrementation
		-- decrementation
		+= , -= , *= , /= , %=

	3.2. <math.h>

		fabs () = absolu
		ceil () = arrondi superieur
		floor () = arrondi inferieur
		pow ( , ) = puissance
		sqrt = racine carree
		sin, cos, tan
		etc.

4. Conditions

	4.1. Symboles

		== egal
		> superieur
		< inferieur
		>= superieur ou egal
		<= inferieur ou egal
		!= different

	4.2. if

		if ( condition )
		{
			instructions ;
		}

	4.3. if ... else

		if ( condition )
		{
			instructions ;
		}
		else
		{
			instructions2 ;
		}

	4.4. if ... else if ... else

		if ( condition )
		{
			instructions ;
		}
		else if ( condition2 )
		{
			instructions2 ;
		}
		else
		{
			instructions3 ;
		}

	4.5. Conditions multiples 

		&& et
		|| ou
		! non

	4.6. Booleans

		0 : faux
		1 ou tout autre nombre : vrai

	4.7. switch

		switch ( variable )
		{
			case 1 :
				instructions ;
				break ;
			case 2 :
				instructions2 ;
				break ;
			default :
				instructions3 ;
				break ;
		}

	4.8. Ternaires

		variable = ( condition ) ? valeur si 1 : valeur si 0 ;

5. Boucles

	5.1. while

		while ( condition )
		{
			instructions ;
		}

	5.2. do ... while

		do
		{
			instructions ;
		} while ( condition ) ;

	5.3. for

		for ( initialisation ; condition ; operation )
		{
			instructions ;

		}

6. Fonctions

	6.1. Declaration

		type nomFonction ( parametres d'entree )
			{
				instructions ;
			}

	Il est interdit de declarer une fonction a l'interieur d'une autre fonction.

	6.2. Prototypes

		type nomFonction ( parametres d'entree ) ;

		Les prototypes sont typiquement stockes dans les headers.

	6.3. Portee

	Une variable declaree dans une fonction n'est accessible que dans celle-ci = variable locale.

	Une variable declaree en dehors d'une fonction sera accessible dans toutes les fonctions de tous les fichiers du projet = variable globale = A BANNIR !

	static variable = accessible uniquement aux fonctions de ce fichier.

	static variable a l'interieur d'une fonction = la variable gardera la valeur de la derniere fois.

	static fonction = fonction uniquement accessible dans ce fichier.

7. Pointeurs

	type *pointeurSurVariable = NULL ;
	type *pointeurSurVariable = &variable ;

	printf ( "%d" , pointeurSurVariable ) => adresse de la variable
	printf ( "%d" , *pointeurSurVariable ) => valeur de la variable
	printf ( "%d" , &poinnteurSurVariable ) => adresse du pointeur

	Envoyer un pointeur a une fonction :

		int variable = x ; // declaration de variable
		int fonction ( *pointeurSurVariable ) {instructions} // declaration de la fonction sans avoir besoin de declarer la variable pointeur
		fonction ( &variable ) // permet d'appliquer la fonction sur n'importe quelle variable meme si celle ci ne fera pas partie de la declaration de la fonction

		ou pour le meme resultat 

		int variable = x ;
		int *pointeurSurVariable = &variable ;
		fonction ( pointeurSurVariable ) ;

8. Tableaux

	Déclaration de tableau :
		int tab[4];
		tab[0] = 1;
		tab[1] = 2;
		tab[2] = 4;
		tab[3] = 8;

	Un tableau correspond à un pointeur :
		int tab[2];
		printf("%d", tab)	; // adresse de la première case du tableau.
		printf("%d",tab[0]); // valeur de la première case.
		printf("%d", *tab); // valeur de la première case.
		printf("%d", *(tab + 1)); // valeur de la deuxième case.

	Tableau à taille dynamique = tableau dont la taille est définie par une variable.
	Allocation dynamique.

	Parcourir un tableau :
		int tab[2], i = 0;
		tab[0]=1;
		tab[1]=2;

		for (i=0; i<2; i++){ // la variable i est souvent utilisée pour parcourir des tableaux
			printf("%d", tab[i]);
		}

	Initialiser toutes les valeurs d'un tableau :
		int tab[2], i=0;
		for (i=0; i<2; i++){
			tab[i]=0; // toutes les variables du tableau sont initialisées à 0
		}

	Autre façon d'initialiser :
	int tab[4] = {0, 0, 0, 0} ; // si l'on ne renseigne les valeurs que des premières cases, les autres prennent automatiquement la valeur 0

	Envoyer un tableau à une fonction : // lors de la déclaration de la fonction, pas lors de son utilisation
		void fonction(*tab)
		ou
		void fonction(tab[]) // plus clair ici car les crochets permettent de comprendre que la fonction attend un tableau

9. Chaînes de caractères

	char lettre = 'A';
	printf("%c", lettre);
	printf("%s", string);

	http://www.asciitable.com/

	Une chaîne de caractères est un tableau de variables de type char.
	La chaîne de caractère doit se terminer par "\0" pour indiquer à l'ordinateur que la chaîne s'arrête.

	Initialisation manuelle :
		char mot[4]={'M','o','t','\0'};

	Initialisation simplifiée :
		char mot[] = "Mot"; // la taille du tableau est automatiquement calculée
		ou char *mot = "Mot";
	L'initialisation simplifiée ne fonctionne que pour l'initialisation; on ne peut pas changer sa valeur ultérieurement juste en mettant char = "qch"

	#include <string.h>
		
		strlen : calcul la longueur d'une chaîne (sans compter le \0)
		size_t strlen(const char* chaine); // size_t est un type de variable personnalisé ; const permet d'assurer que la fonction ne modifie pas la variable chaine
		
		strcpy : copier une chaîne dans une autre
		char* strcpy ( char* copieDeLaChaine , const char* chaineACopier ) ;
				  
		strcat : concaténer 2 chaînes
		char* strcat ( char* chaine1 , const char* chaine2 ) ;
				  
		strcmp : comparer 2 chaînes, rend 1 si différentes ou 0 si identiques (oui c'est contre-intuitif)
		int strcmp ( const char* chaine1 , const char* chaine2 ) ;
										       
		strchr : rechercher un caractère
		char* strchr ( cosnt char* chaine , int caractereARechercher ) ;
		strrchr : renvoie à partir du dernier caractère recherché
		
		strpbrk : recherche le premier caractère de la liste apparaissant
		char* strpbrk ( const char* chaine , const char* lettresARechercher ) ;							
		
		strstr : recherche d'une chaîne dans une autre
		char* strstr ( const char* chaine1, const char* chaineARechercher ) ;
		
		sprintf : écrire dans une chaîne
		char sprintf ( char , "%" , variable ) ; // prototype à revoir / améliorer
		Attention n'imprime rien comme printf mais modifie uniquement la chaîne.
		
10. Le préprocesseur										       
								       
	Déjà vu #include <library.h> et #include "header.h"
										       
	#define : constante de préprocesseur
	Similaire à une variable constante sauf que :
		- ça n'occupe pas de mémoire et ça remplace à chaque fois dans le fichier le mot par la valeur (à la manière d'un ctrl+f) ;
		- le remplacement se fait pour toutes les fonctions du fichier.
	Les #define sont généralement classés dans les headers.
				  
	Exemples :
		- #define LARGEUR_FENETRE 800  1 #ifndef STRUCTUREH
		  #define HAUTEUR_FENETRE 600
		- #define TAILLE_MAX_TABLEAU 1000
		  char tab[TAILLE_MAX_TABLEAU]
	
	Calculs dans #define : 
		#define LARGEUR_FENETRE 800
		#define HAUTEUR_FENETRE 600
		#define NOMBRE_PIXELS (LARGEUR_FENETRE * HAUTEUR_FENETRE)
				  
	Constantes prédéfinies :
		__LINE__
		__FILE__
		__DATE__
		__TIME__
		
	Définition simple #define CONSTANTE , sans donner immédiatement de valeur.
				  
	Macro : #define NOM_DE_LA_MACRO() instructions ;
	exemple : #define COUCOU() printf("Coucou");
	Pour une macro avec du code sur plusieurs lignes, mettre un \ à la fin de chaque ligne.
	
	Macro avec paramètre : #define NOM_DE_LA_MACRO(noms des variables) instructions; 
		
	Conditions en langage préprocesseur :
		#if condition
			code source
		#elif condition2
			code source2
		#endif
	Permet de compiler du code uniquement si une condition de base est vraie.
				  
	#ifdef CONSTANTE / #ifndef CONSTANTE : si la constante est définie / n'est pas définie.
	Peut se coupler avec définition simple.
	Exemple :
		#define NOM_DE_L_OS_UTILISE
		#ifdef WINDOWS
			code source
		#ifdef LINUX
			code source2
		#ifdef MAC
			code source3
		#endif
										       
	Si 2 fichiers headers se référencent l'un l'autre, utiliser #ifndef :
		#ifndef DEF_NOMDUFICHIER // si la définition de la ligne en-dessous n'a jamais été faite, le code de ce fichier sera exécuté 
		#define DEF_NOMDUFCHIER // on fait la définition ce qui permettra de ne pas exécuter une nouvelle fois le code de ce fichier
			code du fichier header
		#endif
	Ceci évite qu'une combinaison de préprocesseurs fasse tourner l'ordi à l'infini et le fasse planter.
				
11. Créer son propre type de variable

	11.1. Les structures
	
		Assemblage de variables dont les types peuvent être différents.
		struct NomDeLaStructure {
			int var1 ;
			float var2 ;
			char var3 ;
		} ; // attention à ne pas oublier le point virgule
		Une structure peut contenir un tableau. Elle sera définie dans le header.
				  
		Pour l'utiliser dans une fonction : 
		struct NomDeLaStructure nomDeLaVariable ;
				  
		Pour éviter de retaper struct à chaque fois que l'on veut créer une variable, taper ceci avant : 
			typedef struct NomDeLaStructure NomDeLaStructure ; // typedef + struct NomDeLaStructure + NomDeLaStructure
				  
		Modifier les composantes de la structure :
			variable.Composante = 10 ;
				  
		Possibilité de créer un tableau de structure :
			structure tableau[] ;
		Modifier valeur d'une structure d'un tableau :
			exemple : scanf("%s" , tableau[i].variable ) ;
		
		Initialiser une structure :
			variableDeTypeStructure = { "" ; 0 } ; // méthode manuelle
			Possibilité d'initialiser une structure en l'envoyant via pointeur à une fonction désignée pour ça.
			
		Pointeur de structure :
			Structure *variable = NULL ; // identique à un pointeur d'autre type de variable
			void initialiserStructure ( structure *variable ) {
				( *variable ).sousVariable = 0 ; // les parenthèses sont nécessaires car le . ne s'applique sinon qu'à variable
			}
			On peut également écrire (dans la fonction) :
				  variable->sousVariable = 0 ; // ne fonctionne que sur un pointeur
				  
	11.2. Enumérations
	
		Une énumération ne contient pas des sous-variables mais une liste de valeurs possibles.
			enum Volume {
				FAIBLE , MOYEN , FORT // le compilateur donne automatiquement des valeurs réelles à chacune de ces valeurs mais peu importe lesquels
			} ;
		On peut ensuite créer une variable de type énumération Volume à laquelle on initialisera une valeur :
			Volume musique = FAIBLE ;
		On peut associer manuellement ces valeurs :
			enum Volume {
				MUET = 0 , FAIBLE = 10 , MOYEN = 50 , FORT = 100 
			} ;
										       
12. Lire et écrire dans des fichiers

	12.1. Ouvrir et fermer un fichier
	
		Fonction d'ouverture de fichier :
			FILE* fopen(const char* nomDuFichier, const char* modeOuverture); // FILE est une structure définie dans stdio.h
		Initialisation du pointeur .
			FILE* fichier = NULL ;
		modeOuverture :
			"r" lecture seule
			"w" écriture seule
			"a" mode d'ajout
			"r+" lecture et écriture
			"w+" lecture et écriture avec suppression du contenu au préalable
			"a+" ajout en lecture / écriture à la fin
		Fichier dans chemin relatif :
			variableFile ( "dossier/fichier.txt" , modeOuverture ) ; 
		Fichier dans chemin absolu :
			variableFile ( "C:\\Program Files\\Notepad\\fichier.txt" , modeOuverture ) ; // les 2 "\\" sont nécessaires pour signifier 1 "\"
										       
										       
										       
										       
										       
										       

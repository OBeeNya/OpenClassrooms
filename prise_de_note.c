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
	type *poinnteurSurVariable = &variable ;

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



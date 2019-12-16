#ifndef _H_PROJET2019_
#define _H_PROJET2019_



typedef struct {
ptrdiff_t decalage;
size_t nb_blocs;
} tranche;


typedef struct{
ptrdiff_t suivant;
size_t
nb_blocs;
} entete_tranche;


typedef union{
intmax_t a;
void *adr;
long double c;
}align_data;


typedef struct{
ptrdiff_t next;
ptrdiff_t previous;
size_t len;
align_data data[];
}node;


typedef struct{
void *memory;
//pointeur vers la memoire
ptrdiff_t first; //ptrdiff_t ou pointeur
ptrdiff_t last; //ptrdiff_t ou pointeur
ptrdiff_t libre; //ptrdiff_t ou pointeur si la liste de tranches
//toute autre information

 tranche *tab_tranches ;                        /*Dans l’implémentation avec le tableau de
								                      tranches on pourra remplacer ce champ par le pointeur vers ce tableau.*/
	 size_t memory_size ;                           // -la taille de la mémoire pointée par memory */
	 int elements_number ;							// -le nombre d’éléments de la liste
	 int nbr_free_block;                            // -le nombre de blocs libres
	 //toute autre information
	//ptrdiff_t libre; //ptrdiff_t ou pointeur si la liste de tranches

} head;


void * ld_create( size_t nboctets );

size_t nb_blocs(size_t o);

void * ld_creer( size_t nboctets );

void * ld_insert_first(void *liste, size_t len, void *p_data);

void *ld_first(void *liste);

#endif

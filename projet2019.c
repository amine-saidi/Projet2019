#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projet2019.h"

#define NTRANCHES 1024



void * ld_creer( size_t nboctets ){  

	head *liste =malloc(sizeof(head)); 
	if(liste==NULL){ printf("erreur allocation head \n"); return NULL;}
	
	liste->memory= malloc(nb_blocs(nboctets)*sizeof(align_data));;
	if(liste->memory==NULL){ printf("erreur allocation head \n"); return NULL; }

	liste->tab_tranches  = malloc( NTRANCHES * sizeof(tranche) ) ;

	liste->first=0;
	liste->last=0;

	liste->memory_size=nboctets;   
	liste->elements_number =0 ;
	liste->nbr_free_block=NTRANCHES ;
							                                               
	return liste;
}


/* calculer le nombre de bloc */
size_t nb_blocs(size_t o){
	size_t nb_blocs=(o+sizeof(align_data)-1)/sizeof(align_data);
	return nb_blocs;
}


void * ld_create( size_t nboctets )
{
	head *liste =malloc(sizeof(head)); 
	if(liste==NULL){ printf("erreur allocation head \n"); return NULL;}
	
	liste->memory= malloc(nb_blocs(nboctets)*sizeof(align_data));;
	if(liste->memory==NULL){ printf("erreur allocation head \n"); return NULL; }

	liste->tab_tranches  = malloc( NTRANCHES * sizeof(tranche) ) ;

	liste->first=0;
	liste->last=0;

	liste->memory_size=nboctets;   
	liste->elements_number =0 ;
	liste->nbr_free_block=NTRANCHES ;
							                                               
	return liste;

}


void * ld_insert_first(void *liste, size_t len, void *p_data){
     //il faut calculer le nombre de bloc 
	head* new_liste=liste;
	if(liste==NULL) {return NULL;}

	/*creation du noeud */ 
	/*node * new_node=malloc(sizeof(node)+len*sizeof(align_data));*/
	node * new_node=(node *)(new_liste->memory);
	if (new_node == NULL)return NULL;

	 ((node*) new_node)->next=len+2;
	 ((node*) new_node)->previous=0;
	 ((node*) new_node)->len =len+2 ; //la taille du nœud
	// align_data *  new_data = p_data;
	 memmove(new_node->data,p_data,len);

	/* if(ld_first(new_liste)==NULL){
		 new_liste->
	 }*/

	 /*if(((node * )new_liste->memory)->previous==0){
	 	new_liste->last =len;
	 	new_node->next=len;
	 	new_liste->memory =new_node; //on affecte noeud a qulle variable de head ???
	 	printf("la if  %ld \n",new_liste->last);
	 }
	 else{

	 	((node*)ld_first(new_liste))->previous += len+2;
	 
	    ((node*)ld_first(new_liste))->next +=len ;
	    new_liste->last+=new_node->len;
	    new_liste->memory =new_node;
	 }*/
	 return new_node;
}


void *ld_first(void *liste){

	head *new_liste=liste;

	if(liste==NULL){
		printf("la liste est vide !!! donc pas de first ..merci ! \n");
		return NULL;
	}
	return (align_data * ) new_liste->memory + new_liste->first;
}



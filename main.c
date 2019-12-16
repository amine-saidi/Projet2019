#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"projet2019.h"

#define NTRANCHES 1024



int main()
{
	printf("sizeof(align_data) = %d",sizeof(align_data) );
	printf("\nle nombre de blocs est %d",nb_blocs(1));


	head *hd=ld_creer(1024);
   	int a=10;
    	void * p_data =&a;
	node * n =ld_insert_first(hd,1,p_data);
	node * nd=ld_first(hd);
	printf("\n%d\n",*((int*)nd->data) );
	printf("%d\n",*((int*)((node *)hd->memory)->data) );
	printf("%ld\n",nd->next);
	printf("%ld\n",((node *)hd->memory)->next);



return 0;
}

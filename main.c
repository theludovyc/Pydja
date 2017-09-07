#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define File FILE
#include "tool.c"
#include "Tab.c"
#include "TabChar.c"
#include "TabInt.c"
#include "Ring.c"
#include "RingChar.c"
#include "RingInt.c"
#include "Lec.c"
#include "Num.c"
#include "Word.c"
#include "Init.c"

int main(){
	File *f=fopen("main","r");
    if(f!=null){
        Ring r=ring0(&r);
        char c;
        Lec l=lec(&l,&c,f);
        Init i=init(&i,&l,&r);
        
        lec_incC(&l);
    	printf("Debut avec: %d\n",c);

        if(c==35){
            init_read(&i);
        }else if(c==40||c==45||(c>47&&c<58)){
            num_read(&l);
        }
    	fclose(f);
    }

    system("PAUSE");
    return 0;
}
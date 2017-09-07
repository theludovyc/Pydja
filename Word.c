Tab word_read(Lec *l){
	if(lec_CisNum(*l)==0){
		Ring r=ringChar(&r,lec_getC(*l));
		while(1){
			lec_incC(l);
			if(lec_getC(*l)!=EOF&&lec_getC(*l)!=32&&lec_getC(*l)!=46){
				ringChar_addUp(&r,lec_getC(*l));
			}else{
				break;
			}
		}
		Tab t=tabChar(&t,ring_getNbEl(r));
		unsigned int i;
		for(i=0;i<t.nbEl;i++){
			tabChar_setEl(&t,i,ringChar_remUp(&r));
		}
		return t;
	}else{
		printf("word_read: Le mot a lire ne commence pas par une lettre!\n");
		exit(0);
	}
}

Tab word_read1(Lec *l, unsigned int i){
	if(lec_CisNum(*l)==0){
		Tab t=tabChar(&t,i);
		int i1;
		for(i1=0;i1<i;i1++){
			if(lec_getC(*l)!=EOF&&lec_getC(*l)!=32&&lec_getC(*l)!=46){
				tabChar_setEl(&t,i1,lec_getC(*l));
			}else{
				printf("word_read1: Fin de lecture avant longueur demandee!\n");
			}
			lec_incC(l);
		}
		if(lec_getC(*l)!=EOF&&lec_getC(*l)!=32&&lec_getC(*l)!=46){
			printf("word_read1: Fin de lecture mais le mot est plus grand!\n");
			exit(0);
		}else{
			return t;
		}
	}else{
		printf("word_read1: Le mot a lire ne commence pas par une lettre!\n");
		exit(0);
	}
}
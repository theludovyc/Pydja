struct Init{
	Lec *l;
	Ring *r;
};
typedef struct Init Init;

struct Stock{
	Tab tag;
	char type;
	void *r;
};
typedef struct Stock Stock;

Init init(Init *i, Lec *l, Ring *r){
	(*i).l=l;
	(*i).r=r;
	return *i;
}

init_read(Init *i){
	lec_incC((*i).l);
	Stock t;
	t.tag=word_read1((*i).l,3);
	lec_incC((*i).l);
	char ty=lec_getC((*(*i).l));
	lec_incC((*i).l);
	if(lec_getC((*(*i).l))==123){

	}else{
		lec_incC((*i).l);
		Tab ta;
		if(ty=='w'){
			ta=tabInt(&ta,num_read((*i).l));
		}
	}
	printf("%c\n",lec_getC((*(*i).l)));
}
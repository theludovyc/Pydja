struct Lec{
	char *c;
	File *f;
	Ring r;
};
typedef struct Lec Lec;

Lec lec(Lec *l, char *c, File *f){
	(*l).c=c;
	(*l).f=f;
	(*l).r=ring0(&(*l).r);
	return *l;
}

char lec_getC(Lec l){
	return *(l.c);
}

lec_incC(Lec *l){
	*(*l).c=fgetc((*l).f);
}

char lec_CisNum(Lec l){
	if(lec_getC(l)>47&&lec_getC(l)<58){
		return 1;
	}
	return 0;
}
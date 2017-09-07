num_getNum(Lec *l, Ring *r){
	int i=1;
	int i1=0;
	if(ring_getNbEl(*r)>1){
		ringChar_rollUp(r);
	}
	while(ring_getNbEl(*r)>0){
		char c=ringChar_remDown(r);
		if(c==45){
			i1*=-1;
			break;
		}else{
			i1+=(c-'0')*i;
			i*=10;
		}
	}
	ringInt_addUp(&(*l).r,i1);
}

num_readNum(Lec *l){
	Ring r=ringChar(&r,lec_getC(*l));
	while(1){
		lec_incC(l);
		if(lec_CisNum(*l)){
			ringChar_addUp(&r,lec_getC(*l));
		}else{
			break;
		}
	}
	num_getNum(l,&r);
}

void num_read1(Lec *l);

void num_debOp(Lec *l);

num_multi(Lec *l){
	num_debOp(l);
	ringInt_set(&(*l).r,ringInt_remDown(&(*l).r)*ringInt_get((*l).r));
	printf("*: %d\n",ringInt_get((*l).r));
}

num_div(Lec *l){
	num_debOp(l);
	ringInt_set(&(*l).r,ringInt_remDown(&(*l).r)/ringInt_get((*l).r));
	printf("/: %d\n",ringInt_get((*l).r));
}

void num_debOp1(Lec *l);

num_addi(Lec *l){
	num_debOp1(l);
	ringInt_set(&(*l).r,ringInt_remDown(&(*l).r)+ringInt_get((*l).r));
	printf("+: %d\n",ringInt_get((*l).r));
}

num_sous(Lec *l){
	num_debOp1(l);
	ringInt_set(&(*l).r,ringInt_remDown(&(*l).r)-ringInt_get((*l).r));
	printf("-: %d\n",ringInt_get((*l).r));
}

void num_debOp(Lec *l){
	lec_incC(l);
	if(lec_getC(*l)==40){
		num_read1(l);
	}else{
		num_readNum(l);
	}
}

void num_op(Lec *l);

void num_debOp1(Lec *l){
	lec_incC(l);
	if(lec_getC(*l)==40){
		num_read1(l);
	}else{
		num_readNum(l);
		num_op(l);
	}
}

void num_op(Lec *l){
	if(lec_getC(*l)==42){
		num_multi(l);
	}else if(lec_getC(*l)==43){
		num_addi(l);
	}else if(lec_getC(*l)==45){
		num_sous(l);
	}else if(lec_getC(*l)==47){
		num_div(l);
	}
}

int num_read(Lec *l){
	if(lec_getC(*l)==40){
		num_read1(l);
	}else{
		num_readNum(l);
	}
	while(1){
		if(lec_getC(*l)!=42&&lec_getC(*l)!=43&&lec_getC(*l)!=45&&lec_getC(*l)!=47){
			break;
		}else{
			num_op(l);
		}
	}
	return ringInt_get((*l).r);
}

void num_read1(Lec *l){
	lec_incC(l);
	if(lec_getC(*l)==40){
		num_read1(l);
	}else{
		num_readNum(l);
	}
	do{
		num_op(l);
	}while(lec_getC(*l)!=41);
	lec_incC(l);
}
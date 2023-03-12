List neighbors(Graph* pG, int x) {
	int n,e;
	List L;
	make_null(&L);
	for(n=1;n<=pG->n;n++) {
		if(n==x) continue;
		for(e=1;e<=pG->m;e++) {
			if(pG->A[x][e] == 1 && pG->A[n][e] == 1) {
			    if(count_list(&L) == 0) {
			        push_back(&L, n);
			        continue;
			    }
				
				if(n != element_at(&L, count_list(&L)))
				push_back(&L, n);
			}	
		}	
	}
return L;
}

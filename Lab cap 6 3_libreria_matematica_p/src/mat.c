void calcola_max(int*x,int*y,int*max){
	if(x>=y) *max=*x;
	else 	 *max=*y;
}

void calcola_min(int*x,int*y,int*min){
	if(x<y) *min=*x;
	else 	*min=*y;
}

void calcola_med(int*x,int*y,float* med){
	*med=*x+*y;
	*med/=2;
}

void val_ass(int*x,int*val){
	if (x<0) *val=-*x;
	else 	 *val=*x;
}

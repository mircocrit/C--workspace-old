#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int giorno;
	int mese;
	int anno;
}data;

data inserimento_data(){
	data d;
	int controllo_giorno(data);
	int flag=0;
	do {
		printf("Anno: ");
		scanf("%d",&d.anno);
		if(d.anno<0)
			printf("Anno non valido! Inserire anno maggiore di 0!\n");
	}while(d.anno<0);

	do {
		printf("Mese: ");
		scanf("%d",&d.mese);
		if(d.mese<0||d.mese>12)
			printf("Mese non valido! Inserire un mese valido [1-12]!\n\n");
	}while(d.mese<0||d.mese>12);

	do{
		printf("Giorno: ");
		scanf("%d",&d.giorno);
		flag=controllo_giorno(d);
		if (flag==0)
			printf("Data non corretta!\nReinserire il giorno!\n");
	}while(flag==0);
	return d;
}

int controllo_giorno(data d){
	int flag=0,bisest;

	if(d.anno%4==0)		bisest=1;
	else	bisest=0;

	if((d.mese==1||d.mese==3||d.mese==5||d.mese==7||d.mese==8||d.mese==10||d.mese==12) && (d.giorno>0 && d.giorno<32)){
		flag=1;
	}else{
	if((d.mese==4||d.mese==6||d.mese==9||d.mese==11)&&(d.giorno>0 && d.giorno<31)){
		flag=1;
	}else{
		if((d.mese==2)&&((d.giorno>0&&d.giorno<29 && bisest==0)||(d.giorno>0 && d.giorno<30 && bisest==1))){
		flag=1;
			}
		}
	}

	return flag;
}

int elabora_dati(data d){
	int i,giorni=0;
	for(i=1;i<d.mese;i++){	//5
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
			giorni+=31;
		}else{
			if(i==4||i==6||i==9||i==11){
				giorni+=30;
			}else{
				if(i==2){
					if((d.anno%4)==0)	giorni+=29;
					else	giorni+=28;
				}
			}
		}
	}
	giorni+=d.giorno-1;
	return giorni;
}

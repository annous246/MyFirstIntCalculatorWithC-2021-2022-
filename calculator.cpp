#include <stdio.h>
#include<stdlib.h>


int abs(int k){
	if (k>=0){
		return k;
	}
	return -k;
	
}



int length(char c[50]){
	int i=-1;
	do{
		
		i++;
	}while(c[i]!='\0');
	return i;
}

int  operation(int a,int b,char c){
	switch(c){
		case('-'):return a-b;break;
		case('+'):return a+b;break;
		case('*'):return a*b;break;
		case('/'):return a/b;break;
	}
	return 0;
}


int partconversion(char c,int *p){
	*p=0;
		*p=((int)c-(int)'0');
	}
	

int conversion(char c[50],int *p){
	int k=1;
	*p=0;
	for(int i=0;i<length(c);i++){
		*p+=((int)c[length(c)-i-1]-(int)'0')*k;
		if(c[length(c)-i-1]=='-'){
			*p-=((int)'-'-(int)'0')*k;
			*p*=-1;
		}
		k*=10;
	}}


int checker(char s[50]){
	char tab[100]={'-','+','*','/','(',')','1','2','3','4','5','6','7','8','9','0'};
	int ok=0,par=0,l=0,r=0;
	for(int j=0;j<length(s);j++){
	for(int i=0;i<16;i++){
		if(tab[i]==s[j]){
		if(i==4){l++;	
		}
		if(i==5){r++;	
		}
		 ok++;
     	if(i<4){
    	for(int p=0;p<4;p++){
	    	if(s[j-1]==tab[p]||s[j+1]==tab[p]){
		    	return 0;
	    	}
	
	}}
	
		
	 }
	}
	if(s[j]=='('||s[j]==')'){
		par++;
	}
		
	}
	if((ok==length(s))&&(par%2==0)&&(l==r)){
		return 1;
	}
	else{
		return 0;
	}
	
}

int symb(char s){
		char tab[10]={'-','+'},tabp[10]{'*','/'};
		int ok=0;
    	for(int p=0;p<2;p++){
		if(tabp[p]==s){
		return 1;
		 }}
    	for(int p=0;p<2;p++){
		if(tab[p]==s){
		return 2;}}
		if(s==')'||s=='('){
			return -1;
		}
		 	return 0;
		 
	
	
}

int deletestr(char c[50],int p,int n){
	for(int i=0;i<n;i++){
	for(int j=0;j<length(c)-p+1;j++){
		c[p+j]=c[p+j+1];
	}
		
	}	
}


int insertstr(char a[50],char c[50],int p){
	for(int i=0;i<length(a);i++){
	for(int j=0;j<length(c)-p;j++){
		c[length(c)-j]=c[length(c)-1-j];
	}}
	for(int i=0;i<length(a);i++){
		c[i+p]=a[i];
}
c[length(c)]='\0';
}


int inv(char c[50]){
	if (c[0]=='-'){
	
	for(int i=1;i<(length(c)+1)/2;i++){
		int x= c[i];
		c[i]=c[length(c)-i];
		c[length(c)-i]=x;
		
	}}
	else{
	for(int i=0;i<(length(c))/2;i++){
		int x= c[i];
		c[i]=c[length(c)-1-i];
		c[length(c)-1-i]=x;
		
	}
	
}}




int str(int k, char c[50]){
int i=0,p=abs(k);
if(k<0){
	c[i]='-';
	i++;
}
	do{
		c[i]=char(48+p%10);
		p/=10;
        i++;
	}while(p>0);
	c[i]='\0';
	inv(c);
	
	}
	
	
	
		
		

int pos(char s[50]){
	int p=-1;
	for(int i=0;i<length(s);i++){
		if(s[i]=='('){
			p=i;
		}
	}
	return p;
}
int pos_1(char s[50],int ps){
	int p=-1;
	for(int i=0;i<length(s);i++){
		if(s[i+ps]==')'){
			p=i+ps;
			goto err;
		}
	}err:
	return p;
}
int calc(char s[50]){
	int so=0,v,p=0,c=0,st=0,aux,tab[10000];char tabs[50];
	char caux[50];
	caux[0]='\0';
	
		v=pos(s)+1;
		aux=v;
	do{
		int ok=1;
		p=0;
		int ppt=0;
		if((symb(s[v])==1||symb(s[v])==2||s[v]==')')&&v!=aux){
			for(int k=0;k<abs(aux-v);k++){
				if(symb(s[k+aux])==2){
				ok=-1;
				ppt=1;
				continue;
				}
				else{
				caux[p]=s[k+aux];
				p++;
				}}
				caux[abs(aux-v)-ppt]='\0';
			conversion(caux,&p);
			for(int k=0;k<length(caux);k++){
				
			caux[length(caux)-k]='\0';
			}
			
			tab[c]=ok*p;
			c++;
;		aux=v+1;
		}
		if(symb(s[v])==1||symb(s[v])==2){
			if(symb(s[v-1])==0){
			tabs[st]=s[v];
			st++;}
		}
		v++;
	}while(s[v-1]!=')');
	
	for(int i=0;i<st;i++){
		if(symb(tabs[i])==1){
			so=operation(tab[i],tab[i+1],tabs[i]);
	for(int j=i;j<st-1;j++){
	 tabs[j]=tabs[j+1];
	}
	for(int j=i;j<st;j++){
	 tab[j]=tab[j+1];
	}
	tab[i]=so;
	st--;c--;i--;}}
	
	/* prio1->prio2 */
	for(int i=0;i<st;i++){
		if(symb(tabs[i])==2){
			so=operation(tab[i],tab[i+1],tabs[i]);
	for(int j=i;j<st-1;j++){
	 tabs[j]=tabs[j+1];
	}
	for(int j=i;j<st;j++){
	 tab[j]=tab[j+1];
	}
	tab[i]=so;
	st--;c--;i--;
;}
}
	
	return tab[0];
}



int err(char s[50]){
	for(int i=1;i<length(s)-1;i++){
		if(s[i]=='('){
			if(symb(s[i-1])==0){
				return -1;
			}
		}
		if(s[i]==')'){
			if(symb(s[i+1])==0){
				return -1;
			}
		}
	}
	return 0;
}








int main(){
	rep:
	int a,b=1,ok=0;
	char op[5000]="",ress[100];
	do{if(ok)
	     puts("Check your operation there might be an error\npossbile problems: negative integers should be contained into parentheses -> 5/(-1)");
	printf("Type in the operation to calculate :\n");
	scanf("%s",&op);
	ok++;
}while(checker(op)==0);
	insertstr(")",op,length(op));
	insertstr("(",op,0);
if(err(op)==-1){
	goto rep;
}

while(b!=-1){
a=pos(op);
b=pos_1(op,pos(op));
int res=calc(op);
deletestr(op,a,abs(a-b)+1);
str(res,ress);
insertstr(ress,op,a);
b=pos_1(op,pos(op));
}	
printf("Result= %s",op);
}

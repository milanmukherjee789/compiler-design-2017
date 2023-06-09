#include <stdio.h>
#include <string.h>
int label_var = 1;
char *gen_label_var(void){
		char *temp = (char*)malloc(sizeof(char) * 20);
		char *t = (char *)malloc(10);
		temp[0] = 'L';
		snprintf(t,10,"%d",label_var);
		strcat(temp,t);
		label_var++;
		return temp;
	}	
int main(){
	char *s = gen_label_var();
	printf("%s\n",s);
}

#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <cstring>
#include <string>
#define MAX_RULE 50
#define MAX_RULE_RHS_LENGTH 50
#define MAX_NON_TERMINALS 91		// non_terminals will be represented by capital letters
#define MAX_RHS_FIRST_SET 90		// terminals will be reresented by small letters + symbols almost 90
#define PARSING_TABLE_COLUMN 126	// all possible letters ascii 126
using namespace std;
void find_first_set(char set[],char non_terminal);
void find_follow_set(char set[],char non_terminal);
void do_union(char set[],char non_terminal);
int find_first_remaining(char set[],char non_terminal);
void parsing_table_build(string table[][PARSING_TABLE_COLUMN],char first_result_set[][MAX_RHS_FIRST_SET],char follow_result_set[][MAX_RHS_FIRST_SET]);
unsigned int total_rules = 0;
char rule_set[MAX_RULE][MAX_RULE_RHS_LENGTH];
char non_terminal[MAX_NON_TERMINALS];
char actual_non_terminal[MAX_NON_TERMINALS] = {'\0'};
int total_nonterminals = 0;
int main(int argc, char const *argv[])
{
	cout << " Enter total no of production: "<<endl;
	cin >> total_rules;
	for (int i = 0; i < total_rules; ++i)
	{
		cin >> rule_set[i];
	}
	int index = 0;
	for (int i = 0; i < total_rules; ++i)
	{
		if (isupper(rule_set[i][0])){
			non_terminal[index++] = rule_set[i][0];
		}
	}
	char ch = '-';
	char first_result_set[MAX_NON_TERMINALS][MAX_RHS_FIRST_SET];
	char follow_result_set[MAX_NON_TERMINALS][MAX_RHS_FIRST_SET];
	for (int i = 0; i < index; ++i)
	{
		if (ch != non_terminal[i]){
			ch = non_terminal[i];
			memset((void *)first_result_set[ch],'\0',MAX_RHS_FIRST_SET);
			memset((void *)follow_result_set[ch],'\0',MAX_RHS_FIRST_SET);
			find_first_set(first_result_set[ch],ch);
			find_follow_set(follow_result_set[ch],ch);
			printf("First set of %c is:{%s}\n",ch,first_result_set[ch] );
			printf("Follow set of %c is:{%s}\n",ch,follow_result_set[ch] );
			printf("%s\n","--------------------------------------------------------------------------------" );
		}
	}
	char c = non_terminal[0];
	int k = 0;
	for (int i = 1; i < index; ++i)
	{
		if (c != non_terminal[i]){
			actual_non_terminal[k++] = non_terminal[i];
			c = non_terminal[i];
		}
	}
	total_nonterminals = k;
	string parsing_table[PARSING_TABLE_COLUMN][PARSING_TABLE_COLUMN];
	memset(parsing_table,'\0',sizeof(parsing_table));
	parsing_table_build(parsing_table,first_result_set,follow_result_set);
	return 0;
}
void find_first_set(char set[],char non_terminal){
	char temp_result[MAX_RULE_RHS_LENGTH] = {'\0'};
	bool end_epsilon = false;
	if (!isupper(non_terminal)){
		do_union(set,non_terminal);
		return;
	}
	int rhs_start = -1;
	for (int i = 0; i < total_rules; ++i)
	{
		if (rule_set[i][0] == non_terminal){
			if (rule_set[i][2] == '$'){
				do_union(set,'$');
				return;
			}
			else{
				rhs_start = 2;
				while(rule_set[i][rhs_start] != '\0'){
					find_first_set(temp_result,rule_set[i][rhs_start]);
					for (int j = 0; temp_result[j] != '\0'; ++j)
					{
						if (temp_result[j] == '$'){
							end_epsilon = true;
							if (rule_set[i][rhs_start+1] == '\0'){
								do_union(set,'$');
							}
							break;
						}
						do_union(set,temp_result[j]);
					}
					if (!end_epsilon){
						break;
					}
					rhs_start++;
					memset((void*)temp_result,'\0',MAX_RULE_RHS_LENGTH);
					end_epsilon = false;
				}
			}
		}
	}
}
void find_follow_set(char set[],char non_terminal){
	char temp_result[MAX_RHS_FIRST_SET] = {'\0'};
	bool end_epsilon = false;
	if (rule_set[0][0] == non_terminal){
		do_union(set,'$');
	}
	for (int i = 0; i < total_rules; ++i)
	{
		for (int j = 2; rule_set[i][j] != '\0'; ++j)
		{
			if (rule_set[i][j] == non_terminal){
				for (int k = j; rule_set[i][k] != '\0'; ++k)
				{
					end_epsilon = false;
					if (rule_set[i][k+1] == '\0' && non_terminal != rule_set[i][0]){
						find_follow_set(set,rule_set[i][0]);
					}
					else if(rule_set[i][k+1] != '\0'){
						find_first_set(temp_result,rule_set[i][k+1]);
						for (int l = 0; temp_result[l] != '\0'; ++l)
						{
							if (temp_result[l] == '$'){
								end_epsilon = true;
								break;
							}
							do_union(set,temp_result[l]);
						}
						if (!end_epsilon){
							break;
						}
						memset((void *)temp_result,'\0',MAX_RHS_FIRST_SET);
					}
				}
				break;
			}
		}
	}
}
int find_first_remaining(char set[],char non_terminal){
	if (!isupper(non_terminal)){
		do_union(set,non_terminal);
	}
	for (int i = 0; i < total_rules; ++i)
	{
		if (rule_set[i][0] == non_terminal){
			if (islower(rule_set[i][2])){
				do_union(set,rule_set[i][2]);
			}
			else if (rule_set[i][2] == '$'){
				return 1;
			}
			else{
				return find_first_remaining(set,rule_set[i][2]);
			}
		}
	}
}
void do_union(char set[],char non_terminal){
	int i;
	for (i = 0; set[i] != '\0'; ++i)
	{
		if (set[i] == non_terminal)
			return;
	}
	set[i] = non_terminal;
	set[i+1] = '\0';
}
void parsing_table_build(string table[][PARSING_TABLE_COLUMN],char first_result_set[][MAX_RHS_FIRST_SET],char follow_result_set[][MAX_RHS_FIRST_SET]){
	string rule = "";
	for (int i = 0; i < total_rules; ++i)
	{
		rule = string(1,rule_set[i][0]) + " -> ";
		for (int j = 2; rule_set[i][j] != '\0'; ++j)
		{
			rule += string(1,rule_set[i][j]);
		}
		char follow[strlen(follow_result_set[rule_set[i][0]])];
		strcpy(follow,follow_result_set[rule_set[i][0]]);
		if (rule_set[i][2] == '$'){
			for (int j = 0; follow[j] != '\0'; ++j)
			{
				table[rule_set[i][0]][follow[j]] = rule;
				cout<<"["<<rule_set[i][0]<<"]"<<"["<<follow[j]<<"] = "<<rule<<endl;
			}
		}
		else if (!isupper(rule_set[i][2])){
			table[rule_set[i][0]][rule_set[i][2]] = rule;
			cout<<"["<<rule_set[i][0]<<"]"<<"["<<rule_set[i][2]<<"] = "<<rule<<endl;
		}
		else{
			bool end_epsilon = true;
			for (int k = 2; rule_set[i][k] != '\0' && end_epsilon; ++k)
			{
				if (!isupper(rule_set[i][k])){
					table[rule_set[i][0]][rule_set[i][k]] = rule;
					cout<<"["<<rule_set[i][0]<<"]"<<"["<<rule_set[i][k]<<"] = "<<rule<<endl;
					break;
				}
				char first[strlen(first_result_set[rule_set[i][k]])];
				strcpy(first,first_result_set[rule_set[i][k]]);
				end_epsilon = false;
				for (int j = 0; first[j] != '\0'; ++j)
				{
					if (first[j] != '$'){
						table[rule_set[i][0]][first[j]] = rule;
						cout<<"["<<rule_set[i][0]<<"]"<<"["<<first[j]<<"] = "<<rule<<endl;
					}
					else{
						if (rule_set[i][k+1] == '\0'){
							for (int j = 0; follow[j] != '\0'; ++j)
							{
								table[rule_set[i][0]][follow[j]] = rule;
								cout<<"["<<rule_set[i][0]<<"]"<<"["<<follow[j]<<"] = "<<rule<<endl;
							}
						}
						end_epsilon = true;
						break;
					}
				}
			}
		}
	}
}
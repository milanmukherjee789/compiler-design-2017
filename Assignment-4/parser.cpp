#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <stack>
#include <cstdlib>
int TOTAL_RULES =  5;
int MARKER =  5;
int ID_TOK =  0;
int ADDITION_TOK =  1;
int MULTIPLICATION_TOK =  2;
int LPAREN_TOK =  3;
int RPAREN_TOK =  4;
using namespace std;
vector <vector<pair<string,string> > > parsing_table(TOTAL_RULES);
map<string, int> nonterminal_key;
map<string, int> nonnonterminal_key;
int token_no = 0;
void insert_rule(vector<pair<string,string> > &rules);
void display_rules(vector<pair<string,string> > &rules);
bool parse_input(int *input);
void populate_parsing_table(void);
bool check_equal(string top,int index);
void display_stack(stack<string> S);
int main(int argc, char const *argv[])
{
	cout<<"The input should be array of tokens....... :)"<<endl;
	cout<<"Token Dictionary: "<<endl;
	cout<<"ID_TOK = "<<ID_TOK<<endl;
	cout<<"ADDITION_TOK = "<<ADDITION_TOK<<endl;
	cout<<"MULTIPLI_TOK = "<<MULTIPLICATION_TOK<<endl;
	cout<<"LPAREN_TOK = "<<LPAREN_TOK<<endl;
	cout<<"RPAREN_TOK = "<<RPAREN_TOK<<endl;
	cout<<"MARKER_TOK = "<<MARKER<<endl;
	vector<pair<string,string> > rules(TOTAL_RULES);
	populate_parsing_table();
	int *input = new int[argc+1];
	token_no = argc-1;
	for (int i = 1; i < argc; ++i)
	{
		input[i-1] = atoi(argv[i]);
	}
	if(parse_input(input)){
		cout<<"Expresssion is Correctly parsed .. :)"<<endl;
		return 1;
	}
	cout<<"Syntax Error"<<endl;
	return 0;
}
void insert_rule(vector<pair<string,string> > &rules){
	rules[0] = make_pair("E","Te");
	rules[1] = make_pair("e","+Te");
	rules[2] = make_pair("e","");
	rules[3] = make_pair("T","FT");
	rules[4] = make_pair("t","*Ft");
	rules[5] = make_pair("t","");
	rules[6] = make_pair("F","(E)");
	rules[7] = make_pair("F","id");
}
void populate_parsing_table(void){
	nonterminal_key["E"] = 0;
	nonterminal_key["e"] = 1;
	nonterminal_key["T"] = 2;
	nonterminal_key["t"] = 3;
	nonterminal_key["F"] = 4;
	for (int i = 0; i < TOTAL_RULES; ++i)
	{
		vector<pair<string,string> > v(6);
		parsing_table[i] = v;
	}
	parsing_table[nonterminal_key["E"]][ID_TOK] = make_pair("E","Te");
	parsing_table[nonterminal_key["E"]][ADDITION_TOK] = make_pair("","");
	parsing_table[nonterminal_key["E"]][MULTIPLICATION_TOK] = make_pair("","");
	parsing_table[nonterminal_key["E"]][LPAREN_TOK] = make_pair("E","Te");
	parsing_table[nonterminal_key["E"]][RPAREN_TOK] = make_pair("","");
	parsing_table[nonterminal_key["E"]][MARKER] = make_pair("","");
	
	parsing_table[nonterminal_key["e"]][ID_TOK] = make_pair("","");
	parsing_table[nonterminal_key["e"]][ADDITION_TOK] = make_pair("e","+Te");
	parsing_table[nonterminal_key["e"]][MULTIPLICATION_TOK] = make_pair("","");
	parsing_table[nonterminal_key["e"]][LPAREN_TOK] = make_pair("","");
	parsing_table[nonterminal_key["e"]][RPAREN_TOK] = make_pair("e","");
	parsing_table[nonterminal_key["e"]][MARKER] = make_pair("e","");

	parsing_table[nonterminal_key["T"]][ID_TOK] = make_pair("T","Ft");
	parsing_table[nonterminal_key["T"]][ADDITION_TOK] = make_pair("","");
	parsing_table[nonterminal_key["T"]][MULTIPLICATION_TOK] = make_pair("","");
	parsing_table[nonterminal_key["T"]][LPAREN_TOK] = make_pair("T","Ft");
	parsing_table[nonterminal_key["T"]][RPAREN_TOK] = make_pair("","");
	parsing_table[nonterminal_key["T"]][MARKER] = make_pair("","");

	parsing_table[nonterminal_key["t"]][ID_TOK] = make_pair("","");
	parsing_table[nonterminal_key["t"]][ADDITION_TOK] = make_pair("t","");
	parsing_table[nonterminal_key["t"]][MULTIPLICATION_TOK] = make_pair("t","*Ft");
	parsing_table[nonterminal_key["t"]][LPAREN_TOK] = make_pair("","");
	parsing_table[nonterminal_key["t"]][RPAREN_TOK] = make_pair("t","");
	parsing_table[nonterminal_key["t"]][MARKER] = make_pair("t","");

	parsing_table[nonterminal_key["F"]][ID_TOK] = make_pair("F","X");
	parsing_table[nonterminal_key["F"]][ADDITION_TOK] = make_pair("","");
	parsing_table[nonterminal_key["F"]][MULTIPLICATION_TOK] = make_pair("","");
	parsing_table[nonterminal_key["F"]][LPAREN_TOK] = make_pair("F","(E)");
	parsing_table[nonterminal_key["F"]][RPAREN_TOK] = make_pair("","");
	parsing_table[nonterminal_key["F"]][MARKER] = make_pair("","");
	
}
void display_rules(vector<pair<string,string> > &rules){
	for (int i = 0; i < rules.size(); ++i)
	{
		cout<<rules[i].first<<" -> "<<rules[i].second<<endl;
	}
}
bool parse_input(int *input){
	for (int i = 0; i < TOTAL_RULES; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout<<i<<"-"<<j<<" = "<<parsing_table[i][j].first<<"->"<<parsing_table[i][j].second<<"|\t";
		}
		cout<<endl;
	}
	input[token_no] = MARKER;
	stack<string> parse_stack;
	parse_stack.push("$");
	parse_stack.push("E");
	for (int i = 0; i <=token_no; ++i)
	{
		cout<<input[i]<<"\t";
	}
	cout<<endl;
	for (int i = 0; i <= token_no;)
	{
		display_stack(parse_stack);
		string top = parse_stack.top();
		if(top == "$" && input[i] == MARKER){
			return true;
		}
		if((top == "+" && input[i] == ADDITION_TOK)||(top == "*" && input[i] == MULTIPLICATION_TOK)||
			(top == "X" && input[i] == ID_TOK)||(top == "(" && input[i] == LPAREN_TOK)||(top == ")" && input[i] == RPAREN_TOK)){
			parse_stack.pop();
			i += 1;
		}
		else{
			pair<string,string> p = parsing_table[nonterminal_key[top]][input[i]];
			if(p.first == "" && p.second == ""){
				return false;
			}
			parse_stack.pop();
			if(p.second != ""){
				string temp = p.second;
				reverse(temp.begin(), temp.end());
				for (int k = 0; k < temp.length(); ++k)
				{
					string x = "";
					x.push_back(temp[k]);
					parse_stack.push(x);
				}
			}
		}
	}
	return false;
}
void display_stack(stack<string> S){
	for (std::stack<string> dump = S; !dump.empty(); dump.pop())
        std::cout << dump.top() << ' ';
    cout<<endl;
}
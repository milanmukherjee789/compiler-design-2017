#define REASON 10
const char* error_reason[] = {
								"\t\t POSSIBLE ERROR MAY BE AMONG THE FOLLOWING ..... \n\n\0",
								"ERROR FOR INT <ID_TOK> = DIGIT\0",
								"IF <CONDITION> STATEMENT ELSE IF USAGE\0",
								"VARIABLE NAME MUST BE SIGNLE LETTER OR PROGRAMME BEHAVIOUR CAN BE UN DETERMINATE\0",
								"LOGIC EXPRESSION OR|AND|XOR HAS NOT BEEN IMPLEMENTED\0",
								"FLOATING POINT NUMBER HAS NOT BEEN TOKENISE IN main.l SO USAGE CAN GIVE ABNORMAL BEHAVIOUR\0",
								"COMMENTED LINE CAN GIVE SYNTAX ERROR IN main.y FILE\0",								
								"FUNCTION CALL HAS NOT BEEN IMPLEMENTED\0",
								"OPERATOR PRECEDENCE HAS NOT BEEN DEFINED\0",
								"ARITH EXPRESSION LIKE a + a * a ..... WILL CREATE ERROR\n\n\0"
							};
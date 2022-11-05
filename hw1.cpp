#include "tokens.hpp"

std::string handle_string(char* str){

}

void showToken(const char* token){
    if(strcmp("COMMENT", token) == 0){
        printf("%d %s //\n", yylineno, token);
        return;
    }
    if(strcmp("STRING", token) == 0){
        std::string str = handle_string(yytext);
        printf("%d %s ", yylineno, token);
        fwrite(str.c_str(), sizeof(char), sizeof(str), stdout);
        printf("\n");

        return;
    }
    printf("%d %s %s\n", yylineno, token, yytext);
    return;
}

int main()
{
	int token;
	while ((token = yylex())) {
        switch (token) {
            case VOID:
                showToken("VOID");
                break;
            case INT:
                showToken("INT");
                break;
            case BYTE:
                showToken("BYTE");
                break;
            case B:
                showToken("B");
                break;
            case BOOL:
                showToken("BOOL");
                break;
            case AND:
                showToken("AND");
                break;
            case OR:
                showToken("OR");
                break;
            case NOT:
                showToken("NOT");
                break;
            case TRUE:
                showToken("TRUE");
                break;
            case FALSE:
                showToken("TRUE");
                break;
            case RETURN:
                showToken("RETURN");
                break;
            case IF:
                showToken("IF");
                break;
            case ELSE:
                showToken("ELSE");
                break;
            case WHILE:
                showToken("WHILE");
                break;
            case BREAK:
                showToken("BREAK");
                break;
            case CONTINUE:
                showToken("CONTINUE");
                break;
            case SC:
                showToken("SC");
                break;
            case COMMA:
                showToken("COMMA");
                break;
            case LPAREN:
                showToken("LPAREN");
                break;
            case RPAREN:
                showToken("RPAREN");
                break;
            case LBRACE:
                showToken("LBRACE");
                break;
            case RBRACE:
                showToken("RBRACE");
                break;
            case ASSIGN:
                showToken("ASSIGN");
                break;
            case RELOP:
                showToken("RELOP");
                break;
            case BINOP:
                showToken("BINOP");
                break;
            case COMMENT:
                showToken("COMMENT");
                break;
            case ID:
                showToken("ID");
                break;
            case NUM:
                showToken("NUM");
                break;
            case STRING:
                showToken("STRING");
                break;
            default:
                exit(0);
        }
	}
	return 0;
}

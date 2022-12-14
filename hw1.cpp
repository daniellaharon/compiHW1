#include "tokens.hpp"
#include "string"
#include "iostream"

char handle_hex(const std::string& str){
    bool not_valid = false;
    std::string err;
    for(int i = 0; i < str.length(); ++i){
        if(!(std::isalnum(str[i]) || std::isalpha(str[i]))){
            not_valid= true;
            //hex is shorter than 2 characters
            if(str[i]=='\"'){
                printf("Error undefined escape sequence %s\n", ("x"+err).c_str());
                exit(0);
            }
        }
        else{
            err+=str[i];
        }
    }
    if(not_valid){
        printf("Error undefined escape sequence %s\n", ("x"+str).c_str());
        exit(0);
    }
    int number;
    try{
      number = std::stoi(str, nullptr, 0x10);
    }
    catch(const std::invalid_argument& e) {
        printf("Error undefined escape sequence %s\n", ("x"+str).c_str());
        exit(0);
    }
    if (number>=0x00 && number<=0x7f){
        return (char)number;
    }
    else{
        printf("Error undefined escape sequence %s\n", ("x"+str).c_str());
        exit(0);
    }
}

std::string handle_string(std::string str){
    std::string output;
    for(int i = 0; i < str.length(); ++i){
        if(str[i]=='\n'||str[i]=='\r'||str[i]=='\t'==0){
            output+=str[i];
        }
        if(str[i]=='\"'){
            continue;
        }
        if(str[i]=='\\'){
            //hex value case
            if(str[i+1]=='x'){
                output+=handle_hex(str.substr(i+2,2));
                i+=3;
            }
            if(str[i+1]=='0'){
                output+='\0';
                i+=1;
            }
            else{
                //error escaping case
                printf("Error undefined escape sequence %c\n", str[i+1]);
                exit(0);
            }
        }
        else{
            output+=str[i];
        }
    }
    return output;
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
}

void print_unclosed_string(){
    printf("Error unclosed string\n");
    exit(0);
}

void print_zero_error(){
    printf("Error 0\n");
    exit(0);
}

void print_invalid_char(){
    printf("Error %c\n", yytext[0]);
    exit(0);
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
            case UNCLOSED_STRING:
                print_unclosed_string();
            case ZERO_ERROR:
                print_zero_error();
            case INVALID_CHAR:
                print_invalid_char();
            default:
                exit(0);
        }
	}
	return 0;
}

%{
/* Definition section */
#include "tokens.hpp"
%}

%option noyywrap
%option yylineno
letter [a-zA-Z]
digit  [0-9]

%%
void                            return VOID;
int                             return INT;
byte                            return BYTE;
b                               return B;
bool                            return BOOL;
and                             return AND;
or                              return OR;
not                             return NOT;
true                            return TRUE;
false                           return FALSE;
return                          return RETURN;
if                              return IF;
else                            return ELSE;
while                           return WHILE;
break                           return BREAK;
continue                        return CONTINUE;
;                               return SC;
,                               return COMMA;
\(                              return LPAREN
\)                              return RPAREN
\{                              return LBRACE
\}                              return RBRACE
=                               return ASSIGN
==|!=|<|>|<=|>=                 return RELOP
\+|\-|\*|\/                     return BINOP
\/\/[^\r\n]*                    return COMMENT
{letter}+({letter}|{digit})*    return ID
0|[1-9][0-9]*                   return NUM
\"([^\\\"\n\r]|\\.)*\"          return STRING
(0[0-9]+)                       return ZERO_ERROR
\"([^\\\"]|\\.)*[\n\r<<EOF>>]*  return UNCLOSED_STRING
.                               return INVALID_CHAR
[\n\r\t]                        ;
%%
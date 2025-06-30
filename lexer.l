%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

char* to_python_identifier(const char* cobol_id) {
    char* py_id = strdup(cobol_id);
    for (char* p = py_id; *p; ++p) {
        if (*p == '-') *p = '_';
        else *p = tolower((unsigned char)*p);
    }
    return py_id;
}

%}

%option noyywrap
%option yylineno

%%

"IDENTIFICATION"    { return IDENTIFICATION; }
"DIVISION"          { return DIVISION; }
"PROGRAM-ID"        { return PROGRAM_ID; }
"PROGRAM"           { return PROGRAM; }
"AUTHOR"            { return AUTHOR; }
"INSTALLATION"      { return INSTALLATION; }
"DATE-WRITTEN"      { return DATE_WRITTEN; }
"DATE-COMPILED"     { return DATE_COMPILED; }
"SECURITY"          { return SECURITY; }
"REMARKS"           { return REMARKS; }
"PROCEDURE"         { return PROCEDURE; }
"DATA"              { return DATA; }
"FILE"              { return FILE_TOKEN; }
"WORKING-STORAGE"   { return WORKING_STORAGE; }
"LOCAL-STORAGE"     { return LOCAL_STORAGE; }
"LINKAGE"           { return LINKAGE; }
"SECTION"           { return SECTION; }
"IF"                { return IF; }
"THEN"              { return THEN; }
"ELSE"              { return ELSE; }
"END-IF"            { return END_IF; }
"END-PERFORM"       { return END_PERFORM; }
"END-EVALUATE"      { return END_EVALUATE; }
"END"               { return END; }
"MOVE"              { return MOVE; }
"TO"                { return TO; }
"INTO"              { return INTO_TOKEN; }
"DISPLAY"           { return DISPLAY; }
"PERFORM"           { return PERFORM; }
"VARYing"           { return VARYING; }
"FROM"              { return FROM; }
"BY"                { return BY; }
"UNTIL"             { return UNTIL; }
"ACCEPT"            { return ACCEPT; }
"COMPUTE"           { return COMPUTE; }
"ADD"               { return ADD; }
"SUBTRACT"          { return SUBTRACT; }
"MULTIPLY"          { return MULTIPLY; }
"DIVIDE"            { return DIVIDE; }
"GO"                { return GO; }
"PIC"               { return PIC; }
"COMP"              { return COMP; }
"COMP-3"            { return COMP_3; }
"VALUE"             { return VALUE; }
"VALUES"            { return VALUES; }
"INDEXED"           { return INDEXED; }
"OCCURS"            { return OCCURS; }
"TIMES"             { return OCCURS_TIMES; }
"REDEFINES"         { return REDEFINES; }
"USING"             { return USING; }
"RETURNING"         { return RETURNING; }
"CALL"              { return CALL; }
"EVALUATE"          { return EVALUATE; }
"WHEN"              { return WHEN; }
"OTHER"             { return OTHER; }
"OR"                { return OR; }
"AND"               { return AND; }
"NOT"               { return NOT; }
"GOBACK"            { return GOBACK; }
"EXIT"              { return EXIT; }
"ENVIRONMENT"       { return ENVIRONMENT; }
"CONFIGURATION"     { return CONFIGURATION; }
"SOURCE-COMPUTER"   { return SOURCE_COMPUTER; }
"OBJECT-COMPUTER"   { return OBJECT_COMPUTER; }
"INPUT-OUTPUT"      { return INPUT_OUTPUT; }
"FILE-CONTROL"      { return FILE_CONTROL; }
"STOP"              { return STOP; }
"RUN"               { return RUN; }

">="                { return GEQUAL; }
"<="                { return LEQUAL; }
"<>"                { return NEQUAL; }
">"                 { return GREATER; }
"<"                 { return LESS; }
"="                 { return EQUAL; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MUL_OP; }
"/"                 { return DIV_OP; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
","                 { return COMMA_TOKEN; }

"TRUE"              { yylval.num = 1; return BOOL; }
"FALSE"             { yylval.num = 0; return BOOL; }
[0-9]+\.[0-9]+      { yylval.dval = atof(yytext); return FLOAT; }
\"[^\"]*\"          { yylval.str = strdup(yytext); return STRING; }
'[^']*'             { yylval.str = strdup(yytext); return STRING; }

[0-9]+\([0-9]+\)    { yylval.str = strdup(yytext); return PIC_STRING; }
X\([0-9]+\)         { yylval.str = strdup(yytext); return PIC_STRING; }
A\([0-9]+\)         { yylval.str = strdup(yytext); return PIC_STRING; }
9+                  { yylval.str = strdup(yytext); return PIC_STRING; }
X+                  { yylval.str = strdup(yytext); return PIC_STRING; }
A+                  { yylval.str = strdup(yytext); return PIC_STRING; }

[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }

[A-Za-z0-9][A-Za-z0-9-]* {
    // Verificar si es palabra clave
    if (strcmp(yytext, "OR") == 0) return OR;
    if (strcmp(yytext, "AND") == 0) return AND;
    if (strcmp(yytext, "NOT") == 0) return NOT;
    
    yylval.str = to_python_identifier(yytext);
    return IDENTIFIER;
}

[ \t]+              ; 
\n                  ; 
\.                  { return DOT; }
^[ \t]{0,6}\*[^\n]*  ;
\*>[^\n]*           ;
.                   ;

%%

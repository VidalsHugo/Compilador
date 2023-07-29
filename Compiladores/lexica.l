%{
#include <string>
int contn = 1;
%}

ESPACO [ \t] 
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{DIGITO})\'
STRING \"([^\"\n])*\"
ID {LETRA}({LETRA}|{NUM})*




%%
"//"(.*)  {return TK_COMENT; }/* Ignorar comentários de linha única */

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"print"     {return TK_PRINT;}

"scan"      {return TK_SCAN;}

"break"     {return TK_BREAK;}

"continue"  {return TK_CONTINUE;}

"if"        {return TK_IF;}

"else"      {return TK_ELSE;}  

"for"      {return TK_FOR;}

"while"     {return TK_WHILE;}

"do"        {return TK_DO;}

"switch"	{return TK_SWITCH;}

"case"	    {return TK_CASE;}

"default"   {return TK_DEFAULT;}

":"         {return TK_DP;}

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_FLOAT;}

"char"      {return TK_TIPO_CHAR;}

"bool"      {return TK_TIPO_BOOL;}

"void"      {return TK_TIPO_VOID;}

"string"    {return TK_TIPO_STRING;}

"return"    {return TK_RETURN;}

"(float)"   {return TK_CAST_FLOAT;}

"(int)"     {return TK_CAST_INT;}

"(char)"    {return TK_CAST_CHAR;}




[(){}[\];,]	{ return *yytext; }

[+\-*/=]		{ return *yytext; }

[<>]		    { return *yytext; }
"=="    { return EQ; }
"!="    { return NE; }
">="    { return GE; }
"<="    { return LE; }
"&&"    { return AND; }
"||"    { return OR; }
"!"     { return NO; }

"true"      { yylval.label = yytext; return TK_TRUE; }
"false"     { yylval.label = yytext; return TK_FALSE; }
{NUM}		{ yylval.label = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{REAL}      { yylval.label = yytext; return TK_REAL; }
{CHAR}      { yylval.label = yytext; return TK_CHAR; }
{STRING}    { yylval.label = yytext; return TK_STRING; }

.\n         {contn++;}
.			{ *yytext;}


%%

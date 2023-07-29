%{
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
    string label;
    string label2;
    string traducao;
    string declaracao;
    string tipo;
    string valor;
    string strcpy;
};

void naoDeclarado(string chave);
void declarado(string chave);
void empilha();
void desempilha();
string genTemp();
string genRot();
int busca_escopo(string var);
int verificaVar(string var);
int verificaVarBloco(string var);
void conversaoImplicitaOp(atributos& $$, atributos& $1, atributos& $3, string operador, string tipo);
void operacao(atributos& $$, atributos& $1, atributos& $2, atributos& $3, string operador);

// Struct de cada tipo
typedef struct
{
    string nome;
    string tipo;
	string temp;
    string valor;
    string tamMatriz;
    bool vetor;
    bool matriz;
    int tam;
    int atribuido;
    int bloco;
} TIPO_SIMBOLO;

typedef struct
{
    string nome;
    string tipo;
	string temp;
    string retorno;
    string traducao;
} FUNCAO;

int bloco_atual = -1;
vector<unordered_map<string, TIPO_SIMBOLO>> pilha; 
vector<unordered_map<string, FUNCAO>> funcao; 
vector<tuple<string, string>> pilha_rotulo;
bool gerouRotulo = false;
bool loop = false;

vector<string> pilha_malloc;
int temp;
int tempRot;
bool bloco_switch = false;
bool defaultExecutado = false;
string auxPrint;
extern int contn;

int yylex(void);
void yyerror(string);
%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE TK_CHAR TK_STRING TK_IF TK_ELSE TK_FOR TK_WHILE TK_DO TK_SWITCH TK_CASE TK_DP TK_DEFAULT TK_PRINT TK_SCAN TK_BREAK TK_CONTINUE TK_RETURN TK_TIPO_VOID TK_QB TK_COMENT
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_BOOL TK_CAST_FLOAT TK_CAST_INT TK_CAST_BOOL TK_TIPO_CHAR TK_TIPO_STRING
%token TK_FIM TK_ERROR 


%start S

%left AND OR NO
%left '>' '<' EQ NE GE LE
%left '+' '-'
%left '*' '/'
%right '{'

%nonassoc TK_CAST_FLOAT 
%nonassoc TK_CAST_INT 
%nonassoc TK_CAST_CHAR


%%

S           : TK_TIPO_INT TK_MAIN '(' ')' BLOCO GLOBAL
            {
                cout << "/*Compilador CAPY*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.declaracao << $5.traducao << "\treturn 0;\n}" << endl;
            }
            ;

GLOBAL  : TIPO TK_ID '(' PARAMETROS ')' BLOCO
        {
            //declarado($2.label);
            pilha.push_back(unordered_map<string, TIPO_SIMBOLO>());
            FUNCAO fun;
            fun.nome = $2.label;
            fun.tipo = $1.label;
            fun.traducao = $6.traducao;
        }
        |
        {

        }

TIPO    : TK_TIPO_INT
        {
            $$.label = "int";
        }
        | TK_TIPO_FLOAT
        {
            $$.label = "float";
        }
        | TK_TIPO_CHAR
        {
            $$.label = "char";
        }
        | TK_TIPO_BOOL
        {
            $$.label = "bool";
        }
        | TK_TIPO_STRING
        {
            $$.label = "string";
        }
        | TK_TIPO_VOID
        {
            $$.label = "void";
        } 
        ;



PARAMETROS: TIPO TK_ID
            {
                // if(pilha_funcao.empty()){
                //     pilha_funcao.push_back(unordered_map<string, TIPO_SIMBOLO>());
                // }
                // TIPO_SIMBOLO var;
                // var.tipo = $1.label;
                // var.nome = $2.label;
                // var.temp = genTemp();
            }
            |TIPO TK_ID ',' PARAMETROS
            {
                // if(pilha_funcao.empty()){
                //     pilha_funcao.push_back(unordered_map<string, TIPO_SIMBOLO>());
                // }
                // TIPO_SIMBOLO var;
                // var.tipo = $1.label;
                // var.nome = $2.label;
                // var.temp = genTemp();
            }
            ;

BLOCO       : '{' INI COMANDOS FIM '}'
            {
                $$.traducao = $3.traducao + $4.traducao;
				$$.declaracao = $3.declaracao;
            }
            ;

INI         :
            {
                empilha();
                bloco_atual++;
            }
            ;

FIM         :
            {
                desempilha();
                bloco_atual--;
                string traducao;
                while (pilha_malloc.size() != 0) {
                    string aux = pilha_malloc.back();  // Obter o último elemento da pilha
                    pilha_malloc.pop_back();           // Remover o último elemento da pilha

                    traducao += string("\t") + string("free(") + aux + ");\n";  // Adicionar a instrução correspondente
                }
                $$.traducao = traducao;
            }
            ;

COMANDOS    : COMANDO COMANDOS
            {
                $$.traducao = $1.traducao + $2.traducao;
				$$.declaracao = $1.declaracao + $2.declaracao;
            }
            |
            {
                $$.traducao = "";
                $$.declaracao = "";
            }
            ;

COMANDO     : BLOCO
            | E ';'
            {
                $$.traducao = $1.traducao;
                $$.declaracao = $1.declaracao;
            }
            | IF 
            {
                $$.traducao = $1.traducao;
            }
            | IF_ELSE 
            {
                $$.traducao = $1.traducao;
            }
            | WHILE 
            {
                $$.traducao = $1.traducao;
            }
            | DO_WHILE 
            {
                $$.traducao = $1.traducao;
            }
            | FOR
            {
                $$.traducao = $1.traducao;
                $$.declaracao = $1.declaracao;
            }
            | SWITCH
            {
                $$.traducao = $1.traducao;
                $$.declaracao = $1.declaracao;
            }
            | PRINT
            {
                $$.traducao = $1.traducao;
                $$.declaracao = $1.declaracao;
            }
            | TK_ID '=' TK_SCAN '('')'';'
            {   
                $$.traducao = "\tcin >> " + pilha[busca_escopo($1.label)][$1.label].temp + ";\n";
            }
            | TK_TIPO_INT TK_ID ';'
            {
                declarado($2.label);
                TIPO_SIMBOLO var;
                var.nome = $2.label;
                var.tipo = "int";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                $$.tipo = var.tipo;
                $$.declaracao = "\t" + $$.tipo + " " + var.temp + ";\n";
                $$.traducao = "";
            }
            | TK_TIPO_FLOAT TK_ID';'
            {
                declarado($2.label);
                TIPO_SIMBOLO var;
                var.nome = $2.label;
                var.tipo = "float";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                $$.tipo = var.tipo;
                $$.declaracao = "\t" + $$.tipo + " " + var.temp + ";\n";
                $$.traducao = "";
                
            }
            | TK_TIPO_CHAR TK_ID ';'
            {
                declarado($2.label);
                TIPO_SIMBOLO var;
                var.nome = $2.label;
                var.tipo = "char";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                $$.tipo = var.tipo;
                $$.declaracao = "\t" + $$.tipo + " " + var.temp + ";\n";
                $$.traducao = "";
            }
			| TK_TIPO_BOOL TK_ID ';'
            {
                declarado($2.label);
                TIPO_SIMBOLO var;
                var.nome = $2.label;
                var.tipo = "bool";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                $$.tipo = var.tipo;
                $$.declaracao = "\t" + string("int") + " " + var.temp + ";\n";
                $$.traducao = "";
            } 
            | TK_TIPO_STRING TK_ID ';'
            {
                declarado($2.label);
                TIPO_SIMBOLO var;
                var.nome = $2.label;
                var.tipo = "string";
                var.atribuido = 0;
				var.temp = genTemp();
                var.bloco = bloco_atual;
                pilha[bloco_atual][var.nome] = var;
                $$.tipo = var.tipo;
                $$.declaracao = "\t" + string("char") + " *" + var.temp + ";\n";
                $$.traducao += "";
            }
            |TK_TIPO_INT TK_ID '[' E ']' ';'
            {
                declarado($2.label);
                if(verificaVar($4.label)){
                    if(pilha[busca_escopo($4.label)][$4.label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    if(pilha[busca_escopo($4.label)][$4.label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.label = genTemp();
                    TIPO_SIMBOLO vet;
                    vet.nome = $2.label;
                    vet.tipo = "int";
                    vet.atribuido = 1;
                    vet.temp = $$.label;
                    vet.vetor = true;
                    vet.bloco = bloco_atual;
                    pilha[bloco_atual][vet.nome] = vet;
                    $$.tipo = vet.tipo;
                    $$.declaracao = $4.declaracao;
                    $$.traducao = $4.traducao + "\t" + $$.tipo + " " + $$.label + '[' + pilha[busca_escopo($4.label)][$4.label].temp + "];\n";
                }
                else{
                    if($4.tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    if(stoi($4.valor) < 0){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.label = genTemp();
                    TIPO_SIMBOLO vet;
                    vet.nome = $2.label;
                    vet.tipo = "int";
                    vet.atribuido = 1;
                    vet.temp = $$.label;
                    vet.tam = stoi($4.valor);
                    vet.vetor = true;
                    vet.bloco = bloco_atual;
                    pilha[bloco_atual][vet.nome] = vet;
                    $$.tipo = vet.tipo;
                    $$.declaracao = $4.declaracao;
                    $$.traducao = $4.traducao + "\t" + $$.tipo + " " + $$.label + '[' + $4.label + "];\n";
                }
            }
            |TK_TIPO_FLOAT TK_ID '[' E ']' ';'
            {
                declarado($2.label);
                if(verificaVar($4.label)){
                    if(pilha[busca_escopo($4.label)][$4.label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    if(pilha[busca_escopo($4.label)][$4.label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.label = genTemp();
                    TIPO_SIMBOLO vet;
                    vet.nome = $2.label;
                    vet.tipo = "float";
                    vet.atribuido = 1;
                    vet.temp = $$.label;
                    vet.vetor = true;
                    vet.bloco = bloco_atual;
                    pilha[bloco_atual][vet.nome] = vet;
                    $$.tipo = vet.tipo;
                    $$.declaracao = $4.declaracao;
                    $$.traducao = $4.traducao + "\t" + $$.tipo + " " + $$.label + '[' + pilha[busca_escopo($4.label)][$4.label].temp + "];\n";
                }
                else{
                    if($4.tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.label = genTemp();
                    TIPO_SIMBOLO vet;
                    vet.nome = $2.label;
                    vet.tipo = "float";
                    vet.atribuido = 1;
                    vet.temp = $$.label;
                    vet.vetor = true;
                    vet.bloco = bloco_atual;
                    pilha[bloco_atual][vet.nome] = vet;
                    $$.tipo = vet.tipo;
                    $$.declaracao = $4.declaracao;
                    $$.traducao = $4.traducao + "\t" + $$.tipo + " " + $$.label + '[' + $4.label + "];\n";
                }
            }
            | TK_ID '=' TK_ID '[' E ']' ';'
            {
                if(verificaVar($5.label)){
                    if(pilha[busca_escopo($5.label)][$5.label].tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    $$.declaracao = $5.declaracao;
                    $$.traducao = $5.traducao;
                    if(pilha[busca_escopo($3.label)][$3.label].tipo == "float" && pilha[busca_escopo($1.label)][$1.label].tipo == "int"){
                        $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = (int)" + pilha[busca_escopo($3.label)][$3.label].temp + '[' + pilha[busca_escopo($5.label)][$5.label].temp + "];\n";
                    }
                    else if(pilha[busca_escopo($3.label)][$3.label].tipo == "int" && pilha[busca_escopo($1.label)][$1.label].tipo == "float"){
                        $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = (float)" + pilha[busca_escopo($3.label)][$3.label].temp + '[' + pilha[busca_escopo($5.label)][$5.label].temp + "];\n";
                    }
                    else{
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + pilha[busca_escopo($3.label)][$3.label].temp + "[" + pilha[busca_escopo($5.label)][$5.label].temp + "];\n";
                    }
                }
                else{
                    if($5.tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    $$.declaracao = $5.declaracao;
                    $$.traducao = $5.traducao;
                    if(pilha[busca_escopo($3.label)][$3.label].tipo == "float" && pilha[busca_escopo($1.label)][$1.label].tipo == "int"){
                        $$.label = genTemp();
                        $$.traducao += "\t" + $$.label + " = (int)" + pilha[busca_escopo($3.label)][$3.label].temp + '[' + $5.label + "];\n";
                        $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + $$.label + ";\n";
                    }
                    else if(pilha[busca_escopo($3.label)][$3.label].tipo == "int" && pilha[busca_escopo($1.label)][$1.label].tipo == "float"){
                        $$.label = genTemp();
                        $$.traducao += + "\t" + $$.label + " = (float)" + pilha[busca_escopo($3.label)][$3.label].temp + '[' + $5.label + "];\n";
                        $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + $$.label + ";\n";
                    }
                    else{
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + pilha[busca_escopo($3.label)][$3.label].temp + '[' + $5.label + "];\n";
                    }
                }            
            }
            |TK_ID '[' E ']' '=' E ';'
            {
                if(verificaVar($3.label) && verificaVar($6.label)){
                    if(pilha[busca_escopo($3.label)][$3.label].tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    $$.declaracao = $3.declaracao + $6.declaracao;
                    $$.traducao = $3.traducao + $6.traducao;
                    if(pilha[busca_escopo($3.label)][$3.label].tipo == "float" && pilha[busca_escopo($6.label)][$6.label].tipo == "int"){
                        $$.traducao = "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + pilha[busca_escopo($3.label)][$3.label].temp + "]" + " = (int)" + pilha[busca_escopo($6.label)][$6.label].temp + ";\n";
                    }
                    else if(pilha[busca_escopo($3.label)][$3.label].tipo == "int" && pilha[busca_escopo($6.label)][$6.label].tipo == "float"){
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + pilha[busca_escopo($3.label)][$3.label].temp + "]" + " = (int)" + pilha[busca_escopo($6.label)][$6.label].temp + ";\n";
                    }
                    else{
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + pilha[busca_escopo($3.label)][$3.label].temp + "]" + " = " + pilha[busca_escopo($6.label)][$6.label].temp + ";\n";
                    }
                }
                if(!verificaVar($3.label) && !verificaVar($6.label)){
                    if($3.tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    $$.declaracao = $3.declaracao + $6.declaracao;
                    $$.traducao = $3.traducao + $6.traducao;
                    if($3.tipo == "float" && $6.tipo == "int"){
                        $$.traducao = "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + $3.label + "]" + " = (float)" + $6.label + ";\n";
                    }
                    else if($3.tipo == "int" && $6.tipo == "float"){
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + $3.label + "]" + " = (int)" + $6.label + ";\n";
                    }
                    else{
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + $3.label + "]" + " = " + $6.label + ";\n";
                    }
                }
                if(!verificaVar($3.label) && verificaVar($6.label)){
                    if($3.tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    $$.declaracao = $3.declaracao + $6.declaracao;
                    $$.traducao = $3.traducao + $6.traducao;
                    if($3.tipo == "float" && pilha[busca_escopo($6.label)][$6.label].tipo == "int"){
                        $$.traducao = "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + $3.label + "]" + " = (float)" + pilha[busca_escopo($6.label)][$6.label].temp + ";\n";
                    }
                    else if($3.tipo == "int" && pilha[busca_escopo($6.label)][$6.label].tipo == "float"){
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + $3.label + "]" + " = (int)" + pilha[busca_escopo($6.label)][$6.label].temp + "];\n";
                    }
                    else{
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + $3.label + "]" + " = " + pilha[busca_escopo($6.label)][$6.label].temp + ";\n";
                    }
                }
                if(verificaVar($3.label) && !verificaVar($6.label)){
                    if(pilha[busca_escopo($3.label)][$3.label].tipo != "int"){
                        yyerror("Erro: Posição do Vetor Inválida");
                    }
                    $$.declaracao = $3.declaracao + $6.declaracao;
                    $$.traducao = $3.traducao + $6.traducao;
                    if(pilha[busca_escopo($3.label)][$3.label].tipo == "float" && $6.tipo == "int"){
                        $$.traducao = "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + pilha[busca_escopo($3.label)][$3.label].temp + "]" + " = (float)" + $6.label + ";\n";
                    }
                    else if(pilha[busca_escopo($3.label)][$3.label].tipo == "int" && $6.tipo == "float"){
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + pilha[busca_escopo($3.label)][$3.label].temp + "]" + " = (int)" + $6.label + ";\n";
                    }
                    else{
                        $$.traducao += + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + "[" + pilha[busca_escopo($3.label)][$3.label].temp + "]" + " = " + $6.label + ";\n";
                    }
                }                
            }
            | TK_RETURN E ';'
            {

            }
            | TK_COMENT
            {
                
            }
            | TK_TIPO_INT TK_ID '[' E ']' '[' E ']' ';'
            {
                if(!verificaVar($4.label) && !verificaVar($7.label)){
                    if($4.tipo != "int" || $7.tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.declaracao = $4.declaracao + $7.declaracao;
                    $$.traducao = $4.traducao + $7.traducao;
                    $$.label = genTemp();
                    $$.declaracao += "\tint " + $$.label + ";\n";
                    $$.traducao += "\t" + $$.label + " = " + $4.label + " * " + $7.label + ";\n";
                    string temp = $$.label;
                    TIPO_SIMBOLO matriz;
                    $$.label = genTemp();
                    matriz.nome = $2.label;
                    matriz.tipo = "int";
                    matriz.atribuido = 1;
                    matriz.temp = $$.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    $$.tipo = matriz.tipo;
                    $$.traducao += "\t" + $$.tipo + " " + $$.label + '[' + temp + "];\n";
                }
                if(verificaVar($4.label) && verificaVar($7.label)){
                    if(pilha[busca_escopo($4.label)][$4.label].tipo != "int" || pilha[busca_escopo($7.label)][$7.label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.declaracao = $4.declaracao + $7.declaracao;
                    $$.traducao = $4.traducao + $7.traducao;
                    $$.label = genTemp();
                    $$.declaracao += "\tint " + $$.label + ";\n";
                    $$.traducao += "\t" + $$.label + " = " + pilha[busca_escopo($4.label)][$4.label].temp + " * " + pilha[busca_escopo($7.label)][$7.label].temp + ";\n";
                    string temp = $$.label;
                    TIPO_SIMBOLO matriz;
                    $$.label = genTemp();
                    matriz.nome = $2.label;
                    matriz.tipo = "int";
                    matriz.atribuido = 1;
                    matriz.temp = $$.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    $$.tipo = matriz.tipo;
                    $$.traducao += "\t" + $$.tipo + " " + $$.label + '[' + temp + "];\n";
                }
                if(!verificaVar($4.label) && verificaVar($7.label)){
                    if($4.tipo != "int" || pilha[busca_escopo($7.label)][$7.label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.declaracao = $4.declaracao + $7.declaracao;
                    $$.traducao = $4.traducao + $7.traducao;
                    $$.label = genTemp();
                    $$.declaracao += "\tint " + $$.label + ";\n";
                    $$.traducao += "\t" + $$.label + " = " + $4.label + " * " + pilha[busca_escopo($7.label)][$7.label].temp + ";\n";
                    string temp = $$.label;
                    TIPO_SIMBOLO matriz;
                    $$.label = genTemp();
                    matriz.nome = $2.label;
                    matriz.tipo = "int";
                    matriz.atribuido = 1;
                    matriz.temp = $$.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    $$.tipo = matriz.tipo;
                    $$.traducao += "\t" + $$.tipo + " " + $$.label + '[' + temp + "];\n";
                }
                if(verificaVar($4.label) && !verificaVar($7.label)){
                    if(pilha[busca_escopo($4.label)][$4.label].tipo != "int" || $7.tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.declaracao = $4.declaracao + $7.declaracao;
                    $$.traducao = $4.traducao + $7.traducao;
                    $$.label = genTemp();
                    $$.declaracao += "\tint " + $$.label + ";\n";
                    $$.traducao += "\t" + $$.label + " = " + pilha[busca_escopo($4.label)][$4.label].temp + " * " + $7.label + ";\n";
                    string temp = $$.label;
                    TIPO_SIMBOLO matriz;
                    $$.label = genTemp();
                    matriz.nome = $2.label;
                    matriz.tipo = "int";
                    matriz.atribuido = 1;
                    matriz.temp = $$.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    $$.tipo = matriz.tipo;
                    $$.traducao += "\t" + $$.tipo + " " + $$.label + '[' + temp + "];\n";
                }
            }
            | TK_TIPO_FLOAT TK_ID '[' E ']' '[' E ']' ';'
            {
                if(!verificaVar($4.label) && !verificaVar($7.label)){
                    if($4.tipo != "int" || $7.tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.declaracao = $4.declaracao + $7.declaracao;
                    $$.traducao = $4.traducao + $7.traducao;
                    $$.label = genTemp();
                    $$.declaracao += "\tint " + $$.label + ";\n";
                    $$.traducao += "\t" + $$.label + " = " + $4.label + " * " + $7.label + ";\n";
                    string temp = $$.label;
                    TIPO_SIMBOLO matriz;
                    $$.label = genTemp();
                    matriz.nome = $2.label;
                    matriz.tipo = "float";
                    matriz.atribuido = 1;
                    matriz.temp = $$.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    $$.tipo = matriz.tipo;
                    $$.traducao += "\t" + $$.tipo + " " + $$.label + '[' + temp + "];\n";
                }
                if(verificaVar($4.label) && verificaVar($7.label)){
                    if(pilha[busca_escopo($4.label)][$4.label].tipo != "int" || pilha[busca_escopo($7.label)][$7.label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.declaracao = $4.declaracao + $7.declaracao;
                    $$.traducao = $4.traducao + $7.traducao;
                    $$.label = genTemp();
                    $$.declaracao += "\tint " + $$.label + ";\n";
                    $$.traducao += "\t" + $$.label + " = " + pilha[busca_escopo($4.label)][$4.label].temp + " * " + pilha[busca_escopo($7.label)][$7.label].temp + ";\n";
                    string temp = $$.label;
                    TIPO_SIMBOLO matriz;
                    $$.label = genTemp();
                    matriz.nome = $2.label;
                    matriz.tipo = "float";
                    matriz.atribuido = 1;
                    matriz.temp = $$.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    $$.tipo = matriz.tipo;
                    $$.traducao += "\t" + $$.tipo + " " + $$.label + '[' + temp + "];\n";
                }
                if(!verificaVar($4.label) && verificaVar($7.label)){
                    if($4.tipo != "int" || pilha[busca_escopo($7.label)][$7.label].tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.declaracao = $4.declaracao + $7.declaracao;
                    $$.traducao = $4.traducao + $7.traducao;
                    $$.label = genTemp();
                    $$.declaracao += "\tint " + $$.label + ";\n";
                    $$.traducao += "\t" + $$.label + " = " + $4.label + " * " + pilha[busca_escopo($7.label)][$7.label].temp + ";\n";
                    string temp = $$.label;
                    TIPO_SIMBOLO matriz;
                    $$.label = genTemp();
                    matriz.nome = $2.label;
                    matriz.tipo = "float";
                    matriz.atribuido = 1;
                    matriz.temp = $$.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    $$.tipo = matriz.tipo;
                    $$.traducao += "\t" + $$.tipo + " " + $$.label + '[' + temp + "];\n";
                }
                if(verificaVar($4.label) && !verificaVar($7.label)){
                    if(pilha[busca_escopo($4.label)][$4.label].tipo != "int" || $7.tipo != "int"){
                        yyerror("Erro: Tamanho do Vetor Inválido");
                    }
                    $$.declaracao = $4.declaracao + $7.declaracao;
                    $$.traducao = $4.traducao + $7.traducao;
                    $$.label = genTemp();
                    $$.declaracao += "\tint " + $$.label + ";\n";
                    $$.traducao += "\t" + $$.label + " = " + pilha[busca_escopo($4.label)][$4.label].temp + " * " + $7.label + ";\n";
                    string temp = $$.label;
                    TIPO_SIMBOLO matriz;
                    $$.label = genTemp();
                    matriz.nome = $2.label;
                    matriz.tipo = "float";
                    matriz.atribuido = 1;
                    matriz.temp = $$.label;
                    matriz.tamMatriz = temp;
                    matriz.matriz = true;
                    matriz.bloco = bloco_atual;
                    pilha[bloco_atual][matriz.nome] = matriz;
                    $$.tipo = matriz.tipo;
                    $$.traducao += "\t" + $$.tipo + " " + $$.label + '[' + temp + "];\n";
                }
            }
            |TK_ID '[' E ']' '[' E ']' '=' E ';'
            {
                if(!verificaVar($3.label) && !verificaVar($6.label)){
                    if($3.tipo != "int" || $6.tipo != "int"){
                        yyerror("Erro: Posição da matriz Inválida");
                    }
                }
                if(verificaVar($3.label) && verificaVar($6.label)){
                    if(pilha[busca_escopo($3.label)][$3.label].tipo != "int" || pilha[busca_escopo($6.label)][$6.label].tipo != "int"){
                        yyerror("Erro: Posição da matriz Inválida");
                    }
                }
                if(!verificaVar($3.label) && verificaVar($6.label)){
                    if($3.tipo != "int" || pilha[busca_escopo($6.label)][$6.label].tipo != "int"){
                        yyerror("Erro: Posição da matriz Inválida");
                    }
                }
                if(verificaVar($3.label) && !verificaVar($6.label)){
                    if(pilha[busca_escopo($3.label)][$3.label].tipo != "int" || $6.tipo != "int"){
                        yyerror("Erro: Posição da matriz Inválida");
                    }
                }
                
            }
            ;

IF          : TK_IF '(' E ')' BLOCO 
            {   
                if(verificaVar($3.label)){
                    if(pilha[busca_escopo($3.label)][$3.label].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                       yyerror("ERRO: Variável " + $3.label + " sem valor atribuido");
                    }
                    else{
                        $$.label = genTemp();
                        string rotulo = genRot();
                        $$.declaracao = "\tint " + $$.label + ";\n";
                        $$.traducao += $3.traducao + "\t" + $$.label + " = " + "!" + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + rotulo + ";\n";
                        $$.traducao += $5.traducao + "\t" + rotulo + ":\n";
                        $$.declaracao += $3.declaracao + $5.declaracao + "\tint " + $$.label + ";\n";
                    }
                }
                else{
                    if($3.tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    else{
                        $$.label = genTemp();
                        string rotulo = genRot();
                        $$.traducao += $3.traducao + "\t" + $$.label + " = " + "!" + $3.label + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + rotulo + ";\n";
                        $$.traducao += $5.traducao + "\t" + rotulo + ":\n";
                        $$.declaracao += $3.declaracao + $5.declaracao + "\tint " + $$.label + ";\n";
                    }
                }
            }
            ;
IF_ELSE     : TK_IF '(' E ')' BLOCO TK_ELSE BLOCO
            {   
                if(verificaVar($3.label)){
                    if(pilha[busca_escopo($3.label)][$3.label].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                       yyerror("ERRO: Variável " + $3.label + " sem valor atribuido");
                    }
                    else{
                        string rotulo1 = genRot();
                        string rotulo2 = genRot();
                        $$.label = genTemp();
                        $$.declaracao = "\tint " + $$.label + ";\n";
                        $$.traducao += $3.traducao + "\t" + $$.label + " = " + "!" + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + rotulo1 + ";\n";
                        $$.traducao += $5.traducao + "\tgoto " + rotulo2 + ";\n";
                        //else
                        $$.declaracao += $3.declaracao + $5.declaracao + "\tint " + $$.label + ";\n";
                        $$.declaracao += $7.declaracao;
                        $$.traducao += "\t" + rotulo1 + "\n" + $7.traducao + "\t" + rotulo2 + ":\n";
                    }
                }
                else{
                    if($3.tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    else{
                        string rotulo1 = genRot();
                        string rotulo2 = genRot();
                        $$.label = genTemp();
                        $$.declaracao = "\tint " + $$.label + ";\n";
                        $$.traducao += $3.traducao + "\t" + $$.label + " = " + "!" + $3.label + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + rotulo1 + ";\n";
                        $$.traducao += $5.traducao + "\tgoto " + rotulo2 + ";\n";
                        //else
                        $$.declaracao += $3.declaracao + $5.declaracao + "\tint " + $$.label + ";\n";
                        $$.declaracao += $7.declaracao;
                        $$.traducao += "\t" + rotulo1 + "\n" + $7.traducao + "\t" + rotulo2 + "\n";
                    }
                }
            }
            ;

FOR         : TK_FOR '(' E ';' E ';' E ')' BLOCO_LOOP
            {
                if(verificaVar($5.label)){
                    if(pilha[busca_escopo($5.label)][$5.label].tipo != "bool"){
                        yyerror("Erro: A condição do 'for' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo($5.label)][$5.label].atribuido == 0){
                       yyerror("ERRO: Variável " + $5.label + " sem valor atribuido");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        gerouRotulo = false;
                        $$.label = genTemp(); 
                        $$.traducao += $3.traducao + "\t" +iniRotulo + ":\n" + $5.traducao; 
                        $$.traducao += "\t" + $$.label + " = " + "!" + pilha[busca_escopo($5.label)][$5.label].temp + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + fimRotulo + ";\n";
                        $$.declaracao += $3.declaracao + $5.declaracao + $7.declaracao + $9.declaracao + "\tint " + $$.label + ";\n";
                        $$.traducao +=  $9.traducao + $7.traducao ;
                        $$.traducao += "\t" + fimRotulo +":\n";  
                    }
                }
                else{
                    if($5.tipo != "bool"){
                        yyerror("Erro: A condição do 'for' deve ser uma expressão booleana válida");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        $$.label = genTemp(); 
                        $$.traducao += $3.traducao + "\t" + iniRotulo + ":\n" + $5.traducao;
                        $$.traducao += "\t" + $$.label + " = " + "!" + $5.label + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + fimRotulo + ";\n";
                        $$.declaracao += $3.declaracao + $5.declaracao + $7.declaracao + $9.declaracao + "\tint " + $$.label + ";\n";
                        $$.traducao +=  $9.traducao + $7.traducao ;
                        $$.traducao += string("\tgoto ") + iniRotulo + ";\n\t" + fimRotulo + ":\n";
                    }
                }
            }
            ;


WHILE       : TK_WHILE '(' E ')' BLOCO_LOOP
            {
                if(verificaVar($3.label)){
                    if(pilha[busca_escopo($3.label)][$3.label].tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                       yyerror("ERRO: Variável " + $3.label + " sem valor atribuido");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        gerouRotulo = false;
                        $$.traducao += "\t" + iniRotulo + ":\n";
                        $$.label = genTemp();
                        $$.traducao += $3.traducao + "\t" + $$.label + " = " + "!" + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + fimRotulo + ";\n";
                        $$.traducao += $5.traducao + "\tgoto " + iniRotulo +";\n";
                        $$.traducao += "\t" + fimRotulo + ":\n";
                        $$.declaracao += $3.declaracao + $5.declaracao;
                    }
                }
                else{
                    if($3.tipo != "bool"){
                        yyerror("Erro: A condição do 'if' deve ser uma expressão booleana válida");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        gerouRotulo = false;
                        $$.traducao += "\t" + iniRotulo + ":\n";
                        $$.label = genTemp();
                        $$.traducao += $3.traducao + "\t" + $$.label + " = " + "!" + $3.label + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + fimRotulo + ";\n";
                        $$.traducao += $5.traducao + "\tgoto " + iniRotulo +";\n";
                        $$.traducao += "\t" + fimRotulo + ":\n";
                        $$.declaracao += $3.declaracao + $5.declaracao;
                    }
                }
                gerouRotulo = false;
            }
            ;

DO_WHILE    : TK_DO BLOCO_LOOP TK_WHILE '(' E ')' ';'
            {
                if(verificaVar($5.label)){
                    if(pilha[busca_escopo($5.label)][$5.label].tipo != "bool"){
                        yyerror("Erro: A condição do 'while' deve ser uma expressão booleana válida");
                    }
                    if(pilha[busca_escopo($5.label)][$5.label].atribuido == 0){
                       yyerror("ERRO: Variável " + $5.label + " sem valor atribuido");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        $$.traducao += "\t" + iniRotulo + ":\n";
                        $$.declaracao += $2.declaracao + $5.declaracao;
                        $$.traducao += $2.traducao + $5.traducao;
                        $$.label = genTemp();
                        $$.traducao += "\t" + $$.label + " = " + "!" + pilha[busca_escopo($5.label)][$5.label].temp + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + fimRotulo + ";\n";
                        $$.traducao += "\t"+ iniRotulo +":\n";
                    }
                }
                else{
                    if($5.tipo != "bool"){
                        yyerror("Erro: A condição do 'while' deve ser uma expressão booleana válida");
                    }
                    else{
                        string iniRotulo = get<0>(pilha_rotulo.back());
                        string fimRotulo = get<1>(pilha_rotulo.back());
                        pilha_rotulo.pop_back();
                        $$.traducao += "\t" + iniRotulo + "\n";
                        $$.declaracao += $2.declaracao + $5.declaracao;
                        $$.traducao += $2.traducao + $5.traducao;
                        $$.label = genTemp();
                        $$.traducao += "\t" + $$.label + " = " + "!" + $5.label + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + fimRotulo + ";\n";
                        $$.traducao += "\t"+ iniRotulo +":\n";
                    }
                }
                gerouRotulo = false;
            }
            ;



BLOCO_LOOP  : '{' INI CMD FIM '}'
            {
                $$.declaracao += $3.declaracao;
                $$.traducao += $3.traducao;
                if(!gerouRotulo){
                    pilha_rotulo.push_back(make_tuple(genRot(),genRot())); //ini fim
                }
            }
            
            ;
CMD         :COMANDOS BREAK_OR_CONTINUE CMD {
                $$.declaracao = $1.declaracao + $2.declaracao + $3.declaracao;
                $$.traducao = $1.traducao + $2.traducao + $3.traducao;
            }
            |COMANDOS
            {
                $$.declaracao = $1.declaracao;
                $$.traducao = $1.traducao;
            }
            ;

BREAK_OR_CONTINUE :TK_BREAK ';' 
            {     
                if(!gerouRotulo){
                    pilha_rotulo.push_back(make_tuple(genRot(),genRot())); //ini fim
                    gerouRotulo = true;
                }
                string lula = get<1>(pilha_rotulo.back());
                $$.traducao += "\t" + string("goto ") + lula + ";\n";
            }
            | TK_CONTINUE ';' 
            {
                if(!gerouRotulo){
                    pilha_rotulo.push_back(make_tuple(genRot(),genRot())); //ini fim
                    gerouRotulo = true;
                }
                string iniRotulo = get<0>(pilha_rotulo.back());
                $$.traducao += "\t" + string("goto ") + iniRotulo + ";\n"; 
            }
            ;




SWITCH     : TK_SWITCH '(' E ')' BLOCO_SWITCH
            {
                string rotuloIni = genRot();
                string rotuloFim = genRot();
                $$.traducao += $3.traducao + "\t" +rotuloIni + "\n" + $5.traducao; 
                $$.declaracao += $3.declaracao + $5.declaracao;
                $$.traducao += "\t" + rotuloFim + "\n";
                defaultExecutado = false;
            }
            ;

BLOCO_SWITCH: '{' CASE_LISTA '}'
            {
                // Faça o processamento necessário para o bloco switch
                $$.traducao += $2.traducao;
                $$.declaracao += $2.declaracao;
            }
            ;

CASE_LISTA  : CASE_STMT CASE_LISTA
            {
                $$.traducao += $2.traducao;
                $$.declaracao += $2.declaracao;
            }
            |
            {
                // Caso base: não há mais casos na lista
                $$.traducao = "";
                $$.declaracao = "";
            }
            ;


CASE_STMT   : CASE
            {
                // Faça o processamento necessário para o caso
            }
            ;

CASE        : TK_CASE E TK_DP COMANDOS
            {
                if(verificaVar($2.label)){
                    if(pilha[busca_escopo($2.label)][$2.label].atribuido == 0){
                       yyerror("ERRO: Variável " + $2.label + " sem valor atribuido");
                    }
                    else{
                        $$.declaracao += $2.declaracao + $4.declaracao;
                        string rotuloIni = genRot();
                        string rotuloFim = genRot();
                        $$.label = genTemp();
                        $$.declaracao += "\t" + string("int ") + $$.label + ";\n";
                        $$.traducao += "\t" + rotuloIni + "\n"; 
                        $$.traducao += $2.traducao;
                        $$.traducao += "\t" + $$.label + " = " + "!" + pilha[busca_escopo($2.label)][$2.label].temp + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + rotuloFim + ";\n";
                        $$.traducao += $4.traducao;
                        $$.traducao += "\t"+ rotuloFim +"\n";
                    }
                }
                else{
                        $$.declaracao += $2.declaracao + $4.declaracao;
                        string rotuloIni = genRot();
                        string rotuloFim = genRot();
                        $$.label = genTemp();
                        $$.declaracao += "\t" + string("int ") + $$.label + ";\n";
                        $$.traducao += "\t" + rotuloIni + "\n"; 
                        $$.traducao += $2.traducao;
                        $$.traducao += "\t" + $$.label + " = " + "!" + $2.label + ";\n";
                        $$.traducao += "\tif("+ $$.label + ")" + " goto " + rotuloFim + ";\n";
                        $$.traducao += $4.traducao;
                        $$.traducao += "\t"+ rotuloFim +"\n";
                }
                

            }
            | TK_DEFAULT TK_DP COMANDOS
            {
                if(defaultExecutado){
                   yyerror("ERRO: Mais de um case padrão (default) encontrado.");
                }else{
                    $$.declaracao += $3.declaracao;
                    string rotuloIni = genRot();
                    string rotuloFim = genRot();
                    $$.traducao += "\t" + rotuloIni + "\n"; 
                    $$.traducao += $3.traducao;
                    $$.traducao += "\t"+ rotuloFim +"\n";
                    defaultExecutado = true;
                }
            }
            ;

PRINT       : TK_PRINT '(' EXPRESSAO ')' ';'
            {   
                $$.declaracao += $3.declaracao;

                $$.traducao += $3.strcpy + auxPrint + "\t" + string("cout << ") + $3.traducao + ";\n";
                auxPrint = "";
            }
            ;

EXPRESSAO   : TEXTO
            {
                $$.declaracao = $1.declaracao;
                $$.traducao = $1.traducao;
                $$.strcpy = $1.strcpy;
            }
            | TEXTO '+' EXPRESSAO
            {
                if(verificaVar($3.label)){
                    string tipo = pilha[busca_escopo($3.label)][$3.label].tipo;
                    if(tipo == "int" || tipo == "float" || tipo == "bool"){
                        yyerror("Apenas valores do tipo 'char' ou 'string' podem ser concatenados!");
                    }
                    
                } // ##############################################
                //VAR NUM
                if(verificaVar($$.label) && !verificaVar($3.label)){
                    string aux = genTemp();
                    $$.declaracao += $3.declaracao + "\tchar " + aux + "[" + to_string(pilha[busca_escopo($$.label)][$$.label].valor.length() + $3.label.length() - 2) + "];\n";
                    $$.strcpy += $3.strcpy;
                    auxPrint += "\tstrcpy(" + aux + ", strcat(" + $$.traducao + ", " + $3.label2 + "));\n";
                    $$.traducao = aux;
                //VAR VAR
                }else if(verificaVar($$.label) && verificaVar($$.label)){
                    string aux = genTemp();
                    $$.declaracao += $3.declaracao + "\tchar " + aux + "[" + to_string(pilha[busca_escopo($$.label)][$$.label].valor.length() + pilha[busca_escopo($3.label)][$3.label].valor.length() - 2) + "];\n";
                    $$.strcpy += $3.strcpy;
                    auxPrint += "\tstrcpy(" + aux + ", strcat(" + $$.traducao + ", " + pilha[busca_escopo($3.label)][$3.label].temp + "));\n";
                    $$.traducao = aux;
                //NUM VAR
                }else if(!verificaVar($$.label) && verificaVar($3.label)){
                    string aux = genTemp();
                    $$.declaracao += $3.declaracao + "\tchar " + aux + "["  + to_string($$.traducao.length() + pilha[busca_escopo($3.label)][$3.label].valor.length() - 2) + "];\n";
                    $$.strcpy += $3.strcpy;
                    auxPrint += "\tstrcpy(" + aux + ", strcat(" + $$.traducao + ", " + pilha[busca_escopo($3.label)][$3.label].temp + "));\n";
                    $$.traducao = aux;
                }
                //NUM NUM
                else{
                    $$.label = genTemp();
                    $$.declaracao += $3.declaracao + "\tchar " + $$.label + "[" + to_string($$.traducao.length() + $3.traducao.length() - 2) + "];\n";
                    $$.strcpy += $3.strcpy;
                    auxPrint += "\tstrcpy(" + $$.label + ", strcat(" + $$.label2 + ", " + $3.label2 + "));\n";
                    $$.traducao = $$.label;
                } 
            }
            ;

TEXTO       : TK_STRING
            {   
                $$.tipo = "string";
                $$.label = genTemp();
                $$.valor = $1.label;
                $$.declaracao += "\t" + string("char") + " " + $$.label + string("[") + to_string($1.label.length()-1) +string("]")+ ";\n";
                $$.strcpy += "\t" + string("strcpy(") + $$.label + ", "+ $1.label + ")"+";\n"; 
                $$.traducao += $$.valor;
                $$.label2 += $$.label;
            }
            | TK_CHAR
            {
                $$.tipo = "char";
                $$.label = genTemp();
                $$.valor = $1.label;
                $$.declaracao += "\t" + string("char") + " " + $$.label + string("[") + to_string($1.label.length()-1) +string("]")+ ";\n";
                $$.strcpy += "\t" + string("strcpy(") + $$.label + ", "+ $1.label + ")"+";\n";
                $$.traducao += $1.label;
            }
            | TK_ID
            {
                $$.traducao += pilha[busca_escopo($1.label)][$1.label].temp;
            }
            ;
            

E		   : E '>' E
            {	
				operacao($$,$1,$2,$3, ">");
            }
			| E '<' E
            {	
				operacao($$,$1,$2,$3, "<");
            }
			| E EQ E
            {	
				operacao($$,$1,$2,$3, "==");
            }
			| E NE E
            {	
				operacao($$,$1,$2,$3, "!=");
            }
			| E GE E
            {	
				operacao($$,$1,$2,$3, ">=");
            }
			| E LE E
            {	
				operacao($$,$1,$2,$3, "<=");
            }
			| E AND E
            {	
				operacao($$,$1,$2,$3, "&&");
            }
			| E OR E
            {	
				operacao($$,$1,$2,$3, "||");
            }
            | NO E
            {	
                
                //VAR
                if(verificaVar($2.label)){
                    if(pilha[busca_escopo($2.label)][$2.label].tipo != "bool"){
                        yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
                    }
                    $$.label = genTemp();
                    $$.tipo = "bool";
                    $$.declaracao += $1.declaracao + $2.declaracao + "\t" + "int" + " " + $$.label + ";\n";
                    $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = " + "!" + pilha[busca_escopo($2.label)][$2.label].temp + ";\n";
                }else{
                    //NAO VAR
                    if($2.tipo != "bool"){
                        yyerror("ERRO: Operadores Lógicos só aceitam tipos Booleano!");
                    }
                    $$.label = genTemp();
                    $$.tipo = "bool";
                    $$.declaracao += $1.declaracao + $2.declaracao + "\t" + "int" + " " + $$.label + ";\n";
                    $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = " + "!" + $2.label + ";\n";
                }
            }
			| E '+' E
            {	
				operacao($$,$1,$2,$3, "+");
            }
            | E '-' E
            {
				operacao($$,$1,$2,$3, "-");
            }
            | E '*' E
            {
				operacao($$,$1,$2,$3, "*");
            }
			| E '/' E
            {
				operacao($$,$1,$2,$3, "/");
            }
            | TK_ID '=' E
            {   
                //E -> VAR  
                if(verificaVar($3.label)){
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" && pilha[busca_escopo($3.label)][$3.label].tipo != "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo($1.label)][$1.label].tipo != "bool" && pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" && pilha[busca_escopo($3.label)][$3.label].tipo != "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo($1.label)][$1.label].tipo != "char" && pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" && pilha[busca_escopo($3.label)][$3.label].tipo != "string"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo($1.label)][$1.label].tipo != "string" && pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                       yyerror("ERRO: Variável " + $3.label + " sem valor atribuido");
                    }
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" && pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" && pilha[busca_escopo($3.label)][$3.label].tipo != "int"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo($3.label)][$3.label].tipo == "string" && pilha[busca_escopo($1.label)][$1.label].tipo != "string"){
                    yyerror("ERRO: Tipos difentes!");
                    }
                    
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "float" && pilha[busca_escopo($3.label)][$3.label].tipo == "int"){
                        pilha[busca_escopo($1.label)][$1.label].atribuido = 1;
                        $$.label = genTemp();
                        $$.declaracao += $1.declaracao + $3.declaracao + "\t" + "float" + " " + $$.label + ";\n";
                        $$.traducao += $1.traducao + $3.traducao + "\t" + $$.label + " = " + "(" + "float" + ")" + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
                        $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + $$.label + ";\n";
				    }
                    else if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" && $3.tipo == "float"){
                        pilha[busca_escopo($1.label)][$1.label].atribuido = 1;
                        $$.label = genTemp();
                        $$.declaracao += $1.declaracao + $3.declaracao + "\t" + "int" + " " + $$.label + ";\n";
                        $$.traducao += $1.traducao + $3.traducao + "\t" + $$.label + " = " + "(" + "int" + ")" + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
                        $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + $$.label + ";\n";
                    }
				    //IGUAIS
                    else{
                        pilha[busca_escopo($1.label)][$1.label].atribuido = 1;
                        $$.declaracao += $1.declaracao + $3.declaracao;
                            if(pilha[busca_escopo($1.label)][$1.label].tipo == "string"){
                                pilha[busca_escopo($1.label)][$1.label].valor = $3.valor;
                                $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + string("(char*) malloc(") + to_string(pilha[busca_escopo($3.label)][$3.label].valor.length()-1) + string(")") + ";\n";
                                $$.traducao += "\t" + string("strcpy(") + pilha[busca_escopo($1.label)][$1.label].temp + string(", ") + pilha[busca_escopo($3.label)][$3.label].temp + ");\n";
                                pilha_malloc.push_back(pilha[busca_escopo($1.label)][$1.label].temp);
                            }
                            else{
                                $$.traducao += $1.traducao + $3.traducao + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
                            }
                        
                    }
                }
                else{
                    //E -> NUM
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" && $3.tipo != "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    } 
                    if(pilha[busca_escopo($1.label)][$1.label].tipo != "bool" && $3.tipo == "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    } 
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" && $3.tipo != "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(pilha[busca_escopo($1.label)][$1.label].tipo != "char" && $3.tipo == "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if((pilha[busca_escopo($1.label)][$1.label].tipo == "string") && ($3.tipo != "string")){
                        yyerror("ERRO: Tipos difentes!");
                    }    
                    if($3.tipo == "string" && pilha[busca_escopo($1.label)][$1.label].tipo != "string"){
                    yyerror("ERRO: Tipos difentes!");
                }   
                    
                    
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "float" && $3.tipo == "int"){
                        pilha[busca_escopo($1.label)][$1.label].atribuido = 1;
                        $3.tipo = "float";
                        $$.label = genTemp();
                        $$.declaracao += $1.declaracao + $3.declaracao + "\t" + $3.tipo + " " + $$.label + ";\n";
                        $$.traducao += $1.traducao + $3.traducao + "\t" + $$.label + " = " + "(" + $3.tipo + ")" + $3.label + ";\n";
                        $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + $$.label + ";\n";
                    }
                    else if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" && $3.tipo == "float"){
                        pilha[busca_escopo($1.label)][$1.label].atribuido = 1;
                        $3.tipo = "int";
                        $$.label = genTemp();
                        $$.declaracao += $1.declaracao + $3.declaracao + "\t" + $3.tipo + " " + $$.label + ";\n";
                        $$.traducao += $1.traducao + $3.traducao + "\t" + $$.label + " = " + "(" + $3.tipo + ")" + $3.label + ";\n";
                        $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + $$.label + ";\n";
                    }
                    //IGUAIS -string
                    if(pilha[busca_escopo($1.label)][$1.label].tipo == "string"){
                        if(pilha[busca_escopo($1.label)][$1.label].atribuido == 1){
                            int i;
                            for (i = 0; i < pilha_malloc.size(); i++) {
                                if (pilha_malloc[i] == pilha[busca_escopo($1.label)][$1.label].temp) {
                                    break; 
                                }
                            }
                            string aux = pilha_malloc[i];  // Obter o último elemento da pilha
                            pilha_malloc.erase(pilha_malloc.begin() + i);  // Remover o último elemento da pilha
                            $$.traducao += string("\t") + string("free(") + aux + ");\n";  // Adicionar a instrução 
                        }
                        pilha[busca_escopo($1.label)][$1.label].atribuido = 1;
                        pilha[busca_escopo($1.label)][$1.label].valor = $3.valor;
                        $$.declaracao += $1.declaracao + $3.declaracao;
                        $$.traducao += "\t" + string("strcpy(") + $3.label + string(", ") + $3.valor + ");\n";
                        $$.traducao += "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + string("(char*) malloc(") + to_string($3.valor.length()-1) + string(")") + ";\n";
                        $$.traducao += "\t" + string("strcpy(") + pilha[busca_escopo($1.label)][$1.label].temp + string(", ") + $3.label + ");\n";
                        pilha_malloc.push_back(pilha[busca_escopo($1.label)][$1.label].temp);
                    }
                    else{
                        pilha[busca_escopo($1.label)][$1.label].atribuido = 1;
                        $$.declaracao += $1.declaracao + $3.declaracao;
                        $$.traducao += $1.traducao + $3.traducao + "\t" + pilha[busca_escopo($1.label)][$1.label].temp + " = " + $3.label + ";\n";
                    }
                }
            }
            | TK_NUM
            {
				$$.tipo = "int";
                $$.valor = $1.label;
				$$.label = genTemp();
				$$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";
				$$.traducao += "\t" + $$.label + " = " + $1.label + ";\n";

                $$.valor = $1.label;
            }
            | TK_REAL 
            {
                $$.tipo = "float";
                $$.label = genTemp();
                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + $1.label + ";\n";
                //$$.label = $1.label;
            }
            | TK_CHAR 
            {
                $$.tipo = "char";
                $$.label = genTemp();
                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + $1.label + ";\n";
                //$$.label = $1.label;
            }
            | TK_STRING
            {
                $$.label = genTemp();
                $$.tipo = "string";
                $$.valor = $1.label;
                $$.declaracao += "\t" + string("char") + " " + $$.label + string("[") +to_string($1.label.length()-1) +string("]")+ ";\n";
                $$.traducao += "\t" + string("strcpy(") + $$.label + ", " + $1.label + ");\n";
                //$$.label = $1.label;
            }
			| TK_FALSE
            {
                string valor = "0";
                string tipo = "int";
                $$.tipo = "bool";
                $$.label = genTemp();
                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + valor + ";\n";
                //$$.label = valor;
            }
			| TK_TRUE
            {
                string valor = "1";
                string tipo = "int";
                $$.tipo = "bool";
                $$.label = genTemp();
                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + valor + ";\n";
                //$$.label = valor;
            }
			| TK_CAST_FLOAT E
            {   
                $$.tipo = "float";
                $$.label = genTemp();

                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";

                //CAST VAR
                if(verificaVar($2.label)){
                    $$.traducao += "\t" + $$.label + " = "  + "(float)"  + pilha[bloco_atual][$2.label].temp + ";\n";
                }
                //CAST NUM
                else if(!verificaVar($2.label)){
                    $$.declaracao += $1.declaracao + $2.declaracao;
                    $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = "  + "(float)"  + $2.label + ";\n";
                }
            }
            | TK_CAST_INT E
            {   
                $$.tipo = "int";
                $$.label = genTemp();

                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";

                //CAST VAR
                if(verificaVar($2.label)){
                    $$.traducao += "\t" + $$.label + " = "  + "(int)"  + pilha[bloco_atual][$2.label].temp + ";\n";
                }
                //CAST NUM
                else if(!verificaVar($2.label)){
                    $$.declaracao += $1.declaracao + $2.declaracao;
                    $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = "  + "(int)"  + $2.label + ";\n";
                }
            }
            | TK_CAST_CHAR E
            {   
                $$.tipo = "char";
                $$.label = genTemp();

                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";

                //CAST VAR
                if(verificaVar($2.label)){
                    $$.traducao += "\t" + $$.label + " = "  + "(char)"  + pilha[bloco_atual][$2.label].temp + ";\n";
                }
                //CAST NUM
                else if(!verificaVar($2.label)){
                    $$.declaracao += $1.declaracao + $2.declaracao;
                    $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = "  + "(char)"  + $2.label + ";\n";
                }
            }
            | TK_ID
            {
                naoDeclarado($1.label);
                //TIPO_SIMBOLO var = pilha[bloco_atual][$1.label];
                //$$.tipo = var.tipo;
            }
            | TK_ID '[' E ']'
            {
                $$.label = $1.label + '[' + $3.label + ']';
            }
            |
            {
                
            }
    		;

%%

#include "lex.yy.c"

int yyparse();

string genTemp()
{
	temp++;
	return  "t" + std::to_string(temp);
}
string genRot()
{
	tempRot++;
	return  "label_" + std::to_string(tempRot);
}

void declarado(string chave){
	if (verificaVarBloco(chave))
    	yyerror("ERRO: Variável " + chave + " já foi declarada!");
}

void naoDeclarado(string chave){
	if (!verificaVar(chave))
		yyerror("ERRO: Variável " + chave + " não foi declarada!");
}

int verificaVar(string var){
    for(int i=bloco_atual;i>=0;i--){
        if(!(pilha[i].find(var) == pilha[i].end())){
            return 1;
        }
    }  
    return 0;
}

int verificaVarBloco(string var){
    if(!(pilha[bloco_atual].find(var) == pilha[bloco_atual].end())){
        return 1;
    }
    return 0;
}

int busca_escopo(string var){
    for(int i= bloco_atual; i>=0; i--){
        if(!(pilha[i].find(var) == pilha[i].end())){
            return pilha[i][var].bloco;
        }
    } 
    yyerror("ERRO: Variável " + var + " não foi declarada!");  
    return 0;
} 

void conversaoImplicitaOp(atributos& $$, atributos& $1, atributos& $3, string operador, string tipo){
    //NUMERO NUMERO
    if(!verificaVar($1.label) && !verificaVar($3.label)){
        if(($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao += $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao += $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $1.label + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = $1.tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
        }
    }
    //VAR NUMERO
    else if(verificaVar($1.label) && !verificaVar($3.label)){
        if((pilha[busca_escopo($1.label)][$1.label].tipo == "int" && $3.tipo == "float") || (pilha[busca_escopo($1.label)][$1.label].tipo == "float" && $3.tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + pilha[busca_escopo($1.label)][$1.label].temp + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = pilha[busca_escopo($1.label)][$1.label].tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + pilha[busca_escopo($1.label)][$1.label].temp + " " + operador + " " + $3.label + ";\n";
        }
    }
    //NUMERO VAR
    else if(!verificaVar($1.label) && verificaVar($3.label)){
        if(($1.tipo == "int" && pilha[busca_escopo($3.label)][$3.label].tipo == "float") || ($1.tipo == "float" && pilha[busca_escopo($3.label)][$3.label].tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $1.label + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = $1.tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
        }
    }
    //VAR VAR
    else if(verificaVar($1.label) && verificaVar($3.label)){
        if((pilha[busca_escopo($1.label)][$1.label].tipo == "int" && pilha[busca_escopo($3.label)][$3.label].tipo == "float") || (pilha[busca_escopo($1.label)][$1.label].tipo == "float" && pilha[busca_escopo($3.label)][$3.label].tipo == "int") ){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + pilha[busca_escopo($1.label)][$1.label].temp + ";\n";

            string aux = $$.label;
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = "float";
            }
            else{
                $$.tipo = "bool";
            }
            
            $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
        }
        else{
            $$.label = genTemp();
            if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                $$.tipo = pilha[busca_escopo($1.label)][$1.label].tipo;
            }
            else{
                $$.tipo = "bool";
            }
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + pilha[busca_escopo($1.label)][$1.label].temp + " " + operador + " " + pilha[busca_escopo($3.label)][$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
        }
    }
}

void operacao(atributos& $$, atributos& $1, atributos& $2, atributos& $3, string operador){
    if(verificaVar($1.label) || verificaVar($3.label)){
        // $1 var
        if(verificaVar($1.label)){
            if (pilha[busca_escopo($1.label)][$1.label].atribuido == 0){
                yyerror("ERRO: variável " + $1.label + " sem valor atribuido!");
            }
            if(operador == "||" || operador == "&&"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" || pilha[busca_escopo($1.label)][$1.label].tipo  == "float" || pilha[busca_escopo($1.label)][$1.label].tipo == "char" || pilha[busca_escopo($1.label)][$1.label].tipo == "string" || $3.tipo == "int" || $3.tipo == "float" || $3.tipo == "char" || $3.tipo == "string"){
                    yyerror("ERRO: Operadores lógicos só aceitam tipo Booleano!");
                }
            }
            if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" ||  $3.tipo == "bool"){
                    yyerror("ERRO: Operadores relacionais não aceitam tipo Booleano!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  $3.tipo == "string"){
                    yyerror("ERRO: Operadores relacionais não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  $3.tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
                }
            }
            if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" || $3.tipo == "bool"){
                    yyerror("Erro: operações aritiméticas não aceitam booleanos!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  $3.tipo == "string"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  $3.tipo == "char"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
                }
            }
        }
        // $3 var
        if(verificaVar($3.label)){ 
            if (pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                yyerror("ERRO: Variável " + $3.label + " sem valor atribuido!");
            }
            if(operador == "||" || operador == "&&"){
                if($1.tipo == "int" || $1.tipo == "float" || $1.tipo == "char" || $1.tipo == "string" || pilha[busca_escopo($3.label)][$3.label].tipo == "int" || pilha[busca_escopo($3.label)][$3.label].tipo == "float" || pilha[busca_escopo($3.label)][$3.label].tipo == "char" || pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
                }
            }
            if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
                if($1.tipo == "bool" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo Booleano!");
                }
                if($1.tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo string!");
                }
                if($1.tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
                }
            }
            if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                if($1.tipo == "bool" || pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("Erro: operações aritiméticas não aceitam booleanos!");
                }
                if($1.tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
                }
                if($1.tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
                }
            }
        }
        // $1 e $3 var
        if(verificaVar($1.label) && verificaVar($3.label)){
            if (pilha[busca_escopo($1.label)][$1.label].atribuido == 0){
                yyerror("ERRO: Variável " + $1.label + " sem valor atribuido!");
            }
            if (pilha[busca_escopo($3.label)][$3.label].atribuido == 0){
                yyerror("ERRO: Variável " + $3.label + " sem valor atribuido!");
            }
            if(operador == "||" || operador == "&&"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" || pilha[busca_escopo($1.label)][$1.label].tipo == "float" || pilha[busca_escopo($1.label)][$1.label].tipo == "char" || pilha[busca_escopo($1.label)][$1.label].tipo == "string" || pilha[busca_escopo($3.label)][$3.label].tipo == "int" || pilha[busca_escopo($3.label)][$3.label].tipo == "float" || pilha[busca_escopo($3.label)][$3.label].tipo == "char" || pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
                }
            }
            if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo Booleano!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores Relacionais não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
            }
            }
            if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "bool" || pilha[busca_escopo($3.label)][$3.label].tipo == "bool"){
                    yyerror("Erro: operações aritiméticas não aceitam booleanos!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "string" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "string"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
                }
                if(pilha[busca_escopo($1.label)][$1.label].tipo == "char" ||  pilha[busca_escopo($3.label)][$3.label].tipo == "char"){
                    yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
                }
            }
        }
    }
    // $1 e $3 não var
    else{
        if(operador == "||" || operador == "&&"){
            if(pilha[busca_escopo($1.label)][$1.label].tipo == "int" || pilha[busca_escopo($1.label)][$1.label].tipo == "float" || pilha[busca_escopo($1.label)][$1.label].tipo == "char" || pilha[busca_escopo($1.label)][$1.label].tipo == "string" || $3.tipo == "int" || $3.tipo == "float" || $3.tipo == "char" || $3.tipo == "string"){
                yyerror("ERRO: Operadores Lógicos só aceitam tipo Booleano!");
            }
        }
        if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
            if($1.tipo == "bool" ||  $3.tipo == "bool"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo Booleano!");
            }
            if($1.tipo == "string" ||  $3.tipo == "string"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo string!");
            }
            if($1.tipo == "char" ||  $3.tipo == "char"){
                yyerror("ERRO: Operadores relacionais não aceitam tipo char!");
            }
        }
        if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
            if($1.tipo == "bool" || $3.tipo == "bool"){
                yyerror("Erro: operações aritiméticas não aceitam booleanos!");
            }
            if($1.tipo == "string" ||  $3.tipo == "string"){
                yyerror("ERRO: Operadores aritiméticos não aceitam tipo string!");
            }
            if($1.tipo == "char" ||  $3.tipo == "char"){
                yyerror("ERRO: Operadores aritiméticos não aceitam tipo char!");
            }
        }
    }

    //relacionanis e lógicos
    if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "!=" || operador == "&&" || operador == "||"){
        conversaoImplicitaOp($$, $1, $3, operador, "int");
    }
    
    //aritimeticos
    if(operador == "+" || operador == "-" || operador == "*" || operador == "/"){
        conversaoImplicitaOp($$,$1,$3,operador,"int");
    }
}

void empilha(){
    pilha.push_back(unordered_map<string, TIPO_SIMBOLO>());
}

void desempilha(){
    pilha.pop_back();
}

int main( int argc, char* argv[] )
{
	temp = 0;
    tempRot = 0;
	yyparse();
	

	return 0;
}

void yyerror( string MSG )
{
	cout << "Linha " + to_string(contn) + " -> " + MSG << endl;
    //cout << MSG << endl;
	exit (0);
}
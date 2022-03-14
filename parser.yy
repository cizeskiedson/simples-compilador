/*
 * PARSER
 */

%{

/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"

#define yylex driver.scanner_->yylex

%}

%code requires {
  #include <iostream>
  #include "driver.hh"
  #include "location.hh"
  #include "position.hh"
}

%code provides {
  namespace Simples  {
    // Forward declaration of the Driver class
    class Driver;

    inline void yyerror (const char* msg) {
      std::cerr << msg << std::endl;
    }
  }
}

/* Require bison 2.3 or later */
%require "2.4"
/* enable c++ generation */
%language "C++"
%locations
/* write out a header file containing the token defines */
%defines
/* add debug output code to generated parser. disable this for release
 * versions. */
%debug
/* namespace to enclose parser in */
%define api.namespace {Simples}
/* set the parser's class identifier */
%define api.parser.class {Parser}
/* set the parser */
%parse-param {Driver &driver}
/* set the lexer */
%lex-param {Driver &driver}
/* verbose error messages */
%define parse.error verbose
/* use newer C++ skeleton file */
%skeleton "lalr1.cc"
/* Entry point of grammar */
%start programa

%union
{
 /* YYLTYPE */
  int  			      integerVal;
  double 			    doubleVal;
  std::string*		stringVal;
}

/* Tokens */
%token              TOK_EOF 0     "end of file"
%token			        EOL		        "end of line"
%token <integerVal> INTEGER		    "integer"
%token <doubleVal> 	REAL		      "real"
%token <stringVal> 	IDENTIFIER    "identifier"
%token <stringVal>  CADEIA        "cadeia"
%token   PARE          "pare"
%token   COMENTARIO    "comentario"
%token   PARA          "para"
%token   DE            "de"
%token   ENQUANTO      "enquanto"
%token   FENQUANTO     "fenquanto"
%token   FACA          "faça"
%token   FALSO         "falso"
%token   FIM           "fim"
%token   FPARA         "fpara"
%token   FSE           "fse"
%token   FUN           "fun"
%token   GLOBAL        "global"
%token   CONTINUE      "continue"
%token   INICIO        "início"
%token   LIMITE        "limite"
%token   LOCAL        "local"
%token   NULO          "nulo"
%token   REF           "ref"
%token   RETORNE       "retorne"
%token   SE            "se"
%token   TIPO          "tipo"
%token   VAR           "var"
%token   VALOR         "valor"
%token   VERDADEIRO    "verdadeiro"
%token   VIRGULA       "virgula"
%token   DOISPONTOS    "doisPontos"
%token   PONTOVIRGULA    "pontoVirgula"
%token   ABREPARENTESES    "abreParenteses"
%token   FECHAPARENTESES    "fechaParenteses"
%token   ABRECOLCHETE   "abreColchete"
%token   FECHACOLCHETE    "fechaColchete"
%token   ABRECHAVE    "abreChave"
%token   FECHACHAVE   "fechaChave"
%token   PONTO    "ponto"
%token   MAIS    "mais"
%token   MENOS    "menos"
%token   PRODUTO   "produto"
%token   BARRA   "barra"
%token   COMPARASETA    "comparaSeta"
%token   MENOR    "menor"
%token   MENORIGUAL    "menorIgual"
%token   MAIOR    "maior"
%token   MAIORIGUAL   "maiorIgual"
%token   E    "e"
%token   OU    "ou"
%token   ATRIBUICAO    "atribuicao"
%token   IGUAL    "igual"
%token   COMPARA    "compara"
%token   DIFERENTE    "diferente"
%token   TERNARIA   "ternaria"

%%


programa: declaracoes {std::cout << "DECLARACOES" << std::endl; }

declaracoes: lista_declaracao_de_tipo {std::cout << "COMECA A LISTA" << std::endl; }
            | lista_declaracao_de_globais {std::cout << "COMECA OS GLOBAIS" << std::endl;}

lista_declaracao_de_tipo: 
            | TIPO DOISPONTOS lista_declaracao_tipo {std::cout << "ABRE DECLARACOES" <<std::endl;}

lista_declaracao_de_globais:
            | GLOBAL DOISPONTOS lista_declaracao_variavel {std::cout << "ABRE VARIAVEIS" << std::endl;}

lista_declaracao_tipo: declaracao_tipo {std::cout << "ACHEI UM TIPO " <<std::endl;}
            |lista_declaracao_tipo declaracao_tipo {std::cout << "LOOP DECLARA TIPO" <<std::endl;}

lista_declaracao_variavel: declaracao_variavel {std::cout << "ACHEI UMA VARIAVEL " <<std::endl;}
            |lista_declaracao_variavel declaracao_variavel {std::cout << "LOOP DECLARA VAR" <<std::endl;}


declaracao_tipo:
            IDENTIFIER IGUAL descritor_tipo {std::cout << "DECLARA UM TIPO" <<std::endl;}

descritor_tipo: 
            IDENTIFIER {std::cout << "ID" <<std::endl;}
            | ABRECHAVE tipo_campos FECHACHAVE {std::cout << "CAMPOS STRUCT" <<std::endl;}
            | ABRECOLCHETE tipo_constantes FECHACOLCHETE DE IDENTIFIER {std::cout << "CONSTANTES" <<std::endl;}

tipo_campos: tipo_campo {std::cout << "TIPO CAMPOS" <<std::endl;}
            | tipo_campo VIRGULA tipo_campos

tipo_campo: IDENTIFIER DOISPONTOS IDENTIFIER {std::cout << "TIPO CAMPO" <<std::endl;}

tipo_constantes:
        INTEGER {std::cout << "INTEIRO ARRAY" <<std::endl;}
        | INTEGER VIRGULA tipo_constantes



/*VARIÁVEIS*/
declaracao_variavel: 
      IDENTIFIER DOISPONTOS IDENTIFIER ATRIBUICAO expr {std::cout << "TESTE VARIAVEL DECLARADA" <<std::endl;}

/* REGISTROS */
criacao_de_registro:
    tipo_registro
    | criacao_de_registro VIRGULA tipo_registro

tipo_registro:
    IDENTIFIER IGUAL valor

valor:
    INTEGER
    | REAL
    | CADEIA

/* EXPRESSÕES */
expr: expr_logica {std::cout << "EXPR_LOGIAC" <<std::endl;}
      | ABRECHAVE criacao_de_registro FECHACHAVE {std::cout << "REGISTRO CRIADO" <<std::endl;}

expr_logica: expr_logica OU expr_relacional {std::cout << "OU" <<std::endl;}
      | expr_logica E expr_relacional {std::cout << "E" <<std::endl;}
      | expr_relacional

expr_relacional:
       expr_relacional MENORIGUAL expr_aritmetica  {std::cout << "MENORIGUAL" <<std::endl;}
      | expr_relacional MAIORIGUAL expr_aritmetica {std::cout << "MAIORIGUAL" <<std::endl;}
      | expr_relacional MENOR expr_aritmetica {std::cout << "MENOR" <<std::endl;}
      | expr_relacional MAIOR expr_aritmetica {std::cout << "MAIOR" <<std::endl;}
      | expr_relacional DIFERENTE expr_aritmetica {std::cout << "DIFERENTE" <<std::endl;}
      | expr_relacional COMPARA expr_aritmetica {std::cout << "COMPARA" <<std::endl;}
      | expr_aritmetica

expr_aritmetica:
      expr_aritmetica MAIS expr_aritmetica_linha {std::cout << "MAIS" <<std::endl;}
      | expr_aritmetica MENOS expr_aritmetica_linha {std::cout << "MENOS" <<std::endl;}
      | expr_aritmetica_linha

expr_aritmetica_linha:
      expr_aritmetica_linha PRODUTO fator {std::cout << "PRODUTO" <<std::endl;}
      | expr_aritmetica_linha BARRA fator {std::cout << "DIVISAO" <<std::endl;}
      | fator

fator:
    ABREPARENTESES expr FECHAPARENTESES {std::cout << "PARENTESES" <<std::endl;}
    | valor {std::cout << "VALOR" <<std::endl;}
    | IDENTIFIER {std::cout << "ID" <<std::endl;}
  /*   | chamada_de_funcao
    | local_de_armazenamento
    | nulo */

/* expressao_logica:
  E
  | OU

expressao_aritmetica:
      PRODUTO
      | BARRA
      | MAIS
      | MENOS

expressao_relacional:
      COMPARA
      | DIFERENTE
      | MAIOR
      | MENOR 
      | MAIORIGUAL
      | MENORIGUAL
      | E
      | OU */

/* 
constant : INTEGER { std::cout << "Inteiro: " << $1 << std::endl; }
         | REAL  { std::cout << "Real: " << $1 << std::endl; }

variable : IDENTIFIER {  std::cout << "Identificador: " << $1 << std::endl; }

cadeia:   CADEIA  { std::cout << "Cadeia: " << $1 << std::endl;  }

pare: PARE  { std::cout << "Pare: "  << std::endl;  }

comentario: COMENTARIO { std::cout << "Comentario: " << std::endl; }

para: PARA  { std::cout << "Para: " << std::endl; }

de: DE { std::cout << "Cadeia Tipo: " << std::endl; }

enquanto: ENQUANTO { std::cout << "Enquanto: " << std::endl; }

fenquanto: FENQUANTO { std::cout << "FEnquanto: " << std::endl; }

faca: FACA { std::cout << "Faca: " << std::endl; }

falso: FALSO { std::cout << "Falso: " << std::endl; }

fim: FIM { std::cout << "Fim: " << std::endl; }

fpara: FPARA { std::cout << "Fpara: " << std::endl; }

fse: FSE { std::cout << "Fse: " << std::endl; }

fun: FUN { std::cout << "Fun: " << std::endl; }

global: GLOBAL { std::cout << "Global: " << std::endl; }

continue: CONTINUE { std::cout << "Continue: " << std::endl; }

inicio: INICIO { std::cout << "Inicio: " << std::endl; }

limite: LIMITE { std::cout << "Limite: " << std::endl; }

local: LOCAL { std::cout << "Local: " << std::endl; }

nulo: NULO { std::cout << "Nulo: " << std::endl; }

ref: REF { std::cout << "Ref: " << std::endl; }

retorne: RETORNE { std::cout << "Retorne: " << std::endl; }

se: SE { std::cout << "Se: " << std::endl; }

tipo: TIPO { std::cout << "Tipo: " << std::endl; }

var: VAR { std::cout << "Var: " << std::endl; }

valor: VALOR { std::cout << "Valor: " << std::endl; }

verdadeiro: VERDADEIRO { std::cout << "Verdadeiro: " << std::endl; }

virgula: VIRGULA { std::cout << "Virgula: " << std::endl; }

doisPontos: DOISPONTOS { std::cout << "Dois Pontos: " << std::endl; }

pontoVirgula: PONTOVIRGULA { std::cout << "Ponto e Virgula: " << std::endl; }

abreParenteses: ABREPARENTESES { std::cout << "Abre Parenteses: " << std::endl; }

fechaParenteses: FECHAPARENTESES { std::cout << "Fecha Parenteses: " << std::endl; }

abreColchete: ABRECOLCHETE { std::cout << "Abre Colchete: " << std::endl; }

fechaColchete: FECHACOLCHETE { std::cout << "Fecha Colchete: " << std::endl; }

abreChave: ABRECHAVE { std::cout << "Abre Chave: " << std::endl; }

fechaChave: FECHACHAVE { std::cout << "Fecha Chave: " << std::endl; }

ponto: PONTO { std::cout << "Ponto: " << std::endl; }

mais: MAIS { std::cout << "Mais: " << std::endl; }

menos: MENOS { std::cout << "Menos: " << std::endl; }

produto: PRODUTO { std::cout << "Produto: " << std::endl; }

barra: BARRA { std::cout << "Barra: " << std::endl; }

comparaSeta: COMPARASETA { std::cout << "Compara <>: " << std::endl; }

menor: MENOR { std::cout << "Menor: " << std::endl; }

menorIgual: MENORIGUAL { std::cout << "Menor Igual: " << std::endl; }

maior: MAIOR { std::cout << "Maior: " << std::endl; }

maiorIgual: MAIORIGUAL { std::cout << "Maior Igual: " << std::endl; }

e: E { std::cout << "E: " << std::endl; }

ou: OU { std::cout << "Ou: " << std::endl; }

atribuicao: ATRIBUICAO { std::cout << "Atribuicao: " << std::endl; }

igual: IGUAL { std::cout << "Igual: " << std::endl; }

compara: COMPARA { std::cout << "Compara: " << std::endl; }

ternaria: TERNARIA { std::cout << "Ternaria: " << std::endl; } */
%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}

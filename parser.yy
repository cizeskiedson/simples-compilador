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
%start program

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
%token <stringVal>  PARE          "pare"
%token <stringVal>  COMENTARIO    "comentario"
%token <stringVal>  PARA          "para"
%token <stringVal>  CADEIARESV    "tipo cadeia" 
%token <stringVal>  DE            "de"
%token <stringVal>  ENQUANTO      "enquanto"
%token <stringVal>  FACA          "faca"
%token <stringVal>  FALSO         "falso"
%token <stringVal>  FIM           "fim"
%token <stringVal>  FUN           "fun"
%token <stringVal>  CONTINUE      "continue"
%token <stringVal>  INICIO        "inicio"
%token <stringVal>  INTEIRO       "inteiro"
%token <stringVal>  LIMITE        "limite"
%token <stringVal>  NULO          "nulo"
%token <stringVal>  REF           "ref"
%token <stringVal>  RETORNE       "retorne"
%token <stringVal>  SE            "se"
%token <stringVal>  VAR           "var"
%token <stringVal>  VERDADEIRO    "verdadeiro"
%token <stringVal>  VIRGULA       "virgula"
%token <stringVal>  DOISPONTOS    "doisPontos"
%token <stringVal>  PONTOVIRGULA    "pontoVirgula"
%token <stringVal>  ABREPARENTESES    "abreParenteses"
%token <stringVal>  FECHAPARENTESES    "fechaParenteses"
%token <stringVal>  ABRECOLCHETE   "abreColchete"
%token <stringVal>  FECHACOLCHETE    "fechaColchete"
%token <stringVal>  ABRECHAVE    "abreChave"
%token <stringVal>  FECHACHAVE   "fechaChave"
%token <stringVal>  PONTO    "ponto"
%token <stringVal>  MAIS    "mais"
%token <stringVal>  MENOS    "menos"
%token <stringVal>  PRODUTO   "produto"
%token <stringVal>  BARRA   "barra"
%token <stringVal>  COMPARASETA    "comparaSeta"
%token <stringVal>  MENOR    "menor"
%token <stringVal>  MENORIGUAL    "menorIgual"
%token <stringVal>  MAIOR    "maior"
%token <stringVal>  MAIORIGUAL   "maiorIgual"
%token <stringVal>  E    "e"
%token <stringVal>  OU    "ou"
%token <stringVal>  ATRIBUICAO    "atribuicao"
%token <stringVal>  IGUAL    "igual"
%token <stringVal>  COMPARA    "compara"
%token <stringVal>  TERNARIA   "ternaria"

%%

program:  /* empty */
        | constant program
        | variable program
        | cadeia program
        | pare program
        | comentario program
        | para program
        | cadeiaresv program
        | de program
        | enquanto program
        | faca program
        | falso program
        | fim program
        | fun program
        | continue program
        | inicio program
        | inteiro program
        | limite program
        | nulo program
        | ref program
        | retorne program
        | se program
        | var program
        | verdadeiro program
        | virgula program
        | doisPontos program
        | pontoVirgula program
        | abreParenteses program
        | fechaParenteses program
        | abreColchete program
        | fechaColchete program
        | abreChave program
        | fechaChave program
        | ponto program
        | mais program
        | menos program
        | produto program
        | barra program
        | comparaSeta program
        | menor program
        | menorIgual program
        | maior program
        | maiorIgual program
        | e program
        | ou program
        | atribuicao program
        | igual program
        | compara program
        | ternaria program

constant : INTEGER { std::cout << "Inteiro: " << $1 << std::endl; }
         | REAL  { std::cout << "Real: " << $1 << std::endl; }

variable : IDENTIFIER {  std::cout << "Identificador: " << *$1 << std::endl; }

cadeia:   CADEIA  { std::cout << "Cadeia: " << *$1 << std::endl;  }

pare: PARE  { std::cout << "Pare: " << *$1 << std::endl;  }

comentario: COMENTARIO { std::cout << "Comentario: " << *$1 << std::endl; }

para: PARA  { std::cout << "Para: " << *$1 << std::endl; }

cadeiaresv: CADEIARESV  { std::cout << "Cadeia Tipo: " << *$1 << std::endl; }

de: DE { std::cout << "Cadeia Tipo: " << *$1 << std::endl; }

enquanto: ENQUANTO { std::cout << "Enquanto: " << *$1 << std::endl; }

faca: FACA { std::cout << "Faca: " << *$1 << std::endl; }

falso: FALSO { std::cout << "Falso: " << *$1 << std::endl; }

fim: FIM { std::cout << "Fim: " << *$1 << std::endl; }

fun: FUN { std::cout << "Fun: " << *$1 << std::endl; }

continue: CONTINUE { std::cout << "Continue: " << *$1 << std::endl; }

inicio: INICIO { std::cout << "Inicio: " << *$1 << std::endl; }

inteiro: INTEIRO { std::cout << "Inteiro: " << *$1 << std::endl; }

limite: LIMITE { std::cout << "Limite: " << *$1 << std::endl; }

nulo: NULO { std::cout << "Nulo: " << *$1 << std::endl; }

ref: REF { std::cout << "Ref: " << *$1 << std::endl; }

retorne: RETORNE { std::cout << "Retorne: " << *$1 << std::endl; }

se: SE { std::cout << "Se: " << *$1 << std::endl; }

var: VAR { std::cout << "Var: " << *$1 << std::endl; }

verdadeiro: VERDADEIRO { std::cout << "Verdadeiro: " << *$1 << std::endl; }

virgula: VIRGULA { std::cout << "Virgula: " << *$1 << std::endl; }

doisPontos: DOISPONTOS { std::cout << "Dois Pontos: " << *$1 << std::endl; }

pontoVirgula: PONTOVIRGULA { std::cout << "Ponto e Virgula: " << *$1 << std::endl; }

abreParenteses: ABREPARENTESES { std::cout << "Abre Parenteses: " << *$1 << std::endl; }

fechaParenteses: FECHAPARENTESES { std::cout << "Fecha Parenteses: " << *$1 << std::endl; }

abreColchete: ABRECOLCHETE { std::cout << "Abre Colchete: " << *$1 << std::endl; }

fechaColchete: FECHACOLCHETE { std::cout << "Fecha Colchete: " << *$1 << std::endl; }

abreChave: ABRECHAVE { std::cout << "Abre Chave: " << *$1 << std::endl; }

fechaChave: FECHACHAVE { std::cout << "Fecha Chave: " << *$1 << std::endl; }

ponto: PONTO { std::cout << "Ponto: " << *$1 << std::endl; }

mais: MAIS { std::cout << "Mais: " << *$1 << std::endl; }

menos: MENOS { std::cout << "Menos: " << *$1 << std::endl; }

produto: PRODUTO { std::cout << "Produto: " << *$1 << std::endl; }

barra: BARRA { std::cout << "Barra: " << *$1 << std::endl; }

comparaSeta: COMPARASETA { std::cout << "Compara <>: " << *$1 << std::endl; }

menor: MENOR { std::cout << "Menor: " << *$1 << std::endl; }

menorIgual: MENORIGUAL { std::cout << "Menor Igual: " << *$1 << std::endl; }

maior: MAIOR { std::cout << "Maior: " << *$1 << std::endl; }

maiorIgual: MAIORIGUAL { std::cout << "Maior Igual: " << *$1 << std::endl; }

e: E { std::cout << "E: " << *$1 << std::endl; }

ou: OU { std::cout << "Ou: " << *$1 << std::endl; }

atribuicao: ATRIBUICAO { std::cout << "Atribuicao: " << *$1 << std::endl; }

igual: IGUAL { std::cout << "Igual: " << *$1 << std::endl; }

compara: COMPARA { std::cout << "Compara: " << *$1 << std::endl; }

ternaria: TERNARIA { std::cout << "Ternaria: " << *$1 << std::endl; }
%%

namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}

%{ /* -*- C++ -*- */

#include "parser.hh"
#include "scanner.hh"
#include "driver.hh"

/*  Defines some macros to update locations */
#define STEP() do {driver.location_->step();} while (0)
#define COL(col) driver.location_->columns(col)
#define LINE(line) do {driver.location_->lines(line);} while (0)
#define YY_USER_ACTION COL(yyleng);

/* import the parser's token type into a local typedef */
typedef Simples::Parser::token token;
typedef Simples::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::TOK_EOF

%}

/*** Flex Declarations and Options ***/

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug
/* enable c++ scanner class generation */
%option c++
/* we don’t need yywrap */
%option noyywrap
/* you should not expect to be able to use the program interactively */
%option never-interactive
/* provide the global variable yylineno */
%option yylineno
/* do not fabricate input text to be scanned */
%option nounput
/* the manual says "somewhat more optimized" */
%option batch
/* change the name of the scanner class. results in "SimplesFlexLexer" */
%option prefix="Simples"

/*
%option stack
*/

/* Abbreviations.  */

blank   [ \t]+
eol     [\n\r]+

%%

 /* The following paragraph suffices to track locations accurately. Each time
 yylex is invoked, the begin position is moved onto the end position. */
%{
  STEP();
%}

 /*** BEGIN EXAMPLE - Change the example lexer rules below ***/

[0-9]+ {
     yylval->integerVal = atoi(yytext);
     return token::INTEGER;
 }

[0-9]+"."[0-9]* {
  yylval->doubleVal = atof(yytext);
  return token::REAL;
}

"cadeia" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::CADEIARESV;
}

"continue" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::CONTINUE;
}

"de" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::DE;
  }

"enquanto" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ENQUANTO;
} 

"faça" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FACA;
}

"falso" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FALSO;
}

"fenquanto" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FENQUANTO;
} 


"fim" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FIM;
}

"fpara" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FPARA;
}

"fse" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FSE;
}


"fun" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FUN;
}

"global" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::GLOBAL;
}


"início" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::INICIO;
}

"inteiro" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::INTEIRO;
}

"limite" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::LIMITE;
}

"local" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::LOCAL;
}


"nulo" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::NULO;
}

"para" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PARA;
}

"pare" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PARE;
}

"ref" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::REF;
}

"retorne" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::RETORNE;
}

"se" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::SE;
}

"tipo" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::TIPO;
}

"var" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::VAR;
}

"valor" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::VALOR;
}

"verdadeiro" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::VERDADEIRO;
}

"," {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::VIRGULA;
}
":" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::DOISPONTOS;
}
";" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PONTOVIRGULA;
}
"(" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ABREPARENTESES;
}
")" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FECHAPARENTESES;
}
"[" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ABRECOLCHETE;
}
"]" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FECHACOLCHETE;
}
"{" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ABRECHAVE;
}
"}" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::FECHACHAVE;
}
"." {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PONTO;
}
"+" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MAIS;
}
"-" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MENOS;
}
"*" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::PRODUTO;
}
"/" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::BARRA;
}
"<>" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::COMPARASETA;
}
"<" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MENOR;
}
"<=" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MENORIGUAL;
}
">" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MAIOR;
}
">=" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::MAIORIGUAL;
}
"&" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::E;
}
"|" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::OU;
}
":=" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::ATRIBUICAO;
}
"=" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IGUAL;
}
"==" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::COMPARA;
}
"?" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::TERNARIA;
}



[A-Za-z][A-Za-z0-9_,.-]* {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::IDENTIFIER;
}

\"[^\"]+\" {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::CADEIA;
}

\/*(.)**\/ {
  yylval->stringVal = new std::string(yytext, yyleng);
  return token::COMENTARIO;
}

{blank} { STEP(); }

{eol}  { LINE(yyleng); }

.             {
                std::cerr << *driver.location_ << " Unexpected token : "
                                              << *yytext << std::endl;
                driver.error_ = (driver.error_ == 127 ? 127
                                : driver.error_ + 1);
                STEP ();
              }

%%

/* CUSTOM C++ CODE */

namespace Simples {

  Scanner::Scanner() : SimplesFlexLexer() {}

  Scanner::~Scanner() {}

  void Scanner::set_debug(bool b) {
    yy_flex_debug = b;
  }
}

#ifdef yylex
# undef yylex
#endif

int SimplesFlexLexer::yylex()
{
  std::cerr << "call parsepitFlexLexer::yylex()!" << std::endl;
  return 0;
}

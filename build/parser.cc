// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 5 "parser.yy"


/*** C++ Declarations ***/
#include "parser.hh"
#include "scanner.hh"

#define yylex driver.scanner_->yylex


#line 50 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"


#include "parser.hh"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 44 "parser.yy"
namespace Simples {
#line 147 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 59:
#line 188 "parser.yy"
                                                       {std::cout << "TESTE VARIAVEL DECLARADA" <<std::endl;}
#line 643 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 60:
#line 206 "parser.yy"
                   { std::cout << "Inteiro: " << (yystack_[0].value.integerVal) << std::endl; }
#line 649 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 61:
#line 207 "parser.yy"
                 { std::cout << "Real: " << (yystack_[0].value.doubleVal) << std::endl; }
#line 655 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 62:
#line 209 "parser.yy"
                      {  std::cout << "Identificador: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 661 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 63:
#line 211 "parser.yy"
                  { std::cout << "Cadeia: " << *(yystack_[0].value.stringVal) << std::endl;  }
#line 667 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 64:
#line 213 "parser.yy"
            { std::cout << "Pare: " << *(yystack_[0].value.stringVal) << std::endl;  }
#line 673 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 65:
#line 215 "parser.yy"
                       { std::cout << "Comentario: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 679 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 66:
#line 217 "parser.yy"
            { std::cout << "Para: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 685 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 67:
#line 219 "parser.yy"
                        { std::cout << "Cadeia Tipo: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 691 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 68:
#line 221 "parser.yy"
       { std::cout << "Cadeia Tipo: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 697 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 69:
#line 223 "parser.yy"
                   { std::cout << "Enquanto: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 703 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 70:
#line 225 "parser.yy"
                     { std::cout << "FEnquanto: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 709 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 71:
#line 227 "parser.yy"
           { std::cout << "Faca: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 715 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 72:
#line 229 "parser.yy"
             { std::cout << "Falso: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 721 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 73:
#line 231 "parser.yy"
         { std::cout << "Fim: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 727 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 74:
#line 233 "parser.yy"
             { std::cout << "Fpara: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 733 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 75:
#line 235 "parser.yy"
         { std::cout << "Fse: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 739 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 76:
#line 237 "parser.yy"
         { std::cout << "Fun: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 745 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 77:
#line 239 "parser.yy"
               { std::cout << "Global: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 751 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 78:
#line 241 "parser.yy"
                   { std::cout << "Continue: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 757 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 79:
#line 243 "parser.yy"
               { std::cout << "Inicio: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 763 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 80:
#line 245 "parser.yy"
                 { std::cout << "Inteiro: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 769 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 81:
#line 247 "parser.yy"
               { std::cout << "Limite: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 775 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 82:
#line 249 "parser.yy"
             { std::cout << "Local: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 781 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 83:
#line 251 "parser.yy"
           { std::cout << "Nulo: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 787 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 84:
#line 253 "parser.yy"
         { std::cout << "Ref: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 793 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 85:
#line 255 "parser.yy"
                 { std::cout << "Retorne: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 799 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 86:
#line 257 "parser.yy"
       { std::cout << "Se: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 805 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 87:
#line 259 "parser.yy"
           { std::cout << "Tipo: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 811 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 88:
#line 261 "parser.yy"
         { std::cout << "Var: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 817 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 89:
#line 263 "parser.yy"
             { std::cout << "Valor: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 823 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 90:
#line 265 "parser.yy"
                       { std::cout << "Verdadeiro: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 829 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 91:
#line 267 "parser.yy"
                 { std::cout << "Virgula: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 835 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 92:
#line 269 "parser.yy"
                       { std::cout << "Dois Pontos: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 841 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 93:
#line 271 "parser.yy"
                           { std::cout << "Ponto e Virgula: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 847 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 94:
#line 273 "parser.yy"
                               { std::cout << "Abre Parenteses: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 853 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 95:
#line 275 "parser.yy"
                                 { std::cout << "Fecha Parenteses: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 859 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 96:
#line 277 "parser.yy"
                           { std::cout << "Abre Colchete: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 865 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 97:
#line 279 "parser.yy"
                             { std::cout << "Fecha Colchete: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 871 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 98:
#line 281 "parser.yy"
                     { std::cout << "Abre Chave: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 877 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 99:
#line 283 "parser.yy"
                       { std::cout << "Fecha Chave: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 883 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 100:
#line 285 "parser.yy"
             { std::cout << "Ponto: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 889 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 101:
#line 287 "parser.yy"
           { std::cout << "Mais: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 895 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 102:
#line 289 "parser.yy"
             { std::cout << "Menos: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 901 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 103:
#line 291 "parser.yy"
                 { std::cout << "Produto: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 907 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 104:
#line 293 "parser.yy"
             { std::cout << "Barra: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 913 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 105:
#line 295 "parser.yy"
                         { std::cout << "Compara <>: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 919 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 106:
#line 297 "parser.yy"
             { std::cout << "Menor: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 925 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 107:
#line 299 "parser.yy"
                       { std::cout << "Menor Igual: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 931 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 108:
#line 301 "parser.yy"
             { std::cout << "Maior: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 937 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 109:
#line 303 "parser.yy"
                       { std::cout << "Maior Igual: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 943 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 110:
#line 305 "parser.yy"
     { std::cout << "E: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 949 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 111:
#line 307 "parser.yy"
       { std::cout << "Ou: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 955 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 112:
#line 309 "parser.yy"
                       { std::cout << "Atribuicao: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 961 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 113:
#line 311 "parser.yy"
             { std::cout << "Igual: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 967 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 114:
#line 313 "parser.yy"
                 { std::cout << "Compara: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 973 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;

  case 115:
#line 315 "parser.yy"
                   { std::cout << "Ternaria: " << *(yystack_[0].value.stringVal) << std::endl; }
#line 979 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"
    break;


#line 983 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -5;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      -4,    -5,    -5,    76,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,   113,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    90,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    59,   112,    -5
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     0,     1,    58,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,     0,    59
  };

  const signed char
  Parser::yypgoto_[] =
  {
      -5,    -2,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113
  };

  const unsigned char
  Parser::yytable_[] =
  {
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   114,   115,   172,   173,   174
  };

  const signed char
  Parser::yycheck_[] =
  {
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    36,     0,    24,    56,     4
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    36,     0,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    24,    56,     4
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      63,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"integer\"", "\"real\"", "\"identifier\"", "\"cadeia\"", "\"pare\"",
  "\"comentario\"", "\"para\"", "\"tipo cadeia\"", "\"de\"",
  "\"enquanto\"", "\"fenquanto\"", "\"faça\"", "\"falso\"", "\"fim\"",
  "\"fpara\"", "\"fse\"", "\"fun\"", "\"global\"", "\"continue\"",
  "\"início\"", "\"inteiro\"", "\"limite\"", "\"local\"", "\"nulo\"",
  "\"ref\"", "\"retorne\"", "\"se\"", "\"tipo\"", "\"var\"", "\"valor\"",
  "\"verdadeiro\"", "\"virgula\"", "\"doisPontos\"", "\"pontoVirgula\"",
  "\"abreParenteses\"", "\"fechaParenteses\"", "\"abreColchete\"",
  "\"fechaColchete\"", "\"abreChave\"", "\"fechaChave\"", "\"ponto\"",
  "\"mais\"", "\"menos\"", "\"produto\"", "\"barra\"", "\"comparaSeta\"",
  "\"menor\"", "\"menorIgual\"", "\"maior\"", "\"maiorIgual\"", "\"e\"",
  "\"ou\"", "\"atribuicao\"", "\"igual\"", "\"compara\"", "\"ternaria\"",
  "$accept", "program", "declaracao_variavel", "constant", "variable",
  "cadeia", "pare", "comentario", "para", "cadeiaresv", "de", "enquanto",
  "fenquanto", "faca", "falso", "fim", "fpara", "fse", "fun", "global",
  "continue", "inicio", "inteiro", "limite", "local", "nulo", "ref",
  "retorne", "se", "tipo", "var", "valor", "verdadeiro", "virgula",
  "doisPontos", "pontoVirgula", "abreParenteses", "fechaParenteses",
  "abreColchete", "fechaColchete", "abreChave", "fechaChave", "ponto",
  "mais", "menos", "produto", "barra", "comparaSeta", "menor",
  "menorIgual", "maior", "maiorIgual", "e", "ou", "atribuicao", "igual",
  "compara", "ternaria", YY_NULLPTR
  };

#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   128,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   188,
     206,   207,   209,   211,   213,   215,   217,   219,   221,   223,
     225,   227,   229,   231,   233,   235,   237,   239,   241,   243,
     245,   247,   249,   251,   253,   255,   257,   259,   261,   263,
     265,   267,   269,   271,   273,   275,   277,   279,   281,   283,
     285,   287,   289,   291,   293,   295,   297,   299,   301,   303,
     305,   307,   309,   311,   313,   315
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
    };
    const int user_token_number_max_ = 314;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 44 "parser.yy"
} // Simples
#line 1550 "/home/edson/Documents/uem/COMPILADORES/simples_compilador/build/parser.cc"

#line 316 "parser.yy"


namespace Simples {
   void Parser::error(const location&, const std::string& m) {
        std::cerr << *driver.location_ << ": " << m << std::endl;
        driver.error_ = (driver.error_ == 127 ? 127 : driver.error_ + 1);
   }
}

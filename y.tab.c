/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar    1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 3 "parser.y"

static char sccsID[] = "@(#)parser.y    1.2 07/02/88";

#include <stdio.h>

typedef struct {
  char name[30];
  int offset;
  int type;
  int size;
} record;

#define OPadd 300
#define OPsub 301
#define OPmul 302
#define OPdiv 303
#define OPmod 304
#define OPband 305
#define OPbor 306
#define OPbxor 307
#define OPbnot 308
#define OPlnot 312
#define OPge 313
#define OPle 314
#define OPeq 315
#define OPne 316
#define OPgt 317
#define OPlt 318
#define OPshr 319
#define OPshl 320
#define OPneg 321

#define INTEGER 180
#define CHAR 181

#define LOCAL 200
#define GLOBAL 201
#define PARAM 202
#define PROCEDURE 203
#define STRING 204

#line 56 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  unsigned char *charptr;
  record *recordptr;
  int integer;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 76 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SYMif 257
#define SYMthen 258
#define SYMelse 259
#define SYMelseif 260
#define SYMwhile 261
#define SYMdo 262
#define SYMrepeat 263
#define SYMuntil 264
#define SYMcall 265
#define SYMtext 266
#define SYMdata 267
#define SYMdefine 268
#define SYMstatic 269
#define SYMbegin 270
#define SYMreturn 271
#define SYMend 272
#define SYMint 273
#define SYMchar 274
#define SYMentry 275
#define SYMlparen 276
#define SYMrparen 277
#define SYMlbracket 278
#define SYMrbracket 279
#define SYM2rbracket 280
#define SYMsemi 281
#define SYMcomma 282
#define SYMaddress 283
#define SYMnumber 284
#define SYMid 285
#define SYMstring 286
#define SYMstr 287
#define SYMcode 288
#define SYMcodeaddr 289
#define SYMlowest 290
#define SYMlval 291
#define SYMexpr 292
#define SYMgets 293
#define SYMdotgets 294
#define SYMlogor 295
#define SYMlogxor 296
#define SYMlogand 297
#define SYMlognot 298
#define SYMge 299
#define SYMle 300
#define SYMeq 301
#define SYMne 302
#define SYMgt 303
#define SYMlt 304
#define SYMplus 305
#define SYMminus 306
#define SYMbitor 307
#define SYMbitxor 308
#define SYMtimes 309
#define SYMdivide 310
#define SYMmod 311
#define SYMbitand 312
#define SYMshr 313
#define SYMshl 314
#define SYMbitnot 315
#define SYMdot 316
#define SYMhighest 317
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    8,    8,    9,    9,    9,    9,    9,    9,    9,
    9,    9,   12,   10,   10,    1,    1,    1,    1,   11,
   14,   14,   14,   15,   17,   17,   16,   18,   20,   20,
   19,   19,    7,    6,    5,   21,   21,   21,   21,   21,
   21,   23,   23,   23,   13,   13,   24,   24,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   25,   26,
   27,   29,   30,   30,   28,   28,   28,    2,    4,    3,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    2,    2,    2,    2,    2,    1,    1,
    3,    1,    1,    2,    0,    3,    2,    3,    2,    3,
    1,    2,    2,    3,    2,    0,    4,    1,    2,    0,
    2,    0,    0,    0,    0,    1,    2,    1,    2,    7,
    5,    5,    9,    8,    4,    4,    2,    0,    3,    3,
    3,    3,    3,    2,    3,    3,    3,    2,    3,    3,
    3,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    1,    2,    1,    5,    1,    1,
    1,    1,    2,    0,    3,    3,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,    0,    0,    0,   15,    0,    0,    0,    0,
    2,   12,   89,    8,    7,    0,    0,   88,   21,    6,
    0,    0,    4,   13,    0,   48,    0,   22,   23,   26,
   30,    0,    0,   14,    0,   90,   11,    0,    0,    0,
   20,    0,    0,   17,   19,    0,    0,   45,   47,   46,
   24,   25,   32,   29,   16,   18,    0,    0,   33,   33,
    0,    0,   27,    0,    0,    0,    0,    0,    0,   87,
   77,   38,   31,    0,    0,    0,   39,    0,   32,   82,
    0,    0,    0,    0,    0,   74,    0,   54,   58,   80,
   81,   79,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   76,    0,    0,    0,   84,   71,   85,
   86,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   51,   52,   53,   55,   63,   64,    0,    0,    0,
    0,    0,   32,    0,    0,    0,    0,   32,    0,   78,
    0,   42,    0,    0,   33,   33,   40,   32,    0,    0,
   44,   43,
};
static const YYINT yydgoto[] = {                          1,
   34,   70,   37,   71,  153,  115,   78,    2,   11,   22,
   20,   25,   72,   21,   31,   41,   40,   42,   57,   43,
   73,   74,   77,   38,  109,  110,  111,   75,   81,  146,
};
static const YYINT yysindex[] = {                         0,
    0,  971, -276, -276, -261,    0, -268, -268, -254, -250,
    0,    0,    0,    0,    0, -268, -268,    0,    0,    0,
 -247, -259,    0,    0, -223,    0, -268,    0,    0,    0,
    0, -268, -268,    0, -242,    0,    0, -256, -201, -258,
    0, -191, -259,    0,    0, -268, -268,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  766,  913,    0,    0,
 -255,  913,    0,  913,  913, -255,  913,  913,  913,    0,
    0,    0,    0, 1060, -260, 1060,    0,  913,    0,    0,
 -196, 1060,  968, 1004, -216,    0, 1094,    0,    0,    0,
    0,    0,  913,  913,  913,  913,  913,  913,  913,  913,
  913,  913,  913,  913,  913,  913,  913,  913,  913,  913,
  913,  913,  913,    0, -240, 1060,  782,    0,    0,    0,
    0,  979,  979,  979,  979,  979,  979, -252, -252, -252,
 -252,    0,    0,    0,    0,    0,    0, 1094, 1078, 1078,
 1060, 1060,    0, -180,  913,  903,  822,    0, 1060,    0,
 1060,    0, -187,  851,    0,    0,    0,    0,  913,  887,
    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,   83,    1,    5,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   16,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -186,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  665, -168, -173,    0,    0,    0,    0,
    0,  701,    0,    0, 1040,    0,  167,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -157,    0,    0,    0,    0,
    0,  209,  251,  293,  335,  377,  419, -109,  -50,   49,
  108,    0,    0,    0,    0,    0,    0,  461,  503,  545,
  587,  629,    0,    0,    0,    0, -185,    0,  737,    0,
  929,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
   63, 1215,    0,   64,    0,   -4,  -57,    0,    0,    0,
    0,    0,  111,    0,    0,    0,    0,    0,  -77,    0,
    0,  -58,  -45,    0,    0,    0,    0,    4,    0,    0,
};
#define YYTABLESIZE 1408
static const YYINT yytable[] = {                         76,
   10,  117,   79,   82,    9,   83,   84,   13,   87,   88,
   89,   16,   17,   32,   33,    5,   18,  143,   51,  116,
   48,   26,   65,   18,   13,   27,   18,   13,   30,   18,
   46,   47,  112,  113,  122,  123,  124,  125,  126,  127,
  128,  129,  130,  131,  132,  133,  134,  135,  136,  137,
  138,  139,  140,  141,  142,  114,  103,  104,  105,  106,
  107,  108,   36,  121,   80,  147,   14,   15,   85,   86,
  154,  155,  156,   35,   35,   50,  112,  113,   53,  118,
  160,  148,    1,   28,   34,   35,  149,  151,   75,   75,
   75,   75,   75,   75,   75,   75,   75,  158,  159,  114,
   76,   49,   75,   75,   34,   54,   35,   75,   75,   75,
   75,  144,   12,  161,   75,   75,   75,    0,    0,   75,
   75,    0,    0,    0,    0,    0,   75,   75,   75,   75,
   75,   75,   75,   75,   75,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   75,   75,   75,   49,   49,   49,
   49,   49,   49,   49,   49,   49,    0,    0,    0,    0,
    0,   49,   49,    0,    0,    0,   49,   49,   49,   49,
    0,    0,    0,   49,   49,   49,    0,    0,   49,   49,
    0,    0,    0,    0,    0,   49,   49,   49,   49,   49,
   49,   49,   49,   49,   49,   49,   49,   49,   49,    0,
    0,    0,    0,    0,    0,   49,   50,   50,   50,   50,
   50,   50,   50,   50,   50,    0,    0,    0,    0,    0,
   50,   50,    0,    0,    0,   50,   50,   50,   50,    0,
    0,    0,   50,   50,   50,    0,    0,   50,   50,    0,
    0,    0,    0,    0,   50,   50,   50,   50,   50,   50,
   50,   50,   50,   50,   50,   50,   50,   50,    0,    0,
    0,    0,    0,    0,   50,    0,   10,   10,   10,   10,
    9,    9,    9,    9,    0,   10,    0,    0,    0,    9,
    0,    5,    5,    5,    5,    0,    0,   10,   10,   10,
    5,    9,    9,    9,    0,    0,    0,    0,    0,    0,
    0,    0,    5,    5,    5,   56,   56,   56,   56,   56,
   56,   56,   56,   56,    0,    0,    0,    0,    0,   56,
   56,    0,    0,    0,   56,   56,   56,   56,    0,    0,
    0,   56,   56,   56,    0,    0,   56,   56,    0,    0,
    0,    0,    0,   56,   56,   56,   56,   56,   56,   56,
   56,   56,   56,   56,   56,   56,   56,    0,    0,    0,
    0,    0,    0,   56,   57,   57,   57,   57,   57,   57,
   57,   57,   57,    0,    0,    0,    0,    0,   57,   57,
    0,    0,    0,   57,   57,   57,   57,    0,    0,    0,
   57,   57,   57,    0,    0,   57,   57,    0,    0,    0,
    0,    0,   57,   57,   57,   57,   57,   57,   57,   57,
   57,   57,   57,   57,   57,   57,    0,    0,    0,    0,
    0,    0,   57,   62,   62,   62,   62,   62,   62,   62,
   62,   62,    0,    0,    0,    0,    0,   62,   62,    0,
    0,    0,   62,   62,   62,   62,    0,    0,    0,   62,
   62,   62,    0,    0,   62,   62,    0,    0,    0,    0,
    0,   62,   62,   62,   62,   65,   65,   65,   65,   65,
   65,   65,   65,   65,    0,    0,    0,    0,    0,   65,
   65,   62,    0,    0,   65,   65,   65,   65,    0,    0,
    0,   65,   65,   65,    0,    0,   65,   65,    0,    0,
    0,    0,    0,   65,   65,   65,   65,   66,   66,   66,
   66,   66,   66,   66,   66,   66,    0,    0,    0,    0,
    0,   66,   66,   65,    0,    0,   66,   66,   66,   66,
    0,    0,    0,   66,   66,   66,    0,    0,   66,   66,
    0,    0,    0,    0,    0,   66,   66,   66,   66,   67,
   67,   67,   67,   67,   67,   67,   67,   67,    0,    0,
    0,    0,    0,   67,   67,   66,    0,    0,   67,   67,
   67,   67,    0,    0,    0,   67,   67,   67,    0,    0,
   67,   67,    0,    0,    0,    0,    0,   67,   67,   67,
   67,   68,   68,   68,   68,   68,   68,   68,   68,   68,
    0,    0,    0,    0,    0,   68,   68,   67,    0,    0,
   68,   68,   68,   68,    0,    0,    0,   68,   68,   68,
    0,    0,   68,   68,    0,    0,    0,    0,    0,   68,
   68,   68,   68,   69,   69,   69,   69,   69,   69,   69,
   69,   69,    0,    0,    0,    0,    0,   69,   69,   68,
    0,    0,   69,   69,   69,   69,    0,    0,    0,   69,
   69,   69,    0,    0,   69,   69,    0,    0,    0,    0,
    0,   69,   69,   69,   69,   70,   70,   70,   70,   70,
   70,   70,   70,   70,    0,    0,    0,    0,    0,   70,
   70,   69,    0,    0,   70,   70,   70,   70,    0,    0,
    0,   70,   70,   70,    0,    0,   70,   70,    0,    0,
    0,    0,    0,   70,   70,   70,   70,   59,   59,   59,
   59,   59,   59,   59,   59,   59,    0,    0,    0,    0,
    0,   59,   59,   70,    0,    0,   59,   59,   59,   59,
    0,    0,    0,   59,   59,   59,    0,    0,   59,   59,
    0,    0,    0,    0,    0,   59,   59,   59,   59,   60,
   60,   60,   60,   60,   60,   60,   60,   60,    0,    0,
    0,    0,    0,   60,   60,   59,    0,    0,   60,   60,
   60,   60,    0,    0,    0,   60,   60,   60,    0,    0,
   60,   60,    0,    0,    0,    0,    0,   60,   60,    0,
   60,   61,   61,   61,   61,   61,   61,   61,   61,   61,
    0,    0,    0,    0,    0,   61,   61,   60,    0,    0,
   61,   61,   61,   61,    0,    0,    0,   61,   61,   61,
    0,    0,   61,   61,    0,    0,    0,    0,    0,   61,
   61,    0,   61,   72,   72,   72,   72,   72,   72,   72,
   72,   72,    0,    0,    0,    0,    0,   72,   72,   61,
    0,    0,   72,   72,   72,   72,    0,    0,    0,   72,
   72,   72,    0,    0,   72,   72,    0,    0,    0,    0,
    0,    0,    0,    0,   72,   73,   73,   73,   73,   73,
   73,   73,   73,   73,    0,    0,    0,    0,    0,   73,
   73,   72,    0,    0,   73,   73,   73,   73,    0,    0,
    0,   73,   73,   73,    0,    0,   73,   73,    0,    0,
    0,   36,    0,   36,   36,   36,   73,   36,   36,   36,
    0,    0,    0,    0,    0,   36,   36,    0,    0,    0,
   36,    0,   36,   73,    0,    0,    0,   36,   36,   36,
    0,    0,   36,   36,    0,    0,    0,   37,    0,   37,
   37,   37,   36,   37,   37,   37,    0,    0,    0,    0,
    0,   37,   37,    0,    0,    0,   37,    0,   37,   36,
    0,    0,    0,   37,   37,   37,    0,    0,   37,   37,
    0,    0,    0,   41,    0,   41,   41,   41,   37,   41,
   41,   41,    0,    0,    0,    0,    0,   41,   41,    0,
    0,    0,   41,    0,   41,   37,    0,    0,    0,   41,
   41,   41,   58,    0,   41,   41,   59,    0,   60,    0,
   61,    0,    0,    0,   41,    0,   62,   63,   58,    0,
    0,   64,   59,   65,   60,  145,   61,    0,   66,   13,
   18,   41,   62,    9,   10,    0,    0,   64,    0,   65,
    0,    0,    0,   67,   66,   13,   18,    0,    0,    9,
   10,   68,    0,    0,    0,    0,    0,    0,   58,   67,
   69,    0,   59,    0,   60,    0,   61,   68,    0,    0,
    0,    0,   62,  152,    0,    0,   69,   64,    0,   65,
    0,    0,    0,    0,   66,   13,   18,   58,    0,    9,
   10,   59,    0,   60,    0,   61,    0,    0,    0,   67,
    0,   62,  157,    0,    0,    0,   64,   68,   65,    0,
    0,    0,    0,   66,   13,   18,   69,    0,    9,   10,
    0,    0,    0,   58,    0,    0,    0,   59,   67,   60,
    0,   61,    0,    0,    0,    0,   68,   62,  162,    0,
    0,    0,   64,    0,   65,   69,    0,   61,    0,   66,
   13,   18,    0,    0,    9,   10,    0,   61,   64,  150,
   65,    0,    0,    0,   67,   66,   13,   18,   64,    0,
   65,    0,   68,   83,    0,   66,   13,   18,    0,    0,
   67,   69,    0,    0,   83,   83,   83,    0,   68,    0,
   67,   83,   83,   83,    0,    0,    0,   69,   68,   19,
    0,   23,   24,    0,    0,    0,   83,   69,    0,    0,
   28,   29,    0,    0,    0,    0,    3,    4,    5,    6,
    0,   39,    0,   83,  119,    7,   44,   45,    0,    0,
    0,    0,    0,    0,   52,    0,    0,    8,    9,   10,
   55,   56,   90,   91,   92,    0,   93,   94,   95,   96,
   97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
  107,  108,  120,   99,  100,  101,  102,  103,  104,  105,
  106,  107,  108,    0,    0,    0,    0,    0,   90,   91,
   92,    0,   93,   94,   95,   96,   97,   98,   99,  100,
  101,  102,  103,  104,  105,  106,  107,  108,   75,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   75,   75,   75,    0,   75,   75,
   75,   75,   75,   75,   75,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   90,   91,   92,    0,   93,   94,
   95,   96,   97,   98,   99,  100,  101,  102,  103,  104,
  105,  106,  107,  108,   92,    0,   93,   94,   95,   96,
   97,   98,   99,  100,  101,  102,  103,  104,  105,  106,
  107,  108,   93,   94,   95,   96,   97,   98,   99,  100,
  101,  102,  103,  104,  105,  106,  107,  108,
};
static const YYINT yycheck[] = {                         58,
    0,   79,   60,   62,    0,   64,   65,  284,   67,   68,
   69,  273,  274,  273,  274,    0,  285,  258,  277,   78,
  277,  276,  278,  285,  284,  276,  285,  284,  276,  285,
  273,  274,  293,  294,   93,   94,   95,   96,   97,   98,
   99,  100,  101,  102,  103,  104,  105,  106,  107,  108,
  109,  110,  111,  112,  113,  316,  309,  310,  311,  312,
  313,  314,  286,  280,   61,  143,    3,    4,   65,   66,
  148,  259,  260,  259,  260,  277,  293,  294,  270,  276,
  158,  262,    0,  270,  258,   22,  145,  146,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  155,  156,  316,
  159,   38,  271,  272,  262,   43,   43,  276,  277,  278,
  279,  116,    2,  159,  283,  284,  285,   -1,   -1,  288,
  289,   -1,   -1,   -1,   -1,   -1,  295,  296,  297,  298,
  299,  300,  301,  302,  303,  304,  305,  306,  307,  308,
  309,  310,  311,  312,  313,  314,  315,  257,  258,  259,
  260,  261,  262,  263,  264,  265,   -1,   -1,   -1,   -1,
   -1,  271,  272,   -1,   -1,   -1,  276,  277,  278,  279,
   -1,   -1,   -1,  283,  284,  285,   -1,   -1,  288,  289,
   -1,   -1,   -1,   -1,   -1,  295,  296,  297,  298,  299,
  300,  301,  302,  303,  304,  305,  306,  307,  308,   -1,
   -1,   -1,   -1,   -1,   -1,  315,  257,  258,  259,  260,
  261,  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,
  271,  272,   -1,   -1,   -1,  276,  277,  278,  279,   -1,
   -1,   -1,  283,  284,  285,   -1,   -1,  288,  289,   -1,
   -1,   -1,   -1,   -1,  295,  296,  297,  298,  299,  300,
  301,  302,  303,  304,  305,  306,  307,  308,   -1,   -1,
   -1,   -1,   -1,   -1,  315,   -1,  266,  267,  268,  269,
  266,  267,  268,  269,   -1,  275,   -1,   -1,   -1,  275,
   -1,  266,  267,  268,  269,   -1,   -1,  287,  288,  289,
  275,  287,  288,  289,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  287,  288,  289,  257,  258,  259,  260,  261,
  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,  271,
  272,   -1,   -1,   -1,  276,  277,  278,  279,   -1,   -1,
   -1,  283,  284,  285,   -1,   -1,  288,  289,   -1,   -1,
   -1,   -1,   -1,  295,  296,  297,  298,  299,  300,  301,
  302,  303,  304,  305,  306,  307,  308,   -1,   -1,   -1,
   -1,   -1,   -1,  315,  257,  258,  259,  260,  261,  262,
  263,  264,  265,   -1,   -1,   -1,   -1,   -1,  271,  272,
   -1,   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,
  283,  284,  285,   -1,   -1,  288,  289,   -1,   -1,   -1,
   -1,   -1,  295,  296,  297,  298,  299,  300,  301,  302,
  303,  304,  305,  306,  307,  308,   -1,   -1,   -1,   -1,
   -1,   -1,  315,  257,  258,  259,  260,  261,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,  271,  272,   -1,
   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,  283,
  284,  285,   -1,   -1,  288,  289,   -1,   -1,   -1,   -1,
   -1,  295,  296,  297,  298,  257,  258,  259,  260,  261,
  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,  271,
  272,  315,   -1,   -1,  276,  277,  278,  279,   -1,   -1,
   -1,  283,  284,  285,   -1,   -1,  288,  289,   -1,   -1,
   -1,   -1,   -1,  295,  296,  297,  298,  257,  258,  259,
  260,  261,  262,  263,  264,  265,   -1,   -1,   -1,   -1,
   -1,  271,  272,  315,   -1,   -1,  276,  277,  278,  279,
   -1,   -1,   -1,  283,  284,  285,   -1,   -1,  288,  289,
   -1,   -1,   -1,   -1,   -1,  295,  296,  297,  298,  257,
  258,  259,  260,  261,  262,  263,  264,  265,   -1,   -1,
   -1,   -1,   -1,  271,  272,  315,   -1,   -1,  276,  277,
  278,  279,   -1,   -1,   -1,  283,  284,  285,   -1,   -1,
  288,  289,   -1,   -1,   -1,   -1,   -1,  295,  296,  297,
  298,  257,  258,  259,  260,  261,  262,  263,  264,  265,
   -1,   -1,   -1,   -1,   -1,  271,  272,  315,   -1,   -1,
  276,  277,  278,  279,   -1,   -1,   -1,  283,  284,  285,
   -1,   -1,  288,  289,   -1,   -1,   -1,   -1,   -1,  295,
  296,  297,  298,  257,  258,  259,  260,  261,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,  271,  272,  315,
   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,  283,
  284,  285,   -1,   -1,  288,  289,   -1,   -1,   -1,   -1,
   -1,  295,  296,  297,  298,  257,  258,  259,  260,  261,
  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,  271,
  272,  315,   -1,   -1,  276,  277,  278,  279,   -1,   -1,
   -1,  283,  284,  285,   -1,   -1,  288,  289,   -1,   -1,
   -1,   -1,   -1,  295,  296,  297,  298,  257,  258,  259,
  260,  261,  262,  263,  264,  265,   -1,   -1,   -1,   -1,
   -1,  271,  272,  315,   -1,   -1,  276,  277,  278,  279,
   -1,   -1,   -1,  283,  284,  285,   -1,   -1,  288,  289,
   -1,   -1,   -1,   -1,   -1,  295,  296,  297,  298,  257,
  258,  259,  260,  261,  262,  263,  264,  265,   -1,   -1,
   -1,   -1,   -1,  271,  272,  315,   -1,   -1,  276,  277,
  278,  279,   -1,   -1,   -1,  283,  284,  285,   -1,   -1,
  288,  289,   -1,   -1,   -1,   -1,   -1,  295,  296,   -1,
  298,  257,  258,  259,  260,  261,  262,  263,  264,  265,
   -1,   -1,   -1,   -1,   -1,  271,  272,  315,   -1,   -1,
  276,  277,  278,  279,   -1,   -1,   -1,  283,  284,  285,
   -1,   -1,  288,  289,   -1,   -1,   -1,   -1,   -1,  295,
  296,   -1,  298,  257,  258,  259,  260,  261,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,  271,  272,  315,
   -1,   -1,  276,  277,  278,  279,   -1,   -1,   -1,  283,
  284,  285,   -1,   -1,  288,  289,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  298,  257,  258,  259,  260,  261,
  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,  271,
  272,  315,   -1,   -1,  276,  277,  278,  279,   -1,   -1,
   -1,  283,  284,  285,   -1,   -1,  288,  289,   -1,   -1,
   -1,  257,   -1,  259,  260,  261,  298,  263,  264,  265,
   -1,   -1,   -1,   -1,   -1,  271,  272,   -1,   -1,   -1,
  276,   -1,  278,  315,   -1,   -1,   -1,  283,  284,  285,
   -1,   -1,  288,  289,   -1,   -1,   -1,  257,   -1,  259,
  260,  261,  298,  263,  264,  265,   -1,   -1,   -1,   -1,
   -1,  271,  272,   -1,   -1,   -1,  276,   -1,  278,  315,
   -1,   -1,   -1,  283,  284,  285,   -1,   -1,  288,  289,
   -1,   -1,   -1,  257,   -1,  259,  260,  261,  298,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,  271,  272,   -1,
   -1,   -1,  276,   -1,  278,  315,   -1,   -1,   -1,  283,
  284,  285,  257,   -1,  288,  289,  261,   -1,  263,   -1,
  265,   -1,   -1,   -1,  298,   -1,  271,  272,  257,   -1,
   -1,  276,  261,  278,  263,  264,  265,   -1,  283,  284,
  285,  315,  271,  288,  289,   -1,   -1,  276,   -1,  278,
   -1,   -1,   -1,  298,  283,  284,  285,   -1,   -1,  288,
  289,  306,   -1,   -1,   -1,   -1,   -1,   -1,  257,  298,
  315,   -1,  261,   -1,  263,   -1,  265,  306,   -1,   -1,
   -1,   -1,  271,  272,   -1,   -1,  315,  276,   -1,  278,
   -1,   -1,   -1,   -1,  283,  284,  285,  257,   -1,  288,
  289,  261,   -1,  263,   -1,  265,   -1,   -1,   -1,  298,
   -1,  271,  272,   -1,   -1,   -1,  276,  306,  278,   -1,
   -1,   -1,   -1,  283,  284,  285,  315,   -1,  288,  289,
   -1,   -1,   -1,  257,   -1,   -1,   -1,  261,  298,  263,
   -1,  265,   -1,   -1,   -1,   -1,  306,  271,  272,   -1,
   -1,   -1,  276,   -1,  278,  315,   -1,  265,   -1,  283,
  284,  285,   -1,   -1,  288,  289,   -1,  265,  276,  277,
  278,   -1,   -1,   -1,  298,  283,  284,  285,  276,   -1,
  278,   -1,  306,  265,   -1,  283,  284,  285,   -1,   -1,
  298,  315,   -1,   -1,  276,  277,  278,   -1,  306,   -1,
  298,  283,  284,  285,   -1,   -1,   -1,  315,  306,    5,
   -1,    7,    8,   -1,   -1,   -1,  298,  315,   -1,   -1,
   16,   17,   -1,   -1,   -1,   -1,  266,  267,  268,  269,
   -1,   27,   -1,  315,  277,  275,   32,   33,   -1,   -1,
   -1,   -1,   -1,   -1,   40,   -1,   -1,  287,  288,  289,
   46,   47,  295,  296,  297,   -1,  299,  300,  301,  302,
  303,  304,  305,  306,  307,  308,  309,  310,  311,  312,
  313,  314,  279,  305,  306,  307,  308,  309,  310,  311,
  312,  313,  314,   -1,   -1,   -1,   -1,   -1,  295,  296,
  297,   -1,  299,  300,  301,  302,  303,  304,  305,  306,
  307,  308,  309,  310,  311,  312,  313,  314,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  295,  296,  297,   -1,  299,  300,
  301,  302,  303,  304,  305,  306,  307,  308,  309,  310,
  311,  312,  313,  314,  295,  296,  297,   -1,  299,  300,
  301,  302,  303,  304,  305,  306,  307,  308,  309,  310,
  311,  312,  313,  314,  297,   -1,  299,  300,  301,  302,
  303,  304,  305,  306,  307,  308,  309,  310,  311,  312,
  313,  314,  299,  300,  301,  302,  303,  304,  305,  306,
  307,  308,  309,  310,  311,  312,  313,  314,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 317
#define YYUNDFTOKEN 350
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SYMif","SYMthen","SYMelse",
"SYMelseif","SYMwhile","SYMdo","SYMrepeat","SYMuntil","SYMcall","SYMtext",
"SYMdata","SYMdefine","SYMstatic","SYMbegin","SYMreturn","SYMend","SYMint",
"SYMchar","SYMentry","SYMlparen","SYMrparen","SYMlbracket","SYMrbracket",
"SYM2rbracket","SYMsemi","SYMcomma","SYMaddress","SYMnumber","SYMid",
"SYMstring","SYMstr","SYMcode","SYMcodeaddr","SYMlowest","SYMlval","SYMexpr",
"SYMgets","SYMdotgets","SYMlogor","SYMlogxor","SYMlogand","SYMlognot","SYMge",
"SYMle","SYMeq","SYMne","SYMgt","SYMlt","SYMplus","SYMminus","SYMbitor",
"SYMbitxor","SYMtimes","SYMdivide","SYMmod","SYMbitand","SYMshr","SYMshl",
"SYMbitnot","SYMdot","SYMhighest",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : blocks",
"blocks : blocks block",
"blocks :",
"block : SYMentry id",
"block : SYMstatic globalvars",
"block : SYMdefine procedure",
"block : SYMdata number",
"block : SYMtext number",
"block : SYMdata",
"block : SYMtext",
"block : SYMstr stringid string",
"block : codestmt",
"stringid : id",
"globalvars : globalvars var",
"globalvars :",
"var : number SYMint id",
"var : SYMint id",
"var : number SYMchar id",
"var : SYMchar id",
"procedure : procedureid formals body",
"procedureid : id",
"procedureid : SYMint id",
"procedureid : SYMchar id",
"formals : SYMlparen paramvars SYMrparen",
"paramvars : paramvars id",
"paramvars :",
"body : locals SYMbegin stmts SYMend",
"locals : localvars",
"localvars : localvars var",
"localvars :",
"stmts : stmts stmt",
"stmts :",
"lab :",
"fbrf :",
"fbr :",
"stmt : expr",
"stmt : SYMreturn expr",
"stmt : codestmt",
"stmt : SYMif ifbody",
"stmt : SYMwhile lab expr fbrf SYMdo stmts SYMend",
"stmt : SYMrepeat lab stmts SYMuntil expr",
"ifbody : expr fbrf SYMthen stmts SYMend",
"ifbody : expr fbrf SYMthen stmts fbr SYMelse lab stmts SYMend",
"ifbody : expr fbrf SYMthen stmts fbr SYMelseif lab ifbody",
"codestmt : SYMcode SYMlparen codebytes SYMrparen",
"codestmt : SYMcodeaddr SYMlparen id SYMrparen",
"codebytes : codebytes number",
"codebytes :",
"expr : expr SYMplus expr",
"expr : expr SYMminus expr",
"expr : expr SYMtimes expr",
"expr : expr SYMdivide expr",
"expr : expr SYMmod expr",
"expr : SYMminus expr",
"expr : expr SYMbitand expr",
"expr : expr SYMbitor expr",
"expr : expr SYMbitxor expr",
"expr : SYMbitnot expr",
"expr : expr logand expr",
"expr : expr logor expr",
"expr : expr logxor expr",
"expr : SYMlognot expr",
"expr : expr SYMshr expr",
"expr : expr SYMshl expr",
"expr : expr SYMge expr",
"expr : expr SYMle expr",
"expr : expr SYMeq expr",
"expr : expr SYMne expr",
"expr : expr SYMgt expr",
"expr : expr SYMlt expr",
"expr : SYMlparen expr SYMrparen",
"expr : lval SYMgets expr",
"expr : lval SYMdotgets expr",
"expr : SYMaddress lval",
"expr : lval",
"expr : lval SYMdot",
"expr : number",
"expr : SYMcall function SYMlparen args SYMrparen",
"logand : SYMlogand",
"logor : SYMlogor",
"logxor : SYMlogxor",
"function : lval",
"args : args expr",
"args :",
"lval : SYMlbracket expr SYMrbracket",
"lval : SYMlbracket lval SYM2rbracket",
"lval : id",
"id : SYMid",
"number : SYMnumber",
"string : SYMstring",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 288 "parser.y"

#include "semantics.c"
#include "lex.yy.c"


main(argc, argv0)
int argc;
char *argv0[];
{
  char **argv;
  extern int pc;
  extern int lowerpc;

  argv = argv0;

  if (argc > 1 && ! strcmp(argv[1], "-d")) {
    qdebug = 1;
    argc--;
    argv++;
  }
  if (argc > 2 && ! strcmp(argv[1], "-o")) {
    pc = lowerpc = strtol(argv[2], NULL, 0);
    argc -= 2;
    argv += 2;
  }
  if (argc > 1) {
    fprintf(stderr, "USAGE: %s [-d] [-o <offset>]\n", argv0[0]);
    exit(1);
  }
  yyparse();
}


#line 739 "y.tab.c"

#if YYDEBUG
#include <stdio.h>              /* needed for printf */
#endif

#include <stdlib.h>     /* needed for malloc, etc */
#include <string.h>     /* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 83 "parser.y"
        { dumpcode(); }
break;
case 4:
#line 90 "parser.y"
        { setentry(yystack.l_mark[0].charptr); }
break;
case 7:
#line 93 "parser.y"
        { if (intext) {
                                                    textpc = pc;
                                                    intext = 0;
                                                  }
                                                  pc = yystack.l_mark[0].integer; }
break;
case 8:
#line 98 "parser.y"
        { if (! intext) {
                                                    datapc = pc;
                                                    intext = 1;
                                                  }
                                                  pc = yystack.l_mark[0].integer; }
break;
case 9:
#line 103 "parser.y"
        { if (intext) {
                                                    textpc = pc;
                                                    intext = 0;
                                                    pc = datapc;
                                                  } }
break;
case 10:
#line 108 "parser.y"
        { if (! intext) {
                                                    datapc = pc;
                                                    intext = 1;
                                                    pc = textpc;
                                                  } }
break;
case 11:
#line 114 "parser.y"
        { stringdata(yystack.l_mark[0].charptr); }
break;
case 13:
#line 118 "parser.y"
        { newstring(yystack.l_mark[0].charptr); }
break;
case 14:
#line 121 "parser.y"
        { setvartype(yystack.l_mark[0].recordptr, GLOBAL); }
break;
case 16:
#line 125 "parser.y"
        { yyval.recordptr = newvar(yystack.l_mark[-2].integer,
                                                              INTEGER, yystack.l_mark[0].charptr); }
break;
case 17:
#line 127 "parser.y"
        { yyval.recordptr = newvar(1,
                                                              INTEGER, yystack.l_mark[0].charptr); }
break;
case 18:
#line 129 "parser.y"
        { yyval.recordptr = newvar(yystack.l_mark[-2].integer, CHAR, yystack.l_mark[0].charptr); }
break;
case 19:
#line 130 "parser.y"
        { yyval.recordptr = newvar(1, CHAR, yystack.l_mark[0].charptr); }
break;
case 20:
#line 134 "parser.y"
        { value(0); procexit(); }
break;
case 21:
#line 137 "parser.y"
        { newprocedure(yystack.l_mark[0].charptr); }
break;
case 22:
#line 138 "parser.y"
        { newprocedure(yystack.l_mark[0].charptr); }
break;
case 23:
#line 139 "parser.y"
        { newprocedure(yystack.l_mark[0].charptr); }
break;
case 25:
#line 145 "parser.y"
        { setvartype(newvar(1, INTEGER,
                                                  yystack.l_mark[0].charptr), PARAM); }
break;
case 28:
#line 153 "parser.y"
        { procentry(); }
break;
case 29:
#line 156 "parser.y"
        { setvartype(yystack.l_mark[0].recordptr, LOCAL); }
break;
case 33:
#line 164 "parser.y"
        { yyval.integer = pc; }
break;
case 34:
#line 167 "parser.y"
        { yyval.integer = pc; branchfalse(0); }
break;
case 35:
#line 170 "parser.y"
        { yyval.integer = pc; branch(0); }
break;
case 36:
#line 174 "parser.y"
        { pop(); }
break;
case 37:
#line 176 "parser.y"
        { procexit(); }
break;
case 40:
#line 180 "parser.y"
        { branch(yystack.l_mark[-5].integer);
                                                  t = pc;
                                                  pc = yystack.l_mark[-3].integer;
                                                  branchfalse(t);
                                                  pc = t; }
break;
case 41:
#line 187 "parser.y"
        { branchfalse(yystack.l_mark[-3].integer); }
break;
case 42:
#line 191 "parser.y"
        { t = pc;
                                                  pc = yystack.l_mark[-3].integer;
                                                  branchfalse(t);
                                                  pc = t; }
break;
case 43:
#line 196 "parser.y"
        { t = pc;
                                                  pc = yystack.l_mark[-7].integer;
                                                  branchfalse(yystack.l_mark[-2].integer);
                                                  pc = yystack.l_mark[-4].integer;
                                                  branch(t);
                                                  pc = t; }
break;
case 44:
#line 203 "parser.y"
        { t = pc;
                                                  pc = yystack.l_mark[-6].integer;
                                                  branchfalse(yystack.l_mark[-1].integer);
                                                  pc = yystack.l_mark[-3].integer;
                                                  branch(t);
                                                  pc = t; }
break;
case 46:
#line 213 "parser.y"
        { codeaddr(yystack.l_mark[-1].charptr); }
break;
case 47:
#line 216 "parser.y"
        { code(yystack.l_mark[0].integer); }
break;
case 49:
#line 220 "parser.y"
        { op2(OPadd); }
break;
case 50:
#line 221 "parser.y"
        { op2(OPsub); }
break;
case 51:
#line 222 "parser.y"
        { op2(OPmul); }
break;
case 52:
#line 223 "parser.y"
        { op2(OPdiv); }
break;
case 53:
#line 224 "parser.y"
        { op2(OPmod); }
break;
case 54:
#line 225 "parser.y"
        { op1(OPneg); }
break;
case 55:
#line 226 "parser.y"
        { op2(OPband); }
break;
case 56:
#line 227 "parser.y"
        { op2(OPbor); }
break;
case 57:
#line 228 "parser.y"
        { op2(OPbxor); }
break;
case 58:
#line 229 "parser.y"
        { op1(OPbnot); }
break;
case 59:
#line 231 "parser.y"
        { logical(); op2(OPband); }
break;
case 60:
#line 233 "parser.y"
        { logical(); op2(OPbor); }
break;
case 61:
#line 235 "parser.y"
        { logical(); op2(OPbxor); }
break;
case 62:
#line 236 "parser.y"
        { logical(); op1(OPlnot); }
break;
case 63:
#line 237 "parser.y"
        { op2(OPshr); }
break;
case 64:
#line 238 "parser.y"
        { op2(OPshl); }
break;
case 65:
#line 239 "parser.y"
        { op2(OPge); }
break;
case 66:
#line 240 "parser.y"
        { op2(OPle); }
break;
case 67:
#line 241 "parser.y"
        { op2(OPeq); }
break;
case 68:
#line 242 "parser.y"
        { op2(OPne); }
break;
case 69:
#line 243 "parser.y"
        { op2(OPgt); }
break;
case 70:
#line 244 "parser.y"
        { op2(OPlt); }
break;
case 72:
#line 246 "parser.y"
        { intgets(); }
break;
case 73:
#line 247 "parser.y"
        { bytegets(); }
break;
case 75:
#line 249 "parser.y"
        { deref(); }
break;
case 76:
#line 250 "parser.y"
        { bytederef(); }
break;
case 77:
#line 251 "parser.y"
        { value(yystack.l_mark[0].integer); }
break;
case 78:
#line 253 "parser.y"
        { call(); }
break;
case 79:
#line 256 "parser.y"
        { logical(); }
break;
case 80:
#line 259 "parser.y"
        { logical(); }
break;
case 81:
#line 262 "parser.y"
        { logical(); }
break;
case 82:
#line 265 "parser.y"
        { precall(); }
break;
case 83:
#line 268 "parser.y"
        { argument(); }
break;
case 86:
#line 273 "parser.y"
        { deref(); }
break;
case 87:
#line 274 "parser.y"
        { addr(yystack.l_mark[0].charptr); }
break;
case 88:
#line 277 "parser.y"
        { yyval.charptr = yytext; }
break;
case 89:
#line 280 "parser.y"
        { yyval.integer = constant(yytext); }
break;
case 90:
#line 283 "parser.y"
        { yyval.charptr = yytext; }
break;
#line 1257 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

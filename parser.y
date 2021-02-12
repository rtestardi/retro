
%{

static char sccsID[] = "@(#)parser.y	1.2 07/02/88";

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

%}


%token SYMif SYMthen SYMelse SYMelseif SYMwhile SYMdo SYMrepeat SYMuntil 
%token SYMcall SYMtext SYMdata
%token SYMdefine SYMstatic SYMbegin SYMreturn SYMend SYMint SYMchar
%token SYMentry
%token SYMlparen SYMrparen SYMlbracket SYMrbracket SYM2rbracket
%token SYMsemi SYMcomma SYMaddress
%token SYMnumber SYMid SYMstring SYMstr SYMcode SYMcodeaddr


%union {
  unsigned char *charptr;
  record *recordptr;
  int integer;
}

%type <recordptr> var
%type <charptr> id string
%type <integer> number fbr fbrf lab

%start program

%nonassoc SYMlowest
%nonassoc SYMlval SYMexpr
%right SYMgets SYMdotgets
%left SYMlogor SYMlogxor
%left SYMlogand
%nonassoc SYMlognot
%nonassoc SYMge SYMle SYMeq SYMne SYMgt SYMlt
%left SYMplus SYMminus SYMbitor SYMbitxor
%left SYMtimes SYMdivide SYMmod SYMbitand SYMshr SYMshl
%nonassoc SYMbitnot
%nonassoc SYMdot
%nonassoc SYMhighest

%%

program		: blocks			{ dumpcode(); }
		;

blocks		: blocks block
		|
		;

block		: SYMentry id			{ setentry($2); }
		| SYMstatic globalvars
		| SYMdefine procedure
		| SYMdata number		{ if (intext) {
						    textpc = pc;
						    intext = 0;
						  }
						  pc = $2; }
		| SYMtext number		{ if (! intext) {
						    datapc = pc;
						    intext = 1;
						  }
						  pc = $2; }
		| SYMdata			{ if (intext) {
						    textpc = pc;
						    intext = 0;
						    pc = datapc;
						  } }
		| SYMtext			{ if (! intext) {
						    datapc = pc;
						    intext = 1;
						    pc = textpc;
						  } }
		| SYMstr stringid string			
						{ stringdata($3); }
		| codestmt
		;

stringid	: id				{ newstring($1); }
		;

globalvars	: globalvars var		{ setvartype($2, GLOBAL); }
		|
		;

var		: number SYMint id		{ $$ = newvar($1, 
							      INTEGER, $3); }
		| SYMint id			{ $$ = newvar(1, 
							      INTEGER, $2); }
		| number SYMchar id		{ $$ = newvar($1, CHAR, $3); }
		| SYMchar id			{ $$ = newvar(1, CHAR, $2); }
		;

procedure	: procedureid formals body
						{ value(0); procexit(); }
		;

procedureid	: id				{ newprocedure($1); }
		| SYMint id			{ newprocedure($2); }
		| SYMchar id			{ newprocedure($2); }
		;

formals		: SYMlparen paramvars SYMrparen
		;

paramvars	: paramvars id			{ setvartype(newvar(1, INTEGER,
						  $2), PARAM); }
		|
		;

body		: locals SYMbegin stmts SYMend
		;

locals		: localvars			{ procentry(); }
		;

localvars	: localvars var			{ setvartype($2, LOCAL); }
		|
		;

stmts		: stmts stmt
		|
		;

lab		: 				{ $$ = pc; }
		;

fbrf		:				{ $$ = pc; branchfalse(0); }
		;

fbr		:				{ $$ = pc; branch(0); }
		;

stmt		: expr %prec SYMexpr
						{ pop(); }
		| SYMreturn expr %prec SYMexpr
						{ procexit(); }
		| codestmt
		| SYMif ifbody
		| SYMwhile lab expr fbrf SYMdo stmts SYMend
						{ branch($2);
						  t = pc;
						  pc = $4;
						  branchfalse(t);
						  pc = t; }
						
		| SYMrepeat lab stmts SYMuntil expr %prec SYMexpr
						{ branchfalse($2); }
		;

ifbody		: expr fbrf SYMthen stmts SYMend
						{ t = pc;
						  pc = $2;
						  branchfalse(t);
						  pc = t; }
		| expr fbrf SYMthen stmts fbr SYMelse lab stmts SYMend
						{ t = pc;
						  pc = $2;
						  branchfalse($7);
						  pc = $5;
						  branch(t);
						  pc = t; }
		| expr fbrf SYMthen stmts fbr SYMelseif lab ifbody
						{ t = pc;
						  pc = $2;
						  branchfalse($7);
						  pc = $5;
						  branch(t);
						  pc = t; }
		;

codestmt	: SYMcode SYMlparen codebytes SYMrparen
		| SYMcodeaddr SYMlparen id SYMrparen
						{ codeaddr($3); }
		;

codebytes	: codebytes number		{ code($2); }
		|
		;

expr		: expr SYMplus expr		{ op2(OPadd); }
		| expr SYMminus expr		{ op2(OPsub); }
		| expr SYMtimes expr		{ op2(OPmul); }
		| expr SYMdivide expr		{ op2(OPdiv); }
		| expr SYMmod expr		{ op2(OPmod); }
		| SYMminus expr %prec SYMtimes  { op1(OPneg); }
		| expr SYMbitand expr		{ op2(OPband); }
		| expr SYMbitor expr		{ op2(OPbor); }
		| expr SYMbitxor expr		{ op2(OPbxor); }
                | SYMbitnot expr		{ op1(OPbnot); }
		| expr logand expr %prec SYMlogand
						{ logical(); op2(OPband); }
		| expr logor expr %prec SYMlogor
						{ logical(); op2(OPbor); }
		| expr logxor expr %prec SYMlogxor
						{ logical(); op2(OPbxor); }
		| SYMlognot expr		{ logical(); op1(OPlnot); }
		| expr SYMshr expr		{ op2(OPshr); }
		| expr SYMshl expr		{ op2(OPshl); }
		| expr SYMge expr		{ op2(OPge); }
		| expr SYMle expr		{ op2(OPle); }
		| expr SYMeq expr		{ op2(OPeq); }
		| expr SYMne expr		{ op2(OPne); }
		| expr SYMgt expr		{ op2(OPgt); }
		| expr SYMlt expr		{ op2(OPlt); }
		| SYMlparen expr SYMrparen
		| lval SYMgets expr		{ intgets(); }
		| lval SYMdotgets expr		{ bytegets(); }
		| SYMaddress lval
		| lval %prec SYMlval		{ deref(); }
		| lval SYMdot			{ bytederef(); }
		| number			{ value($1); }
		| SYMcall function SYMlparen args SYMrparen
						{ call(); }
		;

logand		: SYMlogand			{ logical(); }
		;

logor		: SYMlogor			{ logical(); }
		;

logxor		: SYMlogxor			{ logical(); }
		;

function	: lval				{ precall(); }
		;
	
args		: args expr %prec SYMexpr	{ argument(); }
		|
		; 

lval		: SYMlbracket expr SYMrbracket
		| SYMlbracket lval SYM2rbracket	{ deref(); }
		| id				{ addr($1); }
		;

id		: SYMid				{ $$ = yytext; }
		;

number		: SYMnumber			{ $$ = constant(yytext); }
		;

string		: SYMstring			{ $$ = yytext; }
		;


%%

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



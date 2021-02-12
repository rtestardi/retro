#include <string.h>

#define MAXobjcode 0x10000
char objcode[MAXobjcode] = {0};
int upperpc = 0;
int lowerpc = 0;

#define MAXrecords 3000
record records[MAXrecords];
int recordi = 0;

int entrypc = 0;
char entryid[30] = {0};

int lineno = 1;

int localc = 0;
int paramc = 0;
int argc = 0;

#define MAXargcstack 20
int argcstack[MAXargcstack];
int argcstacki = 0;

int textpc = 0;
int datapc = 0;
int intext = 1;
int pc = 0;
int lastaddr = -1;
int t = 0;

int qdebug = 0;

extern void printaddress();
extern void branch(i);
extern void op1(i);
extern void yyerror(char *s);
int yywrap() { return 1; }
void myexit(int v) { ExitProcess(0); }

setvartype(p, i)
record *p;
int i;
{
  p->type = i;
  switch(i) {
    case GLOBAL  : p->offset = pc;
    		   if (qdebug) {
		     printf("\n\n");
		     printaddress();
		     printf("    GLOBAL %s\n\n", p->name);
		   }
                   pc += p->size;
		   break;
    case LOCAL   : localc += p->size;
                   p->offset = localc;
		   break;
    case PARAM   : p->offset = paramc;
                   paramc += p->size;
		   break;
  }
}

record *newvar(n, i, s)
int n, i;
char s[];
{
  int j, k;

  k = recordi;
  for (j=0; j<recordi; j++) {
    if (records[j].name[0] == 0) {
      k = j;
    } else if (strcmp(records[j].name, s) == 0) {
      fprintf(stderr, "ERROR line %d: duplicate symbol %s.\n", lineno, s);
      return &records[j];
    }
  }
  strcpy(records[k].name, s);
  if (i == CHAR) {
    records[k].size = n;
  } else {
    records[k].size = 4*n;
  }
  if (k == recordi) {
    recordi++;
    if (recordi >= MAXrecords) {
      fprintf(stderr, "ERROR line %d: records overflow.\n", lineno);
      myexit(1);
    }
  }
  return &records[k];
}

newstring(s)
char *s;
{
  record *p;

  p = newvar(1, CHAR, s);
  p->type = STRING;
  p->offset = pc;
}

newprocedure(s)
char s[];
{
  record *p;
  int j;

  for (j=0; j<recordi; j++) {
    if ((records[j].type == PARAM) || (records[j].type == LOCAL)) {
      records[j].name[0] = 0;
    }
  }
  p = newvar(1, SYMint, s);
  p->type = PROCEDURE;
  p->offset = pc;
  if (strcmp(s, entryid) == 0) {
    t = pc;
    pc = entrypc;
    branch(t);
    pc = t;
  }
  if (qdebug) {
    printf("\n\n");
    printaddress();
    printf("    PROCEDURE %s\n\n", s);
  }
  localc = 0;
  paramc = 0;
}

precall()
{
  argcstack[argcstacki++] = argc;
  if (argcstacki >= MAXargcstack) {
    fprintf(stderr, "ERROR line %d: argcstack overflow.\n", lineno);
    myexit(1);
  }
  argc = 0;
}

argument()
{
  argc++;
}

int constant(s)
char s[];
{
  int base;
  int i;
  int result;

  if ((s[0] == '0') && (s[1] == 'x')) {
    base = 16;
    i = 2;
  } else {
    base = 10;
    i = 0;
  }
  result = 0;
  while (s[i]) {
    result = result*base;
    if (s[i] > '9') {
      result = result + s[i] - 'A' + 10;
    } else {
      result = result + s[i] - '0';
    }
    i++;
  }
  return result;
}

setentry(s)
char *s;
{
  entrypc = pc;
  strcpy(entryid, s);
  branch(0);
}

dumpcode()
{
  int i;

  if (! qdebug) {
    for (i = lowerpc; i <= upperpc; i++) {
      putchar(objcode[i] & 0xff);
    }
  } else {
    printf("\n\n%x bytes generated.\n", upperpc-lowerpc+1);
  }
}

/* ********************************************************** */
/* ********************************************************** */
/* ********************************************************** */

void
printaddress()
{
  if (lastaddr != pc) {
    printf("%x\n", pc);
    lastaddr = pc;
  }
}

gen(i)
{
  if (pc > upperpc) {
    upperpc = pc;
  }
  objcode[pc++] = i;
  if (pc >= MAXobjcode) {
    fprintf(stderr, "ERROR line %d: objcode overflow.\n", lineno);
    myexit(1);
  }
}

genaddress(i)
int i;
{
  int a, b, c, d;

  a = ((i >> 24) & 0x3f) | 0xc0;
  b = (i >> 16) & 0xff;
  c = (i >> 8) & 0xff;
  d = (i) & 0xff;
  gen(a); gen(b); gen(c); gen(d);
}

code(i)
int i;
{
  if (qdebug) {
    printaddress();
    printf("    %x\n", i);
  }
  gen(i);
}

void
codeaddr(s)
char s[];
{
  int j;
  
  if (qdebug) {
    printaddress();
  }
  for (j=0; j<recordi; j++) {
    if (strcmp(records[j].name, s) == 0) {
      if (qdebug) {
        printf("    %x\n", records[j].offset | 0xc0000000);
      }
      genaddress(records[j].offset);
      return;
    }
  }
  fprintf(stderr, "ERROR line %d: Undefined symbol %s.\n", lineno, s);
  if (qdebug) {
    printf("    %x\n", 0xc0000000);
  }
  genaddress(0);
}

stringdata(s)
char s[];
{
  int i, c;

  if (qdebug) {
    printaddress();
  }
  i = 1;
  while ((c = s[i++]) != '"') {
    if (c == '\\') {
      c = s[i++];
      switch (c) {
        case 'r' : c = 0x0d;
	           break;
	case 'n' : c = 0x0a;
	           break;
	case 't' : c = 0x09;
	           break;
	case '0' : c = 0x00;
		   break;
	case '"' : i--;
		   break;
	default  : fprintf(stderr, "ERROR line %d: illegal character.\n",
		 	   lineno);
		   break;
      }
    }
    gen(c);
  }
}

void
branch(i)
int i;
{
  int disp;
  
  disp = i-pc;
  if (qdebug) {
    lastaddr = -1;
    printaddress();
    printf("    branch %x {%x}\n", disp, i);
  }
  gen(0xea); genaddress(disp);
}

pop()
{
  if (qdebug) {
    printaddress();
    printf("    movd tos,r0\n");
  }
  gen(0x17); gen(0xb8);
}

push()
{
  if (qdebug) {
    printaddress();
    printf("    movd r0,tos\n");
  }
  gen(0xd7); gen(0x05);
}

procexit()
{
  pop();
  if (qdebug) {
    printaddress();
    printf("    exit []\n");
  }
  gen(0x92); gen(0x00);
  if (qdebug) {
    printf("    return 0\n");
  }
  gen(0x12); gen(0x00);
}

procentry()
{
  if (qdebug) {
    printaddress();
    printf("    enter [],%x\n", localc);
  }
  gen(0x82); gen(0x00); genaddress(localc);
}

branchfalse(i)
int i;
{
  int disp;
  
  if (qdebug) {
    lastaddr = -1;
    printaddress();
    printf("    cmpqd tos,0\n");
  }
  gen(0x1f); gen(0xb8);
  disp = i-pc;
  if (qdebug) {
    printf("    beq %x {%x}\n", disp, i);
  }
  gen(0x0a); genaddress(disp);
}

cmp()
{
  if (qdebug) {	
    printaddress();
    printf("    cmpd tos,tos\n");
  }
  gen(0xc7); gen(0xbd);
}


op2(i)
int i;
{
  if (qdebug) {
    printaddress();
  }    
  switch (i) {
    case OPadd   : if (qdebug) {
		     printf("    addd tos,tos\n");
		   }
		   gen(0xc3); gen(0xbd);
		   break;
    case OPsub   : if (qdebug) {
		     printf("    subd tos,tos\n");
		   }
		   gen(0xe3); gen(0xbd);
		   break;
    case OPmul   : if (qdebug) {
		     printf("    muld tos,tos\n");
		   }
		   gen(0xce); gen(0xe3); gen(0xbd);
		   break;
    case OPdiv   : if (qdebug) {
		     printf("    divd tos,tos\n");
		   }
		   gen(0xce); gen(0xff); gen(0xbd);
		   break;
    case OPmod   : if (qdebug) {
		     printf("    modd tos,tos\n");
		   }
		   gen(0xce); gen(0xfb); gen(0xbd);
		   break;
    case OPband  : if (qdebug) {
		     printf("    andd tos,tos\n");
		   }
		   gen(0xeb); gen(0xbd);
		   break;
    case OPbor   : if (qdebug) {
		     printf("    ord tos,tos\n");
		   }
		   gen(0xdb); gen(0xbd);
		   break;
    case OPbxor  : if (qdebug) {
		     printf("    xord tos,tos\n");
		   }
		   gen(0xfb); gen(0xbd);
		   break;
    case OPge    : cmp();
		   if (qdebug) {
		     printf("    sled tos\n");
		   }
		   gen(0xbf); gen(0xbb);
		   break;
    case OPle    : cmp();
		   if (qdebug) {
		     printf("    sged tos\n");
		   }
		   gen(0xbf); gen(0xbe);
		   break;
    case OPeq    : cmp();
		   if (qdebug) {
		     printf("    seqd tos\n");
		   }
		   gen(0x3f); gen(0xb8);
		   break;
    case OPne    : cmp();
		   if (qdebug) {
		     printf("    sned tos\n");
		   }
		   gen(0xbf); gen(0xb8);
		   break;
    case OPgt    : cmp();
		   if (qdebug) {
		     printf("    sltd tos\n");
		   }
		   gen(0x3f); gen(0xbe);
		   break;
    case OPlt    : cmp();
		   if (qdebug) {
		     printf("    sgtd tos\n");
		   }
		   gen(0x3f); gen(0xbb);
		   break;
    case OPshr   : op1(OPneg);
		   /* fall thru to OPshl */
    case OPshl   : pop();
		   if (qdebug) {
		     printf("    lshd r0,tos\n");
		   }
		   gen(0x4e); gen(0xd7); gen(0x05);
		   break;
  }
}

logical()
{
  if (qdebug) {
    printaddress();
    printf("    cmpqd tos,0\n");
  }
  gen(0x1f); gen(0xb8);
  if (qdebug) {
    printf("    sned tos\n");
  }
  gen(0xbf); gen(0xb8);
}

void
op1(i)
int i;
{
  if (qdebug) {
    printaddress();
  }
  switch(i) {
    case OPneg   : if (qdebug) {
		     printf("    negd tos,tos\n");
		   }
		   gen(0x4e); gen(0xe3); gen(0xbd);
		   break;
    case OPbnot  : if (qdebug) {
		     printf("    comd tos,tos\n");
		   }
		   gen(0x4e); gen(0xf7); gen(0xbd);
		   break;
    case OPlnot  : if (qdebug) {
		     printf("    notd tos,tos\n");
		   }
		   gen(0x4e); gen(0xe7); gen(0xbd);
		   break;
  }
}

intgets()
{
  pop();
  if (qdebug) {
    printf("    movd tos,r1\n");
  }
  gen(0x57); gen(0xb8);
  if (qdebug) {
    printf("    movd r0,0(r1)\n");
  }
  gen(0x57); gen(0x02); gen(0x00);
  push();
}

bytegets()
{
  pop();
  if (qdebug) {
    printf("    movd tos,r1\n");
  }
  gen(0x57); gen(0xb8);
  if (qdebug) {
    printf("    movb r0,0(r1)\n");
  }
  gen(0x54); gen(0x02); gen(0x00);
  push();
}

deref()
{
  pop();
  if (qdebug) {
    printf("    movd 0(r0),tos\n");
  }
  gen(0xd7); gen(0x45); gen(0x00);
}

bytederef()
{
  pop();
  if (qdebug) {
    printf("    movxbd 0(r0),tos\n");
  }
  gen(0xce); gen(0xdc); gen(0x45); gen(0x00);
}

value(i)
int i;
{
  int a, b, c, d;

  a = (i >> 24) & 0xff;
  b = (i >> 16) & 0xff;
  c = (i >> 8) & 0xff;
  d = (i) & 0xff;
  if (qdebug) {
    printaddress();
    printf("    movd %x,tos\n", i);
  }
  gen(0xd7); gen(0xa5); gen(a); gen(b); gen(c); gen(d);
}

call()
{
  int a, b, c, d, i;

  if (qdebug) {
    printaddress();
    printf("    jsr 0(%x(sp))\n", argc*4);
  }
  gen(0x7f); gen(0x8e); genaddress(argc*4); gen(0x00);
  i = -argc*4-4;
  a = (i >> 24) & 0xff;
  b = (i >> 16) & 0xff;
  c = (i >> 8) & 0xff;
  d = (i) & 0xff;
  if (qdebug) {
    printf("    adjspd %x\n", i);
  }
  gen(0x7f); gen(0xa5); gen(a); gen(b); gen(c); gen(d);
  push();
  argc = argcstack[--argcstacki];
}

void
addr(s)
char s[];
{
  int j, k;

  if (qdebug) {
    printaddress();
  }
  for (j=0; j<recordi; j++) {
    if (strcmp(records[j].name, s) == 0) {
      k = records[j].offset;
      switch (records[j].type) {
        case STRING     :
        case PROCEDURE  :
        case GLOBAL     : if (qdebug) {
			    printf("    addr @%x,tos\n", k);
			  }
			  gen(0xe7); gen(0xad); genaddress(k);
			  break;
	case LOCAL	: if (qdebug) {
			    printf("    addr %x(fp),tos\n", -k);
			  }
			  gen(0xe7); gen(0xc5); genaddress(-k);
			  break;
	case PARAM	: if (qdebug) {
			    printf("    addr %x(fp),tos\n", paramc-k+4);
			  }
			  gen(0xe7); gen(0xc5); genaddress(paramc-k+4);
			  break;
      }
      return;
    }
  }
  fprintf(stderr, "ERROR line %d: Undefined symbol %s.\n", lineno, s);
  if (qdebug) {
    printf("    addr @%x,tos\n", 0);
  }
  gen(0xe7); gen(0xad); genaddress(0);
}




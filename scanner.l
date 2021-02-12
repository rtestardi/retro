
newline		\n
blank		[\ \t]+
comment		\/\*.*\*\/
preproc		\#.*
space           ({blank}|{comment}|{preproc})+
alpha		([a-z]|[A-Z])
numeric		[0-9]
alphanumeric	({alpha}|{numeric})
identifier	{alpha}{alphanumeric}*
decimal		[0-9]+
hex		0x([0-9]|[A-F])+
number		{decimal}|{hex}
string		\"[^\"]*\"
other		.

%%

{newline}	lineno++;

if		return(SYMif);
then		return(SYMthen);
else		return(SYMelse);
elsif		return(SYMelseif); 
while		return(SYMwhile);
do		return(SYMdo);
repeat		return(SYMrepeat);
until		return(SYMuntil);
call		return(SYMcall);
define		return(SYMdefine);
static		return(SYMstatic);
begin		return(SYMbegin);

return		return(SYMreturn);
end		return(SYMend);
string          return(SYMstr);
code		return(SYMcode);
address		return(SYMcodeaddr);
entry		return(SYMentry); 
text		return(SYMtext);
data		return(SYMdata);

int		return(SYMint);
char		return(SYMchar);

\(		return(SYMlparen);
\)		return(SYMrparen); 
\[		return(SYMlbracket);
\]		return(SYMrbracket);
\]/\]		return(SYM2rbracket);

\&\&		return(SYMlogand);

\|\|		return(SYMlogor);
\^\^		return(SYMlogxor); 
\!\!		return(SYMlognot); 

\+		return(SYMplus);
\-		return(SYMminus); 
\*		return(SYMtimes); 
\/		return(SYMdivide); 
\%		return(SYMmod); 

\&		return(SYMbitand); 
\|		return(SYMbitor); 
\^		return(SYMbitxor); 
\!		return(SYMbitnot);
\>\>		return(SYMshr); 
\<\<		return(SYMshl); 

\@		return(SYMaddress); 
\.		return(SYMdot);

\>\=		return(SYMge); 
\<\=		return(SYMle); 
\<\>		return(SYMne); 
\!\=		return(SYMne);
\=\=		return(SYMeq); 
\>		return(SYMgt); 
\<		return(SYMlt); 

\:\=		return(SYMgets); 
\.{blank}\:\=   return(SYMdotgets); 

\;		return(SYMsemi);
\,		return(SYMcomma);

{number}	return(SYMnumber); 

{identifier}	return(SYMid); 

{string}        return(SYMstring);

{space}		; 

{other}		yyerror("illegal character"); 

%%

yyerror(s)
char *s;
{
  fprintf(stderr, "ERROR line %d: yyerror() - %s.\n", lineno, s);
}




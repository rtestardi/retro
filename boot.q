
/*********************************** boot.q **********************************/

code(0xEF 0xA4 0x00 0x01 0x00 0x00)  /* LPRD SP,0x00010000 */
code(0x0E 0x8B 0x03)                 /* SETCFG [I,M,F]     */

entry main

string sccsID "@(#)boot.q	1.5 07/04/88\r\n\0"


/*********************************** HALT ************************************/

#define HALT code(0xC2)  /* DIA */


/******************************** SIO defines ********************************/

#define SIORBR [0xFFFD00].  /* receive buffer register */
#define SIOTHR [0xFFFD00].  /* transmit holding register */
#define SIOIER [0xFFFD04].  /* interrupt enable register */
#define SIOIIR [0xFFFD08].  /* interrupt identification register */
#define SIOLCR [0xFFFD0C].  /* line control register */
#define SIOMCR [0xFFFD10].  /* modem control register */
#define SIOLSR [0xFFFD14].  /* line status register */
#define SIOMSR [0xFFFD18].  /* modem status register */
#define SIOSCR [0xFFFD1C].  /* scratch register */
#define SIODLL [0xFFFD00].  /* divisor latch (lsb) */
#define SIODLM [0xFFFD04].  /* divisor latch (msb) */

#define DLAB 0x80  /* divisor latch access */
#define BAUD 0x0C  /* 9600 baud */
#define CHAR 0x1E  /* 7 data bits, 2 stop bits, even parity */
#define SGNL 0x0F  /* all signals on */

#define DR   0x01  /* receive data ready */
#define THRE 0x20  /* thansmit holding register empty */


/********************************** sioinit **********************************/

define sioinit()
begin
  SIOLCR := DLAB
  SIODLL := BAUD % 256
  SIODLM := BAUD / 256
  SIOLCR := CHAR
  SIOMCR := SGNL
end


/********************************** scanc ************************************/

define int scanc()
begin
  if SIOLSR & DR then
    return SIORBR & 0x7F
  else
    return 0
  end
end


/*********************************** getc ************************************/

define int getc()
int c
begin
  repeat
    c := call scanc()
  until c
  return c
end


/*********************************** putc ************************************/

define putc(c)
int delay
begin
  repeat
    /* null */
  until SIOLSR & THRE
  SIOTHR := c
  delay := 0
  while delay < 100 do
    delay := delay+1
  end
end


/*********************************** puts ************************************/

define puts(s)
begin
  while [s]. do
    call putc([s].)
    s := s + 1
  end
end


/********************************* asciitohex ********************************/

#define ASCII_0 48
#define ASCII_9 57
#define ASCII_A 65
#define ASCII_F 70

define int asciitohex(c)
begin
  if c >= ASCII_A && c <= ASCII_F then
    return (c - ASCII_A + 10) & 0x0F
  elsif c >= ASCII_0 && c <= ASCII_9 then
    return (c - ASCII_0) & 0x0F
  else
    HALT
  end
end


/********************************** get2hex **********************************/

define int get2hex(psum)
int c1
int c2
int h
begin
  c1 := call asciitohex(call getc())
  c2 := call asciitohex(call getc())
  h := c1*16 + c2
  [psum] := [psum] + h
  return h
end


/********************************** get4hex **********************************/

define int get4hex(psum)
int h1
int h2
begin
  h1 := call get2hex(psum)
  h2 := call get2hex(psum)
  return h1*256 + h2
end


/************************************ main ***********************************/

#define ASCII_COLON 58

#define DATA_RECORD  0
#define EOF_RECORD   1
#define START_RECORD 3

define main()
int start
int sum
int count
int pointer
int type
begin
  call sioinit()
  call puts(@sccsID)
  start := -1
  while 1 do
    sum := 0
    repeat
      /* null */
    until call getc() == ASCII_COLON
    count := call get2hex(@sum)
    pointer := call get4hex(@sum)
    type := call get2hex(@sum)
    if type == START_RECORD then
      start := pointer
    elsif type == DATA_RECORD then
      while count > 0 do
        [pointer]. := call get2hex(@sum)
        pointer := pointer + 1
        count := count - 1
      end
    end
    call get2hex(@sum)
    if (sum & 0xFF) != 0 then
      HALT
    end
    if (type == EOF_RECORD) && (start != -1) then
      call [start]()
      start := -1
    end
  end
end


/*****************************************************************************/

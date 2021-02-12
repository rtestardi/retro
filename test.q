/*********************************** test.q **********************************/

entry main


/******************************** SIO defines ********************************/

#define SIORBR [0xFFFD00].  /* receive buffer register */
#define SIOTHR [0xFFFD00].  /* transmit holding register */
#define SIOLSR [0xFFFD14].  /* line status register */

#define DR   0x01  /* receive data ready */
#define THRE 0x20  /* thansmit holding register empty */


/*********************************** putc ************************************/

define putc(c)
begin
  repeat
    /* null */
  until SIOLSR & THRE
  SIOTHR := c
end


/*********************************** puts ************************************/

define puts(s)
begin
  while [s]. do
    call putc([s].)
    s := s + 1
  end
end

/*********************************** main ************************************/

string hello "hello world!\r\n\0"

define main()
begin
  while 1 do
    call puts(@hello)
  end
end

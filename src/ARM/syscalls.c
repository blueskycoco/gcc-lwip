#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
int _close(int file) {
  return 0;
}

int _fstat(int file, struct stat *st) {
  st->st_mode = S_IFCHR;
  return 0;
}

int _isatty(int file) {
  return 1;
}

int _lseek(int file, int ptr, int dir) {
  return 0;
}

int _open(const char *name, int flags, int mode) {
return -1;
}

int _read(int file, char *ptr, int len) {
  int todo;
  if(len == 0)
    return 0;
  /*while(UART_FR(UART0_ADDR) & UART_FR_RXFE);
  *ptr++ = UART_DR(UART0_ADDR);
  for(todo = 1; todo < len; todo++) {
    if(UART_FR(UART0_ADDR) & UART_FR_RXFE) { break; }
    *ptr++ = UART_DR(UART0_ADDR);
  }
  return todo;*/
}

static char *heap_end = 0;
caddr_t _sbrk(int incr) {
  extern char _end; /* Defined by the linker */
  extern char __cs3_heap_end; /* Defined by the linker */
  char *prev_heap_end;
  if (heap_end == 0) {
    heap_end = &_end;
  }  
  prev_heap_end = heap_end;
  if (heap_end + incr > &__cs3_heap_end) {
    /* Heap and stack collision */
    return (caddr_t)0;
  }
  heap_end += incr;
  return (caddr_t) prev_heap_end;
}

int _write(int file, char *ptr, int len) {
  int todo;
  for (todo = 0; todo < len; todo++) {
    __io_putchar(*ptr++ & (unsigned short)0x01ff);
  }
  return len;
}
int fputc(int ch, FILE *f)  
{
__io_putchar(ch);
return ch;
}
int put_char(char *buf)
{
	char ch,i;
	for(i=0;i<strlen(buf);i++)
	{
		ch=buf[i];
		if(ch=='\n')
			__io_putchar('\r');
		__io_putchar(ch&(unsigned short)0x01ff);
	}
	return ch;
}
#pragma import(__use_no_semihosting)
_sys_exit(int x)
{   

x = x;  

}   

struct __FILE   
{	

int handle;   

/* Whatever you require here. If the only file you are using is */	

/* standard output using printf() for debugging, no file handling 

*/	 

/* is required. */	

};	 

/* 

FILE is typedef�� d in stdio.h. */ 

 

FILE __stdout;	


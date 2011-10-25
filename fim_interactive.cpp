#include <curses.h>

int main()
{
  WINDOW *wnd = initscr();
  cbreak();
  noecho();
  keypad(wnd, 1);
  int numrows,numcols;
  getmaxyx(wnd,numrows,numcols);
  clear();
  refresh();

  int d;  

  while(1) {
   d = getch();
   if( d == KEY_ENTER ) break;
   move(0,0);
   delch();
   insch(d);
   refresh();
 }
 
 endwin();
}
   
   

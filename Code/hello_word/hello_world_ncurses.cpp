#include <ncurses.h>
#define echo printw

int main(int argc, char *argv[])
{
    int ch;
    initscr();
//    raw(); // for now this shit makes no diff
    keypad(stdscr,TRUE); // this shit makes me to use f1
    noecho(); // without this the screen with display the text 2wice

    echo("Type any keys to see in bold\n");

    ch = getch();
    while (ch != KEY_F(1))
    {
        attron(A_BOLD);
        echo("%c",ch);
        attroff(A_BOLD);
        refresh();
        ch = getch();
    }
    echo("F1 is Pressed");
    getch();
    endwin();
    return 0;
}

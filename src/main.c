#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <unistd.h>

void sigint(int sig)
{
	sig = 0;

	struct termios term_t;
	tcgetattr(STDIN_FILENO, &term_t);
	term_t.c_lflag |= ICANON;
	term_t.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term_t);

	exit(0);
}

void cls(void) { printf("\033[2J\033[3J\033[H"); }

int main(void)
{
	signal(SIGINT, sigint);

	struct termios term_t;
	tcgetattr(STDIN_FILENO, &term_t);
	term_t.c_lflag &= ~ICANON;
	term_t.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term_t);
	cls();

	while(1)
	{
		char input;
		scanf("%c", &input);
		switch(input)
		{
			case 127: printf("\033[D \033[D"); break;
			default: printf("%c", input);
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define VERSION "0.0.1"

int main(int argc, char *argv[])
{
        if (argc < 2) {
                goto clear;
        }

        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
                printf(
                        "Clear command for terminal. \n"
                        "Flags: \n"
                                "--help    | -h => this message. \n"
                                "--version | -v => clear's version. \n"
                                "By t3lc4do820. \n"
                                "Source: https://github.com/t3lc4do820/terminal-"
                );
                return 0;
        } else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
                printf("clear - version: %s \n", VERSION);
                return 0;
        } else {
                fprintf(stderr,
                        "Flag '%s': Unknown option \n"
                        "Flags: \n"
                                "--help \n"
                                "--version \n",
                        argv[1]);
                return -1;
        }

        clear:
        fflush(stdout);
        write(STDOUT_FILENO, "\x1b[2J\x1b[H", 7);
        return 0;
}

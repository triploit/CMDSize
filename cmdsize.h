#if defined(__unix__) || defined(__unix) || defined(__linux__)
#define OS_LINUX
#elif defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#define OS_WIN
#elif defined(__APPLE__) || defined(__MACH__)
#define OS_MAC
#else
#error Unknown Platform
#endif


#if defined(OS_LINUX) || defined(OS_MAC)
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#elif defined(OS_WIN)

#include <windows.h>
#endif

int columns() {
	#if defined(OS_LINUX) || defined(OS_MAC)
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
	#elif defined(OS_WIN)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	return columns;
	#endif
}

int rows() {
	#if defined(OS_LINUX) || defined(OS_MAC)
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_row;
	#elif defined(OS_WIN)
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return rows;
	#endif
}

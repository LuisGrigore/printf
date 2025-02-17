#include "puthex_with_charset.h"

void write_hex_with_charset(unsigned long num, int fd, char * charset)
{
    char hex_chars[] = charset;
    char buffer[16];
    int i = 0;

    if (num == 0) {
        ft_putchar_fd(charset[0],fd);
        return;
    }

    while (num > 0) {
        buffer[i++] = hex_chars[num % 16];
        num /= 16;
	}
	ft_putstr_fd(buffer,fd);
}
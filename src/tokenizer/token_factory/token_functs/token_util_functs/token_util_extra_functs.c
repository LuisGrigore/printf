#include "token_util_functs.h"
#include "libft.h"

void print_percentage(void *percentage)
{
	ft_putchar_fd('%',1);
}

void print_ptr(void *p)
{
	ft_putstr_fd("0x",1);
    write_hex((unsigned long)p,1);
}

static void write_hex(unsigned long num, int fd) {
    char hex_chars[] = "0123456789abcdef";
    char buffer[16];
    int i = 0;

    if (num == 0) {
        ft_putchar_fd('0',fd);
        return;
    }

    while (num > 0) {
        buffer[i++] = hex_chars[num % 16];
        num /= 16;
	}
	ft_putstr_fd(buffer,fd);
}
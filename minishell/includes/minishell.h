#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
# include "../libft/libft.h"

void execution(char **argv);
void    ft_cd(char *argv);
int ft_pwd(int fd);
int ft_echo(char **argv, int fd, int chek);
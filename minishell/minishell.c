#include "./includes/minishell.h"
#include <stdlib.h>

int main(int ac,char **av)
{
    (void)(ac);
    
  //execution(av);
  // ft_cd(av[1]);
  //ft_pwd(1);
  ft_echo(av, 1, 0);
}
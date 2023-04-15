#include "./includes/minishell.h"
#include "libft/libft.h"

void execution(char **argv) {
  int pid;
  char *path;
  char **dir;
  int i;

  i = 0;
  pid = fork();
  if (pid == 0) {
    if (ft_strchr(argv[1], '/'))
      path = argv[1];
    else {
      dir = ft_split(getenv("PATH"), ':');

      while (dir[i]) {
        path = ft_strjoin(dir[i], "/");
        path = ft_strjoin(path, argv[1]);
        if (access(path, X_OK) == 0)
          break;
        i++;
      }
    }
    // ghadi ghir nbdlouha l command
    char *arg[] = {argv[1], argv[2], argv[3], NULL};
    if (execve(path, arg, NULL) == -1) {
      perror("execve");
      exit(1);
    }
  }
}

void ft_pipe(char **argv) {
  int fd[2];
  int pid;
  int status;

  pipe(fd);
  pid = fork();
  if (pid == 0) {
    close(fd[0]);
    dup2(fd[1], 1);
    close(fd[1]);
    execution(argv);
  } else {
    close(fd[1]);
    dup2(fd[0], 0);
    close(fd[0]);
    waitpid(pid, &status, 0);
    execution(argv);
  }
}



int ft_exit(char **argv) {
  if (argv[1])
    exit(ft_atoi(argv[1]));
  else
    exit(0);
}

int ft_pwd(int fd) {
  char *pwd;

  pwd = getcwd(NULL, 0);
  ft_putstr_fd(pwd, fd);
  ft_putstr_fd("\n", fd);
  free(pwd);
  return 1;
}


int ft_create_file(char *argv) {
  int fd;

  fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd == -1) {
    perror("open");
    return 0;
  }
  return fd;
}

int ft_close_file(int fd) {
  if (close(fd) == -1) {
    perror("close");
    return 0;
  }
  return 1;
}

int ft_echo(char **argv, int fd, int chek) {
  int i;

  i = 1;
  while (argv[i]) {
    ft_putstr_fd(argv[i], fd);
    ft_putstr_fd(" ", 1);
    i++;
  }
  if (chek == 1)
    ft_putstr_fd("\n", 1);
  return 1;
}

void ft_cd(char *argv) {
  if (chdir(argv) != 0) {
    perror("cd");
    return;
  }
}
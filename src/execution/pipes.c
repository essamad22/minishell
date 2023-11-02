#include "execution.h"
// // utils

// int lst_size1(t_data *node)
// {
// 	int i;
// 	i = 0;
// 	while (node != NULL)
// 	{
// 		node = node->next;
// 		i++;
// 	}
// 	return i;
// }

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }





// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*p;
// 	size_t	lens1;
// 	size_t	lens2;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	lens1 = ft_strlen(s1);
// 	lens2 = ft_strlen(s2);
// 	p = malloc(sizeof(char) * ((lens1 + lens2) + 1));
// 	if (!p)
// 		return (NULL);
// 	while (s1 && s1[i])
// 	{
// 		p[i] = s1[i];
// 		i++;
// 	}
// 	while (s2 && s2[j])
// 		p[i++] = s2[j++];
// 	p[i] = '\0';
// 	free(s1);
// 	return (p);
// }

// char	*ft_strdup( char *s1)
// {
// 	int		i;
// 	char	*ret;

// 	ret = (char *)malloc(ft_strlen(s1) + 1);
// 	if (!ret)
// 		return (0);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		ret[i] = s1[i];
// 		i++;
// 	}
// 	ret[i] = '\0';
// 	return (ret);
// }

// char **convertto2d(t_data **d)
// {
// 	t_data *tmp ;
// 	tmp = *d;
// 	char **newenv;
// 	int i = 0;
	
// 	newenv = malloc(sizeof(char * ) * ((lst_size1(tmp) + 1)));
// 	while(tmp != NULL)
// 	{
// 		newenv[i] = ft_strdup(tmp->content);
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	newenv[i] = NULL;
// 	return newenv;
// }


// char	*path_bring(char **env)
// {
// 	int		i;
// 	char	*save;

// 	i = 0;
// 	while (env[i])
// 	{
// 		if (ft_strncmp(env[i], "PATH=", 5) == 0)
// 		{
// 			save = env[i] + 5;
// 			return (save);
// 		}
// 		i++;
// 	}
// 	return NULL;
// }

// static int	ft_counter(char *s, char sep)
// {
// 	int	i;
// 	int	counter;

// 	i = 0;
// 	counter = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == sep && s[i])
// 			i++;
// 		if (s[i] != sep && s[i] != '\0')
// 		{
// 			counter++;
// 		}
// 		while (s[i] != sep && s[i])
// 			i++;
// 	}
// 	return (counter);
// }

// static int	ft_len_world(char *s, char sep)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (s[i] == sep)
// 		i++;
// 	while (s[i] != sep && s[i])
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (j);
// }

// static char	*ft_str_allocation(char *s, char sep)
// {
// 	int		i;
// 	int		j;
// 	int		len;
// 	char	*word;

// 	i = 0;
// 	j = 0;
// 	len = ft_len_world(s, sep);
// 	word = malloc(len + 1);
// 	if (!word)
// 		return (NULL);
// 	while (s[i] == sep)
// 		i++;
// 	while (s[i] && s[i] != sep)
// 	{
// 		word[j] = s[i];
// 		j++;
// 		i++;
// 	}
// 	word[j] = '\0';
// 	return (word);
// }

// static char	**ft_free(char **spliter)
// {
// 	int	i;

// 	i = 0;
// 	while (spliter[i])
// 	{
// 		free(spliter[i]);
// 		i++;
// 	}
// 	free (spliter);
// 	return (NULL);
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		j;
// 	char	**spliter;

// 	if (!s)
// 		return (NULL);
// 	spliter = malloc(sizeof(char *) * (ft_counter((char *)s, c) + 1));
// 	if (!spliter)
// 		return (NULL);
// 	j = 0;
// 	while (*s)
// 	{
// 		while (*s == c && *s)
// 			s++;
// 		if (*s != c && *s)
// 		{
// 			spliter[j] = ft_str_allocation((char *)(s), c);
// 			if (!spliter[j++])
// 				return (ft_free(spliter));
// 		}
// 		while (*s != c && *s)
// 			s++;
// 	}
// 	spliter[j] = 0;
// 	return (spliter);
// }


// char	*path_finder(char **env, char **cmd)
// {
// 	int		i;
// 	char	**paths;
// 	char *hold;
// 	char	*temp;

// 	i = 0;
// 	hold = path_bring(env);
// 	if(!hold)
// 	{ 
// 		return NULL;
// 	}
// 	paths = ft_split(hold, ':');
	
// 	i = 0;
// 	while (paths[i])
// 	{
// 		temp = paths[i];
// 		paths[i] = ft_strjoin(temp, "/");
// 			//free (temp);
// 		temp = paths[i];
// 		paths[i] = ft_strjoin(temp, cmd[0]);
// 			//free (temp);
// 			if (access(paths[i], F_OK) == 0)
// 				break ;
// 		i++;
// 	}
// 	return (paths[i]);
// }

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// void	ft_putstr_fd(char *s, int fd)
// {
// 	if (!s)
// 		return (ft_putchar_fd(0, fd));
// 	while (*s)
// 	{
// 		ft_putchar_fd(*s, fd);
// 		s++;
// 	}
// }

// void	printerr2(char *s1, char *s2, char *s3)
// {
// 	ft_putstr_fd(s1, 2);
// 	ft_putstr_fd(": ", 2);
// 	if (s2)
// 	{
// 		ft_putstr_fd(s2, 2);
// 		ft_putstr_fd(": ", 2);
// 	}
// 	if (s3)
// 	{
// 		ft_putstr_fd(s3, 2);
// 		ft_putchar_fd('\n', 2);
// 	}
// }

// // utils

// void one_cmd(int argc, char *argv[], char **envp)
// {
// 	(void)argc;
//     char *hold;
//     int pid = fork();
//     if (pid == 0)
//     {
//         // dup2()
//         if (access(argv[0], X_OK) == 0)
//             execve(argv[0], argv, NULL);
//         hold = path_finder(envp, argv);
//         if (!hold)
//         {
//             printerr2("bash", argv[0], "No such file or directory");
//             return;
//         }
//         if (access(hold, X_OK) == -1)
//         {
//             write(2, "Access failed\n", 15);
//             exit(1);
//         }
//         execve(path_finder(envp, argv), argv, envp);
//         write(2, "Execve failed\n", 15);
//     }
//     waitpid(pid, 0, 0);
// }


// int	*create_pipes(int number_of_cmds)
// {
// 	int	*pipes;
// 	int	i;

// 	i = 0;
// 	pipes = malloc (sizeof(int) * ((number_of_cmds - 1) * 2));
// 	while (i < (number_of_cmds - 1))
// 	{
// 		pipe(&pipes[i * 2]);
// 		i++;
// 	}
// 	return (pipes);
// }

// void	close_pipes(int	*pipes, int number_of_cmds)
// {
// 	int	i;

// 	i = 0;
// 	while (i < (number_of_cmds - 1) * 2)
// 	{
// 		close(pipes[i]);
// 		i++;
// 	}	
// }

// void multiple_cmd(int argc, char *argv[], char **envp, int number_of_cmds)
// {
// 	(void)argc;
//     pid_t *pids;
//     int *pipes;
//     int i;
//     char *hold;

//     i = 0;
//     pids = malloc(sizeof(pid_t) * number_of_cmds);
//     pipes = NULL;
//     pipes = create_pipes(number_of_cmds - 1); // Un pipeline de moins que le nombre de commandes
//     while (i < number_of_cmds)
//     {
//         pids[i] = fork();
//         if (pids[i] == 0)
//         {
//             // Gestion des pipes
//             if (i > 0)
//             {
//                 dup2(pipes[(i - 1) * 2], STDIN_FILENO);
//             }
//             if (i < number_of_cmds - 1)
//             {
//                 dup2(pipes[i * 2 + 1], STDOUT_FILENO);
//             }
//             close_pipes(pipes, number_of_cmds - 1);

//             // Exécution de la commande
//             hold = path_finder(envp, &argv[i]);
//             if (!hold)
//             {
//                 printerr2("bash", argv[i], "No such file or directory");
//                 return;
//             }
//             if (access(hold, X_OK) == -1)
//             {
//                 write(2, "Access failed\n", 15);
//                 exit(1);
//             }
//             execve(hold, &argv[i], envp);
//         }
//         i++;
//     }
//     close_pipes(pipes, number_of_cmds - 1);
//     i = 0;
//     while (i < number_of_cmds)
//     {
//         waitpid(pids[i++], NULL, 0);
//     }
// }




// // void execution(int argc, char *argv[], char **envp)
// // {
// //     if (argc == 1)
// //         one_cmd(argc, argv, envp);
// //     else
// //         multiple_cmd(argc, argv, envp, argc - 1); // Nombre de commandes égal à argc - 1
// // }

// int main(int argc, char *argv[], char **envp)
// {
//     // // Appel de la fonction d'exécution avec les arguments de la ligne de commande
//     // execution(argc, argv, envp);

// 	if (argc == 1)
//         one_cmd(argc, argv, envp);
//     else
//         multiple_cmd(argc, argv, envp, argc - 1); // Nombre de commandes égal à argc - 1

//     return 0;
// }








// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>

// // Fonction pour exécuter une commande
// void execute_one_command(int argc, char *argv[])
// {
//     // Vérification du nombre d'arguments
//     if (argc < 2)
//     {
//         fprintf(stderr, "Usage: %s <command>\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     // Création d'un processus fils
//     pid_t pid = fork();

//     if (pid == -1)
//     {
//         perror("Erreur lors de la création du processus fils");
//         exit(EXIT_FAILURE);
//     }
//     else if (pid == 0) // Code exécuté par le processus fils
//     {
//         // Exécution de la commande
//         execvp(argv[1], &argv[1]);

//         // En cas d'échec de l'exécution
//         perror("Erreur lors de l'exécution de la commande");
//         exit(EXIT_FAILURE);
//     }
//     else // Code exécuté par le processus parent
//     {
//         // Attente que le processus fils se termine
//         int status;
//         waitpid(pid, &status, 0);

//         if (WIFEXITED(status))
//         {
//             // Le processus fils s'est terminé normalement
//             printf("Le processus fils s'est terminé avec le code de sortie : %d\n", WEXITSTATUS(status));
//         }
//         else if (WIFSIGNALED(status))
//         {
//             // Le processus fils s'est terminé à la suite d'un signal
//             printf("Le processus fils s'est terminé avec le signal : %d\n", WTERMSIG(status));
//         }
//     }
// }

// // Fonction pour exécuter plusieurs commandes avec des pipes
// void execute_multiple_commands(int argc, char *argv[])
// {
//  // Vérification du nombre d'arguments
//     if (argc < 2)
//     {
//         fprintf(stderr, "Usage: %s <command1> [command2] [command3] ...\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     // Nombre de commandes
//     int num_commands = argc - 1;

//     // Création des pipes
//     int pipes[(num_commands - 1) * 2];
//     for (int i = 0; i < num_commands - 1; ++i)
//     {
//         if (pipe(&pipes[i * 2]) == -1)
//         {
//             perror("Erreur lors de la création des pipes");
//             exit(EXIT_FAILURE);
//         }
//     }

//     // Exécution des commandes avec des pipes
//     for (int i = 0; i < num_commands; ++i)
//     {
//         pid_t pid = fork();

//         if (pid == -1)
//         {
//             perror("Erreur lors de la création du processus fils");
//             exit(EXIT_FAILURE);
//         }
//         else if (pid == 0) // Code exécuté par le processus fils
//         {
//             // Redirection des pipes pour les commandes intermédiaires
//             if (i > 0)
//                 dup2(pipes[(i - 1) * 2], STDIN_FILENO); // Redirection de l'entrée standard depuis le pipe
//             if (i < num_commands - 1)
//                 dup2(pipes[i * 2 + 1], STDOUT_FILENO); // Redirection de la sortie standard vers le pipe

//             // Fermeture des descripteurs de fichier inutilisés
//             for (int j = 0; j < (num_commands - 1) * 2; ++j)
//                 close(pipes[j]);

//             // Exécution de la commande
//             execlp(argv[i + 1], argv[i + 1], NULL);

//             // En cas d'échec de l'exécution
//             perror("Erreur lors de l'exécution de la commande");
//             exit(EXIT_FAILURE);
//         }
//     }

//     // Fermeture des descripteurs de fichier inutilisés dans le processus parent
//     for (int i = 0; i < (num_commands - 1) * 2; ++i)
//         close(pipes[i]);

//     // Attente que tous les processus fils se terminent
//     for (int i = 0; i < num_commands; ++i)
//         wait(NULL);
// }

// int main(int argc, char *argv[])
// {
//     // Appel de la fonction pour exécuter la commande
//     execute_one_command(argc, argv);

//     // Appel de la fonction pour exécuter plusieurs commandes
//     // execute_multiple_commands(argc, argv);

//     return 0;
// }












char	*path_bring(char **env)
{
	int		i;
	char	*save;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			save = env[i] + 5;
			return (save);
		}
		i++;
	}
	return NULL;
}

static int	ft_counter(char *s, char sep)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		if (s[i] != sep && s[i] != '\0')
		{
			counter++;
		}
		while (s[i] != sep && s[i])
			i++;
	}
	return (counter);
}

static int	ft_len_world(char *s, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == sep)
		i++;
	while (s[i] != sep && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

static char	*ft_str_allocation(char *s, char sep)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = 0;
	j = 0;
	len = ft_len_world(s, sep);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (s[i] == sep)
		i++;
	while (s[i] && s[i] != sep)
	{
		word[j] = s[i];
		j++;
		i++;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_free(char **spliter)
{
	int	i;

	i = 0;
	while (spliter[i])
	{
		free(spliter[i]);
		i++;
	}
	free (spliter);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**spliter;

	if (!s)
		return (NULL);
	spliter = malloc(sizeof(char *) * (ft_counter((char *)s, c) + 1));
	if (!spliter)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			spliter[j] = ft_str_allocation((char *)(s), c);
			if (!spliter[j++])
				return (ft_free(spliter));
		}
		while (*s != c && *s)
			s++;
	}
	spliter[j] = 0;
	return (spliter);
}


// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*p;
// 	size_t	lens1;
// 	size_t	lens2;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	lens1 = ft_strlen(s1);
// 	lens2 = ft_strlen(s2);
// 	p = malloc(sizeof(char) * ((lens1 + lens2) + 1));
// 	if (!p)
// 		return (NULL);
// 	while (s1 && s1[i])
// 	{
// 		p[i] = s1[i];
// 		i++;
// 	}
// 	while (s2 && s2[j])
// 		p[i++] = s2[j++];
// 	p[i] = '\0';
// 	free(s1);
// 	return (p);
// }


char	*path_finder(char **env, char **cmd)
{
	int		i;
	char	**paths;
	char *hold;
	char	*temp;

	i = 0;
	hold = path_bring(env);
	if(!hold)
	{ 
		return NULL;
	}
	paths = ft_split(hold, ':');
	
	i = 0;
	while (paths[i])
	{
		temp = paths[i];
		paths[i] = ft_strjoin(temp, "/");
			//free (temp);
		temp = paths[i];
		paths[i] = ft_strjoin(temp, cmd[0]);
			//free (temp);
			if (access(paths[i], F_OK) == 0)
				break ;
		i++;
	}
	return (paths[i]);
}

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// void	ft_putstr_fd(char *s, int fd)
// {
// 	if (!s)
// 		return (ft_putchar_fd(0, fd));
// 	while (*s)
// 	{
// 		ft_putchar_fd(*s, fd);
// 		s++;
// 	}
// }

void	printerr2(char *s1, char *s2, char *s3)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(": ", 2);
	if (s2)
	{
		ft_putstr_fd(s2, 2);
		ft_putstr_fd(": ", 2);
	}
	if (s3)
	{
		ft_putstr_fd(s3, 2);
		ft_putchar_fd('\n', 2);
	}
	// g_globe.exit_status = 127;
}



void one_cmd(int argc, char *argv[], char **envp)
{
    (void)argc;
    char *hold;
    int pid = fork();
    if (pid == 0)
    {
        // dup2()
        if (access(argv[0], X_OK) == 0)
            execve(argv[0], argv, NULL);
        hold = path_finder(envp, argv);
        if (!hold)
        {
            printerr2("bash", argv[0], "No such file or directory");
            return;
        }
        if (access(hold, X_OK) == -1)
        {
            write(2, "Access failed\n", 15);
            exit(1);
        }
        execve(path_finder(envp, argv), argv, envp);
        write(2, "Execve failed\n", 15);
    }
    waitpid(pid, 0, 0);
}


int main(int argc, char *argv[], char **env)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return EXIT_FAILURE;
    }

    one_cmd(argc - 1, argv + 1, env);

    return EXIT_SUCCESS;
}
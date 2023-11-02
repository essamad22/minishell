// #include "minishell.h"




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}


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


char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	p = malloc(sizeof(char) * ((lens1 + lens2) + 1));
	if (!p)
		return (NULL);
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}


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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ft_putchar_fd(0, fd));
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

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



void execute_multiple_commands(int argc, char *argv[], char *envp[])
{
    int i = 0;
    int pid;
    int status;

    while (i < argc)
    {
        pid = fork();

        if (pid == 0)
        {
            // Processus fils

            // Construction du chemin complet de la commande
            char *full_path = path_finder(envp, argv);
            // ... logic to extract the full path of the command using your environment path system
            // You may use functions like strtok, strcat, etc.
            if (!full_path)
            {
                printerr2("bash", argv[0], "No such file or directory");
                return;
            }

            if (access(full_path, X_OK) == -1)
            {
                write(2, "Access failed\n", 15);
                exit(1);
            }
            // Exécution de la commande avec execve
            execve(full_path, &argv[i], envp);

            // Si execve échoue
            perror("Execve failed");
            exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
            // Erreur lors de la création du processus fils
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        // Processus père
        waitpid(pid, &status, 0);
        i++;
    }
}


int main(int argc, char *argv[], char *envp[])
{
    if (argc < 2)
    {
        printf("Usage: {commande1} {commande2} ...");
    }
    else
        execute_multiple_commands(argc - 1, &argv[1], envp);
    return 0;
}



// int main(int argc, char *argv[])
// {
//     // Supposons que tu aies déjà initialisé t_data **envp

//     execute_multiple_commands(argc - 1, argv + 1);

//     return 0;
// }

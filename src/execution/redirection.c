#include "execution.h"

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	i = 0;
// 	if (s)
// 		while (s[i])
// 			write(fd, &s[i++], 1);
// }

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	count;

// 	count = 0;
// 	while (s && s[count])
// 		count++;
// 	return (count);
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


// char	*ft_strdup(const char *s1)
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

static void	detect_error(char *msg, char *arg)
{
	char	*error_msg;

	if (!msg && !arg)
	{
		error_msg = ft_strjoin(ft_strdup("minishell: "), strerror(errno));
		ft_putstr_fd(error_msg, 2);
		ft_putchar_fd('\n', 2);
		free (error_msg);
	}
	else if (!msg && arg)
	{
		arg = ft_strjoin(ft_strdup("minishell: "), arg);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		free (arg);
	}
}

void	print_error(char *msg, char *arg, int status)
{
	char	*error_msg;

	if (msg && !arg)
		ft_putstr_fd(msg, 2);
	else if ((!msg && !arg) || (!msg && arg))
		detect_error(msg, arg);
	else
	{
		arg = ft_strjoin(ft_strdup("minishell: "), arg);
		error_msg = ft_strjoin(arg, msg);
		ft_putstr_fd(error_msg, 2);
		free (error_msg);
	}
	if (status != -1)
		exit(status);
}
/////// Error

//////// Opening File

int	input_redirection(char *infile)
{
	int	fd;

	if (access (infile, F_OK))
	{
		print_error(ENSFD, infile, -1);
		return (-1);
	}
	if (access (infile, R_OK))
	{
		print_error(EPD, infile, -1);
		return (-1);
	}
	fd = open(infile, O_RDONLY);
	if (fd == -1)
	{
		print_error(NULL, NULL, -1);
		return (-1);
	}
	return (fd);
}

int	output_redirection(char *outfile)
{
	int	fd;

	if (access (outfile, F_OK) == 0 && access(outfile, W_OK) == -1)
	{
		print_error(EPD, outfile, -1);
		return (-1);
	}
	fd = open (outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		print_error(NULL, NULL, -1);
		return (-1);
	}
	return (fd);
}

int	append_output(char *outfile)
{
	int	fd;

	if (!access (outfile, F_OK) && access(outfile, W_OK))
	{
		print_error(EPD, outfile, -1);
		return (-1);
	}
	fd = open (outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		print_error(NULL, NULL, -1);
		return (-1);
	}
	return (fd);
}

// Fonction pour gérer la redirection de l'entrée standard depuis un fichier
void handle_input_redirection(char *filename) {
    int fd = input_redirection(filename);
    
    if (fd < 0) {
        // perror("Erreur lors de la redirection de l'entrée standard");
        exit(EXIT_FAILURE);
    }

    // Redirection de l'entrée standard depuis le fichier
    if (dup2(fd, STDIN_FILENO) < 0) {
        perror("Erreur lors de la redirection de l'entrée standard");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

// Fonction pour gérer la redirection de la sortie standard vers un fichier
void handle_output_redirection(char *filename) {
    int fd = output_redirection(filename);
    
    if (fd < 0) {
        perror("Erreur lors de la redirection de la sortie standard");
        exit(EXIT_FAILURE);
    }

    // Redirection de la sortie standard vers le fichier
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("Erreur lors de la redirection de la sortie standard");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

// Fonction pour gérer l'ajout à la sortie standard vers un fichier
void handle_append_output(char *filename) {
    int fd = append_output(filename);
    
    if (fd < 0) {
        perror("Erreur lors de la redirection de la sortie standard (ajout)");
        exit(EXIT_FAILURE);
    }

    // Redirection de la sortie standard vers le fichier (ajout)
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("Erreur lors de la redirection de la sortie standard (ajout)");
        exit(EXIT_FAILURE);
    }

    close(fd);
}



// int main(int argc, char **argv) {
//     // Vérifie s'il y a un nombre correct d'arguments
//     if (argc < 3 || argc > 4) {
//         fprintf(stderr, "Usage: %s <fichier_entree> <fichier_sortie> <mode>\n", argv[0]);
//         exit(EXIT_FAILURE);
//     }

//     // Ouverture des fichiers avant la redirection
//     int input_fd = input_redirection(argv[1]);
// 	if (input_fd < 0) {
//         // perror("Minishell");
//         exit(EXIT_FAILURE);
//     }
//     int output_fd;

//     if ( (argc == 4) && strcmp(argv[3], "append") == 0) {
//         output_fd = append_output(argv[2]);
//     } else {
//         output_fd = output_redirection(argv[2]);
//     }

//     if (output_fd < 0) {
//         // perror("minishell: No such file or directory");
//         close(input_fd);  // Ferme le fichier d'entrée ouvert
//         exit(EXIT_FAILURE);
//     }

//     // Appelle la fonction de gestion de la redirection d'entrée
//     handle_input_redirection(argv[1]);

//     // Appelle la fonction de gestion de la redirection de sortie
//     if (argc == 4 && strcmp(argv[3], "append") == 0) {
//         handle_append_output(argv[2]);
//     } else {
//         handle_output_redirection(argv[2]);
//     }

//     // Lecture depuis l'entrée standard redirigée et écriture vers la sortie standard redirigée
//     char buffer[1024];
//     ssize_t bytesRead;

//     while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
//         // Traitement des données lues depuis le fichier d'entrée
//         write(STDOUT_FILENO, buffer, bytesRead);
//     }

//     if (bytesRead < 0) {
//         perror("Erreur lors de la lecture depuis le fichier d'entrée");
//         exit(EXIT_FAILURE);
//     }

//     // Fermeture des fichiers ouverts
//     close(input_fd);
//     close(output_fd);

//     return EXIT_SUCCESS;
// }

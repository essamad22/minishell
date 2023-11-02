#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_read {
    char *input;
} t_read;

void execute_command(char *command) {
    char *commands[64];
    int i = 0;

    // Tokenize the command based on semicolons
    char *token = strtok(command, "|");
    while (token != NULL) {
        commands[i++] = token;
        token = strtok(NULL, "|");
    }
    commands[i] = NULL;

    // Execute each command sequentially
    for (int j = 0; j < i; j++) {
        char *current_command = commands[j];

        // Tokenize the current command
        char *args[64];
        int k = 0;

        char *arg_token = strtok(current_command, " ");
        while (arg_token != NULL) {
            args[k++] = arg_token;
            arg_token = strtok(NULL, " ");
        }
        args[k] = NULL;

        // Create a child process
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
        } else {
            // Parent process
            waitpid(pid, NULL, 0);
        }
    }
}

void print_minishell(t_read *readln) {
    readln->input = readline("my_minishell $> ");
    add_history(readln->input);
    if (readln->input == NULL)
        readln->input = calloc(1, 1);
}

int main(int ac, char **av, char **env) {
    (void)env;
    t_read *readline;

    (void)av;
    readline = malloc(sizeof(t_read));

    while (ac == 1) {
        print_minishell(readline);

        if (readline->input == NULL)
            exit(1);

        // Check for exit command
        if (strcmp(readline->input, "exit") == 0) {
            free(readline);
            exit(0);
        }

        // Execute the commands
        execute_command(readline->input);

        // Free the input buffer
        free(readline->input);
    }

    return 0;
}

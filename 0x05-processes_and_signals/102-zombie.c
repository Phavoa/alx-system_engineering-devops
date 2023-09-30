/*
 * File: 102-zombie.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * infinite_while - Creates an infinite loop to keep the program running.
 *
 * Return: Always returns 0.
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

/**
 * main - Creates five zombie processes.
 *
 * Return: Always returns 0.
 */
int main(void)
{
    pid_t child_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork");
            return (1);
        }
        if (child_pid == 0)
        {
            printf("Zombie process created, PID: %d\n", getpid());
            exit(0);  // Child exits immediately to become a zombie
        }
    }

    infinite_while();  // Keep the program running

    return (0);
}

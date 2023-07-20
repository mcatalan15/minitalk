/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:15:44 by mcatalan@st       #+#    #+#             */
/*   Updated: 2023/07/20 12:26:23 by mcatalan@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig)
{
	printf("remember that multpilication....\n");
}

int main(int argc, char* argv[])
{
	int pid = fork();
	if (pid == -1)
	{
		return 1;
	}

	if (pid == 0)
	{
		//chill process
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		struct sigaction sa = {0};
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);

		
		//Parent process
		int x;
		printf("what is the result of 3 x 5:");
		scanf("%d", &x);
		if (x == 15)
			printf("Right");
		else
			printf("Wrong");
		wait(NULL);
	}
	return 0;
}

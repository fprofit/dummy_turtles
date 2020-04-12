#include <stdio.h>

int poisk(char **av, int i, int j, int x, int y, int naprav, int sum, int startj)
{
	if(x == 15 && y == 15)
		return(sum);
	if(av[i][j] == '-')
		j = startj;
	if(sum > 1000)
		return(-2);
	else if(av[i][j] == 'g' && naprav == 0)
	{
		if(y==29)
			return(sum = poisk(av, i, j+1, x, 0, naprav, sum+1, startj));
		return(sum = poisk(av, i, j+1, x, y+1, naprav, sum+1, startj));
	}
	else if(av[i][j] == 'g' && naprav == 1)
	{
		if(x==29)
			return(sum = poisk(av, i, j+1, 0, y, naprav, sum+1, startj));
		return(sum = poisk(av, i, j+1, x+1, y, naprav, sum+1, startj));
	}
	else if(av[i][j] == 'g' && naprav == 2)
	{
		if(y==0)
			return(sum = poisk(av, i, j+1, x, 29, naprav, sum+1, startj));
		return(sum = poisk(av, i, j+1, x, y-1, naprav, sum+1, startj));
	}
	else if(av[i][j] == 'g' && naprav == 3)
	{
		if(x==0)
			return(sum = poisk(av, i, j+1, 29, y, naprav, sum+1, startj));
		return(sum = poisk(av, i, j+1, x-1, y, naprav, sum+1, startj));
	}
	else if(av[i][j] == 'r')
		{
			if(naprav == 3)
				return(sum = poisk(av, i, j+1, x, y, 0, sum+1, startj));
			return(sum = poisk(av, i, j+1, x, y, naprav+1, sum+1, startj));
		}
	else if(av[i][j] == 'l')
		{
			if(naprav == 0)
				return(sum = poisk(av, i, j+1, x, y, 0, sum+1, startj));
			return(sum = poisk(av, i, j+1, x, y, naprav-1, sum+1, startj));
		}
	return(sum);
}
int coord(char **av, int i, int j)
{
	int x;
	int y;
	x = 0;
	y = 0;
	//int sum;
	if(av[i][0] == ':')
		return(-3);
	while(av[i][j] >= '0' && av[i][j] <= '9' )
	{
		x = x * 10 + (av[i][j] - 48);
		j++;
	}
	if(av[i][j] != ':' || av[i][j+1] == '-')
		return(-4);
	j++;
	while(av[i][j] >= '0' && av[i][j] <= '9' )
	{
		y = y * 10 + (av[i][j] - 48);
		j++;
	}
	if(av[i][j] != '-' || (x == 0 && y ==0))
		return(-5);
	printf("1 res x: %d res y: %d char: %c\n", x, y, av[i][j]);
	return(poisk(av, i, j+1, x-1, y-1, 0, 0, j+1));
}
int main(int ac, char **av)
{
	if(ac < 1)
		return (0);
	int sum;
	sum = (coord(av, 1, 0));
	printf("%d\n", sum);
	return(0);
}
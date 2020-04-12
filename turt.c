#include <stdio.h>

int poisk(char **av, int i, int j, int x, int y, int naprav, int sum, int startj)
{
	if(x == 15 && y == 15)
		return(sum);
	if(av[i][j] == '-')
		j = startj;
	if(sum > 1000)
		return(-1);
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

int main(int ac, char **av)
{
	if(ac < 1)
		return (0);
	int sum;
	sum = poisk(av, 1, 0, 1, 2, 0, 0, 0);
	printf("%d\n", sum);
	return(0);
}
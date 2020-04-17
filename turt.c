#include <unistd.h>


int poisk(char **av, int i, int j, int x, int y, int naprav, int sum, int startj)
{
	if (x > 29)
		return(-2);
	if (y > 29)
		return(-2);
	if(x == 14 && y == 14)
		return(sum);
	if(av[i][j] == '-')
		j = startj;
	if(sum > 1000)
		return(-3);
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
	if(av[i][0] == ':')
		return(-2);
	while(av[i][j] >= '0' && av[i][j] <= '9' )
	{
		x = x * 10 + (av[i][j] - 48);
		j++;
	}
	if(av[i][j] != ':' || av[i][j+1] == '-')
		return(-2);
	j++;
	while(av[i][j] >= '0' && av[i][j] <= '9' )
	{
		y = y * 10 + (av[i][j] - 48);
		j++;
	}
	if(av[i][j] != '-' || (x == 0 && y ==0))
		return(-2);
	return (poisk(av, i, j+1, x-1, y-1, 0, 0, j+1));
}
int turtNamePrint(char *av)
{
	int j;
	j = 0;
	int jtemp;
	while(av[j] >= '0' && av[j] <= '9' )
		j++;
	j++;
	while(av[j] >= '0' && av[j] <= '9' )
		j++;
	j++;
	while(av[j] == 'g' || av[j] == 'r' || av[j] == 'l')
		j++;
	if(av[j] != '-')
		return -1;
	j++;
	jtemp = j;
	while(av[j] != '\0')
	{
		if((av[j] >= 'A' && av[j] <= 'Z') || (av[j] >= 'a' && av[j] <= 'z')){
			j++;
		}
		else
			return -1;
	}
	j = jtemp;
	write(1, "om nom nom ", 11);
	while(av[j] != '\0')
	{
		if((av[j] >= 'A' && av[j] <= 'Z') || (av[j] >= 'a' && av[j] <= 'z')){
		write(1, &av[j], 1);
		j++;
		}
		else
			return -1;
	}
	write(1, " eat cucumber:)\n", 16);
	return 0;
}

int main(int ac, char **av)
{
	if(ac < 1 || ac > 11)
	{
		write(1, "Incorrect data\n", 15);
		return (0);
	}
	int i;
	int istart;
	int sum;
	i = 1;
	sum = 999;
	istart = 0;
	while(i < ac){
	if((coord(av, i, 0) < sum) && (coord(av, i, 0) > 0)){
		sum = coord(av, i, 0);
		istart = i;
		i++;
	}
	else if(sum == 999 && (coord(av, i, 0) < 0)){
		istart = coord(av, i, 0);
		i++;
	}
	else
		i++;
	}
	if(istart > 0)
		if(turtNamePrint(av[istart]) == -1)
			write(1, "Incorrect name\n", 15);
	if(istart == -2)
		write(1, "Incorrect coordinates\n", 22);
	if(istart == -3)
		write(1, "We are tired, I want to eat:(\n", 30);	
	return(0);
}
#include <unistd.h>
#include <stdlib.h>

#include <fcntl.h>
#include <stdio.h>

int 	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}
int	ft_strchr(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char	*ft_strjoin(char *buffer, char *rest)
{
	char	*all;
	int		i = -1;
	int		j = 0;

	if (!buffer || !rest)
		return (NULL);
	all = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(rest)) + 1);
	if (!all)
		return (NULL);
	while (rest[++i] != '\0')
		all[i] = rest[i];
	while (buffer[j] != '\0')
		all[i++] = buffer[j++];
	all[i] = '\0';
	free(rest);
	return (all);
}
char	*ft_strdup(char *str)
{
	char	*new;
	int		i = -1;

	new = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	while (str[++i] != '\0')
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}


char	*read_file(int fd, char *rest)
{
	char		*buffer;
	ssize_t		rread;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!rest)
		rest = ft_strdup("");
	rread = 1;
	while (ft_strchr(rest) == 0 && rread != 0)
	{
		rread = read(fd, buffer, BUFFER_SIZE);
		if (rread == -1)
			return (free(buffer), free(rest), NULL);
		buffer[rread] = '\0';
		rest = ft_strjoin(buffer, rest);
	}
	return (free(buffer), rest);
}

char	*getline(char *rest)
{
	char	*str;
	int		i = 0;

	while (rest[i] != '\n' && rest[i])
		i++;
	if (rest[i] == '\n')
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		str[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*getrest(char *rest, char *line)
{
	char	*rrest;
	int		i = ft_strlen(line);
	int		j = 0;

	while (rest[i++] != '\0')
		j++;
	rrest = malloc(sizeof(char) * (j + 1));
	if (!rrest)
		return (NULL);
	i = ft_strlen(line);
	j = 0;
	while (rest[i] != '\0')
		rrest[j++] = rest[i++];
	rrest[j] = '\0';
	free(rest);
	return (rrest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = read_file(fd, rest);
	if (!rest)
		return (NULL);
	line = getline(rest);
	if (line[0] == '\0')
	{
		free(rest);
		rest = NULL;
		return (free(line), NULL);
	}
	rest = getrest(rest, line);
	if (!rest)
		return (free(line), NULL);
	return (line);
}

int	main(void)
{
	int	fd;
	fd = open("../test", O_RDONLY);

	for (unsigned short i = 0; i < 5; i++)
		printf("%d\t: %s", i, get_next_line(fd));
	return (0);
}

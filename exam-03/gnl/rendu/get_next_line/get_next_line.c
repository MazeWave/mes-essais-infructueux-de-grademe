#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int i = 0;

	while (*str)
		i++;
	return (i);
}

int	ft_strchr(const char *str, const char c)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);	// trouve la position de 'c' genre '\n'
		i++;
	}
	if (c == '\0')
		return (i);		// trouve la position de '\0'
	else
		return (-1);		// 'c' n'a pas été trouvé
	return (-1);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int	i = 0;

	dup = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

char	*ft_cat(char *line, const char *buffer)
{
	char	*temp;
	int	i = 0;
	int	j = 0;

	if (line != NULL)	// si line n'est pas vide
	{
		temp = ft_strdup(line);
		free(line)
	}
	else			// cas si premiere fois
	{
		line = ft_strdup(buffer);
		return (line);
	}
	line = malloc(sizeof(char) * (ft_strlen(temp) + ft_strlen(buffer) + 1));
	if (!line)
		return (NULL);
	while (temp[i] != '\0')	// copy temp dans line
	{
		line[i] = temp[i];
		i++;
	}
	while (buffer[j] != '\0')	// copy buffer apres temp dans line
	{
		line[i+j] = buffer[j];
		j++;
	}
	line[i+j] = '\0';	// null terminate
	free(temp);
	return ();
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*raw;
	char		*result;
	int		readv;
	int		pos;
	int		i = 0;

	raw = malloc(sizeof(char) * 1);
	raw[0] = NULL;
	if (stash != NULL)
	{
		raw = ft_strdup(stash);
		free(stash);
	}
	while (ft_strchr() == -1 || (readv = read(fd, &buffer, BUFFER_SIZE) > 0))
		raw = ft_cat(raw, buffer);
	// todo copier jusqua \n ou \0 dans result
	pos = ft_strchr(raw, '\n');
	if (pos = -1)	// raw est la dernière ligne, on peut la return directement
	{
		free (stash);
		return (raw)
	}
	else		// copie raw dans result jusqu'à \n
	{
		result = malloc(sizeof(char) * pos + 2);
		if (!result)
		{
			free (stash);
			free (raw);
			return (NULL);
		}
		while (i <= pos)	// copie raw jusqua \n
		{
			result[i] = raw[i];
			i++;
		}

	}
	if (readv < 0)
	{
		free (result);
		free (raw);
		free (stash);
		return (NULL);
	}
	// todo copier le reste dans stash et free raw
	if (stash != NULL)
		free (stash);
	stash = malloc (sizeof(char) * (pos - ft_strlen(raw)) + 1);
	if (!stash)
		return (NULL);
	i = 0;
	pos++;	// pour copier après le \n
	while (raw[pos + i] != '\0')
	{
		stash[i] = raw[pos+i];
		i++;
	}
	return (NULL);
}



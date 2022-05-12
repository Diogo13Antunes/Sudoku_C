//==========================================================================================================
//                                                                                                           
//    ####    #####  ######        ##     ##  #####  ##    ##  ######        ##      ##  ##     ##  #####  
//   ##       ##       ##          ####   ##  ##      ##  ##     ##          ##      ##  ####   ##  ##     
//   ##  ###  #####    ##          ##  ## ##  #####    ####      ##          ##      ##  ##  ## ##  #####  
//   ##   ##  ##       ##          ##    ###  ##      ##  ##     ##          ##      ##  ##    ###  ##     
//    ####    #####    ##          ##     ##  #####  ##    ##    ##          ######  ##  ##     ##  #####  
//                                                                                                           
//==========================================================================================================

#include "../includes/sudoku.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;
	char	*cp;

	i = 0;
	cp = (char *)(str);
	while (cp && *cp)
	{
		cp++;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dst)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	if (s)
	{
		len = ft_strlen(s);
		if (!len)
			return (NULL);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ft_memcpy(str, s, len);
		*(str + len) = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ptr)
		return (NULL);
	while (i < (s1len + s2len + 1))
		ptr[i++] = 0;
	ft_memcpy(ptr, s1, s1len);
	ft_memcpy(ptr + s1len, s2, s2len);
	ptr[s1len + s2len] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	if (s)
	{
		tmp = (char *)(s);
		while (*tmp)
		{
			if (*tmp == (char)c)
				return (tmp);
			tmp++;
		}
		if (*tmp == c)
			return (tmp);
	}
	return (NULL);
}

static char	*verif_buffer(char **storage, char **buffer, size_t buffer_len)
{
	char	*ret;
	char	*tmp;
	size_t	i;

	i = ft_strlen(*storage);
	ret = (char *)malloc(sizeof(char) * (buffer_len + i + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, *storage, i);
	ft_memcpy(ret + i, *buffer, buffer_len);
	ret[i + buffer_len] = '\0';
	tmp = ft_strdup((*buffer) + buffer_len);
	if (*storage)
		free (*storage);
	(*storage) = tmp;
	return (ret);
}

static char	*put_storage(char **storage, char **buffer, size_t i)
{
	char	*tmp;
	char	*ret;

	ret = NULL;
	if (i <= 0)
	{
		if (i == 0 && *storage)
		{
			ret = (*storage);
			*storage = NULL;
		}
		return (ret);
	}
	(*buffer)[i] = '\0';
	tmp = ft_strchr(*buffer, '\n');
	if (tmp)
		ret = verif_buffer(storage, buffer, (tmp - *buffer) + 1);
	else
	{
		tmp = ft_strjoin(*storage, *buffer);
		if (*storage)
			free (*storage);
		*storage = tmp;
	}
	return (ret);
}

static char	*verif_storage(char **storage, size_t size)
{
	char	*tmp;
	char	*ret;
	size_t	i;

	if (size < 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i != size)
		ret[i] = (*storage)[i];
	ret[i] = '\0';
	tmp = ft_strdup(*storage + i);
	free (*storage);
	(*storage) = tmp;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*ret;
	size_t		i;

	if ((read(fd, 0, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (0);
	i = 1;
	ret = NULL;
	buffer = ft_strchr(storage, '\n');
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if(!buffer)
			return (0);
		while (ret == NULL && i > 0)
		{
			i = read(fd, buffer, BUFFER_SIZE);
			ret = put_storage(&storage, &buffer, i);
		}
		free (buffer);
		return (ret);
	}
	ret = verif_storage(&storage, (buffer - storage) + 1);
	return (ret);
}

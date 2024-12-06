/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:03:35 by nrey              #+#    #+#             */
/*   Updated: 2024/12/06 02:45:16 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*handle_read_error(char *buf, char *stash)
{
	free(stash);
	free(buf);
	return (NULL);
}

static char	*append_buffer_to_stash(char *stash, char *buf)
{
	char	*temp;

	temp = stash;
	stash = gnl_strjoin(stash, buf);
	free(temp);
	return (stash);
}

static char	*read_and_update_stash(int fd, char *stash)
{
	char	*buf;
	int		read_ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_ret = 1;
	while (ft_strchr(stash, '\n') == NULL && read_ret != 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
			return (handle_read_error(buf, stash));
		if (read_ret == 0)
			break ;
		buf[read_ret] = '\0';
		stash = append_buffer_to_stash(stash, buf);
		if (stash == NULL)
			return (handle_read_error(buf, NULL));
	}
	free(buf);
	return (stash);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*temp;
	char	*bns_pos;

	if (*stash == NULL || **stash == '\0')
		return (NULL);
	bns_pos = gnl_strchr(*stash, '\n');
	if (bns_pos != NULL)
	{
		line = gnl_substr(*stash, 0, bns_pos - *stash + 1);
		temp = gnl_strdup(bns_pos + 1);
		free(*stash);
		*stash = temp;
		if (line == NULL || *stash == NULL)
			return (NULL);
	}
	else
	{
		line = gnl_strdup(*stash);
		free(*stash);
		*stash = NULL;
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = gnl_strdup("");
		if (stash == NULL)
			return (NULL);
	}
	stash = read_and_update_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(&stash);
	return (line);
}

/*

	Walkthrough GNL

	Checks if fd is invalid or if BUFFER_SIZE is invalid.

	If stash contains nothing, ft_strdup will make it an empty pointer
	on the heap.

	Stash goes through read_and_update_stash();

	> read_and_update_stash explained
	--------------------------------------

	Takes fd and stash as arguments. This is where the main things happen.

	/!\ Learn about the read() function before continuing if
		you're learning here.

	The while loop checks for a '\n' within the stash.
	It will keep looping until one of two things:

	- Until it finds a '\n'
	- Or until the file ends and no bytes can be read.

	/!\ Everytime we read something stored in buf, 
	/!\ there must be a NULL terminating char.

	If anything goes wrong. goes to handle_read_error,
	which clears buf, stash, returns NULL and ensures no leaks.

	once the buf is read, it appends it with the stash using ft_strjoin.

	finally, it returns the updated stash.

	--------------------------------------

	Back to the get_next_line(); function.

	if the returned updated stash only contains an "end of string" (\0),
	we return NULL, as this means the file was valid but did not contain data.

	Now, we assign line's data with extract_line.

	> extract_line explained
	--------------------------------------

	extract_line takes a pointer to our stash as an argument (char **stash)
	the reason being, if we just send the stash, it will be a copy of
	the values. By sending a pointer to our stash, we can modify its
	values from this function.

	(Remember ft_swap ? same thing)
	
	first of all, it stores a pointer to the position of the '\n' with ft_strchr
	if the stash contains a \n we use ft_substr to retrieve the line, subtracting
	whatever follow the '\n' so we remain with the clean line.
	ft_strdup then lets us take whatever should remain to the stash, and by using
	a temporary pointer, reassigning it as the stash.

	If our fd's content looks like this :

	"Bonjour\n comment ca va\n"

	With a buffer of 11, it would go like this :

	buf = "Bonjour\n co" (11 chars)
	stash = "Bonjour\n co"

	After going through extract_line :
	
	line = "Bonjour\n"
	stash = " co"

	Now that our stash has remaining content,
	it will be joined with the next line.
	(read section on read_and_update_stash)

	The "else" statement in my extract_line is here in case it's the
	end of a file. Because the end of the text might probably not end
	with a '\n'.

	As said earlier, the read will only stop if it crosses a \n or
	until it cannot be read anymore. (if read_ret != 0)

	This means the stash, when arriving towards the end of file,
	will contain all the data, and that data will be returned
	in the else statement in extract_line.
*/

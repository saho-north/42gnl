/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 23:06:36 by sakitaha          #+#    #+#             */
/*   Updated: 2023/05/31 17:13:15 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*print_error(short error_code)
{
	char	*error_message[10];

	error_message[0] = "Error: Failed to allocate memory.\n";
	error_message[1] = "Error: Failed to read the file.\n";
	error_message[2] = "Error: Invalid BUFFER_SIZE\n";
	error_message[3] = "\n";
	ft_putstr(error_message[error_code]);
	return (NULL);
}

/*
fd:  The file descriptor to read from
read, malloc, free

Return value
Read line:  correct behavior
NULL: there is nothing else to read, or an error occurred
Description
Write a function that returns a line read from a
file descriptor
 */

// • Repeated calls (e.g.,
// 		using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor,
// 	one line at a time.
// // • Your function should return the line that was read.
// // If there is nothing else to read or if an error occurred,
// 	it should return NULL.
//
// • Make sure that your function works as expected both when reading a file and when reading from the standard input.
//
// • Please note that the returned line should include the terminating \n character,
// 	except if the end of file was reached and does not end with a \n character.
//
// • Your header file get_next_line.h must at least contain the prototype of the get_next_line() function.
//
// • Add all the helper functions you need in the get_next_readline_utils.c file.

char	*get_next_line(int fd)
{
	static char	*residue;
	char		*read_line;
	char		*tmp;
	char		*buf;
	ssize_t		bytes_read;
	size_t		readline_len;
	size_t		residue_len;
	size_t		before_nl_len;
	size_t		after_nl_len;
	bool		has_new_line;
	size_t		index;

	before_nl_len = 0;
	after_nl_len = 0;
	//読み込んだファイルがデータがない、または全て読み終わったということ
	if (fd < 0)
		return (NULL);
	//無効なBUFFERサイズはエラーと見なす
	if (BUFFER_SIZE <= 0)
		return (print_error(2));
	/*
	残余がある場合（2回目以降の読み込みで、前回の残余が0以外）
	...残余がある時には、残余の中身を'\n'以前と以降に分けて前者をread_lineに渡し
	...後者をresidueに再度allocateする必要が発生する
	...残余の中身に'\n'がなかった場合には、bufferを読み込んで続きを探さないといけない
	*/
	if (residue)
	{
		has_new_line = false;
		readline_len = 0;
		residue_len = 0;
		while (residue[readline_len + residue_len] != '\0')
		{
			if (!has_new_line)
			{
				//'\n'も含めてカウントしているので、後で+1のmallocはしなくていい
				//ここで'\n'を含めないとwhileのループカウントが機能しなくなる
				if (residue[readline_len] == '\n')
					has_new_line = true;
				readline_len++;
			}
			else
			{
				residue_len++;
			}
		}
		//readline_lenとresidue_lenが確定したので、それぞれにmallocして文字列を収める
		//もしif(has_new_line)ならreadlineはこのままreturnして良いことになる
		//freeの手続きは後で確認する
		read_line = NULL;
		//readline_lenが0の場合にはどうする？？？
		read_line = (char *)malloc(readline_len);
		if (read_line)
			return (print_error(0));
		if (residue_len > 0)
			residue = (char *)malloc(residue_len + 1);
		else
			residue = NULL;
		index = 0;
		while (tmp[readline_len + readline_len])
		{
		}
		free(tmp);
		tmp = NULL;
		bytes_read = read(fd, buf, BUFFER_SIZE - 1);
		if (bytes_read == -1)
		{
			print_error('0');
			return (NULL);
		}
	}
	//残余がない場合（初回の読み込みor前回が残余0）
	if (!residue)
	{
		//fdからbufferに文章を読み込むためのmalloc
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (print_error(0));
		//fdからbufferに文章を読み込む
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (print_error(1));
		//bufferの終端に'\0'を追加して終了を明確にする？
		//しかし、bufに読み込まれた文字数がBUFFER_SIZEより小さければ？->bytes_readで'\0'の位置を確保する
		buf[bytes_read] = '\0';
		//bufferをread_lineとresidueに分ける必要がある。分ける目安は'\n'となる
		has_new_line = false;
		readline_len = 0;
		residue_len = 0;
	}
	has_new_line = false;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (residue)
	{
		readline_len = 0;
		residue_len = 0;
		while (residue[readline_len + residue_len] != '\0')
		{
			if (!has_new_line && residue[readline_len] == '\n')
				has_new_line = true;
			else if (!has_new_line)
				readline_len++;
			else
				residue_len++;
		}
	}
	tmp = residue;
	read_line = (char *)malloc(readline_len + 1);
	if (residue_len > 0)
		residue = (char *)malloc(residue_len + 1);
	else
		residue = NULL;
	index = 0;
	while (tmp[readline_len + readline_len])
	{
	}
	free(tmp);
	tmp = NULL;
	bytes_read = read(fd, buf, BUFFER_SIZE - 1);
	if (bytes_read == -1)
	{
		print_error('0');
		return (NULL);
	}
}

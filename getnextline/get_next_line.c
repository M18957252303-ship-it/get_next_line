#include "get_next_line.h"
#define BUFFER_SIZE 25

hello\nthis is newline\nagain\n
1st-buf:hello\nthis is newline\naga
new:hello\n\0
line:hello\n\0
left:this is newline\naga
check if line has \n: y
return(line);
2nd-check if left has\n:y
line:this is newline\n\0
return(line)
left:aga
3rd-iflefthas\n:n
line:aga(cpy from left)
do read
buf:in\n\0
new:in\n\0
left:NULL
line:strjoin(line+new):again\n\0
4th-read(return<=0)-end

buffer_size = 3;
1st-buf:he\0
new:he\0
line:he\0
left:NULL
check if line has\n: n
read again
2nd-buf:ll\0
new:ll\0
realloc(line)
strjoin(line, new):line:hell\0
check\n:n
read again
3rd-buf:o\n\0
new:o\n\0
realloc line
strjoin(line, new):line:hello\n\0
check\n:y
return(line)

buffer_size = 5
1st read
buf:hell\0
new:hell\0
left:NULL
line:hell\0
checkif:n
read again
2nd
buf:o\nt\0
new:o\n\0
left:t\0
line:strjoin:hello\n\0
checkif:y
return(line);

char    *ft_newline(char *buf, char *left)
{
    int i;
    int j;
    int l;
    char    *new;

    i = 0;
    j = 0;
    l = 0;
    while(buf[i] != '\0' && buf[i] != '\n')
        i++;
    new = malloc(i + 1);
    while(j <= i)
        new[j++] = buf[j++];
    new[j] = '\0';
    while(j < strlen(buf))
        left[l++] = buf[j++];
    left[l] = '\0';
    return(new);
}

char    ft_cpytilln
//check if str has \n, find first \n and return substr till \n and change
// str to new str start after the first \n 

char	*get_next_line(int fd)
{
    char    *line;
    int count;
    int n;
    int i;
    static int total;
    static char* left;
    char    *buf;
    char    *new;
    i = 1;
    line = NULL;
    left = NULL;
    new = NULL;
    count = BUFFER_SIZE - 1;
    if(*left)
    //check if left have \n
    //cpy left to line till \n
    n = read(fd, buf, count);
    buf[n] = '\0';
    if(n <= 0)
        return(NULL);
    else
    {
        while(n > 0)
        {
            new = ft_newline(buf);
            left = ft_left(buf);
            total = n;
            line = realloc(line, total);
            line = strjoin(line, new);
            //checkiflinehas\n
            //if y return line
            //if n check if left has content
            //if y strjoin line+left
            //if n read again
            n = read(fd, buf, count);
            if(n <= 0)
                return(free(line), NULL);
            buf[n] = '\0';
            total = total + n;
        }
    }
	return(line);
}

char	*readline(int fd)
{
	static char *buffer;
	static int	total;
    int n;

	total = 0;
    n = count;
	buffer = (static char *)buf;
	while(n = count)
	{
		n = read(fd, buffer + total, sizeof(buffer) - total - 1);
        //if file size > buffer size, i need a bigger memory to store
        //and use realloc to extend size when the file size is unknown.
        total += n;
	}


int main(void)
{
    get_next_line(fd);
}

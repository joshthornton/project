#include "miscellaneous.h"

ssize_t read_stream(char **buffer, FCGX_Stream *stream, int guessContentLength, int maxSize )
{
    int contentLength = guessContentLength;
    int length = 0;
    if (contentLength > 0)
    {
        // Allow for null char
        contentLength += 1;
		
		if (contentLength > maxSize)
			contentLength = maxSize;

        *buffer = malloc( sizeof(char) * contentLength );
        while ( !FCGX_HasSeenEOF( stream ) && length < maxSize)
        {
            if ( length == contentLength )
            {
                contentLength += contentLength;
                *buffer = realloc( *buffer, sizeof(char) * contentLength );
            }
            length += FCGX_GetStr( *buffer + length, contentLength - length, stream );
        }
    }
    return length;
}

int content_length(FCGX_ParamArray envp)
{
    int contentLength = -1;
    char * string = FCGX_GetParam("CONTENT_LENGTH", envp);
	if ( !string )
		return -1;
    char *rubbishChar;
    contentLength = strtol(string, &rubbishChar, 10);
    /*If the null char was not the following char then the integer is invalid*/
    if (*rubbishChar != '\0')
        contentLength = -1;

    return contentLength;
}


#ifndef Project_Miscellaneous
#define Project_Miscellaneous

#include <fcgiapp.h>
#include <stdlib.h>
#include <unistd.h>

int content_length(FCGX_ParamArray envp );
ssize_t read_stream(char **buffer, FCGX_Stream *stream, int guessContentLength, int maxSize );

#endif

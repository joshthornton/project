#ifndef Project_FUNCTIONS
#define Project_FUNCTIONS

#include <fcgiapp.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t read_stream(char **buffer, FCGX_Stream *stream, FCGX_ParamArray envp );
int content_length(FCGX_ParamArray envp);

#endif

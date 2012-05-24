#include <fcgiapp.h>
#include <stdlib.h>
#include <unistd.h>

#include "functions.h"

int main( int argc, char * argv[] )
{

	FCGX_Stream *in, *out, *err;
	FCGX_ParamArray envp;

	while ( FCGX_Accept(&in, &out, &err, &envp) >= 0 )
	{
		FCGX_FPrintF( out, "Content-Type: text/plain\n\n");
		FCGX_FPrintF( out, "Hello, World!\n" );
		
		char * post;
		if ( read_stream( &post, in, envp) )
			FCGX_FPrintF( out, "POST: %s\n", post );
	}

	return EXIT_SUCCESS;
}

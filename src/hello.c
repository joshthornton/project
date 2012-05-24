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
		FCGX_FPrintF( out, "Hello, World!\n\n" );

		//for ( int i = 0; envp[i]; ++i )
		//	FCGX_FPrintF( out, "%s\n", envp[i] );
		
		char * post;
		if ( read_stream( &post, in, envp) )
			FCGX_FPrintF( out, "POST:\t\t%s\n", post );

		FCGX_FPrintF( out, "QUERY_STRING:\t%s\n", FCGX_GetParam("QUERY_STRING", envp) );
		FCGX_FPrintF( out, "REQUEST_URI:\t%s\n", FCGX_GetParam("REQUEST_URI", envp) );
	}

	return EXIT_SUCCESS;
}

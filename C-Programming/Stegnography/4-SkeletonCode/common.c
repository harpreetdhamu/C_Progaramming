#include <stdlib.h>
#include <stdio.h>
#include "encode.h"
#include "types.h"
#include <string.h>
#include <math.h>

/* Function Definitions */

/* Get error message
 * Input: Error message
 * Description: prints Usage format and error message
 */


/* Check operation type */
 OperationType check_operation_type(char *argv[])
{
	if (strcmp(argv[1],"e") == 0 )
	{
		return e_encode;
	}
	else if (strcmp(argv[1],"d") == 0 )
	{
		return d_encode;
	}
		return e_unsupported;
}

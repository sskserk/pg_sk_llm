#include "postgres.h"
#include "fmgr.h"
#include "utils/guc.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

Datum llm_prompt( PG_FUNCTION_ARGS );


PG_FUNCTION_INFO_V1( llm_prompt );
Datum
llm_prompt( PG_FUNCTION_ARGS )
{
   // variable declarations
   char greet[] = "Hello, ";
   text *prompt;
   int greetlen;
   int promptLen;
   text *greeting;
   char *apiBase;
   
   apiBase = GetConfigOptionByName("pg_sk_llm.api_base", NULL, 0);


   // Get arguments.  If we declare our function as STRICT, then
   // this check is superfluous.
   if( PG_ARGISNULL(0) ) {
      PG_RETURN_NULL();
   }
   prompt = PG_GETARG_TEXT_P(0);

   // Calculate string sizes.
   greetlen = strlen(greet);
   apiBaseLen = strlen(apiBase);
   promptLen = VARSIZE(prompt) - VARHDRSZ;

   // Allocate memory and set data structure size.
   greeting = (text *)palloc( greetlen + promptLen );
   SET_VARSIZE(greeting, greetlen + apiBaseLen + promptLen  + VARHDRSZ);

   // Construct greeting string.
   strncpy( VARDATA(greeting), greet, greetlen );
   strncpy( VARDATA(greeting) + greetlen, VARDATA(prompt), promptLen );

   PG_RETURN_TEXT_P( greeting );
}

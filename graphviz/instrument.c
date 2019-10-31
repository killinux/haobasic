// Instrumentation source -- link this with your application with
// -g -finstrument-functions options, and
// then execute to build trace data file (trace.txt).

#include <stdio.h>
#include <stdlib.h>

int initialization_complete = 0;
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/* Function prototypes with attributes */
void main_constructor( void )
    __attribute__ ((no_instrument_function, constructor));

void main_destructor( void )
    __attribute__ ((no_instrument_function, destructor));

void __cyg_profile_func_enter( void *, void * )
    __attribute__ ((no_instrument_function));

void __cyg_profile_func_exit( void *, void * )
    __attribute__ ((no_instrument_function));


static FILE *fp;


void main_constructor( void )
{
  initialization_complete = 1;
  fp = fopen( "trace.txt", "w" );
  if (fp == NULL) exit(-1);
}


void main_deconstructor( void )
{
  fclose( fp );
}


void __cyg_profile_func_enter( void *this_fn, void *call_site )
{
if (!initialization_complete) return;
    /* fprintf(fp, "E %p %p\n", (int *)this_fn, (int *)call_site); */
//    fprintf(fp, "%p %p\n", (int *)this_fn, (int *)call_site);
   fprintf(fp, "E%p\n", (void *)this_fn); 
}


void __cyg_profile_func_exit( void *this_fn, void *call_site )
{
    if (!initialization_complete) return;
    /* fprintf(fp, "X %p %p\n", (int *)this_fn, (int *)call_site); */
//    fprintf(fp, "X %p %p\n", (int *)this_fn, (int *)call_site); 
    fprintf(fp, "X%p\n", (int *)this_fn);        
}

#ifdef __cplusplus
}
#endif // __cplusplus

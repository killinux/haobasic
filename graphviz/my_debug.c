#include <stdio.h>  
#include <stdlib.h>  
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

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
  fp = fopen( "trace.txt", "w" );  
  if (fp == NULL) exit(-1);  
}  
void main_deconstructor( void )  
{  
  fclose( fp );  
}  
//modify from this to this_fn,modify by hao
void __cyg_profile_func_enter( void *this_fn, void *callsite )  
{  
  fprintf(fp, "E%p\n", (void *)this_fn);  
}  
void __cyg_profile_func_exit( void *this_fn, void *callsite )  
{  
  fprintf(fp, "X%p\n", (int *)this_fn);  
}  

#ifdef __cplusplus
}
#endif // __cplusplus

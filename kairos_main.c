/*============================---(source-start)---============================*/
#include    "kairos.h"



/*====================------------------------------------====================*/
/*===----                            main                              ----===*/
/*====================------------------------------------====================*/
static void      o___MAIN____________________o (void) {;}

int          /*===[[ main driver ]]=======================[ ------ [ ------ ]=*/
main               (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----------+-*/
   int         rc          = 0;
   /*---(initialize)---------------------*/
   if (rc >= 0)   rc = PROG_urgents (a_argc, a_argv);
   if (rc >= 0)   rc = PROG_startup  (a_argc, a_argv);
   if (rc <  0)  {
      PROG_shutdown ();
      exit (-1);
   }
   PROG_dawn ();
   /*---(main)---------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*> yVIKEYS_args (a_argc, a_argv);                                                 <*/
   /*> yVIKEYS_main ("keys", "every", NULL);                                          <*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   /*---(complete)-----------------------*/
   PROG_dusk ();
   PROG_shutdown ();
   return 0;
}





/*============================----(source-end)----============================*/

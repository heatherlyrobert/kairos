/*============================---(source-start)---============================*/
#include    "kairos.h"



tGLOBAL     my;
char        unit_answer [LEN_FULL];



/*====================------------------------------------====================*/
/*===----                         supporting                           ----===*/
/*====================------------------------------------====================*/
static void      o___SUPPORT___________o (void) {;}

char      verstring    [LEN_HUND];

char*
PROG_version            (void)
{
   char    t [20] = "";
#if    __TINYC__ > 0
   ystrlcpy (t, "[tcc built  ]", 15);
#elif  __GNUC__  > 0
   ystrlcpy (t, "[gnu gcc    ]", 15);
#elif  __CBANG__  > 0
   ystrlcpy (t, "[cbang      ]", 15);
#else
   ystrlcpy (t, "[unknown    ]", 15);
#endif
   snprintf (verstring, LEN_HUND, "%s   %s : %s", t, P_VERNUM, P_VERTXT);
   return verstring;
}



/*====================------------------------------------====================*/
/*===----                       pre-initialization                     ----===*/
/*====================------------------------------------====================*/
static void      o___PREINIT________o (void) {;}

char
PROG__header            (void)
{
   /*---(log header)---------------------*/
   DEBUG_PROG   yLOG_info     ("purpose"   , P_PURPOSE);
   DEBUG_PROG   yLOG_info     ("namesake"  , P_NAMESAKE);
   DEBUG_PROG   yLOG_info     ("heritage"  , P_HERITAGE);
   DEBUG_PROG   yLOG_info     ("imagery"   , P_IMAGERY);
   DEBUG_PROG   yLOG_info     ("kairos"    , PROG_version      ());
   /*---(core)---------------------------*/
   DEBUG_PROG   yLOG_note     ("custom core");
   DEBUG_PROG   yLOG_info     ("yLOG"      , yLOGS_version     ());
   DEBUG_PROG   yLOG_info     ("yURG"      , yURG_version      ());
   DEBUG_PROG   yLOG_info     ("ySTR"      , ySTR_version      ());
   /*---(fundamental)--------------------*/
   DEBUG_PROG   yLOG_note     ("vi-keys fundamental");
   DEBUG_PROG   yLOG_info     ("yMODE"     , yMODE_version     ());
   DEBUG_PROG   yLOG_info     ("yKEYS"     , yKEYS_version     ());
   DEBUG_PROG   yLOG_info     ("yFILE"     , yFILE_version     ());
   DEBUG_PROG   yLOG_info     ("yVIEW"     , yVIEW_version     ());
   /*---(extended)-----------------------*/
   DEBUG_PROG   yLOG_note     ("vi-keys extended");
   DEBUG_PROG   yLOG_info     ("yMAP"      , yMAP_version      ());
   DEBUG_PROG   yLOG_info     ("yCMD"      , yCMD_version      ());
   DEBUG_PROG   yLOG_info     ("yMACRO"    , yMACRO_version    ());
   DEBUG_PROG   yLOG_info     ("ySRC"      , ySRC_version      ());
   DEBUG_PROG   yLOG_info     ("yMARK"     , yMARK_version     ());
   /*---(opengl-specific)----------------*/
   DEBUG_PROG   yLOG_note     ("vi-keys opengl");
   DEBUG_PROG   yLOG_info     ("yVIOPENGL" , yVIOPENGL_version ());
   DEBUG_PROG   yLOG_info     ("yX11"      , yX11_version      ());
   DEBUG_PROG   yLOG_info     ("yFONT"     , yFONT_version     ());
   DEBUG_PROG   yLOG_info     ("yGLTEX"    , yGLTEX_version    ());
   DEBUG_PROG   yLOG_info     ("yCOLOR"    , yCOLOR_version    ());
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit  (__FUNCTION__);
   return 0;
}

char
PROG_urgents            (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(set mute)-----------------------*/
   yURG_all_mute ();
   /*---(start logger)-------------------*/
   rc = yURG_logger  (a_argc, a_argv);
   DEBUG_PROG   yLOG_value    ("logger"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(process urgents)----------------*/
   rc = yURG_urgs    (a_argc, a_argv);
   DEBUG_PROG   yLOG_value    ("urgents"   , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(show header)--------------------*/
   rc = PROG__header ();
   DEBUG_PROG   yLOG_value    ("header"    , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   return rc;
}



/*====================------------------------------------====================*/
/*===----                          start-up                            ----===*/
/*====================------------------------------------====================*/
static void      o___STARTUP___________o (void) {;}

char             /* [------] minimal pre-argument program initialization -----*/
PROG__init              (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter    (__FUNCTION__);
   /*---(globals)------------------------*/
   my.w_wide = 800;
   my.w_tall = 10;
   /*---(yVIKEYS)------------------------*/
   /*> rc = yVIKEYS_init         (MODE_MAP);                                          <*/
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char             /* [------] process the command line arguments --------------*/
PROG__args              (int a_argc, char *a_argv[])
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;             /* loop iterator -- arguments     */
   char       *a           = NULL;          /* current argument               */
   int         len         = 0;             /* argument length                */
   int         x_total     = 0;
   int         x_args      = 0;
   /*---(begin)--------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(process)------------------------*/
   for (i = 1; i < a_argc; ++i) {
      /*---(read)------------------------*/
      a   = a_argv [i];
      len = strlen(a);
      ++x_total;
      /*---(filter)----------------------*/
      if (a[0] == '@')  continue;
      ++x_args;
      DEBUG_ARGS   yLOG_info  ("argument"  , a);
      /*---(startup/shutdown)------------*/
      /*> if      (strcmp (a, "--print"             ) == 0)    my.print          = 'y';   <*/
   }
   /*---(display urgents)----------------*/
   DEBUG_ARGS   yLOG_note    ("summarization of argument processing");
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char             /* [------] post-argument program initialization ------------*/
PROG__begin             (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         x_cum       = 0;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---()-------------------------------*/
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   DEBUG_PROG   yLOG_break   ();
   return 0;
}

char
PROG_startup            (int a_argc, char *a_argv [])
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(header)----------------------*/
   yURG_stage_check (YURG_BEG);
   DEBUG_PROG  yLOG_enter   (__FUNCTION__);
   /*---(initialize)---------------------*/
   rc = PROG__init   (a_argc, a_argv);
   DEBUG_PROG   yLOG_value    ("init"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(arguments)----------------------*/
   rc = PROG__args   (a_argc, a_argv);
   DEBUG_PROG   yLOG_value    ("args"      , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(begin)--------------------------*/
   rc = PROG__begin  ();
   DEBUG_PROG   yLOG_value    ("begin"     , rc);
   --rce;  if (rc < 0) {
      DEBUG_PROG   yLOG_exitr    (__FUNCTION__, rce);
      return rce;
   }
   /*---(complete)-----------------------*/
   DEBUG_PROG  yLOG_exit  (__FUNCTION__);
   yURG_stage_check (YURG_MID);
   return rc;
}



/*====================------------------------------------====================*/
/*===----                       execution support                      ----===*/
/*====================------------------------------------====================*/
static void      o___EXECUTION__________o (void) {;}

char
PROG_dawn               (void)
{
   /*---(locals)-----------+-----------+-*/
   int         i           = 0;
   int         x_cum       = 0;
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(yVIKEYS)------------------------*/
   /*> yVIKEYS_simple (P_NAMESAKE, P_VERNUM, YVIKEYS_OPENGL, 1351, 753, YVIKEYS_TOPLEF, MODE_MAP, "hack", "verdana", DRAW_main);   <*/
   /*> yVIKEYS_cmds_direct   (":layout min");                                         <*/
   /*> yVIKEYS_cmds_direct   (":title show");                                         <* 
    *> yVIKEYS_cmds_direct   (":status show");                                        <* 
    *> yVIKEYS_cmds_direct   (":modes show");                                         <* 
    *> yVIKEYS_cmds_direct   (":palette  30 rcomp pale earthy");                      <* 
    *> yVIKEYS_cmds_direct   (":status macro");                                       <* 
    *> yVIKEYS_cmds_direct   (":float_loc b");                                        <* 
    *> yVIKEYS_view_colors   (YCOLOR_POS, YCOLOR_BAS, YCOLOR_NEG, YCOLOR_POS);        <*/
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   DEBUG_PROG   yLOG_break   ();
   return 0;
}

char                /* PURPOSE : shutdown program and free memory ------------*/
PROG_dusk               (void)
{
   DEBUG_PROG   yLOG_break   ();
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(yVIKEYS)------------------------*/
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   DEBUG_PROG   yLOGS_end     ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                        program shutdown                      ----===*/
/*====================------------------------------------====================*/
static void      o___SHUTDOWN__________o (void) {;}

char       /*----: drive the program closure activities ----------------------*/
PROG__end               (void)
{
   /*---(locals)-----------+-----+-----+-*/
   char        rce         =  -10;
   char        rc          =    0;
   /*---(shutdown)--------------------*/
   DEBUG_PROG   yLOG_enter   (__FUNCTION__);
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit    (__FUNCTION__);
   return 0;
}

char             /* [------] drive the program closure activities ------------*/
PROG_shutdown           (void)
{
   /*---(stage-check)--------------------*/
   yURG_stage_check (YURG_END);
   /*---(header)-------------------------*/
   DEBUG_PROG   yLOG_enter    (__FUNCTION__);
   PROG__end ();
   /*---(complete)-----------------------*/
   DEBUG_PROG   yLOG_exit     (__FUNCTION__);
   DEBUG_PROG   yLOGS_end    ();
   return 0;
}



/*====================------------------------------------====================*/
/*===----                   helpers for unit testing                   ----===*/
/*====================------------------------------------====================*/
static void      o___UNITTEST__________o (void) {;}

char       /*----: set up programgents/debugging -----------------------------*/
PROG__unit_quiet    (void)
{
   char        rc          =    0;
   char        x_argc      =    1;
   char       *x_argv [1]  = { "kairos" };
   rc = PROG_urgents   (x_argc, x_argv);
   rc = PROG_startup   (x_argc, x_argv);
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
PROG__unit_loud    (void)
{
   char        rc          =    0;
   char        x_argc      =    2;
   char       *x_argv [2]  = { "kairos_unit", "@@kitchen"    };
   rc = PROG_urgents   (x_argc, x_argv);
   rc = PROG_startup   (x_argc, x_argv);
   return 0;
}

char       /*----: set up programgents/debugging -----------------------------*/
PROG__unit_end     (void)
{
   PROG_shutdown ();
   return 0;
}






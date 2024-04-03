/*===============================[[ beg-code ]]===============================*/


/*===[[ ONE_LINERS ]]=========================================================*/
/*                      ´·········1·········2·········3·········4·········5·········6·········7*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/
/*········· ··········· ´·····························´········································*/
#define     P_FOCUS     "AU (automation)"
#define     P_NICHE     "wn (windows)"
#define     P_SUBJECT   "cross-application scripting"
#define     P_PURPOSE   "coordinate multiple independent programs in scripts"
/*········· ··········· ´·····························´········································*/
#define     P_NAMESAKE  "kairos-falakra (opportunity)"
#define     P_PRONOUNCE "kai·rohs"
#define     P_HERITAGE  "youngest child of zeus who represents the right, fleeting moment"
#define     P_BRIEFLY   "embodiment of fleeting opportunity"
#define     P_IMAGERY   "handsome, fast-running boy with single lock of forehead hair"
#define     P_REASON    ""
/*········· ··········· ´·····························´········································*/
#define     P_ONELINE   P_NAMESAKE " " P_SUBJECT
/*········· ··········· ´·····························´········································*/
#define     P_HOMEDIR   "/home/system/kairos.script_coordinator"
#define     P_BASENAME  "kairos"
#define     P_FULLNAME  "/usr/local/bin/kairos"
#define     P_SUFFIX    ""
#define     P_CONTENT   ""
/*········· ··········· ´·····························´········································*/
#define     P_SYSTEM    "gnu/linux   (powerful, ubiquitous, technical, and hackable)"
#define     P_LANGUAGE  "ansi-c      (wicked, limitless, universal, and everlasting)"
#define     P_COMPILER  "gcc 5.3.0"
#define     P_CODESIZE  "small       (appoximately 1,000 slocl)"
/*········· ··········· ´·····························´········································*/
#define     P_DEPSTDC   "stdio,stdlib,string"
#define     P_DEPPOSIX  ""
#define     P_DEPCORE   "yURG,yLOG,ySTR"
#define     P_DEPVIKEY  "yMODE,yKEYS,yFILE,yVIEW,yMAP,yCMD,yMACRO,ySRC,yMARK"
#define     P_DEPGRAPH  "X11/X,X11/Xlib,X/extensions/shape,GL/gl,GL/glx"
#define     P_DEPOTHER  ""
#define     P_DEPSOLO   ""
/*········· ··········· ´·····························´········································*/
#define     P_AUTHOR    "heatherlyrobert"
#define     P_CREATED   "2020-06"
/*········· ··········· ´·····························´········································*/
#define     P_VERMAJOR  "0.--, pre-production"
#define     P_VERMINOR  "0.2-, switch to new vi-keys"
#define     P_VERNUM    "0.2a"
#define     P_VERTXT    "compiled with changes away from yVIKEYS, but not runnable yet"
/*········· ··········· ´·····························´········································*/
#define     P_TOPOFMIND "wild ideas, big experimental code base, single maintainer"
#define     P_PRIORITY  "direct, simple, brief, vigorous, and lucid (h.w. fowler)"
#define     P_PRINCIPAL "[grow a set] and build your wings on the way down (r. bradbury)"
#define     P_REMINDER  "there are many better options, but i *own* every byte of this one"
/*········· ··········· ´·····························´········································*/
#define     P_HEADERS   P_FOCUS, P_NICHE, P_SUBJECT, P_PURPOSE, P_NAMESAKE, P_PRONOUNCE, P_HERITAGE, P_BRIEFLY, P_IMAGERY, P_REASON, P_ONELINE, P_HOMEDIR, P_BASENAME, P_FULLPATH, P_SUFFIX, P_CONTENT, P_SYSTEM, P_LANGUAGE, P_COMPILER, P_CODESIZE, P_DEPSTDC, P_AUTHOR, P_CREATED, P_VERMAJOR, P_VERMINOR, P_VERNUM, P_VERTXT
/*········· ··········· ´·····························´········································*/
/*--------- 12345678901 ´123456789-123456789-123456789-123456789-123456789-123456789-123456789-*/

/*===[[ END ONE_LINERS ]]=====================================================*/

/*
 *
 *  falakra means "bald" which is what makes opportunity so hard to catch as
 *  he runs by -- he has a lock of hair on his forehead which is the only way.
 *  once he passes by, his head is bald and can not be grasped.
 *
 *
 */




/*===[[ HEADER GUARD ]]=======================================================*/
#ifndef YKAIROS
#define YKAIROS loaded

/*---(heatherly libraries)-------------------------*/

/*---(big standards)------------*/
#include    <stdio.h>        /* C_ANSI : strcpy, strlen, strchr, strcmp, ...  */
#include    <string.h>       /* C_ANSI : printf, snprintf, fgets, fopen, ...  */
#include    <stdlib.h>       /* C_ANSI : exit, system, ...                    */


/*===[[ CUSTOM LIBRARIES ]]===================================================*/
#include    <make_opengl.h>


/*---(X11/opengl libraries)------------------------*/
/*> #include    <GL/glu.h>                                                            <*/
#include    <X11/extensions/shape.h>   /* xwindows shape extension            */



typedef     struct     cGLOBAL      tGLOBAL;
struct cGLOBAL {
   char        w_wide;
   char        w_tall;
};
extern      tGLOBAL    my;

extern      char          unit_answer [LEN_FULL];


/*345678901-12345678901-12345678901-12345678901-12345678901-12345678901-123456*/
/*---(support)--------------*/
char*       PROG_version            (void);
/*---(preinit)--------------*/
char        PROG__header            (void);
char        PROG_urgents            (int a_argc, char *a_argv []);
/*---(startup)--------------*/
char        PROG__init              (int a_argc, char *a_argv []);
char        PROG__args              (int a_argc, char *a_argv []);
char        PROG__begin             (void);
char        PROG_startup            (int a_argc, char *a_argv []);
/*---(execution)------------*/
char        PROG_dawn               (void);
char        PROG_dusk               (void);
/*---(shutdown)-------------*/
char        PROG__end               (void);
char        PROG_shutdown           (void);
/*---(unittest)-------------*/

char        DRAW_main               (void);


#endif

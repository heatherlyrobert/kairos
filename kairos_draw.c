/*============================---(source-start)---============================*/
#include    "kairos.h"


char
DRAW_mask               (void)
{
}

char
DRAW_main               (void)
{
   /*---(locals)-----------+-----+-----+-*/
   Pixmap      x_bounds;
   XGCValues   x_style;
   GC          x_context;
   int         w_wide, w_tall;
   short       x_left      =    0;
   short       x_wide      =    0;
   short       x_bott      =    0;
   short       x_tall      =    0;
   int         x           =    0;
   int         i           =    0;
   int         x_min       =    0;
   int         y_max       =    0;
   /*---(header)-------------------------*/
   DEBUG_GRAF   yLOG_enter    (__FUNCTION__);
   /*---(get full sizes)-----------------*/
   yVIEW_size (YVIEW_MAIN, NULL, &x_left, &x_wide, &x_bott, &x_tall);
   DEBUG_GRAF   yLOG_complex ("window"    , "%4dl, %4dw, %4db, %4dt", x_left, x_wide, x_bott, x_tall);
   w_wide = x_wide;
   w_tall = x_tall;
   /*---(create)-------------------------*/
   x_bounds  = XCreatePixmap (YX_DISP, YX_BASE, x_wide, x_tall, 1);
   x_style.line_width = 3;
   x_context = XCreateGC     (YX_DISP, x_bounds, GCLineWidth, &x_style);
   /*---(clear all)----------------------*/
   XSetForeground (YX_DISP, x_context, 0);
   XFillRectangle (YX_DISP, x_bounds, x_context, 0, 0, x_wide, x_tall);
   /*---(prepare for draw)---------------*/
   XSetForeground (YX_DISP, x_context, 1);
   /*---(outline)------------------------*/
   XFillRectangle (YX_DISP, x_bounds, x_context, 0, 0, x_wide, 2);
   XFillRectangle (YX_DISP, x_bounds, x_context, x_wide - 2, 0, 2, x_tall);
   /*---(parts)--------------------------*/
   /*> if (yVIKEYS_view_showing (YVIKEYS_TITLE)) {                                                              <* 
    *>    DEBUG_GRAF   yLOG_note     ("draw the title mask");                                                   <* 
    *>    yVIKEYS_view_size (YVIKEYS_TITLE , &x_left, &x_wide, &x_bott, &x_tall, NULL);                         <* 
    *>    DEBUG_GRAF   yLOG_complex ("title"     , "%4dl, %4dw, %4db, %4dt", x_left, x_wide, x_bott, x_tall);   <* 
    *>    XFillRectangle (YX_DISP, x_bounds, x_context, x_left, w_tall - x_bott - x_tall, x_wide, x_tall);      <* 
    *>    x = x_wide;                                                                                           <* 
    *> }                                                                                                        <*/
   /*> if (yVIKEYS_view_showing (YVIKEYS_MODES)) {                                                              <* 
    *>    DEBUG_GRAF   yLOG_note     ("draw the modes mask");                                                   <* 
    *>    yVIKEYS_view_size (YVIKEYS_MODES , &x_left, &x_wide, &x_bott, &x_tall, NULL);                         <* 
    *>    DEBUG_GRAF   yLOG_complex ("modes"     , "%4dl, %4dw, %4db, %4dt", x_left, x_wide, x_bott, x_tall);   <* 
    *>    XFillRectangle (YX_DISP, x_bounds, x_context, x_left, w_tall - x_bott - x_tall, x_wide, x_tall);      <* 
    *> }                                                                                                        <*/
   /*> if (yVIKEYS_view_showing (YVIKEYS_STATUS)) {                                                             <* 
    *>    DEBUG_GRAF   yLOG_note     ("draw the status mask");                                                  <* 
    *>    yVIKEYS_view_size (YVIKEYS_STATUS, &x_left, &x_wide, &x_bott, &x_tall, NULL);                         <* 
    *>    DEBUG_GRAF   yLOG_complex ("status"    , "%4dl, %4dw, %4db, %4dt", x_left, x_wide, x_bott, x_tall);   <* 
    *>    XFillRectangle (YX_DISP, x_bounds, x_context, x_left, w_tall - x_bott - x_tall, x_wide, x_tall);      <* 
    *> }                                                                                                        <*/
   /*> if (yVIKEYS_view_showing (YVIKEYS_COMMAND)) {                                                            <* 
    *>    DEBUG_GRAF   yLOG_note     ("draw the command mask");                                                 <* 
    *>    yVIKEYS_view_size (YVIKEYS_COMMAND, &x_left, &x_wide, &x_bott, &x_tall, NULL);                        <* 
    *>    DEBUG_GRAF   yLOG_complex ("command"   , "%4dl, %4dw, %4db, %4dt", x_left, x_wide, x_bott, x_tall);   <* 
    *>    XFillRectangle (YX_DISP, x_bounds, x_context, x_left, w_tall - x_bott - x_tall, x_wide, x_tall);      <* 
    *> }                                                                                                        <*/
   /*> if (yVIKEYS_view_showing (YVIKEYS_KEYS)) {                                                               <* 
    *>    DEBUG_GRAF   yLOG_note     ("draw the keys mask");                                                    <* 
    *>    yVIKEYS_view_size (YVIKEYS_KEYS  , &x_left, &x_wide, &x_bott, &x_tall, NULL);                         <* 
    *>    DEBUG_GRAF   yLOG_complex ("keys"      , "%4dl, %4dw, %4db, %4dt", x_left, x_wide, x_bott, x_tall);   <* 
    *>    XFillRectangle (YX_DISP, x_bounds, x_context, x_left, w_tall - x_bott - x_tall, x_wide, x_tall);      <* 
    *> }                                                                                                        <*/
   /*---(main-related masks)-------------*/
   /*> yVIKEYS_view_bounds  (YVIKEYS_MAIN, &x_min, NULL, NULL, NULL, &y_max, NULL);   <* 
    *> yVIKEYS_source_mask   (&x_bounds, &x_context, x, 0, x_min, y_max);             <* 
    *> yVIKEYS_menu_mask     (&x_bounds, &x_context, x, 0, x_min, y_max);             <* 
    *> yVIKEYS_hist_mask     (&x_bounds, &x_context, x, 0, x_min, y_max);             <* 
    *> yVIKEYS_note_mask     (&x_bounds, &x_context, x, 0, x_min, y_max);             <*/
   /*---(set mask)-----------------------*/
   XShapeCombineMask (YX_DISP, YX_BASE, ShapeBounding, 0, 0, x_bounds, ShapeSet);
   /*---(free)---------------------------*/
   XFreePixmap (YX_DISP, x_bounds);
   XFreeGC     (YX_DISP, x_context);
   /*---(complete)-----------------------*/
   DEBUG_GRAF   yLOG_exit     (__FUNCTION__);
   return 0;
}


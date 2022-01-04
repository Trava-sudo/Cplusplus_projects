#ifndef PASSE_PAR_TOUT
#define PASSE_PAR_TOUT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/utsname.h>
#include <fcntl.h>
#include <unistd.h>
#include <malloc/malloc.h>
#include <math.h>
#ifdef __cplusplus
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#endif
#include <X11/Intrinsic.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>
#include <X11/Shell.h>
#include <X11/StringDefs.h>
#ifdef GL
#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#endif
#define BOTTONE_SCORREVOLE -1
#define BOTTONE_ATTIVATORE 0
#define BOTTONE_INTERRUTTORE 1
#define BOTTONE_SELETTORE  2
#define BOTTONE_MULTISELETTORE 3
#define BOTTONE_TEXTFIELD 4
#define BOTTONE_INPUT_FLOAT 5
#define BOTTONE_INPUT_INT 6
#define BOTTONE_INPUT_CHARS 7
#define ACCESO 1
#define SPENTO 0
#define MASSIMO_NUMERO_FINESTRE 32
#define MAXDISPLAYS 8
#define NERO    0
#define ROSSO   1
#define VERDE   2
#define BLU     4 
#define GIALLO  3 
#define CIANO   6 
#define MAGENTA 5 
#define BIANCO  7
#define COLORA_RIQUADRO  0x20000000
#define RIQUADRO_OPACO   0x40000000
#define RICHIEDO_LEGENDA 0x800000
#define RIDUCI_FONTE     0x10000000
#define GRIGIO_2  2
#define GRIGIO_4  4
#define GRIGIO_8  8
#define COLORE_1 -1
#define COLORE_2 -2
#define COLORE_4 -4
#define COLORE_8 -8
#define PUNTINO         0
#define PUNTONE         1
#define TONDINO_VUOTO   2
#define TONDINO_PIENO   3
#define QUADRETTO_VUOTO 4
#define QUADRETTO_PIENO 5
#define ROMBETTO_VUOTO  6
#define ROMBETTO_PIENO  7
#define ASTERISCO       8
#define STELLINA_VUOTA  9
#define STELLINA_PIENA 10
#define CROCETTA       11
#define CROCE_S_ANDREA 12
#define QUADRO_E_CROCE 13
#define TRIANGOLO_VUOTO 14
#define TRIANGOLO_PIENO 15
#define NABLA_VUOTO 16
#define NABLA_PIENO 17
#define PENTAGONO_VUOTO 18
#define PENTAGONO_PIENO 19
#define PENTAGONO_DRITTO_VUOTO 20
#define PENTAGONO_DRITTO_PIENO 21
#define ESAGONO_VUOTO 22
#define ESAGONO_PIENO 23
#define ESAGONO_RUOTATO_VUOTO 24
#define ESAGONO_RUOTATO_PIENO 25
#define OTTAGONO_VUOTO 26
#define OTTAGONO_PIENO 27
#define STELLA_DI_DAVIDE_VUOTA 28
#define STELLA_DI_DAVIDE_PIENA 29
#define	NIDO_D_APE_VUOTO  30
#define	NIDO_D_APE_PIENO  31
#define CIFRA_0        48
#define CIFRA_1        49
#define CIFRA_2        50
#define CIFRA_3        51
#define CIFRA_4        52
#define CIFRA_5        53
#define CIFRA_6        54
#define CIFRA_7        55
#define CIFRA_8        56
#define CIFRA_9        57
#define	CUSTOM_VUOTO   42
#define	CUSTOM_PIENO   43
#define DA_QUI_A_SINISTRA_ALTO  1
#define DA_QUI_A_DESTRA_BASSO   2
#define DA_QUI_A_DESTRA_ALTO    3
#define DA_QUI_A_SINISTRA_BASSO 4
#define DA_SINISTRA_ALTO  5
#define DA_DESTRA_ALTO    6
#define DA_DESTRA_BASSO   7
#define DA_SINISTRA_BASSO 8
#define FRECCIA_ALTO 127
#define FRECCIA_DESTRA 128
#define FRECCIA_BASSO 129
#define FRECCIA_SINISTRA 130
#define FINESTRA_DOPPIA 0x400000
#define CONTROL_L 0x100
#define CONTROL_R 0x200
#define CONTROL_A 0x300
#define ALT_L 0x400
#define ALT_R 0x800
#define ALT_A 0xc00
#define EVENTO_MOUSE 0
#define EVENTO_ENTER 999
#define ADERISCI_ASSE_SINISTRO 0x40000000
#define OMBREGGIA_FINESTRA 0x80000000
#define ATTIVA_TRASPARENZA 0x800
#define SFONDO_OPACO 1
#define ORDINE_NATURALE 0xffffffff
#define A_RITROSO 0xefffffff
#define A_CASACCIO 0xdfffffff
#define FOTOGRAMMA_PER_FOTOGRAMMA 0xcfffffff
#define FOTOGRAMMA_PER_FOTOGRAMMA_A_ROVESCIO 0xbfffffff
#define DA_FOTOGRAMMA_A_FOTOGRAMMA 0xafffffff
#define ASPETTA_ORDINI 0x9fffffff
#define versione_corrente_passe_par_tout "10 luglio 2018"
#define COMANDO_INTERPRETE "gs -sDEVICE=nullpage"
#define RISALTO   0x100
#define STOP      0x200
#define PLAY      0x300
#define REPLAY    0x400
#define FRECCE    0x500
#define STELLA    0x600
#define MOVIOLA   0x700
#define REMOVIOLA 0x800
#define TIMELINE  0x900
#define SFONDO    0xa00
#define START     0xb00
#define END       0xc00
#define CORRENTE  0xd00
#define CURSORE   0xe00
#define XSTOP     0xf00
typedef enum
 {slider = -1, attivatore, interruttore, selettore, multiselettore,
  textfield, inputwidget, inputIwidget, inputSwidget} _tipo_bottone;
typedef struct
 {Window window; Widget widget, shell; GC contesto_grafico;
  Drawable drawable; Pixmap pixmap;
  int offset[2]; Dimension dimen[2];} Data_Win;
typedef struct
 {Display *display; Colormap colormap; XtAppContext contesto;
  Visual *visual; unsigned int depth;} Data_X;
typedef enum {none, press, drag, release} _ragione;
typedef struct
 {int index[2]; signed char click; double valore; _tipo_bottone tipo;
  _ragione ragione;} _dati_widget;
typedef struct
  {Pixmap tile; int offa[2]; unsigned int dim[2];
   Boolean trasparente, hidden, *shape; void (*f)(int*, char*);} _Tile;
#ifdef __cplusplus
extern "C" {
#endif
extern
Data_Win *m_get_window_info(int *);
extern
Data_X *m_get_server_info();
extern
int m_prestartg(int *), m_prestartg_(int *), m_startg(char *, int *, int *), m_map_fonts_(int *),
    m_startg_(char *, int *, int *), m_use_as_pixmap(int *, int *), m_map_fonts(int *),
    m_close_display(char *), m_close_display_(char *), m_polygon_int(int[],int*),
    m_access_server(const char *), m_access_server_(const char *), m_polygon_int_(int[],int*),
    m_select_display(char *, int *), m_select_display_(char *, int *), m_opacity(double *),
    m_select_display_by_number(int *), m_select_display_by_number_(int *),
    m_shutdown_event_handler(int *), m_shutdown_event_handler_(int *), m_how_join_lines_(int*,int*),
    m_restart_event_handler(int *), m_restart_event_handler_(int *), m_how_join_lines(int*,int*),
    m_add_GL_keyevent_handlers(int *, int *, void (*[])(void*, int*,int*), void *[]),
    m_add_GL_keyevent_handlers_(int *, int *, void (*[])(void*, int*, int*), void *[]),
    m_set_GL_angle(int *, float *), m_set_GL_angle_(int *, float *),
    m_refreshmenu(int *), m_refreshmenu_(int *),
    m_save_pixmap_to_load(int *, char *, int *), m_save_pixmap_to_load_(int *, char *, int *),
    m_use_as_Lego(int *, int *, double *), m_use_as_Lego_(int *, int *, double *),
    m_use_as_lego(int *, int *, double *), m_use_as_lego_(int *, int *, double *),
    m_draw_Lego(int *, int *, double [][2], int *, double *), m_toggle_mouse_save_right(int *),
    m_draw_Lego_(int *, int *, double [][2], int *, double *), m_toggle_mouse_save_right_(int *),
    m_clear_Lego(int *), m_clear_Lego_(int *), m_toggle_pointer_motion(int *), m_opacity_(double *),
    m_show_pixmap(int *), m_show_pixmap_(int *), m_remove_pixmap(int *), m_remove_pixmap_(int *),
    m_draw_lego(int *, int *, double [][2], int *, double *), m_mouse_int(int *),
    m_draw_lego_(int *, int *, double [][2], int *, double *), m_mouse_int_(int *),
    m_mouse_int_from_any(int *), m_mouse_int_from_any_(int *), m_mouse_from_any(double *),
    m_clear_lego(int *), m_clear_lego_(int *),  m_toggle_pointer_motion_(int *), m_text_ext(char *, int *),
    m_inquire_monitor_size(int *, int *), m_inquire_monitor_size_(int *, int *), m_text_ext_(char *, int *),
    m_use_as_pixmap_(int *, int *), m_save_pixmap(int *, char *), m_save_pixmap_(int *, char *),
    m_load_external_pixmap(int *, char *, int *), m_load_external_pixmap_(int *, char *, int*),
    m_hide_tiles(int *, int *), m_hide_tiles_(int *, int *),
    m_unhide_tiles(int *, int *), m_unhide_tiles_(int *, int *),
    m_unload_tiles(int *, int *), m_unload_tiles_(int *, int *),
    m_move_tiles(int *, int *, int *), m_move_tiles_(int *, int *, int *),
    m_clear_pixmap(int *, int *), m_clear_pixmap_(int *, int *), m_recover_font(int *, int *),
    m_change_pixmap_background(int *, int *), m_change_pixmap_background_(int *, int *),
    m_window(int *, int *, ...), m_window_(int *, int *, ...), m_get_current_pointer_position(int *, int *),
    m_window_GL(int *, int *, char *, int(int*), int(void*), void*),
    m_window_GL_(int *, int *, char *, int(int*), int(void*), void*),
    m_snap_shadow(int *, int *), m_snap_shadow_(int *, int *), m_get_current_pointer_position_(int *, int *),
    m_font(int *, int *, int *, ...), m_font_(int *, int *, int *, ...), m_mouse_from_any_(double *),
    m_font_by_name(int *, char *), m_font_by_name_(int *, char *), m_get_current_pointer_coordinates(int *, double *),
    m_reset_font(int *), m_reset_font_(int *), m_remove_color(int *), m_remove_color_(int *),
    m_get_current_pointer_coordinates_(int *, double *),  m_recover_font_(int *, int *),
    m_add_my_own_redraw(int *, int (*)(XtPointer), XtPointer), m_ellipse(double[], double[], int *),
    m_add_my_own_redraw_(int *, int (*)(XtPointer), XtPointer), m_ellipse_(double[], double[], int *),
    m_add_my_own_event_handler(int *, XtEventHandler (*)(Widget, XtPointer, XEvent *, Boolean *), XtPointer),
    m_add_my_own_event_handler_(int *, XtEventHandler (*)(Widget, XtPointer, XEvent *, Boolean *), XtPointer),
    m_add_my_own_opacity(int *, unsigned long (*)(unsigned long, unsigned long, char *), char * ),
    m_add_my_own_opacity_(int *, unsigned long (*)(unsigned long, unsigned long, char *), char * ),
    m_toggle_message(), m_toggle_message_(), m_insert_color(double *, double *, double *, int *),
    m_sound_message(char *), m_sound_message_(char *), m_move_pointer(int *, double *, int *),
    m_place_window(int [], char *), m_place_window_(int [], char *), m_move_pointer_(int *, double *, int *),
    m_save_window(int *, char *), m_save_window_(int *, char *), m_move_pointer_int(int *, int *),
    m_load_window(int *, char *), m_load_window_(int *, char *), m_move_pointer_int_(int *, int *),
    m_endg(), m_endg_(), m_how_clip(int *), m_how_clip_(int *), m_close(int *), m_close_(int *),
    m_select(int *), m_select_(int *), m_which_window(int *), m_which_window_(int *), marco_ps_(double[], double[], int*, double*, int*),
    m_which_frame(int *), m_which_frame_(int *), m_insert_color_(double *, double *, double *, int *),
    m_move(double *), m_move_(double *), m_point(double *), m_point_(double *), marco_ps(double[], double[], int*, double*, int*),
    m_line(double *), m_line_(double *), m_polygon(double[], int *), m_polygon_(double[], int *),
    m_ellypse(double[], double[], int *), m_ellypse_(double[], double[], int *), m_arc(double[], double[], double[], int*),
    m_target(double *, double **, int **, char ***), m_change_sectors(int*,int*,double**),
    m_target_(double *, double **, int **, char ***), m_change_sectors_(int*,int*,double**),
    m_target_int(int *, int **, int **, char ***), m_change_ptr_(int*,int*,int*,void*),
    m_set_textfield_button(int *, int*, char*), m_set_textfield_button_(int *, int*, char*),
    m_target_int_(int *, int **, int **, char ***), m_change_ptr(int*,int*,int*,void*),
    m_widget_loop(double*, int*, char[]), m_widget_loop_(double*, int*, char[]),
    m_menu(int *, char *, int *, int **, char **, double ***, int(**[])(void *,void*), void **[]), m_manage_button(int *, int *),
    m_menu_(int *, char *, int *, int **, char **, double ***, int(**[])(void *,void*), void **[]),  m_manage_button_(int *, int *),
    m_mouse(double *), m_mouse_(double *), m_insert_color_hcv(double *, double *, double *, int *, int *, double[]),
    m_fill_pixmap(int *, double *, int *), m_fill_pixmap_(int *, double *, int *), m_arc_(double[], double[], double[], int*),
    m_fill_int_pixmap(int *, int *, int *), m_fill_int_pixmap_(int *, int *, int *),
    m_log_scales(int *), m_log_scales_(int *), m_insert_color_hcv_(double *, double *, double *, int *, int *, double[]),
    m_get_color(int *, double [], int [], double *, double *, double *), m_load_tiles(int *, char*[], int *[]),
    m_get_color_(int *, double [], int [], double *, double *, double *), m_load_tiles_(int *, char*[], int *[]),
    m_load_diaphanous_tiles(int *, char*[], int *[], char *, void(*[])(int*, char*)),
    m_load_diaphanous_tiles_(int *, char*[], int *[], char *, void(*[])(int*, char*)),
    m_frame(double *, double *, double *, double *), m_replace_color(int *, int *, double *, double *, double *), m_replace_color_(int *, int *, double *, double *, double *),
    m_frame_(double *, double *, double *, double *), m_line_int(int *), m_line_int_(int *),
    m_multiframe(int *, int *, int [], double *), m_multiframe_(int *, int *, int [], double *),
    m_select_frame(int *, int *), m_select_frame_(int *, int *), m_point_int(int*), m_point_int_(int*),
    m_loop_for_events(int *, int *), m_loop_for_events_(int *, int *), m_ellypse_int(int[], int[], int *),
    m_wait_for_events(int *), m_wait_for_events_(int *), m_move_int(int *), m_move_int_(int *),
    m_modified_key_events(int *, int *), m_modified_key_events_(int *, int *), m_arc_int(int[], int[], int[], int*),
    m_wait_for_microseconds(int *), m_wait_for_microseconds_(int *), m_ellypse_int_(int[], int[], int *),
    m_new_color(double *, double *, double *), m_new_color_(double *, double *, double *),
    m_new_color_hcv(double *, double *, double *, int *, double[]), m_arc_int_(int[], int[], int[], int*),
    m_new_color_hcv_(double *, double *, double *, int *, double[]), m_set_size_symbol(int *),
    m_clear(int *), m_clear_(int *), m_symbol(int *), m_symbol_(int *), m_set_size_symbol_(int *),
    m_size_symbol(double *), m_size_symbol_(double *), m_color(int *), m_color_(int *),
    m_reset_size_symbol(), m_reset_size_symbol_(), m_color_frame(int *, int *), m_ellipse_int(int[], int[], int *),
    m_legend(int *, char *[], double *, int *, int *), m_legend_(int *, char *[], double *, int *, int *),
    m_move_legend(int *, double *, int *), m_move_legend_(int *, double *, int *),  m_ellipse_int_(int[], int[], int *),
    m_recolor_legend(int *, int *), m_recolor_legend_(int *, int *), m_vector_int_(int*, int*, int*),
    m_hide_legend(int *), m_hide_legend_(int *), m_unhide_legend(int *), m_unhide_legend_(int *),
    m_destroy_legend(int *), m_destroy_legend_(int *), m_color_frame_(int *, int *),
    m_dash(int *), m_dash_(int *), m_thickness(int *), m_thickness_(int *), m_vector_int(int*, int*, int*),
    m_vector(double *, double *, double *), m_vector_(double *, double *, double *),
    m_text(char *, double *), m_text_(char *, double *), m_text_int(char *, int *), m_text_int_(char *, int *),
    m_write_photogram(int *, char *, int *), m_write_photogram_(int *, char *, int *),  m_quote_(int *, char *, char *, char *, int *),
    m_write_owned_photogram(int *, char *, int *), m_write_owned_photogram_(int *, char *, int *),
    m_mount_film(char *, char *, int *), m_mount_film_(char *, char *, int *), m_quote(int *, char *, char *, char *, int *),
    m_mount_owned_film(const char *, const char *, int *), m_mount_owned_film_(const char *, const char *, int *),
    m_animate(const char *, unsigned int *, unsigned int *), m_animate_(const char *, unsigned int *, unsigned int *),
    minizio_ps(char *, double *, double *), minizio_ps_(char *, double *, double *), mfine_ps(),
    mfine_ps_(), mmarca_ps(int *), mmarca_ps_(int *),
    mmarca_stringa_ps(const char *, int *), mmarca_stringa_ps_(const char *, int *),
    mcancella_ps(int *, int *, int *), mcancella_ps_(int *, int *, int *),
    mrimuovi_ps(const char *, const char *, int *), mrimuovi_ps_(const char *, const char *, int *),
    mpoligono_ps(double[], int *), mpoligono_ps_(double[], int *),
    mellisse_ps(double[], double[], int *, int *),mellisse_ps_(double[], double[], int *, int *),
    mbersaglio_ps(double *, double **, int **, char ***),
    mbersaglio_ps_(double *, double **, int **, char ***),
    mrapporto_assi(int *, double *), mrapporto_assi_(int *, double *),
    mchiudi_ps(char *), mchiudi_ps_(char *), mindirizza_ps(char *), mindirizza_ps_(char *),
    mqualefile_ps(int *, int *, char *), mqualefile_ps_(int *, int *, char *),
    mscalelogaritmiche_ps(int *), mscalelogaritmiche_ps_(int *), m_reset_frame(double *, char*, int *),
    mfinestra_ps(double *, double *, double *, double *),  m_reset_frame_(double *, char*, int *),
    mfinestra_ps_(double *, double *, double *, double *),
    mlegenda_ps(char *[], double *, int *, int *),
    mlegenda_ps_(char *[], double *, int *, int *),
    mdistruggi_legenda(int *), mdistruggi_legenda_(int *),
    mfattore_scala_ps(int *, int *), mfattore_scala_ps_(int *, int *),
    mpaginaA4_ps(), mpaginaA4_ps_(), mgiunzione_linee_ps(int*),
    mpaginaa4_ps(), mpaginaa4_ps_(), mgiunzione_linee_ps_(int*),
    msfondo_ps(double *, double *, double *),
    msfondo_ps_(double *, double *, double *),
    mcontorno_ps(int *), mcontorno_ps_(int *),
    mquotature_ps(int *, int *, int *, int *, int *),
    mquotature_ps_(int *, int *, int *, int *, int *),
    mdisegnaLego_ps(int *, double *, int *, double[][2], int *, double *),
    mdisegnaLego_ps_(int *, double *, int *, double[][2], int *, double *),
    mdisegnalego_ps(int *, double *, int *, double[][2], int *, double *),
    mdisegnalego_ps_(int *, double *, int *, double[][2], int *, double *),
    mquotature_con_stringhe_ps(int *, int *, int *, int *, int *, char **[]),
    mquotature_con_stringhe_ps_(int *, int *, int *, int *, int *, char **[]),
    mtratteggio_ps(int *), mtratteggio_ps_(int *),
    mfora_contorno_ps(), mfora_contorno_ps_(),
    mricontorna_ps(), mricontorna_ps_(),
    minverti_messaggio(), minverti_messaggio_(),
    msuono_messaggio(char *), msuono_messaggio_(char *),
    mspessore_linea_ps(double *), mspessore_linea_ps_(double *),
    mgrandezza_simbolo_ps(double *), mgrandezza_simbolo_ps_(double *),
    mripristina_grandezza_simbolo_ps(), mripristina_grandezza_simbolo_ps_(),
    msimbolo_ps(int *), msimbolo_ps_(int *), mmuovi_ps(double *), mmuovi_ps_(double *),
    mfreccia_ps(double *, double *, double *, int *),
    mfreccia_ps_(double *, double *, double *, int *),
    mlinea_ps(double *), mlinea_ps_(double *), mcolore_ps(int *), mcolore_ps_(int *),
    mcolore_rgb_ps(double *, double *, double *, int *),
    mcolore_rgb_ps_(double *, double *, double *, int *),
    mcolore_hcv_ps(double *, double *, double *, int *),
    mcolore_hcv_ps_(double *, double *, double *, int *),
    mpunto_ps(double *), mpunto_ps_(double *),
    mtitoli_ps(char *, char *, char *, int *),
    mtitoli_ps_(char *, char *, char *, int *),
    morigine_ps(double *, double *, double *), morigine_ps_(double *, double *, double *),
    mscrivi_quasi_come_tex_ps(char[], double[], double *),
    mscrivi_quasi_come_tex_ps_(char[], double[], double *),
    mscrivi_quasi_come_TeX_ps(char[], double[], double *),
    mscrivi_quasi_come_TeX_ps_(char[], double[], double *),
    mscrivi_ps(char *, double *, double *), mscrivi_ps_(char *, double *, double *),
    mcercafonte_per_nome_ps(char *, char *, double *),
    mcercafonte_per_nome_ps_(char *, char *, double *),
    mfonte_ps(int *, int *, double *), mfonte_ps_(int *, int *, double *),
    mclasse_bitmap(int *, int *), mclasse_bitmap_(int *, int *),
    mcancella_bitmap(int *), mcancella_bitmap_(int *),
    minizia_bitmap(int *, int *), minizia_bitmap_(int *, int *),
    mdistruggi_bitmap(int *), mdistruggi_bitmap_(int *),
    mseleziona_bitmap(int *), mseleziona_bitmap_(int *),
    mcambia_bitmap(int *, int *, int *, int *), mcambia_bitmap_(int *, int *, int *, int *),
    mcancella_colore_bitmap(int *, int *), mcancella_colore_bitmap_(int *, int *),
    mcodifica_colore_bitmap(double *, double *, double *, int *),
    mcodifica_colore_bitmap_(double *, double *, double *, int *),
    mcodifica_colore_hcv_bitmap(double *, double *, double *, int *),
    mcodifica_colore_hcv_bitmap_(double *, double *, double *, int *),
    mtrasforma_bitmap(int *, double *, double *, int *),
    mtrasforma_bitmap_(int *, double *, double *, int *),
    mstampa_bitmap_ps(int *, int *), mstampa_bitmap_ps_(int *, int *),
    mimpagina(int *, char**, double *, double *, double *, double *, char *, int *),
    mimpagina_(int *, char**, double *, double *, double *, double *, char *, int *);
extern void
     m_multi_threaded_program(), m_multi_threaded_program_(),
     m_modify_bezier(int *), m_modify_bezier_(int *), mtrasforma_ps(double*, int*, int*),
     massegna_bounding_box_ps(int *), massegna_bounding_box_ps_(int *),
     mricolora_legenda(int *, int *, char *), mricolora_legenda_(int *, int *, char *),
     mrivela_legenda(int *, char *), mrivela_legenda_(int *, char *),
     mnascondi_legenda(int *, char *), mnascondi_legenda_(int *, char *),
     msposta_legenda(int *, double *, int *, char *),
     msposta_legenda_(int *, double *, int *, char *),
     m_flush(), m_flush_(), m_redraw(int *), m_redraw_(int *);
extern unsigned char * m_remap_colors(unsigned char *), * m_remap_colors_(unsigned char *);
extern char
     *m_get_textfield_button(int *, int*), *m_get_textfield_button_(int *, int*),
     *m_get_button_status(int *, int*), *m_get_button_status_(int *, int*),
     *m_open_display(const char *), *m_open_display_(const char *), *m_which_display(int *), *m_which_display_(int *),
     *mversione_passe_par_tout(), *mversione_passe_par_tout_(),
     m_string_for_events(char *, int *), m_string_for_events_(char *, int *),
     *mcomponi_accento(char *, char *), *mcomponi_accento_(char *, char *);
extern double
     * m_curve(double *, int *), * m_curve_(double *, int *),
     * m_curve_int(int *, int *), * m_curve_int_(int *, int *),
     * mcurva_ps(double *, int *), * mcurva_ps_(double *, int *);
#ifdef __cplusplus
}
using namespace std;
#endif
#endif

/* See LICENSE file for copyright and license details. */

/* appearance */
static const char *fonts[] = {
	"Ohsnap.Icons:size=14"
};
static const char dmenufont[]       = "Ohsnap.Icons:size=14";

//"STOCK" Design.
static const char normbordercolor[] = "#353636";
static const char normbgcolor[]     = "#353636";
static const char normfgcolor[]     = "#fafbfc";
static const char selbordercolor[]  = "#fafbfc";
static const char selbgcolor[]      = "#353636";
static const char selfgcolor[]      = "#fafbfc";

#define NUMCOLORS 10
static const char colors[NUMCOLORS][10][10] = {
  // border          foreground background
  { normbordercolor, "#fafbfc", "#353636" }, // 1 = normal (grey on black)
  { selbordercolor,  "#fafbfc", "#353636" }, // 2 = new selected
  { selbordercolor,  "#353636", "#fafbfc" }, // 3 = urgent (black on yellow)
  { normbordercolor, "#eff2f4", "#353636" }, // 4 = red on black
  { normbordercolor, "#e4e9ec", "#353636" }, // 5 = green on black
  { normbordercolor, "#d9dee2", "#4b5053" }, // 6 = orange on black
  { normbordercolor, "#c9d0d5", "#353636" }, // 7 = yellow on darkgrey
  { normbordercolor, "#b6bdc2", "#353636" }, // 8 = blue on darkgrey
  { normbordercolor, "#9ba0a3", "#4b5053" }, // 9 = magenta on darkgrey
  { normbordercolor, "#787d80", "#4b5053" }, // A = cyan on darkgrey
};

static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int extrabar           = 1;        /* 0 means no extra bar */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Firefox",  NULL,       NULL,       0 << 1,       0,           -1 },
	{ "URxvt",    NULL,       NULL,       0 << 2,       0,           -1 },
	{ "Atom",     NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Wireshark",NULL,       NULL,       1 << 6,				0,					 -1 },
	{ "Transmission", NULL,   NULL,       1 << 5,       0,           -1 },
	{ "mpv",      NULL,       NULL,       1 << 4,       0,           -1 },
	{ "VirtualBox", NULL,     NULL,       1 << 7,       0,           -1 },
	{ "PopcornTime", NULL,    NULL,       1 << 4,       0,           -1 },
	{ "ThunderBird", NULL,    NULL,       1 << 2,       0,           -1 },
	{ "HexChat",    NULL,     NULL,       0 << 3,       1,           -1 },
	{ "Discord",    NULL,     NULL,       0 << 3,       1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "gaplessgrid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[ N ]",      NULL },    /* first entry is default */
	{ "[ T ]",      tile },    /* no layout function means floating behavior */
	{ "[ M ]",      monocle },
	{ "[ B ]",      bstack },
	{ "[ H ]",      bstackhoriz },
	{ "[ G ]",	gaplessgrid },
};

/* tagging */
static const char *tags[] = {
	/* name       layout           mfact    nmaster */
	{ "web", 			&layouts[1],		 -1,			-1		},
	{ "trm",      &layouts[4],		 0.55,    -1    },
	{ "soc", 			&layouts[0],		 -1,      -1    },
	{ "dev", 			&layouts[5],     0.85,    -1    },
	{ "med",      &layouts[2],     1.00,    -1    },
	{ "dum",      &layouts[0],     -1,      -1    },
	{ "pen",      &layouts[1],     0.55,    -1    },
	{ "win",      &layouts[3],     0.33,    -1    },
	{ "msc",      &layouts[0],     -1,      -1    },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion.
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
Currently uneeded but I keep it anyway. */

/* dwm Stuff */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
/* CLI Stuff */
static const char *termcmd[]  = { "urxvtc", NULL };
static const char *ranger[]   = { "urxvtc", "-e", "ranger", NULL };
static const char *htop[]     = { "urxvtc", "-e", "htop", NULL };
static const char *ncmpcpp[]  = { "urxvtc", "-e", "ncmpcpp", NULL };
static const char *cava[]     = { "urvxtc", "-e", "cava", NULL };
static const char *tmpterm[]  = { "trxvt", NULL }; /* own made script to a terminal widget.
/* GUI Stuff */
static const char *firefox[]  = { "firefox", NULL };
static const char *thunar[]   = { "thunar", NULL };
static const char *trans[]    = { "transmission-gtk", NULL };
static const char *wire[]     = { "wireshark-gtk", NULL };
static const char *lxrandr[]  = { "lxrandr", NULL };
static const char *pacmac[]   = { "pamac-updater", NULL };
static const char *popcorn[]  = { "popcorntime", NULL };
static const char *vb[]       = { "vb", NULL };
/* Media Stuff */
static const char *mpdnext[]  = { "mpc", "next", NULL };
static const char *mpdprev[]  = { "mpc", "prev", NULL };
static const char *mpdtogg[]  = { "mpc", "toggle", NULL };
/* Hardware Stuff */
static const char *volup[]    = { "amixer", "sset", "Master", "3dB+", NULL };
static const char *voldn[]    = { "amixer", "sset", "Master", "3dB-", NULL };
static const char *volmt[]    = { "amixer", "sset", "Master", "toggle", NULL };
static const char *brtup[]    = { "xbacklight", "+1", NULL };
static const char *brtdn[]    = { "xbacklight", "-1", NULL };
static const char *arpln[]    = { "aeroplan-mine", NULL }; /* own made script with zenity to control wireless stuff such as bluetooth.
/* System Stuff */
static const char *syspend[] = { "suspend", NULL };
static const char *sysreb[]  = { "reboot", NULL };
static const char *sysdown[] = { "shutdown", '-h', 'now', NULL };
static const char *syslock[] = { "slock", NULL };

#include "moveresize.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_F2,      spawn,         {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_r,      spawn,          {.v = ranger } },
	{ MODKEY,                       XK_h,      spawn,          {.v = htop } },
	{ MODKEY,                       XK_n,      spawn,          {.v = ncmpcpp } },
	{ MODKEY,                       XK_c,      spawn,          {.v = cava } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = tmpterm } },
	{ MODKEY, 											XK_f,      spawn,          {.v = firefox } },
	{ MODKEY,												XK_p,      spawn,          {.v = thunar } },
	{ MODKEY,                       XK_o,      spawn,          {.v = trans } },
	{ MODKEY,                       XK_w,      spawn,          {.v = wire } },
	{ MODKEY,                       XK_x,      spawn,          {.v = lxrandr } },
	{ MODKEY,												XK_u,      spawn,          {.v = pacmac } },
	{ MODKEY,                       XK_m,      spawn,          {.v = popcorn } },
	{ MODKEY,                       0x1008FF13,spawn,          {.v = mpdnext } },
	{ MODKEY,                       0x1008FF11,spawn,          {.v = mpdprev} },
	{ MODKEY,                       0x1008FF12,spawn,          {.v = mpdtogg } },
	{ 0,                            0x1008FF13,spawn,          {.v = volup } },
	{ 0,                            0x1008FF11,spawn,          {.v = voldn } },
	{ 0,                            0x1008FF12,spawn,          {.v = volmt } },
	{ 0,                            0x1008FF02,spawn,          {.v = brtup } },
	{ 0,                            0X1008FF03,spawn,          {.v = brtdn } },
	{ 0,                            0x1008FFA9,spawn,          {.v = arpln } },
	{ MODKEY,                       XK_v,      spawn,          {.v = vb } },
	{ MODKEY|ShiftMask,             XK_x,      spawn,          {.v = syslock } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = syspend } },
	{ MODKEY|ShiftMask,             XK_q,      spawn,          {.v = sysdown } },
	{ MODKEY|ShiftMask,             XK_r,      spawn,          {.v = sysreb } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_b,      toggleextrabar, {0} },
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,							XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_b,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_h,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[0]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = firefox } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

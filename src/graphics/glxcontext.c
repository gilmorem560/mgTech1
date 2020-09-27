/*
 * glxcontext - OpenGL X11 context
 */
#include "glxcontext.h"

void glx_init(void);
void glx_free(void);
void glx_draw(void);

const glxcontext gfx_context = {
	&glx_init
	,&glx_free
	,&glx_draw
	,&gl_clearblack
	,&gl_clearscreen
	,&glPushMatrix
	,&glPopMatrix
	,&gl_position
};

/* X11 variables */
Display *dpy;
static XVisualInfo *vis;
static Window win;
static Cursor cursor;
static Window root;
static int screen_number;

/* GLX variables */
static GLXFBConfig *config;
static GLXContext context;
static GLXWindow window;

/* glx_init - acquire GLX resources */
void glx_init(void)
{
	XSetWindowAttributes attrs;
	XColor cursor_color = { 0, 0, 0, 0, 0, 0 };
	Pixmap cursor_pixmap;
	const char null_bitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int major, minor;
    int config_count;
    int attrib_list[] = {
        GLX_X_RENDERABLE    ,True
        ,GLX_DRAWABLE_TYPE  ,GLX_WINDOW_BIT
        ,GLX_RENDER_TYPE    ,GLX_RGBA_BIT
        ,GLX_X_VISUAL_TYPE  ,GLX_TRUE_COLOR
        ,GLX_RED_SIZE       ,8
        ,GLX_GREEN_SIZE     ,8
        ,GLX_BLUE_SIZE      ,8
        ,GLX_ALPHA_SIZE     ,8
        ,GLX_DEPTH_SIZE     ,24
        ,GLX_STENCIL_SIZE   ,8
        ,GLX_DOUBLEBUFFER   ,True
        ,None
    };
    dpy = NULL;
    vis = NULL;
    
    /* open X display */
    dpy = XOpenDisplay(NULL);
        if (dpy == NULL) {
            fputs("glxinit: could not open X11 display", stderr);
            exit(EXIT_FAILURE);
        }
    
    /* query GLX version */
    if (!glXQueryVersion(dpy, &major, &minor)) {
        fputs("glxinit: could not query version", stderr);
        XCloseDisplay(dpy);
        exit(EXIT_FAILURE);
    }
    
    /* determine default screen */
    screen_number = XDefaultScreen(dpy);
	
	if (g_fullscreen) {
		/* get resolution */
		g_xres = XDisplayWidth(dpy, screen_number);
		g_yres = XDisplayHeight(dpy, screen_number);
	}
	else {
		g_xres = 640;
		g_yres = 480;
	}
	
	/* set aspect ratio */
	g_aspect_ratio = (double) g_xres / (double) g_yres;
    
    /* retrieve root window */
    root = XRootWindow(dpy, screen_number);
    
    /* get framebuffer config */
    config = glXChooseFBConfig(dpy, screen_number, attrib_list, &config_count);
        if (config == NULL) {
            fputs("glxinit: could not retrieve fb config", stderr);
            XCloseDisplay(dpy);
            exit(EXIT_FAILURE);
        }
    
    /* retrieve X visual info */
    vis = glXGetVisualFromFBConfig(dpy, *config);
        if (vis == NULL) {
            fputs("glxinit: could not retrieve visual", stderr);
            XFree(config);
            XCloseDisplay(dpy);
            exit(EXIT_FAILURE);
        }
    
    /* create context */
    context = glXCreateContext(dpy, vis, NULL, True);
        if (context == NULL) {
            fputs("glxinit: could not retrieve context", stderr);
            XFree(vis);
            XFree(config);
            XCloseDisplay(dpy);
            exit(EXIT_FAILURE);
        }
    
    /* set input events */
    attrs.event_mask = KeyPressMask | KeyReleaseMask | StructureNotifyMask | PointerMotionMask;
	
	attrs.override_redirect = g_fullscreen ? True : False;
    
    /* create window */
    win = XCreateWindow(
        dpy                 /* Display *display */
        ,root               /* Window parent */
        ,0                  /* int x */
        ,0	                /* int y */
        ,g_xres             /* unsigned int width */
        ,g_yres             /* unsigned int height */
        ,1                  /* unsigned int border_width */
        ,CopyFromParent     /* int depth */
        ,CopyFromParent     /* unsigned int class */
        ,vis->visual        /* Visual *visual */
        ,CWEventMask | CWOverrideRedirect /* unsigned long valuemask */
        ,&attrs);             /* XSetWindowAttributes *attributes */
    
    /* create on-screen rendering area */
    window = glXCreateWindow(dpy, *config, win, NULL);
	
	/* create invisible cursor pixmap */
	cursor_pixmap = XCreateBitmapFromData(dpy, win, null_bitmap, 8, 8);
	
	/* create custom (invisible) cursor - modes must implement cursors */
	cursor = XCreatePixmapCursor(dpy, cursor_pixmap, cursor_pixmap, &cursor_color, &cursor_color, 0, 0);
	
	/* free pixmap now that we're done */
	XFreePixmap(dpy, cursor_pixmap);
	
	/* associate it */
	XDefineCursor(dpy, win, cursor);
    
    /* associate context to window */
    if (!glXMakeCurrent(dpy, window, context)) {
        fputs("glxinit: could not associate context with window", stderr);
        glXDestroyWindow(dpy, window);
        XDestroyWindow(dpy, win);
        glXDestroyContext(dpy, context);
        XFree(vis);
        XFree(config);
        XCloseDisplay(dpy);
        exit(EXIT_FAILURE);
    }
    
    /* set name */
    XStoreName(dpy, win, "OpenGL");
    
    /* display window */
    XMapWindow(dpy, win);
	
	/* grab keyboard */
	XGrabKeyboard(dpy, win, False, GrabModeAsync, GrabModeAsync, CurrentTime);
	
	#ifndef NDEBUG
	puts("glx_init: complete");
	#endif /* NDEBUG */
    
    return;
}

/* glx_free - free GLX resources */
void glx_free(void)
{
	XSetWindowAttributes attrs;
		attrs.override_redirect = False;
		
	/* ungrab keyboard */
	XUngrabKeyboard(dpy, CurrentTime);
	
    /* hide window */
    XUnmapWindow(dpy, win);
    
    /* dissociate context from window */
    glXMakeCurrent(dpy, None, NULL);
	
	/* return visible cursor */
	XUndefineCursor(dpy, win);
    
    /* destroy on-screen rendering area */
    glXDestroyWindow(dpy, window);
	
	/* need to return the window to the window manager to close properly */
	XChangeWindowAttributes(dpy, win, CWOverrideRedirect, &attrs);
    
    /* destroy window */
    XDestroyWindow(dpy, win);
	
	/* delete cursor */
	XFreeCursor(dpy, cursor);
    
    /* destroy context */
    glXDestroyContext(dpy, context);
    
    /* free X visual info */
    XFree(vis);
    
    /* free framebuffer config */
    XFree(config);
    
    /* close X display */
    XCloseDisplay(dpy);
	
	#ifndef NDEBUG
	puts("glx_free: complete");
	#endif /* NDEBUG */
    
    return;
}

/* glx_draw - draw the current frame */
void glx_draw(void)
{
	glXSwapBuffers(dpy, window);
	return;
}

void glx_clearblack(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}


#define SQR(x) ((x)*(x))	/* macro for square */
#ifndef M_PI			/* in case M_PI not found in math.h */
#define M_PI 3.1415927
#endif
#ifndef M_E
#define M_E 2.718282
#endif


HWND	MainWnd,hLogo;
HBITMAP hLogoImage, hGenerateImage;


#define TIMER_SECOND	1			/* ID of timer used for animation */

#define WINWIDTH 415
#define WINHEIGHT 460

UINT NewWidth, NewHeight;

// Function prototypes
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
void AddControls(HWND hWnd, int width, int height);
void LoadImages();
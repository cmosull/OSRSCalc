
#define SQR(x) ((x)*(x))	/* macro for square */
#ifndef M_PI			/* in case M_PI not found in math.h */
#define M_PI 3.1415927
#endif
#ifndef M_E
#define M_E 2.718282
#endif

#define MAXBUFFLEN 500

HWND	MainWnd,hMainLogo,hXPNeededImg;
HBITMAP hMainLogoImage,hXPNeededImage;
LPSTR InitialDirectory[MAXBUFFLEN];


#define TIMER_SECOND	1			/* ID of timer used for animation */

#define WINWIDTH 510
#define WINHEIGHT 531

UINT NewWidth, NewHeight;

int ShowXPNeededExp;
int ShowXPNeededLevel;

// Function prototypes
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
void AddInitialControls(HWND hWnd, int width, int height);
void LoadInitialImages();
void AddXPNeededControls(HWND hWnd, int width, int height);
void LoadXPNeededImages();
#include <assert.h>
typedef short Guard;
typedef int _Bool;
void sign(int x) {
{
/*TP*/ int T_x = x;
/*TP*/ Guard Ret = 0;
/*TP*/ Guard T_Ret = 0;
/*TP*/ int RetVal;
/*TP*/ int T_RetVal = RetVal;
{char *CP0;}
{
{
int sgn;
int T_sgn;
{char *CP1;}
{
{
Guard G0 = 1;
Guard T_G0 = 1;
if (!Ret) G0 = (x < 0);
if (!T_Ret) T_G0 = (T_x < 0);
{char *CP2;}
if (!Ret) if (G0) sgn = 1;
if (!T_Ret) if (T_G0) T_sgn = 1;
{char *CP3;}
if (!Ret) if (!G0) sgn = -1;
if (!T_Ret) if (!T_G0) T_sgn = -1;
{char *CP4;}
}
}
{
Guard T_G1 = 1;
if (!T_Ret) T_G1 = (T_x == 0);
if (!T_Ret) if (T_G1) T_sgn = 0;
}
{char *CP5;}
if (!Ret) RetVal = sgn;
if (!T_Ret) T_RetVal = T_sgn;
{char *CP6;}
if (!Ret) Ret = 1;
if (!T_Ret) T_Ret = 1;
{char *CP7;}
}
}
}
}




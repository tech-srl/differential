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
/*
For Correlation Point: union.sign.c:11:2
State = [
{ T_Ret = 0; Ret = 0; } <-> { RetVal - 1T_RetVal = 0; T_x - 1x = 0; }
]

*/
{char *CP0;}
{
{
int sgn;
int T_sgn;
/*
For Correlation Point: union.sign.c:16:2
State = [
{ T_Ret = 0; Ret = 0; } <-> { RetVal - 1T_RetVal = 0; T_x - 1x = 0; }
]

*/
{char *CP1;}
{
{
Guard G0 = 1;
Guard T_G0 = 1;
if (!Ret) G0 = (x < 0);
if (!T_Ret) T_G0 = (T_x < 0);
/*
For Correlation Point: union.sign.c:23:2
State = [
{ T_Ret = 0; G0 - 1T_G0 = 0; Ret = 0; - 1G0 + 1 >= 0; G0 >= 0; } <-> { RetVal - 1T_RetVal = 0; T_x - 1x = 0; }
]

*/
{char *CP2;}
if (!Ret) if (G0) sgn = 1;
if (!T_Ret) if (T_G0) T_sgn = 1;
/*
For Correlation Point: union.sign.c:26:2
State = [
{ T_Ret = 0; G0 - 1 = 0; Ret = 0; T_G0 - 1 = 0; } <-> { T_x - 1x = 0; sgn - 1 = 0; RetVal - 1T_RetVal = 0; T_sgn - 1 = 0; }
{ T_Ret = 0; T_G0 = 0; Ret = 0; G0 = 0; } <-> { RetVal - 1T_RetVal = 0; T_x - 1x = 0; }
]

*/
{char *CP3;}
if (!Ret) if (!G0) sgn = -1;
if (!T_Ret) if (!T_G0) T_sgn = -1;
/*
For Correlation Point: union.sign.c:29:2
State = [
{ T_Ret = 0; G0 - 1T_G0 = 0; Ret = 0; T_G0 >= 0; - 1T_G0 + 1 >= 0; } <-> { T_x - 1x = 0; T_sgn - 1sgn = 0; RetVal - 1T_RetVal = 0; sgn + 1 >= 0; - 1sgn + 1 >= 0; }
]

*/
{char *CP4;}
}
}
{
Guard T_G1 = 1;
if (!T_Ret) T_G1 = (T_x == 0);
if (!T_Ret) if (T_G1) T_sgn = 0;
}
/*
For Correlation Point: union.sign.c:37:2
State = [
{ T_Ret = 0; T_G1 = 0; G0 - 1T_G0 = 0; Ret = 0; G0 >= 0; - 1G0 + 1 >= 0; } <-> { T_x - 1x = 0; T_sgn - 1sgn = 0; RetVal - 1T_RetVal = 0; - 1T_sgn + 1 >= 0; T_sgn + 1 >= 0; }
{ T_Ret = 0; T_G1 - 1 = 0; Ret = 0; G0 - 1T_G0 = 0; G0 >= 0; - 1G0 + 1 >= 0; } <-> { T_x = 0; x = 0; RetVal - 1T_RetVal = 0; T_sgn = 0; sgn + 1 >= 0; - 1sgn + 1 >= 0; }
]

<-------------------
Sub-state with diff (T_sgn, sgn, ):
{ T_x = 0; x = 0; RetVal - 1T_RetVal = 0; T_sgn = 0; sgn + 1 >= 0; - 1sgn + 1 >= 0; }
------------------->
*/
{char *CP5;}
if (!Ret) RetVal = sgn;
if (!T_Ret) T_RetVal = T_sgn;
/*
For Correlation Point: union.sign.c:40:2
State = [
{ T_Ret = 0; T_G1 - 1 = 0; Ret = 0; G0 - 1T_G0 = 0; G0 >= 0; - 1G0 + 1 >= 0; } <-> { x = 0; RetVal - 1sgn = 0; T_RetVal = 0; T_sgn = 0; T_x = 0; RetVal + 1 >= 0; - 1RetVal + 1 >= 0; }
{ T_Ret = 0; T_G1 = 0; G0 - 1T_G0 = 0; Ret = 0; G0 >= 0; - 1G0 + 1 >= 0; } <-> { T_x - 1x = 0; RetVal - 1sgn = 0; T_RetVal - 1sgn = 0; T_sgn - 1sgn = 0; sgn + 1 >= 0; - 1sgn + 1 >= 0; }
]

<-------------------
Sub-state with diff (RetVal, T_RetVal, T_sgn, sgn, ):
{ x = 0; RetVal - 1sgn = 0; T_RetVal = 0; T_sgn = 0; T_x = 0; RetVal + 1 >= 0; - 1RetVal + 1 >= 0; }
------------------->
*/
{char *CP6;}
if (!Ret) Ret = 1;
if (!T_Ret) T_Ret = 1;
/*
For Correlation Point: union.sign.c:43:2
State = [
{ T_Ret - 1 = 0; T_G1 = 0; Ret - 1 = 0; G0 - 1T_G0 = 0; G0 >= 0; - 1G0 + 1 >= 0; } <-> { T_x - 1x = 0; RetVal - 1sgn = 0; RetVal - 1T_sgn = 0; RetVal - 1T_RetVal = 0; - 1RetVal + 1 >= 0; RetVal + 1 >= 0; }
{ T_Ret - 1 = 0; T_G1 - 1 = 0; Ret - 1 = 0; G0 - 1T_G0 = 0; G0 >= 0; - 1G0 + 1 >= 0; } <-> { x = 0; RetVal - 1sgn = 0; T_RetVal = 0; T_sgn = 0; T_x = 0; RetVal + 1 >= 0; - 1RetVal + 1 >= 0; }
]

<-------------------
Sub-state with diff (RetVal, T_RetVal, T_sgn, sgn, ):
{ x = 0; RetVal - 1sgn = 0; T_RetVal = 0; T_sgn = 0; T_x = 0; RetVal + 1 >= 0; - 1RetVal + 1 >= 0; }
------------------->
*/
{char *CP7;}
}
}
}
}




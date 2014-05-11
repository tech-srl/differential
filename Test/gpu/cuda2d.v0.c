#define WIDTH 512
#define N 1
#define KERNEL(in,out,tx,ty) \
		{ \
	float x = 0, a = 0, b = 0 , c = 0 , d = 0; \
	x = Min[(tx)*WIDTH+ty]; \
	b = Min[(tx-1)*WIDTH+ty]; \
	c = Min[(tx+1)*WIDTH+ty]; \
	a = Min[(tx)*WIDTH+ty-1]; \
	d = Min[(tx)*WIDTH+ty+1]; \
	Mout[(tx)*WIDTH+ty] = (x + a + b + c + d) / 5; \
		}

// run with (tx,ty) = {(0,0),(0,1),(1,0),(1,1)}
void kernel(float *Min, float *Mout, int tx, int ty) {
	KERNEL(Min,Mout,tx,ty);
//	KERNEL(Min,Mout,tx,ty+1);
//	KERNEL(Min,Mout,tx+1,ty);
//	KERNEL(Min,Mout,tx+1,ty+2);
}

#define WIDTH 512
#define N 2

// run with (tx,ty) = {(0,0)}
void kernel(int *Min, int *Mout, int tx, int ty) {
	int Mout1 = 0, Mout2 = 0,Mout3 = 0,Mout4 = 0;
	int x = 0, a = 0, b = 0 , c = 0 , d = 0;
	int t1 = 0, t11 = 0, t12 = 0, t2 = 0, t21 = 0, t22 = 0;
	// doing (tx,ty) thread's work
	t11 = Min[(tx+1)*WIDTH+(ty+1)]; // each read requires a new variable
	t12 = Min[(tx)*WIDTH+ty];
	t1 = t11 + t12;
	t21 = Min[(tx+1)*WIDTH+ty];
	t22 = Min[(tx)*WIDTH+(ty+1)];
	t2 = t21 + t22;
	{
			x = Min[(tx)*WIDTH+ty];
			b = Min[(tx-1)*WIDTH+ty];
			a = Min[(tx)*WIDTH+ty-1];
			Mout[(tx)*WIDTH+ty] = 2 * (x + a + b + t2);
	}
	// doing (tx,ty+1) thread's work
	{
			x = Min[(tx)*WIDTH+ty+1];
			b = Min[(tx-1)*WIDTH+ty+1];
			c = Min[(tx)*WIDTH+ty+2];
			Mout[(tx)*WIDTH+ty+1] = 2 * (x + t1 + b + c);
	}
	// doing (tx+1,ty) thread's work
	{
			x = Min[(tx+1)*WIDTH+ty];
			a = Min[(tx+1)*WIDTH+ty-1];
			d = Min[(tx+2)*WIDTH+ty];
			Mout3 = 2 * (x + a + d + t1);
			Mout[(tx+1)*WIDTH+ty] = Mout3;
	}
	// doing (tx+1,ty+1) thread's work
	{
			x = Min[(tx+1)*WIDTH+ty+1];
			d = Min[(tx+2)*WIDTH+ty+1];
			c = Min[(tx+1)*WIDTH+ty+2];
			Mout4 = 2 * (x + c + d + t2);
			Mout[(tx+1)*WIDTH+ty+1] = Mout4;
	}
}


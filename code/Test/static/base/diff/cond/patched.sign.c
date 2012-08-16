int sign(int x) {
	int sgn;
	if (x<0)
		sgn = -1;
	else
		sgn = 1;
	if (x==0)
		sgn = 0;
	return sgn;
}

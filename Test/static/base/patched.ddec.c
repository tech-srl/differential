/*
 * patched.ddec.c
 *
 *  Created on: Nov 3, 2013
 *      Author: user
 */

int f(int x, int n){
	int i = 0, k = 0;
	loop:
	if (i<n || i>n){
		x += k;
		k += 5;
		if (i >= 5)
			k += 15;
		++i;
		goto loop;
	}
	return x;
}

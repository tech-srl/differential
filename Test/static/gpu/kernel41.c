void kernel(int M_tx_ty, int width, int height, int tx, int ty) { // width and height are even
	int M_txPlus1_ty,M_txMinus1_ty,M_tx_tyPlus1,M_tx_tyMinus1,val;
	if (tx == 0 || tx == 2) {
		if (((tx == 0) && (ty == 2 || ty == 0)) || ((tx == 2) && (ty == 1 || ty == 3))) {
			val = M_tx_ty;
			if (tx+1 < height)
				M_txPlus1_ty = val;
			if (tx-1 >= 0)
				M_txMinus1_ty = val;
			if ((ty+1 < width) && (ty == 2 || ty == 0))
				M_tx_tyPlus1 = val;
			if ((ty-1 >= 0) && (ty == 1 || ty == 3))
				M_tx_tyMinus1 = val;
		}
	}
}

void kernel1(int M_tx_ty, int width, int height, int tx, int ty) { // width and height are even
	int M_txPlus1_ty,M_txMinus1_ty,M_tx_tyPlus1,M_tx_tyMinus1,val;
	if (tx == 0 || tx == 2) {
			val = M_tx_ty;
			if (tx < height)
				M_txPlus1_ty = val;
	}
}

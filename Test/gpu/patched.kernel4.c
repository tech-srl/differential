// kernel4 - assume 2x2 threads
void kernel(int M_tx_ty, int width, int height, int tx, int ty) { // width and height are even
	int M_txPlus1_ty,M_txMinus1_ty,M_tx_tyPlus1,M_tx_tyMinus1;
	if ((tx == 0) && (ty == 1 || ty == 3))
		M_tx_ty = M_tx_tyMinus1;
	else if ((tx == 2) && (ty == 0 || ty == 2))
		M_tx_ty = M_tx_tyPlus1;
	else if (tx == 1)
		if (ty == 0 || ty == 2)
			M_tx_ty = M_txMinus1_ty;
		else
			M_tx_ty = M_txPlus1_ty;
	else if (tx == 3)
		if (ty == 1 || ty == 3)
			M_tx_ty = M_txMinus1_ty;
		else
			M_tx_ty = M_txPlus1_ty;
}

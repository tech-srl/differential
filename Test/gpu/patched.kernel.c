void kernel(int M_tx_ty, int width, int height, int tx, int ty) { // width and height are even
	int M_txPlus1_ty,M_txMinus1_ty,M_tx_tyPlus1,M_tx_tyMinus1,val;
	if ((tx % 4 == 0) && (ty % 2 == 1))
		M_tx_ty = M_tx_tyMinus1;
	else if ((tx % 4 == 2) && (ty % 2 == 0))
		M_tx_ty = M_tx_tyPlus1;
	else if (tx % 4 == 1)
		if (ty % 2 == 0)
			M_tx_ty = M_txMinus1_ty;
		else
			M_tx_ty = M_txPlus1_ty;
	else if (tx % 4 == 3)
		if (ty % 2 == 1)
			M_tx_ty = M_txMinus1_ty;
		else
			M_tx_ty = M_txPlus1_ty;
}

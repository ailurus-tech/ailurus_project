int GetValByRank(int wz, int rank) {
	if (wz == 0){
		return INF;
		　　
	}
	if (x[x[wz].ls].size >= rank)
		　　 {
		return GetValByRank(x[wz].ls, rank);
		　　
	}
	if (x[x[wz].ls].size + x[wz].cnt >= rank)
		　　 {
		return x[wz].val;
		　　
	}
	return GetValByRank(x[wz].rs, rank - x[x[wz].ls].size - x[wz].cnt);
}

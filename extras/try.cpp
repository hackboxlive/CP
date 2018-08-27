int check(int l1, int r1, int l2, int r2)	{
	if(r1 < l2)	{
		return 0;
	}
	if(r2 < l1)	{
		return 1;
	}
	return -1;
}
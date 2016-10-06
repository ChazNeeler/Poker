int *Sort(int a, int b, int c, int d, int e)
{
	int hand[5]{ a, b, c, d, e };
	int x, y, z;
	for (x = 0; x < 5; x++)
	{
		if (data[x] > data[x + 1])
		{
			data[x] = data[x] + data[x + 1];
			data[x + 1] = data[x] - data[x + 1];
			data[x] = data[x] - data[x + 1];
			}
	}
	return data;
}
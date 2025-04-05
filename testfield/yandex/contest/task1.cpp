#include <iostream>

int main()
{
	const size_t maxSize = 50;
	int n, m, x, y;
	std::cin >> n >> m >> x >> y;
	
	const size_t width = m * y;
	const size_t height = n * x;
	
	bool windows[width][height]; // Не эффективно

	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = 0; j < height; ++j)
		{
			char buffer;
			std::cin >> buffer;
			windows[i][j] = buffer == 'X';
		}
	}

	int result = 0;
	const int halfWindowCount = (x * y + 1) / 2;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int count = 0;
			
			for (int k = 0; k < y; ++k)
			{
				for (int l = 0; l < x; ++l)
				{
					if (windows[i * y + k][j * x + l])
						++count;
				}
			}

			if (count >= halfWindowCount)
				++result;
		}
	}

	std::cout << result;
	
	return 0;
}
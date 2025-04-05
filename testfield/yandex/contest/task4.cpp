#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <vector>

struct Vector2
{
	int16_t x;
	int16_t y;

	Vector2()
		: x{0}, y{0} { }
	Vector2(int16_t x, int16_t y)
		: x{x}, y{y} { }
	
	int16_t GetDistance(int16_t otherX, int16_t otherY)
		{ return std::abs(otherX - x) + std::abs(otherY - y); }
};

int main()
{
	uint32_t n, m, d;
	std::cin >> n >> m >> d;

	std::vector<Vector2> buildings;
	buildings.reserve(n * m);
	
	for (size_t y = 0; y < n; ++y)
	{
		for (size_t x = 0; x < m; ++x)
		{
			char buffer;
			std::cin >> buffer;
			if (buffer == 'x')
				buildings.emplace_back(x, y);
		}
	}
	
	if (buildings.size() == 0) // если зданий нет
		return std::min(m, n); // значит ответ это меньшая сторона данного прямоугольника
	
	// вычисление расстояние чёбышева относительно ближайшего здания

	int16_t distances[m][n];
	
	// Перезапись
	Vector2 firstBuilding = buildings[0];
	for (size_t y = 0; y < n; ++y)
		for (size_t x = 0; x < m; ++x)
			distances[x][y] = firstBuilding.GetDistance(x, y);
	
	// Все остальные
	for (size_t i = 1; i < buildings.size(); ++i)
	{
		Vector2 building = buildings[i];
		for (size_t y = 0; y < n; ++y)
		{
			for (size_t x = 0; x < m; ++x)
			{
				int16_t nextDistance = building.GetDistance(x, y);
				distances[x][y] = std::min(distances[x][y], nextDistance);
			}
		}
	}

	/*for (size_t y = 0; y < n; ++y)
	{
		for (size_t x = 0; x < m; ++x)
		{
			std::cout << distances[x][y] << ' ';
		}
		std::cout << std::endl;
	}*/

	// Нахождение большего числа и постойка здания от него
	
	int16_t largest = 0;

	for (size_t y = 0; y < n; ++y)
	{
		for (size_t x = 0; x < m; ++x)
		{
			if (distances[x][y] > largest)
				largest = distances[x][y];
		}
	}
	
	// Финальное вычисление, largest = (сторона - 1) * 2, сторона = (largest + 1) / 2 + 1
	if (largest - d <= 0) std::cout << 0;
	else
	{
		int16_t side = (largest - d /*+ 1*/) / 2 + 1;
		std::cout << side;
	}
	
	return 0;
}
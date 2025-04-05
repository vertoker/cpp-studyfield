#include <iostream>
#include <string>
#include <unordered_map>

#include <cstdint>
#include <ctime>

struct TaxiCoord
{
	std::time_t timestamp; // в секундах
	size_t taxi_id;
	uint32_t taxi_position;
};
struct Order
{
	std::time_t timestamp; // в секундах
	size_t order_id;
	uint32_t order_position;
	std::time_t order_time;
};

std::istream& operator>>(std::istream& is, TaxiCoord& coord)
{
	is >> coord.timestamp >> coord.taxi_id >> coord.taxi_position;
	return is;
}
std::istream& operator>>(std::istream& is, Order& order)
{
	is >> order.timestamp >> order.order_id >> order.order_position >> order.order_time;
	return is;
}


uint32_t Repeat(uint32_t position, uint32_t max)
{
	// TODO не обрабатывает множественный Repeat
	if (position >= max)
		position -= max;
	return position;
}
uint32_t DistanceOnlyForward(uint32_t start, uint32_t end, uint32_t max)
{
	if (start < end) return end - start;
	return max - start + end;
	// 2 1 5 - 0 1 2 3 4
}
bool CanComplete(const Order& order, const TaxiCoord& taxiCoord, uint32_t L, uint32_t S)
{
	std::time_t diff = order.timestamp - taxiCoord.timestamp;
	uint32_t maxTaxiPosition = Repeat(taxiCoord.taxi_position + S * diff, L);

	uint32_t minDistance = DistanceOnlyForward(taxiCoord.taxi_position, order.order_position, L);
	uint32_t maxDistance = DistanceOnlyForward(maxTaxiPosition, order.order_position, L);
	uint32_t optimalDistance = std::min(minDistance, maxDistance);

	return optimalDistance * S <= order.order_time;
}


int main()
{
	size_t N; // число событий
	uint32_t L; // Длина круга в метрах
	uint32_t S; // Максимальная скорость таксиста
	std::cin >> N >> L >> S;
	
	// Я бы использовал обычный C массив, но в задаче не указано, что taxi_id идут последовательно
	std::unordered_map<uint32_t, TaxiCoord> coords;
	coords.reserve(N);

	std::string cmdBuffer;

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> cmdBuffer;
		if (cmdBuffer == "TAXI")
		{
			TaxiCoord coord;
			std::cin >> coord;
			coords[coord.taxi_id] = coord;
		}
		else if (cmdBuffer == "ORDER")
		{
			Order order;
			std::cin >> order;
			
			const uint8_t maxTaxi = 5;
			uint8_t taxiCounter = maxTaxi;
        
			for (const auto& pair : coords)
			{
				if (CanComplete(order, pair.second, L, S))
				{
					if (taxiCounter != maxTaxi)
						std::cout << ' ';
					std::cout << pair.first;

					--taxiCounter;
					if (taxiCounter == 0)
						break;
				}
			}
			
			if (taxiCounter == maxTaxi)
				std::cout << "-1";
			std::cout << std::endl;
		}
		cmdBuffer.clear();
	}

	return 0;
}
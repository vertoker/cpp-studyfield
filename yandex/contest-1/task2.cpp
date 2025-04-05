#include <iostream>
#include <cstdint>

uint32_t Resample(uint8_t sampled, uint32_t min, uint32_t max)
{
	const double invertMaxByte = 1.0 / 255.0;

	if (max < min) return 0;
	double delta = static_cast<double>(sampled) * invertMaxByte;
	delta *= static_cast<double>(max - min);
	return min + static_cast<uint32_t>(delta);
}

uint64_t Dot(uint32_t* Q, uint32_t* D, uint8_t N)
{
	uint64_t result = 0;
	for (size_t i = 0; i < N; ++i)
	{
		uint64_t q = static_cast<uint64_t>(Q[i]);
		uint64_t d = static_cast<uint64_t>(D[i]);
		result += q * d;
	}
	return result;
}

int main()
{
	int N; // могло бы быть uint8_t, но мне лень возиться с этим
	std::cin >> N;

	uint32_t Q[N], D[N];
	for (size_t i = 0; i < N; ++i)
		std::cin >> Q[i];
	for (size_t i = 0; i < N; ++i)
		std::cin >> D[i];
	
	uint32_t A, B;
	std::cin >> A >> B;

	for (uint8_t i = 0; i < N; i++)
		D[i] = Resample(D[i], A, B);
	uint64_t result = Dot(Q, D, N);

	std::cout << result;

	return 0;
}
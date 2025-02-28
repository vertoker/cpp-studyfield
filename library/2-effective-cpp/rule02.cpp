
// Why `const`, `enum` and `inline` more preferred than `#define` 

// 1: const vs define

#define ASPECT_RATIO 1.653 // can be deleted by compiler

const double AspectRation = 1.653; // always being see by compiler

// 2: const for char*

const char* NonConstStr = "Non-const"; // non-const because pointer can be overrided

const char* const ConstStr = "Const"; // const because pointer itself is const

// 3. enum vs define

// it's a bad practice in most cases
#define TYPE_API_VULKAN 0
#define TYPE_API_DIRECTX 1
#define TYPE_API_METAL 2

// typical enum for C (hello Vulkan API)
typedef enum GraphicsAPI {
    GRAPHICS_API_VULKAN = 0,
    GRAPHICS_API_DIRECTX = 1,
    GRAPHICS_API_METAL = 2,
} GraphicsAPI;

// typical for C++, prefer to use `enum class` instead of `enum`
enum class Color {
    Red = 0,
    Green = 1,
    Blue = 2,
} Color;

// 4. inline vs define

#define MAX(a, b) (a > b) ? a : b // define is bad

// inline template is cool
template <typename T>
inline T Max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}


#include <iostream>
#include <bitset>

int main()
{
    std::cout << std::endl;

    std::bitset<8> i8_1(0), i8_2(127), i8_3(-128), i8_4(-1);
    std::cout << "i8 - signed 8 bit number" << std::endl;
    std::cout << "1.    0 - " << i8_1 << std::endl;
    std::cout << "2.  127 - " << i8_2 << std::endl;
    std::cout << "3. -128 - " << i8_3 << std::endl;
    std::cout << "4.   -1 - " << i8_4 << std::endl;
    std::cout << std::endl;

    std::bitset<8> u8_1(0), u8_2(127), u8_3(128), u8_4(255);
    std::cout << "u8 - unsigned 8 bit number" << std::endl;
    std::cout << "1.    0 - " << u8_1 << std::endl;
    std::cout << "2.  127 - " << u8_2 << std::endl;
    std::cout << "3.  128 - " << u8_3 << std::endl;
    std::cout << "4.  255 - " << u8_4 << std::endl;
    std::cout << std::endl;
    
    std::bitset<16> i16_1(0), i16_2(32767), i16_3(-32768), i16_4(-1);
    std::cout << "i16 - signed 16 bit number" << std::endl;
    std::cout << "1.      0 - " << i16_1 << std::endl;
    std::cout << "2.  32767 - " << i16_2 << std::endl;
    std::cout << "3. -32768 - " << i16_3 << std::endl;
    std::cout << "4.     -1 - " << i16_4 << std::endl;
    std::cout << std::endl;
    
    std::bitset<16> u16_1(0), u16_2(32767), u16_3(32768), u16_4(65535);
    std::cout << "u16 - unsigned 16 bit number" << std::endl;
    std::cout << "1.      0 - " << u16_1 << std::endl;
    std::cout << "2.  32767 - " << u16_2 << std::endl;
    std::cout << "3.  32768 - " << u16_3 << std::endl;
    std::cout << "4.  65535 - " << u16_4 << std::endl;
    std::cout << std::endl;
    
    std::bitset<32> i32_1(0), i32_2(2147483647), i32_3(-2147483648), i32_4(-1);
    std::cout << "i32 - signed 32 bit number" << std::endl;
    std::cout << "1.           0 - " << i32_1 << std::endl;
    std::cout << "2.  2147483647 - " << i32_2 << std::endl;
    std::cout << "3. -2147483648 - " << i32_3 << std::endl;
    std::cout << "4.          -1 - " << i32_4 << std::endl;
    std::cout << std::endl;
    
    std::bitset<32> u32_1(0), u32_2(2147483647), u32_3(2147483648), u32_4(4294967295);
    std::cout << "u32 - unsigned 32 bit number" << std::endl;
    std::cout << "1.           0 - " << u32_1 << std::endl;
    std::cout << "2.  2147483647 - " << u32_2 << std::endl;
    std::cout << "3. -2147483648 - " << u32_3 << std::endl;
    std::cout << "4.  4294967295 - " << u32_4 << std::endl;
    std::cout << std::endl;
    
    std::bitset<64> i64_1(0), i64_2(9223372036854775807), i64_3(-9223372036854775808), i64_4(-1);
    std::cout << "i64 - signed 64 bit number" << std::endl;
    std::cout << "1.                    0 - " << i64_1 << std::endl;
    std::cout << "2.  9223372036854775807 - " << i64_2 << std::endl;
    std::cout << "3. -9223372036854775808 - " << i64_3 << std::endl;
    std::cout << "4.                   -1 - " << i64_4 << std::endl;
    std::cout << std::endl;
    
    std::bitset<64> u64_1(0), u64_2(9223372036854775807ULL), u64_3(9223372036854775808ULL), u64_4(18446744073709551615ULL);
    std::cout << "u64 - unsigned 64 bit number" << std::endl;
    std::cout << "1.                    0 - " << u64_1 << std::endl;
    std::cout << "2.  9223372036854775807 - " << u64_2 << std::endl;
    std::cout << "3.  9223372036854775808 - " << u64_3 << std::endl;
    std::cout << "4. 18446744073709551615 - " << u64_4 << std::endl;
    std::cout << std::endl;
    
    return 0;
}
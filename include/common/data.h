/**
 * @file data.h 
 * @brief This program give you some tools to convers data types 
 *
 * Here you should converd number to strings or strings to numbers
 * 
 * @author Pool Diego Gonzales Loayza
 * @date 11/11/2020 
 *
 */

/**
 * @brief Convert data from standard integer to ASCII string
 *
 * This function take a 32 bit integer and depending on the base 
 * provided, it converts the integer to ASCII string representation. 
 *
 * @param ptr Pointer to data 
 * @param data Integer
 * @param base Base (2 - 16)
 *
 * @return The length of the converted data including a negative sign
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts data from ASCII to integer
 *
 * This function take a pointer to a data, the length of the string and
 * dependin on the base it converts from ascii string to integer
 *
 * @param ptr Pointer to data 
 * @param digits Length of the String
 * @param base Base (2 - 16)
 *
 * @return The integer
 * 
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

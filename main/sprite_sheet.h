#include <stdint.h>
#define SPRITE_SHEET_FRAME_COUNT 2
#define SPRITE_SHEET_FRAME_WIDTH 128
#define SPRITE_SHEET_FRAME_HEIGHT 128
static const uint32_t sprite_sheet_data[2][16384] = {
{
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000010100000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000011000000000000000, 0b00000000000000000000000000000000,
 0b00000111111111111111111111110000, 0b00000111111111111111111111110000, 0b00000111111111000001111111110000, 0b00000000000000000000000000000000,
 0b00001100000000100100000000110000, 0b00001100000000100100000000110000, 0b00001100000001000110000000110000, 0b00000000000000000000000000000000,
 0b00001010000001000010000000101000, 0b00001010000001000010000000101000, 0b00001010000001101000000000101000, 0b00000000000000000000000000000000,
 0b00010010000010000001000001001000, 0b00010010000010000001000001001000, 0b00010010000010011001000001001000, 0b00000000000000000000000000000000,
 0b00100001000010000000100001000100, 0b00100001000010000000100001000100, 0b00100001000010001000100001000100, 0b00000000000000000000000000000000,
 0b01000000100100000000010010000100, 0b01000000100100000000010010000100, 0b01000000100100001000010010000100, 0b00000000000000000000000000000000,
 0b01000000101000000000001010000010, 0b01000000101000000000001010000010, 0b01000000101000000100001010000010, 0b00000000000000000000000000000000,
 0b11111111111111111111111111111111, 0b11111111111111111111111111111111, 0b11111111111111111111111111111111, 0b00000000000000000000000000000000,
 0b01000000010000000000001000000010, 0b01000000010000000000001000000010, 0b01000000110000010000001000000010, 0b00000000000000000000000000000000,
 0b00100000010000000000001000000100, 0b00100000010000000000001000000100, 0b00100001010000001000001000000100, 0b00000000000000000000000000000000,
 0b00010000001000000000010000001000, 0b00010000001000000000010000001000, 0b00010010001000000100010100001000, 0b00000000000000000000000000000000,
 0b00001000001000000000010000010000, 0b00001000001000000000010000010000, 0b00001000000100011000010010010000, 0b00000000000000000000000000000000,
 0b00000100000100000000100000100000, 0b00000100000100000000100000100000, 0b00000100000111101000100000100000, 0b00000000000000000000000000000000,
 0b00000010000100000000100001000000, 0b00000010000100000000100001000000, 0b00000010000000001000100001000000, 0b00000000000000000000000000000000,
 0b00000001000100000001000010000000, 0b00000001000100000001000010000000, 0b00000001000100001000000010000000, 0b00000000000000000000000000000000,
 0b00000000100010000001000100000000, 0b00000000100010000001000100000000, 0b00000000100010001111110100000000, 0b00000000000000000000000000000000,
 0b00000000010010000010001000000000, 0b00000000010010000010001000000000, 0b00000000010010001010001000000000, 0b00000000000000000000000000000000,
 0b00000000001001000010010000000000, 0b00000000001001000010010000000000, 0b00000000001001000010000000000000, 0b00000000000000000000000000000000,
 0b00000000000101000100100000000000, 0b00000000000101000100100000000000, 0b00000000000101000010000000000000, 0b00000000000000000000000000000000,
 0b00000000000011000101000000000000, 0b00000000000011000101000000000000, 0b00000000000011000101010000000000, 0b00000000000000000000000000000000,
 0b00000000000001101010000000000000, 0b00000000000001101010000000000000, 0b00000000000001101010011000000000, 0b00000000000000000000000000000000,
 0b00000000000000101100000000000000, 0b00000000000000101100000000000000, 0b00000000000000101100000000000000, 0b00000000000000000000000000000000,
 0b00000000000000011000000000000000, 0b00000000000000011000000000000000, 0b00000000000000011000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000010000000000000000, 0b00000000000000010000000000000000, 0b00000000000000010000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000
},
{
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00011100000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000111000000000000000001100000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000111100000, 0b00000010000000000000000001010000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000011111111000110000, 0b00000000000000000000000001010000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000001111111100000000001010000, 0b00010000000000000000000001001000, 0b00000000000000000000000000000000,
 0b00000111111111111111111111110000, 0b00011110000001010000000001001000, 0b00011100000000000000000001000100, 0b00000000000000000000000000000000,
 0b00001100000000100100000000110000, 0b00010100000010001100000010000100, 0b00010011001000000000000001011000, 0b00000000000000000000000000000000,
 0b00001010000001000010000000101000, 0b00100100000100000010000010000100, 0b00100000110000000000000001100000, 0b00000000000000000000000000000000,
 0b00010010000010000001000001001000, 0b00100010001000000001000100000010, 0b01000000010000000000000001000000, 0b00000000000000000000000000000000,
 0b00100001000010000000100001000100, 0b00100010010000000000110100111110, 0b01000001100000000000000100000000, 0b00000000000000000000000000000000,
 0b01000000100100000000010010000100, 0b00100001100000001111111111000010, 0b11111111100000000000011100000000, 0b00000000000000000000000000000000,
 0b01000000101000000000001010000010, 0b01000001111111110000001000000100, 0b01000000010000000001101000000000, 0b00000000000000000000000000000000,
 0b11111111111111111111111111111111, 0b01111110100000000000001000000100, 0b00100000001000000110001000000000, 0b00000000000000000000000000000000,
 0b01000000010000000000001000000010, 0b00100000010000000000010000001000, 0b00010000001000001000010000000000, 0b00000000000000000000000000000000,
 0b00100000010000000000001000000100, 0b00011000010000000000010000010000, 0b00001000010000000100010000000000, 0b00000000000000000000000000000000,
 0b00010000001000000000010000001000, 0b00000100001000000000010000100000, 0b00000100010000000011100011111111, 0b00000000000000000000000000000000,
 0b00001000001000000000010000010000, 0b00000010000100000000010000100000, 0b00000010010000000000100101000010, 0b00000000000000000000000000000000,
 0b00000100000100000000100000100000, 0b00000001000010000000100001000000, 0b00000001100000000000001000110010, 0b00000000000000000000000000000000,
 0b00000010000100000000100001000000, 0b00000000100010000000100010000000, 0b00000000111110000000010000001010, 0b00000000000000000000000000000000,
 0b00000001000100000001000010000000, 0b00000000011001000000100100000000, 0b00000000010001000000100000000110, 0b00000000000000000000000000000000,
 0b00000000100010000001000100000000, 0b00000000000100100000100100000000, 0b00000000001001000000100001111000, 0b00000000000000000000000000000000,
 0b00000000010010000010001000000000, 0b00000000000010100001001000000000, 0b00000000000100100001111110000000, 0b00000000000000000000000000000000,
 0b00000000001001000010010000000000, 0b00000000000001010001010000000000, 0b00001100000010010011000000000000, 0b00000000000000000000000000000000,
 0b00000000000101000100100000000000, 0b00000000000000101001100000000000, 0b00001011000001010100000000000000, 0b00000000000000000000000000000000,
 0b00000000000011000101000000000000, 0b00000000000000011101100000000000, 0b00000100100000101000000000000000, 0b00000000000000000000000000000000,
 0b00000000000001101010000000000000, 0b00000000000000000111000000000000, 0b00000111110000010000111110000000, 0b00000000000000000000000000000000,
 0b00000000000000101100000000000000, 0b00000000000000000010000000000000, 0b00000000000000000000011010000000, 0b00000000000000000000000000000000,
 0b00000000000000011000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000100000000, 0b00000000000000000000000000000000,
 0b00000000000000010000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000,
 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000, 0b00000000000000000000000000000000
},
};
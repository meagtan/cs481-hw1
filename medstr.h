/*
 * Finding median string of DNA sequences
 * Functions are provided for processing directly on characters, as well as on sequences of two bits
 *  for each nucleotide. Goal is to compare overhead of creating bit sequences with faster searching.
 */

#include <stdint.h>
#include <stdlib.h>

#ifndef __MEDSTR
#define __MEDSTR

// type used to store sequences of two bits, and how many two bits it can store
// implicitly assuming k < SEQSIZ
#define BITSEQ uint64_t
#define SEQSIZ 32 

// bit representation of nucleotides
// A - 0x41, C - 0x43, G - 0x47, T - 0x54 (0x20 added for lowercase)
// / 2 0x20,     0x21,     0x23,     0x2A
// % 4   00,       01,       11,       10
#define BITS(c) (((c) >> 1) & 3)
extern const char *nucs;

// convert sequence of characters into sequence of 2 bits, size of array returned
// output malloc'd, should be free'd as well
// size is number of characters, not number of elements in array (which is size / SEQSIZ rounded above)
BITSEQ *writebits(char *seq, size_t *size);

// return median string as bit sequence after searching directly on character sequences
// t - number of sequences, k - size of median string
BITSEQ medstr_char(char *dna[], size_t t, size_t k);

// return median string as bit sequence after searching on bit sequences
// t, k defined the same, function adjusts them accordingly using SEQSIZ etc.
// l is the length of each row of dna
BITSEQ medstr_bit(BITSEQ *dna[], size_t t, size_t l, size_t k);

// calculates minimum distance of pattern string str to DNA sequence seq
// k stores how many elements in str are enabled 
// the starting position of the best match is optionally returned
int dist_char(char *seq, BITSEQ str, size_t k, size_t *pos);
int dist_bit(BITSEQ *seq, size_t l, BITSEQ str, size_t k, size_t *pos);

#endif
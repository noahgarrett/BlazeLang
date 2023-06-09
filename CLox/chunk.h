#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
	OP_CONSTANT, // Ex. [00][23] <- [opcode][constant index] (2 bytes)
	OP_NIL,
	OP_TRUE,
	OP_FALSE,
	OP_POP,
	OP_GET_GLOBAL,
	OP_SET_GLOBAL,
	OP_DEFINE_GLOBAL,
	OP_EQUAL,
	OP_GREATER,
	OP_LESS, // Need to add !=, <=, and >= later
	OP_ADD,
	OP_SUBTRACT,
	OP_MULTIPLY,
	OP_DIVIDE,
	OP_NOT,
	OP_NEGATE,
	OP_PRINT,
	OP_RETURN, // Ex. [01] <- opcode (1 byte)
} OpCode;

typedef struct {
	int count; // The number of allocated elements that are actually in use
	int capacity; // The number of elements we have allocated
	uint8_t* code;
	int* lines; // Stores the chunk's line numbers
	ValueArray constants; // Stores the chunk's constants
} Chunk;

// Initializes a new chunk
void initChunk(Chunk* chunk);

// Frees a chunk in memory
void freeChunk(Chunk* chunk);

// Append a byte to the end of a chunk
void writeChunk(Chunk* chunk, uint8_t byte, int line);

// Adds a constant to the chunk
// Returns: The index where the constant was appended
int addConstant(Chunk* chunk, Value value);

#endif // !clox_chunk_h


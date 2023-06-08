#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
	Chunk* chunk; // Chunk of bytecode currently being executed
	uint8_t* ip; // The location of the next instruction to be executed (Instruction Pointer)
	Value stack[STACK_MAX];
	Value* stackTop; // Points just past the last item in the stack

	Obj* objects; // Stores a pointer to the head of the linked list of objects in memory
} VM;

typedef enum {
	INTERPRET_OK,
	INTERPRET_COMPILE_ERROR,
	INTERPRET_RUNTIME_ERROR
} InterpretResult;

// Globally exposing the vm object defined in vm.c
extern VM vm;

// Initialize the virtual machine
void initVM();

// Free the virtual machine from memory
void freeVM();

// Interprets the chunk of bytecode
InterpretResult interpret(const char* source);

// Push a new value onto the stack
void push(Value value);

// Pop the most recently added value off the stack
Value pop();

#endif // !clox_vm_h

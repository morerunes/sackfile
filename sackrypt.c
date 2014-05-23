//-- ALL IMPORTS --//
#include "sackrypt.h"

//-- VARIABLES --//
short currently_encrypting = 1;
//TODO implement some sort of operation stack
int current_operation_stack = 0;

//-- PUBLIC FUNCTIONS --//
int begin_encryption() {
	if (currently_encrypting) return 1;
	else {
		currently_encrypting = 0;
		//TODO init operation stack
	}
}

int finish_encryption() {
	if (!currently_encrypting) return -1;
	else {
		currently_encrypting = 1;
		//TODO move operation stack into array
		return current_operation_stack++;
	}
}

keyfile_t generate_keyfile(int index) {
	//TODO
}

void encrypt_counter(uint8_t* data, long size, int mod_val) {
	long i;
	for (i = 0; i < size; i++)
		data[i] += (i % mod_val);
}

void encrypt_complex_counter(uint8_t* data, long size,
							 int mod_val, char method, int i_mult) {
	long i;
	if (method == '+')
		for (i = 0; i < size; i++)
			data[i] += ((i * i_mult) % mod_val);
	else
		for (i = 0; i < size; i++)
			data[i] -= ((i * i_mult) % mod_val);
}

void encrypt_matrix(uint8_t* data, long size, int xsize) {
	int extra = size % xsize;
	int rows = size / xsize;
	if (extra != 0) rows += 1;

	
}

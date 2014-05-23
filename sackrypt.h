/** Encryption functions for sack files
 *
 *  Uses a number of naive encryption methods
 *  in tandem to produce an encrypted output.
 *  
 *  See LICENSE for licensing information
 *  
 *  For use with the sackfile program
 */
#include <stdint.h>

/*  Will keep track of 'encryption transactions'
 *  and later dump them to a keyfile
 */

//-- DATA STRUCTURES --//
typedef struct KEYFILE_S {
	uint16_t size;
	uint8_t* data;
} keyfile_t;

//-- GENERAL FUNCTIONS --//

/* Call these before and after encryption to
 * generate the keyfile, or you won't be able
 * to decrypt it!
 */

/** Begin a new set of enryption operations.
 *  
 *  @return 0 if successful, or 1 if you did
 *          not end the previous encryption.
 */
int begin_encryption();

/** Finishes the current encryption operations,
 *  prepares the keyfile for returning
 *
 *  @return keyfile index, used for retrieving
 *          the keyfile with generate_keyfile();
 *          example use is:
 *          generate_keyfile(finish_encryption());
 *          returns -1 on error.
 */
int finish_encryption();

/** Generate a keyfile based on provided index
 *  (index is resultant of finish_encryption())
 *  
 *  @param int index
 *  @return keyfile_t Keyfile info
 */
keyfile_t generate_keyfile(int index);

//-- ENCRYPTION METHODS --//

/** Uses index i in data as encryption key
 *  by adding (i % mod_val) to data[i]
 *  
 *  @param uint8_t* data - the data to encrypt
 *  @param long size - the size of the data
 *  @param int mod_val - modulus value for index
 */
void encrypt_counter(uint8_t* data, long size, int mod_val);

/** A more advanced form of encrypt_counter.
 *  
 *  Allows you to choose addition or subtraction
 *  and to choose a multiplier for index
 * 
 *  @param uint8_t* data - the data to encrypt
 *  @param int mod_val - modulus value for index
 *  @param char method - '+' or '-'
 *  @param int i_mult - index multiplier
 */
void encrypt_complex_counter(uint8_t* data, long size,
							 int mod_val, char method, int i_mult);

/** Uses matrix encryption. Shuffles data as if it
 *  were reading columns from a row-oriented matrix
 *  of the data.
 * 
 *  @param uint8_t* data - the data to encrypt
 *  @param long size - the size of the data in bytes
 *  @param xsize - number of columns
 */
void encrypt_matrix(uint8_t* data, long size, int xsize);

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

/** Call these before and after encryption to
 *  generate the keyfile, or you won't be able
 *  to decrypt it!
 */
void begin_encryption();

/** Finishes the current encryption operations,
 *  prepares the keyfile for returning
 *
 *  @return keyfile index, used for retrieving
 *          the keyfile with generate_keyfile();
 *          example use is:
 *          generate_keyfile(finish_encryption());
 */
int finish_encryption();

/** Generate a keyfile based on provided index
 *  (index is resultant of finish_encryption())
 *  
 *  @param int index
 *  @return keyfile_t Keyfile info
 */
keyfile_t generate_keyfile(int index);

/** Uses index i in data as encryption key
 *  by adding (i % mod_val) to data[i]
 *  
 *  @param uint8_t* data - the data to encrypt
 */
void encrypt_counter(uint8_t* data, int mod_val);


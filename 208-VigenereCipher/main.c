/*
* import header files
* The ctype.h header file of the C Standard Library declares several functions that are useful for 
* testing and mapping characters.
* https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
*/
#include <stdio.h>
#include <ctype.h>

#define ASZ 512
#define LINSZ 80
#define ALSZ 26

//global variables
char textData[ASZ];
char keyData[ASZ];
char cipherKey[ASZ];
char cipherText[ASZ];
int keyCharCount = 0;
int textCharCount = 0;


//function prototype
void readKeyFile(char * KeyFname);
void readTextFile(char * textFname);
void cipherKeyFunc(char * keyData);
void cipherTextFunc(char * cipherKey, char * textData);

static
inline
void dump(char const data[]) {
  puts("\n++++++++++");
  for (size_t i_ = 0ul; i_ < ASZ; ++i_) {
    printf("%02x", (unsigned char) data[i_]);
  }
  puts("\n++++++++++");
}

//function main
int main(int argc, char ** argv) {

  char * keyFileName = argv[1];
  char * TextFileName = argv[2];

  printf("%s\n", "[!] Vigenere Key: ");
  //reads key file, prints unmodified, converts and stores in array
  readKeyFile(keyFileName);
  putchar('\n');

  printf("\n\n%s\n\n", "[!] Plaintext: ");
  //reads text file, prints unmodified, converts and stores in array
  readTextFile(TextFileName);
  putchar('\n');

  printf("\n\n%s\n", "Ciphertext:");
  //creates cipherKeyText that repeats the key until it fills the 512 array
  cipherKeyFunc(keyData);
  putchar('\n');

  /*
   * creates cipher text by adding the ascii values of key and plaintext via mod 26 and returning 
   * the new value and prints it
   */
  cipherTextFunc(cipherKey, textData);

  return 0;
} //int main(int argc, char **argv)


//function to read in data of key and store in array and print key
void readKeyFile(char * KeyFname) {
  FILE * file = fopen(KeyFname, "r");

  if (file == NULL) {
    printf("%s\n", "[-] Could not open file" );
  } //end if(file == 0)
  else {
    printf("%s\n", "[+] File opened successfully\n");
    
    int ch; //char ch;
    size_t idx = 0ul;

    /*
     * The C library function int fgetc(FILE *stream) gets the next character into an "int NOPE! -- (an unsigned char)
     * from the specified stream and advances the position indicator for the stream.
     * https://www.tutorialspoint.com/c_standard_library/c_function_fgetc.htm
     */
    while ((ch = fgetc(file)) != EOF) {
      printf("%c", ch);

      /*
       * The C library function int isalpha(int c) checks if the passed character is alphabetic.
       */
      if (isalpha(ch) != 0) {
        keyData[idx] = tolower(ch);
        idx++;
        keyCharCount++;
      } //if(isalpha(ch) != 0)
    } //while ((ch = fgetc(file)) != EOF)
  } //else

  fclose(file);

  dump(keyData);
} //void readKeyFile


/*
 * function to read in data of plaintext and store in 512 array (read data in plaintext 
 * char by char in C). Print unmodified plaintext. Function to rid of spaces and punctuation and 
 * convert to lowercase and pad with x. Use isalpha function to determine if the char read in is 
 * letter or not. Convert to lowercase if is aplpha using toLower() function. If the characters read
 * by the file is less than 512, pad with 'x'
 */
void readTextFile(char * textFname) {
  FILE * file = fopen(textFname, "r");

  if (file == NULL) {
    printf("\n%s\n", "[-] Could not open file" );
  } //if(file == 0)
  else {
    printf("\n%s\n", "[+] File opened successfully");

    char ch;
    size_t idx = 0ul;

    while ((ch = fgetc(file)) != EOF) {
      printf("%c", ch);

      if (isalpha(ch) != 0) {
        textData[idx] = tolower(ch);
        idx++;
        textCharCount++;
      } //if(isalpha(ch) != 0)
    } //while((ch = fgetc(file)) != EOF)

    if (idx < ASZ) {
      while (idx < ASZ) {
        textData[idx] = 'x';
        idx++;
      } //while(idx < 512)
    } //if(idx < 512)
  } //else
 
  fclose(file);

  dump(textData);
} //void readTextFile(char * textFname)


void cipherKeyFunc(char * keyData) {
  size_t i;
  size_t idx = 0ul;
  int count = 0;

  while (count != ASZ) {
    for (i = 0ul; i < ASZ; i++) {
      cipherKey[i] = keyData[idx];
      idx++;
      count++;

      if (idx == keyCharCount) {
        idx = 0ul; //start reading the key from scratch
      } //if(idx == keyCharCount)
    } //for(i = 0; i < 512; i++)
  } //while(count != 512)
} //void cipherKeyFunc(char* keyData)


void cipherTextFunc(char * cipherKey, char * textData) {
  size_t i;
  int cipherCharCount = 0;

  for (i = 0ul; i < ASZ; i++) {
    //why are adding 85?
    cipherText[i] = (((int) cipherKey[i] + (int) textData[i]) % ALSZ + 'A' + 20/*85*/);

    if ((int) cipherText[i] < /*97*/ 'a') {
        cipherText[i] = cipherText[i] + ALSZ; //what is this and why are we doing this?
    } //if((int)cipherText[i] < 97)

    printf("%c", cipherText[i]);
    cipherCharCount++;

    if (cipherCharCount == LINSZ) { //print ciphertext in exactly 80 letters per row
      printf("\n");
      cipherCharCount = 0;
    } //if(cipherCharCount == 80)
  } //for(i = 0; i < 512; i++)
} //void cipherTextFunc(char* cipherKey, char* textData)

#ifndef DOC_H
#define DOC_H

#include <iostream>
	using std::string;

/**
 * this value is used to determine the approximate
 * size for an array of words that are contained
 * in a file of size = N bytes.
 * Assuming that the average word length is larger
 * than this number of characters, a reasonable
 * estimate for the max length of the array of words
 * is N / SMALL_WORD_LENGTH.
 */
const int SMALL_WORD_LENGTH = 3;

/**
 * Prints the contents of a string array to the console,
 * each element separated by a single space.
 * No more than 8 strings to a single line.
 * @param words a pointer to an array of non-empty strings.
 * 	The sentinel value "" (empty string) marks the end of the array
 * 	which is not a member of the array elements.
 */
void print_word_array(string * words);

/**
 * Prints an array of numbers to the console, separated by spaces.
 * @param nums a pointer to an array of integers.
 * @param size the number of elements in the array.
 */
void print_int_array(int * nums, int size);

/**
 * Finds the longest string or one of the longest strings
 * in an array of strings.
 *	The sentinel value "" (empty string) marks the end of the array.
 * @param words a pointer to an array of non-empty strings.
 * @return one of the longest strings.
 */
string find_longest_word(string * words);

/**
 * Locates the position of a particular target string in
 * an array of strings.
 *	The sentinel value "" (empty string) marks the end of the array.
 * @param words a pointer to an array of non-empty strings.
 * @param target a non-empty string that is being sought in the array.
 * @return the index position of the target string within the array
 *		or -1 if the target cannot be found.
 */
int find_word(string * words, string target);

/**
 * Determines the number of non-empty strings in an array.
 *	The sentinel value "" (empty string) marks the end of the array.
 * @param words a pointer to an array of non-empty strings.
 * @return the number of non-empty strings in the array.
 */
int array_length(string *words);

/**
 * Calculates the average number of characters in an array of strings.
 *	The sentinel value "" (empty string) marks the end of the array.
 * @param words a pointer to an array of non-empty strings.
 * @return the average string length of the elements in the array
		or 0 if there are no elements.
 */
double average_word_length(string *words);

/**
 * Creates an array of non-empty words extracted from a text file.
 * The file may have upper and lower case words but no punctuation.
 *	The sentinel value "" (empty string) marks the end of the created array.
 * @param filename the name of the text file that is assumed to be present
 * 	and readable. No error checking is done for its existence.
 *		It is assumed that the file does not contain punctuation.
 * @param filesize the size of the file in bytes.
 * @return an array of strings that contains all the words in the file,
 *			all lower case.
 *		After the last word in the array, the next index position contains the empty string
 *			as a sentinel value to indicate the end of the array.
 */
string * create_word_array(string filename,int filesize);

/**
 * Modifies a string by replacing all upper case (American Standard) letters with lower case letters.
 * @param word a reference to a particular string.
 *		This string will be modified if it contains any upper case
 *			(American standard) letters.
 */
void make_lower_case(string & word);

/**
 * Returns an array of unique strings from the incoming array.
 * @param words an array of strings, whose end is marked with an empty string.
 *	@return an array that contains every string that the input array contains,
 *			but with no duplicates.
 *		The sentinel value "" (empty string) marks the end of this array.
 */
string * unique_words(string * words);

/**
 * Using the first input array as a reference, searches and counts the number
 * of times a particular word occurs in the second input array.
 * @param unique_words an array of unique words, terminated by the sentinel value "".
 * @param words an array of words.
 * @return an integer array A, where A[i] contains the frequency of
  *  unique_words[i] in the words array.
 *		The size of this array is the number of words contained within the unique_words array.
 */
int * word_frequencies(string * unique_words, string * words);

/**
 * Prints out the word frequencies.
 * The two input arrays are related by index number.
 * Each word and its frequency is printed on a separate line, using the format
 * in the following example:
 * 	happy : 13
 * @param unique_words an array of strings.
 * @param counts an array of non-negative integers.
 */
void display_word_freqs(string * unique_words, int * counts);

#endif

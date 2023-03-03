#include "change_jar.hpp"
#include <iostream>

using namespace std;

/*
 * change_jar.cpp
 * Using static and dynamic arrays to represent polynomials.
 * The polynomials, when multiplied, create a generating function
 * that determines the number of ways coin change can be calculated,
 * depending on what's available in the jar.
 * Basically, some combinatorial fun while practing array handling.
 * @author Bette Bultena, inspired by an original idea of Maartin van Emden.
 * For use in CSCI 160 VIU Fall 2021
 */


/**
 * Prints out the elements of an integer array.
 * Very useful for visualizing arrays during the creation
 * of code.
 * @param arr A pointer to an array.
 * @param size The number of integers in the array.
 */
void print_array(int * arr, int size)
{
    cout<<"Contents of the array are:\n";
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return;
}

/**
 * Multiplies two polynomials.
 * @param p_x One of the polynomials to be multiplied.
 * @param q_x The other polynomial to be multiplied.
 * @param p_degree The degree of p_x.
 * @param q_degree The degree of q_x
 * @return A new polynomial that is the product of p_x and q_y.
 * @see "https://www.mathsisfun.com/algebra/polynomials-multiplication-long.html"(Math is Fun Website) for information on how polynomials are multiplied.
 */
int* poly_multiply( int* p_x, int* q_x, int p_degree, int q_degree)
{
    int new_array_size = p_degree + q_degree + 1;       // new ploynomials degree
    int * polynomial = new int[new_array_size];         // Initalizing the polynomial array
    for(int i=0; i<new_array_size; i++)
        polynomial[i] = 0;

    // Calculate the (p+q)th array index which is coeddicient of (p+q) the power
    for(int p= 0; p<=p_degree; p++)
    {
        for(int q= 0; q<=q_degree; q++)
        {
            polynomial[p+q] += (p_x[p]*q_x[q]);
        }
    }
    return polynomial;
}

/**
 * Creates a representative polynomial for the number and value of a particular coin, as an array of integers.
 * The polynomial is of the form x^0 + x^value, x^2*value + ... + x^value*num_coins.
 * Cells with an index that is a multiple of value will contain 1, all other elements are set to 0.
 * @param coin_value The value of the coin (in cents).
 * @param num_coins The number of coins of this type.
 * @return The integer array representing the cooeficients of this polynomial for x^i, where i is the index position.
 */
int* createPoly(int coin_value, int num_coins)
{
    int poly_length = coin_value * num_coins +1;        // Degree of polynomial
    int * polynomial = new int[poly_length];
    for(int i=0; i<poly_length; i++)                    // Only have non negative coesfficient for elements multiple of the coin_value
        if( (i%coin_value)==0 )
            polynomial[i] = 1;
        else
            polynomial[i] = 0;
    return polynomial;
}

/**
 * Creates a polynomial to represent the number and value of all the coins in a change jar.
 * The cooefficients of this polynomial represent the number of ways that change can be arranged to add up
 * to the value of the degree of the term.
 * For example a term of 39x^45 indicates that there are 39 unique ways to arrange a subset of coins from the jar that will add up to a monetary value of 45.
 * @param values An array of the cent value of each coin;
 * @param numbers A matching array of the actual number of this particular coin, so there are numbers[i] coins that have value[i].
 *		The number of coins are expected to be non-negative.  No error-checking is done.
 * @param length The length of each array (they must be the same length).
 * @return an array that represents the polynomial for this set of coins.
 */
int* spare_change_poly(int values[], int numbers[], int length)
{
    int* ret_poly;
    int ret_poly_len = 0;
    for(int i=0; i<length; i++)
    {
        int* poly_val_num = createPoly(values[i], numbers[i]);      // Create ith polynomial
        int poly_val_num_len = values[i] * numbers[i] + 1;          // Calculate power of the ith polynomical
        if(i == 0)                                                  // For 0th polynomial, it is our base case hence dont multiply
        {
            ret_poly = poly_val_num;
            ret_poly_len = poly_val_num_len;
        }
        else                                                        // For further polynomials, multiply with the previous multiplication
        {
            ret_poly = poly_multiply(ret_poly, poly_val_num, ret_poly_len, poly_val_num_len);
            ret_poly_len = ret_poly_len + poly_val_num_len + 1;     // New power of polynomial
        }
        // cout<<ret_poly[1]<<endl;    // <-------- See here, prints 1st element (0 indexed) of the array
    }
    return ret_poly;
}

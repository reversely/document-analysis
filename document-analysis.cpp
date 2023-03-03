#include <iostream>
#include <fstream>
#include <sstream>
#include "doc_analysis.hpp"

using namespace std;


//const int SMALL_WORD_LENGTH = 3;

void print_word_array(string * words)
{
    int currPos = 0;
    while(words[currPos] != "")
    {
        if(currPos%8 == 0)
            cout<<endl;
        cout<<words[currPos]<<" ";
        currPos++;
    }
}

void print_int_array(int * nums, int size)
{
    cout<<"Contents of the array are:\n";
    for(int i=0; i<size; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}


string find_longest_word(string * words)
{
    int currPos = 0;
    int maxLength = -1;
    string longestString;
    while(words[currPos] != "")
    {
        if(words[currPos].length() > maxLength)
        {
            longestString = words[currPos];
            maxLength = words[currPos].length();
        }
        currPos++;
    }
    return longestString;
}

int find_word(string * words, string target)
{
    int currPos = 0;
    while(words[currPos] != "")
    {
        if(words[currPos] == target)
            return currPos;
        currPos++;
    }
    return -1;
}

int array_length(string *words)
{
    if(words == NULL)
        return 0;
    int currPos = 0;
    while(words[currPos] != "")
    {
        currPos++;
    }
    return currPos;
}

double average_word_length(string *words)
{
    int noOfWords = array_length(words);
    if(noOfWords == 0)
        return 0;
    int currPos = 0;
    int noOfChars = 0;
    while(words[currPos] != "")
    {
        noOfChars += words[currPos].length();
        currPos++;
    }
    return (double)noOfChars/(double)noOfWords;
}

string * create_word_array(string filename,int filesize)
{
    ifstream myfile;
    myfile.open(filename);   // Open the file with the filename

    string blank = "";

    int sizeArray = filesize/SMALL_WORD_LENGTH;
    string* wordArray = (string*)malloc(sizeArray * sizeof(string));

    // for(int i=0; i<1; i++)
    // {
    //     wordArray[i] = blank;
    // }

    //cout<<"Here\n";

    string ip;
    int counter=0;
    while(myfile>>ip)
    {
        stringstream ss(ip);
        string word;
        while (ss >> word) {
            make_lower_case(word);
            wordArray[counter] = word;
            counter++;
        }
    }
    // wordArray[counter] = blank;

    return wordArray;
}

void make_lower_case(string & word)
{
    for(int i=0; i<word.length(); i++)
    {
        if(word.at(i) >= 'A' && word.at(i) <= 'Z')
            word.at(i) = (word.at(i) - 'A') + 'a';
    }
}

string * unique_words(string * words)
{
    string* uniqueArray = (string*)malloc(10^6 * sizeof(string));
    for(int i=0; i<INT32_MAX; i++)
        uniqueArray[i] = "";

    int currPos1 = 0;
    int currPos2 = 0;
    while(words[currPos2] != "")
    {
        if(find_word(uniqueArray, words[currPos2]) == -1)
        {
            uniqueArray[currPos1] = words[currPos2];
            currPos1++;
        }
        currPos2++;
    }

    return uniqueArray;
}


int * word_frequencies(string * unique_words, string * words)
{
    int* uniqueWordFreq = (int*)malloc(10^6 * sizeof(int));
    for(int i=0; i<10^6; i++)
        uniqueWordFreq[i] = 0;
    int currPos1 = 0;
    int currPos2 = 0;
    while( unique_words[currPos1] != "" )
    {
        int cnt=0;
        currPos2 = 0;
        while(words[currPos2] != "")
        {
            if(unique_words[currPos1] == words[currPos2])
            {
                uniqueWordFreq[currPos1]++;

            }
            currPos2++;
        }
        currPos1++;
    }
    return uniqueWordFreq;
}

void display_word_freqs(string * unique_words, int * counts)
{
    int currPos = 0;
    while(unique_words[currPos] != "")
    {
        cout<<unique_words[currPos]<<" : "<<counts[currPos]<<endl;
    }
}

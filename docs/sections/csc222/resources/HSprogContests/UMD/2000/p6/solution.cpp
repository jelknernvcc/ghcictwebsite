//-----------------------------------------------------------------------
//  File:         format.cc
//  Description:  Format text to given width line
//  Author:       Dave Mount (mount@cs.umd.edu)
//
//  This program inputs a line width and a sequence of text, words
//  separated by spaces and formats the text to fit within the
//  lines.  The spaces are distributed as evenly as possible with
//  longer runs of spaces near the right side of the line. 
//-----------------------------------------------------------------------

#include <cstdlib>     // standard C functions
#include <iostream>    // C++ I/O
#include <assert.h>    // assertion checking
#include <string>      // standard C++ string class
using namespace std;

//-----------------------------------------------------------------------
//  Global types
//-----------------------------------------------------------------------

const int MAX_WORDS = 5000;                 // maximum number of words

class WordList {                            // a list of words
  int    nWords;                            // number of words
  string  theWords[MAX_WORDS];              // the words
public:
  WordList() { nWords = 0; }                // default constructor

  void addWord(const string &newWord) {
    assert(nWords < MAX_WORDS);
    theWords[nWords++] = newWord;           // add to next position
  }

  string operator[](int i) const {          // index for reading
    assert(i >= 0 && i < nWords);  return theWords[i];
  }

  string& operator[](int i) {               // index for assignment
    assert(i >= 0 && i < nWords);  return theWords[i];
  }

  int length() const {                      // number of words
    return nWords;
  }
};

// input words into wordList
void readWords(istream &in, WordList &wordList)
{
  string temp;
  while (!in.eof()) {                        // read until EOF
     in >> temp;                             // input a word
     if (temp == "$$$") break;               // terminate on $$$
     wordList.addWord(temp);                 // add to list
  }
}

void formatWords(ostream &out, const WordList &wordList, int width)
{
  int cw = 0;                                // current word
  int nWords = wordList.length();            // number of words
  while (cw < nWords) {                      // while words remain
    int charCt = wordList[cw].length();      // count characters
    int nw = cw + 1;                         // next word
    while (nw < nWords &&                    // grab as many words
      charCt+wordList[nw].length()+1 <= width) { // ...as possible without
      charCt += wordList[nw].length()+1;     // ...exceeding width
      nw++;                                  // go to next word
    }
    if (nw >= nWords) {                      // no more words, last line
      for (int i = cw; i < nw; i++) {
      cout << wordList[i];                   // print each word
      if (i < nw-1) cout << ' ';             // ...with 1 space between
    }
    cout << endl;
  }
  else {                                     // not last line
    int nGaps = nw - cw - 1;                 // number of interword gaps
    int excess = width - charCt;             // excess number of spaces
    assert (excess >= 0);                    // ...cannot be negative
    for (int i = cw; i < nw; i++) {
      cout << wordList[i];                   // print next word
      if (i < nw-1) {                        // not the last word
        int nSpaces = excess/nGaps;          // number of spaces per gap
        for (int j = 0; j <= nSpaces; j++) cout << ' ';
        excess -= nSpaces;                   // decrement excess
        nGaps--;                             // decrement number of gaps
      }
    }
    cout << endl;                            // output end of line
  }
  cw = nw;                                   // go to next word
  }
}

int main()
{
  int width;                                 // line width
  WordList wordList;                         // list of words

  cin >> width;                              // input line width
  readWords(cin, wordList);                  // input the words
  formatWords(cout, wordList, width);        // format and output words

  return 0;
}

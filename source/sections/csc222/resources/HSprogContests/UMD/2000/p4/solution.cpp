/*
  File: kbdrank.cc
  Author: Sudarshan S. Chawathe <chaw@cs.umd.edu>
  Date: 06th March, 2000
  Compile using: gcc -Wall -o kbdrank kbdrank.cc 
  Terms: GPL

  For the Maryland High School Programming Contest, 2000

  kbdrank: A program to calculate the keyboard-friendliness of words.
  Copyright (C) 1999 Sudarshan S. Chawathe

  See the accompanyng file kbdrank.ps for details.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.
     
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
     
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <stdio.h>
#include <cstring>
#include <cctype>
#include <assert.h>
using namespace std;

#define NUM_CHARS 30
#define MAX_STR_LEN 257
#define C_HORIZ 3
#define C_VERT 2
#define C_ALT 1

#define ABS(x) ((x)<0 ? -(x) : (x))

int debug = 0;

/* We use xpos[] and ypos[] to store the x and y coordinates of characters
   on the keyboard.  The origin is in the middle of the keyboard.  Thus
   the coordinate of 'g' is (-1,0) while that of 'f' is (-2,0).  No character
   has a 0 x-coordinate. x-coordinates are in [-5,...1,1,...5].  y-coordinates
   are in [-1..1]. */
/* Array index order is a..z (0..25), then ';', ',', '.', and '/' (26--29) */
/* a b c d e f g h i j  k  l  m  n  o */
/* 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 */
/* p   q  r  s  t  u  v  w  x  y  z  ;  ,  .  / */
/* 15 16 17 18 19 20 21 22 23 24 15 26 27 28 29 */
short xpos[30] = {
/* a   b   c   d   e   f   g   h   i   j   k   l   m   n   o */
  -5, -1, -3, -3, -3, -2, -1, +1, +3, +2, +3, +4, +2, +1, +4, 
/* p   q   r   s   t   u   v   w   x   y   z   ;   ,   .   / */
  +5, -5, -2, -4, -1, +2, -2, -4, -4, +1, -5, +5, +3, +4, +5
};
short ypos[30] = {
/* a   b   c   d   e   f   g   h   i   j   k   l   m   n   o */
   0, -1, -1,  0, +1,  0,  0,  0, +1,  0,  0,  0, -1, -1, +1,
/* p   q   r   s   t   u   v   w   x   y   z   ;   ,   .   / */
  +1, +1, +1,  0, +1, +1, -1, +1, -1, +1, -1,  0, -1, -1, -1
};

int charVertCost(int c, int pl, int pr)
{
  return ABS(ypos[c] - ypos[(xpos[c] < 0 ? 
			     (pl == -1 ? 0 /* 'a' */ : pl) : 
			     (pr == -1 ? 11 /* 'l' */ : pr))]) * C_VERT;
}

int charHorizCost(int c, int p)
{
  static int costlyCharIdx[] = {19, 6, 1, 24, 7, 13, -1};
  /* chars in the +1, -1 cols: {'t', 'g', 'b', 'y', 'h', 'n', null} */
  for(int i = 0; costlyCharIdx[i] != -1; i++) {
    if(costlyCharIdx[i] == c) return (c != p ? C_HORIZ : 0);
  }
  return 0;
}

int charAltCost(int c, int p)
{
  return (p == -1 || xpos[c] * xpos[p] < 0 || c == p ? 0 : C_ALT);
}

int charContrib(int c, int p, int pl, int pr)
{
  return charVertCost(c,pl,pr) + charHorizCost(c,p) + charAltCost(c,p);
}

int charIndex(char c)
/* returns c's index in our tables */
{
  char ans;
  if(isalpha(c)) {
    ans = tolower(c) - 'a'; 
  }
  else {
    switch(c) {
    case ';': ans = 26; break;
    case ',': ans = 27; break;
    case '.': ans = 28; break;
    case '/': ans = 29; break;
    default:  ans = 27;
    }
  }
  return ans;
}

int kbdrank(char * word)
{
  int ans = 0;
  int prevCharIdx = -1; /* null */
  int prevLeftCharIdx = -1, prevRightCharIdx = -1;
  for(int i = 0; word[i]; i++) {
    int cIdx = charIndex(word[i]);
    assert(cIdx >= 0 && cIdx < NUM_CHARS);
    ans += charContrib(cIdx,prevCharIdx,prevLeftCharIdx,prevRightCharIdx);
    prevCharIdx = cIdx;
    (xpos[cIdx] < 0 ? prevLeftCharIdx : prevRightCharIdx) = cIdx;
  }
  return ans;
}

int main(int argc, char * argv[])
{
  if(argc > 1) {
    debug = 1;
    printf("%s running in debugging mode...\n", argv[0]);
  }
  char instr[MAX_STR_LEN];
  for(;;) {
    scanf("%s", instr);
    if(debug) printf("Read: %s\n", instr);
    if(!strncmp(instr,".", 2)) break;
    if(debug) printf("Rank: ");
    printf("%d\n", kbdrank(instr));
  } 

  return 0;
}

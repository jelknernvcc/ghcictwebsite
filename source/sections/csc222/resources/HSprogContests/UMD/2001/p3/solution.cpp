/*
  File: lsys.cc
  Author: Sudarshan S. Chawathe <chaw@cs.umd.edu>
  Date: 05th March, 2001
  Compile using: gcc -Wall -o lsys lsys.cc 
  Terms: GPL

  For the Maryland High School Programming Contest, 2001

  lsys: A simple implementation of a rule system akin to L-systems
  Copyright (C) 2001 Sudarshan S. Chawathe

  For details, see the accompanying lsys.ps file. For more
  information, see The Algorithmic Beauty of Plants by Przymyslaw
  Prusinkiewicz and Aristid Lindenmayer (New York: Springer-Verlag,
  1990, ISBN 3-540-97297-8).
   
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
  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <assert.h>
using namespace std;

#define MAX_RULES 16
#define MAX_STR_LEN 257

int debug = 0;

void applyRules(char *sstate, char lhs[MAX_RULES][MAX_STR_LEN], char
                rhs[MAX_RULES][MAX_STR_LEN], int nRules)
{
  int matchRule[MAX_STR_LEN];
  char nstate[MAX_STR_LEN];
  int slen = strlen(sstate);

  for(int i = 0; i < slen; i++) matchRule[i] = -1;
  
  for(int r = 0; r < nRules; r++) { /* find matches for LHS of  rule r */
    for(int i = 0; i < slen; /* null */) {
      char * mp = strstr((char*)((unsigned int)sstate + i), lhs[r]);
      if(mp == NULL) break; /* no match */
      int m = mp - sstate; /* ptr arith to get index from pointers */
      if(debug) printf("Found match for rule %d (%s -> %s) at posn %d\n",
		       r, lhs[r], rhs[r], m);
      assert(matchRule[m] == -1); /* shouldn't be multiple matches */
      matchRule[m] = r;  /* record match */
      i = m + strlen(lhs[r]); /* find any remaining matches from this posn */
    }
  }

  int nlen = 0;
  for(int i = 0; i < slen; /* null */) {
    if(matchRule[i] == -1) { /* nothing matched here; cpy and move on */
      nstate[nlen] = sstate[i]; nlen++; i++;
    }
    else { /* include rule rhs instead of rule lhs starting at this position */
      if(debug) printf("Replacing %s with %s at posn %d\n", lhs[matchRule[i]],
		       rhs[matchRule[i]], i);
      for(unsigned int j = 0; j < strlen(rhs[matchRule[i]]); j++)
	nstate[nlen++] = rhs[matchRule[i]][j];
      i += strlen(lhs[matchRule[i]]);
    }
  }
  nstate[nlen] = 0;
  strcpy(sstate, nstate);
}


void error(char * s)
{
  puts(s);
  exit(-1);
}

int main(int argc, char * argv[])
{
  if(argc > 1) {
    debug = 1;
    printf("%s running in debugging mode...\n", argv[0]);
  }
  char instr[MAX_STR_LEN];
  int nRules = 0;
  char lhs[MAX_RULES][MAX_STR_LEN];
  char rhs[MAX_RULES][MAX_STR_LEN];
  char sstate[MAX_STR_LEN];
  int nGen;
  /* read rules */
  for(;;) { 
    scanf("%s", instr);
    if(!strncmp(instr,".", 2)) break;
    strcpy(lhs[nRules], instr);
    scanf("%s", instr);
    if(!strncmp(instr,".", 2)) error("Incomplete rule!");
    strcpy(rhs[nRules], instr);
    if(debug) printf("Read rule %d: %s -> %s\n", 
		    nRules, lhs[nRules], rhs[nRules]);
    nRules++;
  } 
  /* read seed */
  scanf("%s", sstate);
  if(debug) printf("Read: %s\n", sstate);
  /* read number of generations */
  scanf("%d", &nGen);
  if(debug) printf("Read: %d\n", nGen);
  /* run for nGen generations */
  printf("%s\n", sstate);
  for(int i=0; i < nGen; i++) {
    applyRules(sstate, lhs, rhs, nRules);
    printf("%s\n", sstate);
  }
  return 0;
}

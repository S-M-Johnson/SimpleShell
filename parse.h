#ifndef PARSE_H
#define PARSE_H

#include "string.h"

static void parse( char* input, char* args[] )
{
    int i = 0;
        
    // fgets reads the \n, so overwrite it
    input[strlen(input)-1] = '\0';  
            
    //get the first token
    args[i] = strtok( input, " " );
                   
    // get the rest of them
    while( ( args[++i] = strtok(NULL, " ") ) );
}
#endif

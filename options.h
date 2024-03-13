#ifndef OPTIONS_H
#define OPTIONS_H

//Every options held in struct
typedef struct {
    _Bool valid;
    char* input_mode;
    char* output_mode;
    char* file;
    unsigned int blocksize;
    unsigned int nbytes;

} ProgramOptions;

//Function to parse arguments
ProgramOptions parse_options(int argc, char *argv[]);

#endif
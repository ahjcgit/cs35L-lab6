#ifndef OPTIONS_H
#define OPTIONS_H

enum Input { RDRAND, LRAND48, FILE };
enum Output { STDIO, BYTES };

//Every options held in struct
typedef struct {
    int valid;
    enum Input input_mode;
    enum Output output_mode;
    char* file_dir;
    unsigned int blocksize;
    long long nbytes;

} ProgramOptions;

//Function to parse arguments
ProgramOptions parse_options(int argc, char *argv[]);

#endif
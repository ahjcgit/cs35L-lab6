#ifndef OPTIONS_H
#define OPTIONS_H

//Every options held in struct
typedef struct {
    _Bool valid;
    enum Input input_mode;
    enum Output output_mode;
    char* file_dir;
    unsigned int blocksize;

} ProgramOptions;

//Function to parse arguments
ProgramOptions parse_options(int argc, char *argv[]);

#endif
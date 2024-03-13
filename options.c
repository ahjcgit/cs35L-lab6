#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "options.h"

ProgramOptions parse_options(int argc, char *argv[]){
    ProgramOptions options;

    //Initializing default cases
    options.input_mode = "rdrand"; //Default case
    options.output_mode = "stdio"; //Default case
    options.valid = 0;
    options.file = NULL;
    options.blocksize = 0;

    int opt;
    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
        case 'i':
            if (strcmp(optarg, "rdrand") == 0){
                options.input_mode = "rdrand";
            } else if (strcmp(optarg, "lrand48_r") == 0)
            options.input_mode = "ldrand48_r";
            else{
                options.input_mode = "file";
                options.file = optarg;
            }
            options.valid = 1;
            break;
        
        case 'o':
            if (strcmp(optarg, "stdio") == 0){
                options.output_mode = "stdio";
            } else {
                options.output_mode = "bytes";
                options.blocksize = atoi(optarg);
            }
            break;
        default: // '?' for unrecognized options and missing option arguments
            fprintf(stderr, "Usage: %s [-i input_source] [-o output_mode]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if (optind < argc){
        options.nbytes = atoll(argv[optind]);
    } else {
        fprint(stderr, "Expected argument after option\n");
        return options;
    }

    options.valid = 1;
    return options;
}

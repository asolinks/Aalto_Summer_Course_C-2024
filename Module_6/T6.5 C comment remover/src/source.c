
#include "source.h"
#include <stdlib.h>
#include <string.h>

/**
 * \brief Removes the C comments from the input C code.
 *
 * \details The function polishes the code by */
//          - removing the block comments delimited by /* and */.
/*            These comments may span multiple lines.You should remove only */
//            characters starting with /* and ending with */. The characters,
/*            including white space characters (' ', \n, \r, \t), */
//            after */ should not be removed.
/*
 *          - remove the line comments starting with // until and including the
 *            newline character \n.
 *
 * \param input A code segment that contains some comments.It is a dynamically
 *              allocated string(array of characters).
 * \return A pointer to the polished code
 */



char *delete_comments(char *input) {
    char *output = (char *)malloc(strlen(input) + 1);
    if (!output) {
        return NULL; // Handle allocation failure
    }
    char *in = input;
    char *out = output;
    int inside_block_comment = 0;
    int nested_block_comments = 0;
    int in_string = 0;
    int in_char = 0;
    int in_preprocessor = 0;

    while (*in != '\0') {
        if (!inside_block_comment && !in_string && !in_char && !in_preprocessor) {
            if (*in == '/') {
                if (*(in + 1) == '/') {
                    // Skip everything until the end of the line or end of input
                    in += 2;
                    while (*in != '\n' && *in != '\0') {
                        in++;
                    }
                    // Skip the newline character as well
                    if (*in == '\n') {
                        in++;
                    }
                } else if (*(in + 1) == '*') {
                    inside_block_comment = 1;
                    nested_block_comments = 0;
                    in += 2;
                } else {
                    *out++ = *in++;
                }
            } else if (*in == '"') {
                in_string = !in_string;
                *out++ = *in++;
            } else if (*in == '\'') {
                in_char = !in_char;
                *out++ = *in++;
            } else if (*in == '#') {
                in_preprocessor = 1;
                *out++ = *in++;
            } else {
                *out++ = *in++;
            }
        } else if (inside_block_comment) {
            if (*in == '*' && *(in + 1) == '/') {
                if (nested_block_comments > 0) {
                    nested_block_comments--;
                } else {
                    inside_block_comment = 0;
                }
                in += 2;
            } else if (*in == '/' && *(in + 1) == '*') {
                nested_block_comments++;
                in += 2;
            } else {
                in++;
            }
        } else if (in_string) {
            // Handle escaped quotes
            if (*in == '\\' && *(in + 1) == '"') {
                in += 2;
                *out++ = '\\';
                *out++ = '"';
            } else if (*in == '"') {
                in_string = 0;
                *out++ = *in++;
            } else {
                *out++ = *in++;
            }
        } else if (in_char) {
            // Handle escaped quotes
            if (*in == '\\' && *(in + 1) == '\'') {
                in += 2;
                *out++ = '\\';
                *out++ = '\'';
            } else if (*in == '\'') {
                in_char = 0;
                *out++ = *in++;
            } else {
                *out++ = *in++;
            }
        } else if (in_preprocessor) {
            if (*in == '\n') {
                in_preprocessor = 0;
            }
            *out++ = *in++;
        }
    }
    *out = '\0';

    // Free input only if necessary
    if (output != input) {
        free(input);
    }
    return output;
}
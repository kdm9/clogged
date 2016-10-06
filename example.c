/* Copyright © 2016 Kevin Murray <kdmfoss@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "clogged.h"

int
main (int argc, char *argv[])
{
    clg_logger_t *logger = clg_logger_create();

    (void) argc;
    (void) argv;

    clg_logger_default(logger, CLG_LOG_DEBUG);

    /* The following log levels are available */
    clg_log_msg_debug(logger, "Debug message, nice and quiet\n");
    clg_log_msg_info(logger, "Informative message, clearer\n");
    clg_log_msg_warning(logger, "Warning message, pay attention!\n");
    clg_log_msg_error(logger, "Error message, something's gone wrong\n");


    /* Additionally, there is the special "progress" log level */
    clg_log_fmt_info(logger, "Begin loop\n", 0.1);
    for (size_t i = 0; i <= 100; i+=20) {
        sleep(1);
        // This can be used to selectively output often lengthy progress lines
        clg_log_fmt_progress(logger, "  - (%d%)\n", i);
    }
    clg_log_fmt_info(logger, "Done\n", 0.1);

    clg_logger_destroy(logger);
    return EXIT_SUCCESS;
}

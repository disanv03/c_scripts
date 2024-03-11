/* A Low-Level File-Copy Program
 * File-copy program which copies text & binary fi
 *
 */
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char buffer[512], source[128], target[128];
    int inhandle, outhandle, bytes;

    printf("\nEnter source file name");
    gets(source);

    /* O-flags defined in fcntl.h */
    /* Combined using bitwise OR */
    inhandle = open(source, O_RDONLY | O_BINARY);
    /* open retruns interger value, this is a number assigned
     * to a particular file.
     * -1 means that the file couldn't be succesfully opened
     */
    if (inhandle == -1)
        exit(1);

    printf("\nEnter target file name");
    gets(target);

    /* S_IWRITE -> writing to the file permitted */
    /* For permissions, both types.h and stat.h must be included */
    ouhandle = open(target, O_CREAT | O_BINARY | O_WRONLY, S_IWRITE);
    if (outhandle == -1) {
        close(inhandle);
        exit(2);
    }

    while (1) {
        /* read() takes three arguments
         * file handle, address of buffer, maximum bytes to read
         * read() returns the number of bytes actually readed
         */
        bytes = read(inhandle, buffer, 512);
        if (bytes > 0)
            /* bytes therefore is used to tell write(),
             * to know how many bytes to write from buffer to target
             */
            write (outhandle, buffer, bytes);
        else
            break;
    }
    close(inhandle);
    close(outhandle);
    return 0;
}

        

}


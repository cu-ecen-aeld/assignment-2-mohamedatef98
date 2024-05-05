#include <stdio.h>
#include <syslog.h>

const char* const ERR_WRONG_ARG_COUNT = "Wrong number of arguments";
const char* const ERR_FILE_NO_EXIST = "File doesn't exist";

int main (int argc, char **argv)
{
    const char* retStatus = 0;
    int retVal = 0;

    if (argc != 3)
    {
        retStatus = ERR_WRONG_ARG_COUNT;
    }
    else
    {
        // argc is 3, so the indexing below is safe
        const char* filePath = argv[1];
        const char* writeStr = argv[2];
        FILE* filePtr = fopen(filePath, "w");
        if (filePtr != NULL)
        {
            syslog(LOG_DEBUG | LOG_USER, "Writing %s to %s", writeStr, filePath);

            while (*writeStr != '\0')
            {
                fputc(*writeStr, filePtr);
                writeStr++;
            }

            retStatus = 0;

        }
        else
        {
            retStatus = ERR_FILE_NO_EXIST;
        }
    }

    if (retStatus != 0)
    {
        syslog(LOG_ERR | LOG_USER, "%s", retStatus);
        retVal =  1;
    }

    closelog();

    return retVal;
}

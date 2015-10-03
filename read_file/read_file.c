#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    uint8_t sum = 0;

    if (argc < 2) return EXIT_FAILURE;

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) return EXIT_FAILURE;

    for(;;)
    {
        uint8_t buffer;
        size_t bytes_read = fread(&buffer, sizeof(uint8_t), 1, fp);
        if (feof(fp)) break;
        assert(bytes_read == 1);

        sum += buffer;
    }
    if (ferror(fp)) return EXIT_FAILURE;
    if (fclose(fp) != 0) return EXIT_FAILURE;

    printf("%i\n", sum);
    return EXIT_SUCCESS;
}

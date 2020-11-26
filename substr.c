#include <stdio.h>
#include <string.h>

//#define DEBUG   1 /* Enable debugs */

/* Just to print to debug */
void print_chars(char *in, int count) {
    int i;
    for (i = 0; i < count; i++)
        printf("%c", in[i]);
    return;
}

void find_substr(char *inp) {
    char max_str[100];
    int match_chars = 0;
    int match_count = 0;
    int prev_matched = 0;
    int i, j, k;
    int inp_len;

    memset(max_str, 0, strlen(max_str));

    /* Move by each char and start from there till end
     * Once you move each char, take 2 chars atleast and start from there
     * Till we can reach right side less than left side: TODO
     */
    inp_len = strlen(inp);
    for (i = 0; i < (inp_len - 1); i++) { /* Starting char */
        for (j = (i + 2); j < (inp_len - 1); j++) { /* start comparing from 2 chars till end. TODO: Optmz for len/2 */
            for (k = j, match_count = 0; k < (inp_len - 1); k++) {
                /* String is - SATHISHTHISH - i = S, j = S, k = A
                 * Take input compare from j to k - SA for example
                 * Compare with string start with index k 
                 * Each loop, just move a character and compare for chars of len (j - i)
                 */
                if (strncmp(&inp[i], &inp[k], (j - i)) == 0) {
#ifdef DEBUG
                    printf("Substring found for str: ");
                    print_chars(&inp[k], (j - i));
                    printf(" at location : %d\n", k);
#endif /* DEBUG */
                    match_count++;
                }
            }
            if (match_count && ((match_count > prev_matched) || 
                        ((match_count == prev_matched) && ((j - i) > match_chars)))) {
                // Save matched chars here
                strncpy(max_str, &inp[i], (j - i));
                prev_matched = match_count;
                match_chars = j - i;
                //Debug
#ifdef DEBUG
                printf("Save max chars str: %s, ccount: %d, count: %d\n", &inp[i], match_chars, match_count);
#endif /* DEBUG */
            }
        }
    }
    if (prev_matched)
        printf("\nInput String: %s\n\t Substring: %s of count: %d\n", inp, max_str, (prev_matched+1));
    else
        printf("\nInput String: %s\n\t No substring found\n", inp);

    return;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <String>\n\tEx: %s TESTETESTSTST\n", argv[0], argv[0]);
        return -1;
    }
    //find_substr("TESTETESTSTST");
    //find_substr("SATHISHTHIS");
    find_substr(argv[1]);

    return 0;
}

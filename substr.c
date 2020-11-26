#include <stdio.h>
#include <string.h>

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
		for (j = (i + 2); j < (inp_len - i); j++) { /* j-i : num char comparision */
			for (k = (j + 1), match_count = 0; k < (inp_len - 1); k++) {
				/* String is - SATHISHTHISH - i = S, j = S, k = A
				 * Take input compare from j to k - SA for example
				 * Compare with string start with index k */
				if (strncmp(&inp[i], &inp[k], (j - i)) == 0) {
					//Debug
					//printf("Match found: str: %s, cmp_str: %s, max_chars: %d\n", &inp[i], &inp[k], j-i);
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
				//printf("Save max chars str: %s, ccount: %d, count: %d\n", &inp[i], match_chars, match_count);
			}
		}
	}
	printf("Input String: %s, Substring: %s of count: %d\n", inp, max_str, (prev_matched+1));
	
	return;
}

int main() {
	find_substr("TESTETESTSTST");
	find_substr("SATHISHTHIS");
	find_substr("GEEKSFORGEEKS");
}

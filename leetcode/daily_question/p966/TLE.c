#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
      c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    return true;
  }
  return false;
}

int strcomplexcmp(const char *str1, const char *str2) {

  int len1, len2;
  int i;

  len1 = strlen(str1);
  len2 = strlen(str2);
  for (i = 0; i < len1 && i < len2; i++) {
    if (str1[i] == str2[i]) {
      continue;
    } else if (isVowel(str1[i]) && isVowel(str2[i])) {
      continue;
    } else if (tolower(str1[i]) == tolower(str2[i])) {
      continue;
    } else {
      return str1[i] - str2[i];
    }
  }
  if (str1[i] == '\0' && str2[i] == '\0') {
    return 0;
  } else {
    return str1[i] - str2[i];
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **spellchecker(char **wordlist, int wordlistSize, char **queries,
                    int queriesSize, int *returnSize) {
  char **returnArray;
  char *totally_matched;
  char *case_matched;
  char *vowel_matched;
  char *complex_matched;

  *returnSize = queriesSize;
  returnArray = (char **)malloc(queriesSize * sizeof(char *));

  for (int i = 0; i < queriesSize; i++) {
    totally_matched = NULL;
    case_matched = NULL;
    vowel_matched = NULL;
    complex_matched = NULL;

    for (int j = 0; j < wordlistSize; j++) {
      if (strcmp(wordlist[j], queries[i]) == 0 && totally_matched == NULL) {
        totally_matched = wordlist[j];
        break;
      } else if (strcasecmp(wordlist[j], queries[i]) == 0 &&
                 case_matched == NULL) {
        case_matched = wordlist[j];
      } else if (strcomplexcmp(wordlist[j], queries[i]) == 0 &&
                 complex_matched == NULL) {
        complex_matched = wordlist[j];
      }
    }

    if (totally_matched) {
      returnArray[i] = strdup(totally_matched);
    } else if (case_matched) {
      returnArray[i] = strdup(case_matched);
    } else if (complex_matched) {
      returnArray[i] = strdup(complex_matched);
    } else {
      returnArray[i] = strdup("");
    }
  }
  return returnArray;
}

int main() {
  char *wordlist[] = {"KiTe", "kite", "hare", "Hare"};
  int wordlistSize = 4;
  char *queries[] = {"kite", "Kite", "KiTe", "Hare", "HARE",
                     "Hear", "hear", "keti", "keet", "keto"};

  int queriesSize = 10;
  int returnSize = queriesSize;
  char **returnArray;
  returnArray =
      spellchecker(wordlist, wordlistSize, queries, queriesSize, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%s, ", returnArray[i]);
    free(returnArray[i]);
  }
  free(returnArray);
}

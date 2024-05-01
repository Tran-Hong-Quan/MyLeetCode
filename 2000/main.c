char* reversePrefix(char* word, char ch) {
    int chIndex = -1;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (word[i] == ch) {
            chIndex = i;
            break;
        }
    }
    if (chIndex == 0 || chIndex == -1) {
        return word;
    }

    int i = 0;
    while (i < chIndex) {
        char t = word[chIndex];
        word[chIndex] = word[i];
        word[i] = t;
        i++;
        chIndex--;
    }

    return word;
}
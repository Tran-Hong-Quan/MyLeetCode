#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int findRotateSteps(char *ring, char *key);

int main()
{
    char key[] = "yyynnnnnnlllggg";
    char ring[] = "nyngl";
    printf("%d", findRotateSteps(ring, key));
}

int findRotateSteps(char *ring, char *key)
{
    int keyLn = strlen(key);
    int ringLn = strlen(ring);
    int step = 0;

    for (int i = 0; i < keyLn; i++)
    {
        if (key[i] == ring[0])
        {
            step++;
            printf("key = %c,step = %d\n", key[i], step);
            continue;
        }

        int p = 1;

        while (p < ringLn)
        {
            // printf("%c,%c,%c",key[i],ring[p],ring[ringLn-p]);
            if (key[i] == ring[p])
            {
                // Left shift
                char *t = malloc(ringLn);
                strncpy(t, ring, p);
                memmove(ring, ring + p, ringLn - p);
                strncpy(ring + ringLn - p, t, p);
                free(t);

                step += p + 1;

                printf("left: %s,step = %d\n", ring, step);
                break;
            }
            if (key[i] == ring[ringLn - p])
            {
                // Right shift
                char *t = malloc(ringLn);
                strncpy(t, ring + ringLn - p, p);
                memmove(ring + p, ring, ringLn - p);
                strncpy(ring, t, p);
                free(t);

                step += p + 1;
                printf("right: %s,step = %d\n", ring, step);
                break;
            }
            p++;
        }
    }
    return step;
}

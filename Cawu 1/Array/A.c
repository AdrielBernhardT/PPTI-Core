#include <stdio.h>

int main(){
    int views;
    scanf("%d", &views);
    int penonton[views];
    for (int test_case = 1; test_case <= views; test_case++)
    {
        scanf("%d", &penonton[test_case]);
    }
    int teman;
    scanf("%d", &teman);
    int harike, sampaike, sum = 0;
    for (int test_case = 1; test_case <= teman; test_case++)
    {
        scanf("%d %d", &harike, &sampaike);
        for (int i = harike; i <= sampaike; i++)
        {
            sum += penonton[i];
        }
        printf("Case #%d: %d\n", test_case, sum);
        sum = 0;
    }
    return 0;
}

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define CONTEST_COUNT 3
#define TEAM_COUNT 30
#define xi 50
#define REMOVE_COUNT 0

struct Team {
    int rank[CONTEST_COUNT + 1];
    int solve[CONTEST_COUNT + 1];
    double score[CONTEST_COUNT + 1];
    double result;
    char name[100];
} e[100];

bool cmp(Team a, Team b) {
    return a.result > b.result;
}

int weight[] = {3, 5, 8};

void reopen() {
    freopen("C:\\Users\\tc200\\Desktop\\2021_TTS\\xi=35  weight={3,5,8}.txt", "w+", stdout);
}

int main() {

    freopen("C:\\Users\\tc200\\Desktop\\2021_TTS\\in.txt", "r", stdin);

    for (int i = 0; i < TEAM_COUNT; i++) {
        scanf("%s", e[i].name);
        for (int j = 0; j < CONTEST_COUNT; j++) {
            scanf("%d%d", &e[i].rank[j], &e[i].solve[j]);
        }
    }

    for (int contest_i = 0; contest_i < CONTEST_COUNT; contest_i++) {
        int all_solve = 0;
        for (int i = 0; i < TEAM_COUNT; i++) {
            all_solve += e[i].solve[contest_i];
        }
        for (int i = 0; i < TEAM_COUNT; i++) {
            e[i].score[contest_i] = e[i].solve[contest_i] * 1.0 / all_solve * (xi - e[i].rank[contest_i]);
        }
    }

    for (int i = 0; i < TEAM_COUNT; i++) {
        printf("%s    ", e[i].name);
        e[i].result = 0;
        for (int j = REMOVE_COUNT; j < CONTEST_COUNT; j++) {
            e[i].score[j] *= weight[j];
            e[i].result += e[i].score[j];
            printf("%.3f    ", e[i].score[j]);
        }
        printf("%.3f\n", e[i].result);
    }

    sort(e, e + TEAM_COUNT, cmp);

    reopen();

    for (int i = 0; i < TEAM_COUNT; i++) {
        printf("%d %s ", i + 1, e[i].name);
        printf("%.3f\n", e[i].result);
    }
    //system("pause");
    return 0;
}

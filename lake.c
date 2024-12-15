#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int y, x;
int matrix[MAX_SIZE][MAX_SIZE];
int judge_matrix[MAX_SIZE][MAX_SIZE];  // 用來標記是否已經訪問過
int lake_areas[MAX_SIZE * MAX_SIZE];   // 儲存每個湖泊的面積
int lake_areas_index = 0;

int dx[] = {1, 0, -1, 0};  // 上下左右方向
int dy[] = {0, 1, 0, -1};

void dfs(int i, int j) {
    judge_matrix[i][j] = 1;  // 標記為已訪問
    lake_areas[lake_areas_index]++;  // 當前湖泊面積+1

    for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir];
        int nj = j + dy[dir];

        // 檢查邊界條件和是否為湖泊
        if (ni >= 0 && ni < y && nj >= 0 && nj < x && matrix[ni][nj] == 1 && judge_matrix[ni][nj] == 0) {
            dfs(ni, nj);  // 遞迴探索
        }
    }
}

void sort_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    scanf("%d %d", &y, &x);

    // 輸入矩陣
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 初始化 judge_matrix，所有位置設為 0，表示未訪問
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            judge_matrix[i][j] = 0;
        }
    }

    // 進行 DFS，尋找所有湖泊
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (matrix[i][j] == 1 && judge_matrix[i][j] == 0) {
                // 找到一個未訪問的湖泊
                lake_areas[lake_areas_index] = 0;  // 重置湖泊面積
                dfs(i, j);  // 執行 DFS
                lake_areas_index++;  // 紀錄下一個湖泊
            }
        }
    }

    // 排序湖泊面積
    sort_array(lake_areas, lake_areas_index);

    // 輸出所有湖泊面積
    for (int i = 0; i < lake_areas_index; i++) {
        printf("%d\n", lake_areas[i]);
    }

    return 0;
}

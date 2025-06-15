#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define TARGET_FREQUENCY_NUM 10
#define MIN_FREQUENCY 1
#define MAX_FREQUENCY 99

int printArray(int arr[HEIGHT][WIDTH]);
int SortTargetArrFrequency(int arr[][TARGET_FREQUENCY_NUM], int lenth);
int scan(int space[][WIDTH], int target[][TARGET_FREQUENCY_NUM], int target_num);
int show(int target[][TARGET_FREQUENCY_NUM], int target_num);

int main() {
	srand(time(NULL));
	int spaceFrequency[HEIGHT][WIDTH], targetFrequency[2][TARGET_FREQUENCY_NUM];

	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			spaceFrequency[i][j] = MIN_FREQUENCY + rand() % (MAX_FREQUENCY - MIN_FREQUENCY + 1);
		}
	}

	printf("��ܱ��y�ϰ�: \n");
	printArray(spaceFrequency);

	while (1) {
		printf("\n�п�J�����n���y���¬}�W�v���`��(��J-1�����{��): ");
		int targetFrequencyNum = 0;
		scanf("%d", &targetFrequencyNum);
		if(targetFrequencyNum == -1) {
			printf("�{�������C\n");
			break;
		} else if (targetFrequencyNum < 1 || targetFrequencyNum > TARGET_FREQUENCY_NUM) {
			printf("�п�J���� 1 �� %d ���Ʀr�C\n", TARGET_FREQUENCY_NUM);
			continue;
		}
		printf("�п�J�����n�j�M���¬}�W�v��:\n");
		for(int i = 0; i < targetFrequencyNum; i++) {
			scanf("%d", &targetFrequency[0][i]);
			if(targetFrequency[0][i] < MIN_FREQUENCY || targetFrequency[0][i] > MAX_FREQUENCY) {
				printf("�W�v�ȥ������� %d �� %d �����C\n", MIN_FREQUENCY, MAX_FREQUENCY);
				i--; // ���ƿ�J
			}
			targetFrequency[1][i] = 0; // ��l�ƭp�ƾ�
		}

		printf("\n�ҭn�j�M���¬}�W�v�P�Ӽƪ���l���p(���Ƨ�):\n");
		for (int i = 0; i < targetFrequencyNum; i++) {
			printf("[%2d] ", targetFrequency[0][i]);
		}
		putchar('\n');
		for (int i = 0; i < targetFrequencyNum; i++) {
			printf("[%2d] ", targetFrequency[1][i]);
		}
		putchar('\n');

		printf("\n�ҭn�j�M���¬}�W�v�P�Ӽƪ���l���p(�w�Ƨ�):\n");
		SortTargetArrFrequency(targetFrequency, targetFrequencyNum);
		for (int i = 0; i < targetFrequencyNum; i++) {
			printf("[%2d] ", targetFrequency[0][i]);
		}
		putchar('\n');
		for (int i = 0; i < targetFrequencyNum; i++) {
			printf("[%2d] ", targetFrequency[1][i]);
		}
		putchar('\n');

		printf("\n�j�M�¬}�W�v��:\n");
		scan(spaceFrequency, targetFrequency, targetFrequencyNum);

		printf("\n�j�M�����A�¬}�W�v�P�ӼƲέp���G:\n");
		show(targetFrequency, targetFrequencyNum);
	}
	system("pause");
	return 0;
}

int printArray(int arr[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			printf("[%2d] ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int SortTargetArrFrequency(int arr[][TARGET_FREQUENCY_NUM], int lenth) {
	for (int i = 0; i < lenth; i++) {
		for (int j = 0; j < lenth - 1 - i; j++) {
			if (arr[0][j] > arr[0][j + 1]) {
				int temp = arr[0][j];
				arr[0][j] = arr[0][j + 1];
				arr[0][j + 1] = temp;
			}
		}
	}
}

int scan(int space[][WIDTH], int target[][TARGET_FREQUENCY_NUM], int target_num) {
	for (int i = 0; i < target_num; i++) {
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				if (space[y][x] == target[0][i]) {
					printf("�¬}�W�v%d�A���m�y�Ь�:(%d, %d)\n", target[0][i], x, y);
					target[1][i] += 1;
				}
			}
		}
	}
}

int show(int target[][TARGET_FREQUENCY_NUM], int target_num) {
	for (int i = 0; i < target_num; i++) {
		printf("�¬}�W�v%d�A�¬}�ƶq��:%d \n", target[0][i], target[1][i]);
	}
}
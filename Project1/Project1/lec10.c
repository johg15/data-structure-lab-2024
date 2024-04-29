#include <stdio.h>
int insertElement(int L[], int n, int x) {
	int i, k = 0, move = 0;
	for (i = 0; i < n; i++) {
		if (L[i] <= x && x <= L[i + 1]) {
			k = i + 1;
			break;
		}
	}
	if (i == n) k = n;

	for (i = n; i > k; i--) {
		L[i] = L[i - 1];
		move++;
	}
	L[k] = x;
	return move;
}

int deleteElement(int L[], int n, int x) {
	int i, m, k = n, move = 0;
	for (i = 0; i < n; i++) {
		if (L[i] == x) {
			k = i;
			break;
		}
	}
	if (i == n) move = n;

	for (i = k; i < n - 1; i++) {
		L[i] = L[i + 1];
		move++;
	}

	return move;
}

int main(void) {
	int list[10] = { 10, 20, 40, 50, 60, 70 };
	int i, move, size = 6;
	printf("\n���� �� ���� ����Ʈ: ");
	for (i = 0; i <= size; i++) printf("%3d ", list[i]);

	move = insertElement(list, size, 30);

	printf("\n���� �� ���� ����Ʈ: ");
	for (i = 0; i <= size; i++) printf("%3d ", list[i]);
	printf("\n������ ����: %d  ", ++size);
	printf("\n�ڸ� �̵� Ƚ��: %d \n", move);

	move = deleteElement(list, size, 30);
	if (move == size) printf("\n��������Ʈ�� ���Ұ� �����ϴ�.\n");
	else {
		printf("\n���� �� ���� ����Ʈ: ");
		for (i = 0; i < size - 1; i++) printf("%3d ", list[i]);
		printf("\n������ ����: %d  ", --size);
		printf("\n�ڸ� �̵� Ƚ��: %d\n", move);
	}

	getchar(); return 0;
}
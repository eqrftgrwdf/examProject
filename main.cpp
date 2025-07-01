//7. ������� ��������� ��������� �� ��������� ������� ������� : (3�)
//a.������� �� ��������
//b.������� ���������� ���������
//c.�������� ����� ���������
//d.�������� ��������� � ��������� ����
//e.������� ��������� � ���������� �����
#include <iostream>
using namespace std;

void addElement(int*& arr, int& size, int value, int position) {
	if (position < 0 || position > size) {
		cout << "Invalid position" << endl;
		return;
	}
	int* newArr = new int[size + 1];
	for (int i = 0; i < position; i++) {
		newArr[i] = arr[i];
	}
	newArr[position] = value;
	for (int i = position; i < size; i++) {
		newArr[i + 1] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size++;
}

void removeElement(int*& arr, int& size, int position) {
	if (position < 0 || position >= size) {
		cout << "Invalid position" << endl;
		return;
	}
	int* newArr = new int[size - 1];
	for (int i = 0; i < position; i++) {
		newArr[i] = arr[i];
	}
	for (int i = position + 1; i < size; i++) {
		newArr[i - 1] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size--;
}

void addBlockToEnd(int*& arr, int& size, int* block, int blockSize) {
	int* newArr = new int[size + blockSize];
	for (int i = 0; i < size; i++) {
		newArr[i] = arr[i];
	}
	for (int i = 0; i < blockSize; i++) {
		newArr[size + i] = block[i];
	}
	delete[] arr;
	arr = newArr;
	size += blockSize;
}

void printArray(int* arr, int size) {
	cout << "Array: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main() {
	srand(time(NULL));
//1. ��������� � ����������� ��� �����, �������� �� � ���� � �� �,
//�������� ������ �������� � ��� ������. (1�)
	int firstNum, secondNum, temp;

	cout << "Enter first num: ";
	cin >> firstNum;
	cout << "Enter second num: ";
	cin >> secondNum;

	temp = secondNum;
	secondNum = firstNum;
	firstNum = temp;
	cout << "First num = " << firstNum << ", Second num = " << secondNum << endl << endl;
	//2. ��������� � ����������� �����, ��������� ������� ���� � �����. (1�)
	int countDigitNum, counter = 0;

	cout << "Enter num: ";
	cin >> countDigitNum;

	while (countDigitNum != 0) {
		countDigitNum /= 10;
		counter++;
	}
	cout << "Count digits in num: " << counter << endl << endl;
	//3. ���������� ������� � ��������� ������� ��������, �� ������
	//�����, �� ������� ���������. ���������, ���� ������� ����������
	//��������� �� �������� ������� ��������, � ����� ���� �������
	//���������� ��������, �� ������ �����.(1�)
	int qPassedExam, qFailedExam;

	cout << "Enter quantity of students who passed the exam: ";
	cin >> qPassedExam;

	cout << "Enter quantity of students who failed the exam: ";
	cin >> qFailedExam;
	cout << endl;

	int totalStudents = qPassedExam + qFailedExam;

	cout << "Percentage of students who passed the exam: " << (float)qPassedExam / totalStudents * 100  << "%" << endl;
	cout << "Percentage of students who failed the exam: " << (float)qFailedExam / totalStudents * 100 << "%" << endl;
	cout << endl;
	//4. ������� ����� � 20 ��������, ����������� ����� �����������
	//������� �� - 20 �� 20. (1�)
	//a.��������� ������� �������� ��������
	//b.��������� ������ �������� ����������
	//c.������� ����������� �������� ����� ��������� �����.
	const int size = 20;
	int arr[size] = {};

	for (size_t i = 0; i < size; i++) {
		arr[i] = rand() % 41 - 20;
	}

	int countNullEls = 0, countNegativeEls = 0, avgNegativeEls = 0, maxPositiveEl = arr[0];

	cout << "Array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	for (int i = 0; i < size; i++) {
		if (arr[i] == 0) countNullEls++;
		if (arr[i] < 0) avgNegativeEls += arr[i], countNegativeEls++;
		if (arr[i] > 0 && arr[i] > maxPositiveEl) maxPositiveEl = arr[i];
	}

	cout << "Count of null elements: " << countNullEls << endl;
	cout << "Average value of negative elements: " << avgNegativeEls / countNegativeEls << endl;
	cout << "Maximum value among positive numbers: " << maxPositiveEl << endl;
	cout << endl;
	//5. ������� ���������� ��������� ����� ������� 5�5: (2�)
	int row = 5, col = 5;
	int** dynamicArr = new int* [row];
	for (int i = 0; i < row; ++i) {
		dynamicArr[i] = new int[col];
	}

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			dynamicArr[i][j] = 10 + rand() % 100;
		}
	}

	cout << "Dynamic array:" << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << dynamicArr[i][j] << " ";
		}
		cout << endl;
	}
	int maxCol = 0, maxSum = 0;
	//a.��������� � ����� ��������� ���� �������� � ������������
	for (int j = 0; j < col; j++) {
		int colSum = 0;
		for (int i = 0; i < row; i++) {
			colSum += dynamicArr[i][j];
		}
		if (colSum > maxSum) {
			maxSum = colSum;
			maxCol = j;
		}
	}
	cout << endl;
	cout << "Row with max sum: " << maxCol << ", sum = " << maxSum << endl;
	cout << endl;
	//b.�������� ������ 3 �� 4 �����
	int firstCol = 3, secondCol = 4, tempNum = 0;

	cout << "Arr after swap 3 and 4 col:" << endl;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cout << dynamicArr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < col; i++) {
		tempNum = dynamicArr[firstCol][i];
		dynamicArr[firstCol][i] = dynamicArr[secondCol][i];
		dynamicArr[secondCol][i] = tempNum;
	}

	cout << "Arr before swap 3 and 4 col:" << endl;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cout << dynamicArr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//c.������ ������ 5 �����.
	firstCol = 4, tempNum = 0;

	cout << "Arr after revers 5 col:" << endl;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cout << dynamicArr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (size_t i = 0; i < row / 2; i++) {
		tempNum = dynamicArr[firstCol][i];
		dynamicArr[firstCol][i] = dynamicArr[firstCol][row - i - 1];
		dynamicArr[firstCol][row - i - 1] = tempNum;
	}

	cout << "Arr after revers 5 col:" << endl;
	for (size_t i = 0; i < col; i++) {
		for (size_t j = 0; j < row; j++) {
			cout << dynamicArr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
//6. ������� ��������� ����� �� ��������� ������� ������� : (3�)
	int* arr2 = nullptr;
	int sizeArr = 0;
	//a.��������� ������ �������� � ���� - ��� �������
	addElement(arr2, sizeArr, 10, 0);
	addElement(arr2, sizeArr, 20, 1);
	addElement(arr2, sizeArr, 15, 1);
	printArray(arr2, sizeArr);

	//b.��������� �������� � ���� - ��� �������
	removeElement(arr2, sizeArr, 1);
	printArray(arr2, size);

	//c.��������� ����� �������� � ����� ������
	int block[] = { 30, 40, 50 };
	addBlockToEnd(arr2, sizeArr, block, 3);
	printArray(arr2, sizeArr);

	delete[] arr2;
	for (int i = 0; i < row; ++i) {
		delete[] dynamicArr[i];
	}
	delete[] dynamicArr;


	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

class Array {
private:
    int* data;
    int size;

public:
    Array() : data(nullptr), size(0) {}

    Array(int sizeP) : size(sizeP) {
        data = new int[size];
    }

    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (int a = 0; a < size; ++a) {
            data[a] = other.data[a];
        }
    }

    ~Array() {
        delete[] data;
    }
    
    void input() {
        for (int a = 0; a < size; ++a) {
            cout << "������� " << a+1 << " �������: ";
            cin >> data[a];
        }
    }

    void print() {
        cout << endl;
        for (int a = 0; a < size; ++a) {
            cout << a + 1 << " ������� �������: " << data[a] << endl;
        }
        cout << endl;
    }

    void NewSize() {
        cout << "\n������� ����� ����������� �������: "<<endl;
        int newSize;
        cin >> newSize;
        int* newData = new int[newSize];
        int copySize = min(size, newSize);
        for (int a = 0; a < copySize; ++a) {
            newData[a] = data[a];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }

    void Sort(int left, int right) {
        if (left < right) {
            int arrindex = partition(left, right);
            Sort(left, arrindex - 1);
            Sort(arrindex + 1, right);
        }
    }

    int partition(int left, int right) {
        int pivot = data[right];
        int i = left - 1;
        for (int b = left; b < right; b++) {
            if (data[b] <= pivot) {
                i++;
                swap(data[i], data[b]);
            }
        }
        swap(data[i + 1], data[right]);
        return i + 1;
    }

    int ArrMin() {
        if (size == 0) {
            cout << "������ ����";
            return 0;
        }
        int min = data[0];
        for (int a = 1; a < size; a++) {
            if (data[a] < min) {
                min = data[a];
            }
        }
        return min;
    }

    int ArrMax() {
        if (size == 0) {
            cout << "������ ����";
            return 0;
        }
        int max = data[0];
        for (int a = 1; a < size; a++) {
            if (data[a] > max) {
                max = data[a];
            }
        }
        return max;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    int size, choice, vib=1;
    cout << "������� ������ �������: ";
    cin >> size;
    cout << endl;

    Array arr(size);
    arr.input();
    while (vib == 1) {
        cout << "\n�������� ��������: \n[1]����� �������\n[2]�������� ����������� �������\n[3]����������\n[4]���/����\n[5]�����\n��� �����: ";
        cin >> choice;
        if (choice < 1 || choice > 5) cout << "������ ������";
        if (choice == 1) arr.print();
        if (choice == 2) arr.NewSize();
        if (choice == 3) {
            arr.Sort(0, size - 1);
            cout << "\n��������������� ������: "<<endl;
            arr.print();
        }
        if (choice == 4) {
            cout << "����������� �������: " << arr.ArrMin() << endl;
            cout << "������������ �������: " << arr.ArrMax() << endl;
        }
        if (choice == 5) {
            vib == 0;
            return 1;
        }
    }

    return 0;
}

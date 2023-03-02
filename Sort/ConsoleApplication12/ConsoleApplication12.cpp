#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>
#include <string>

using namespace std;

//Input random numbers
void zap(int* arr, int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100 + 10;
}

//Visualization
void show(int* arr, int N) {
    SetConsoleCP(866);
    SetConsoleOutputCP(866);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < arr[i]; j++)
            cout << char(219);
        cout << endl;
    }
}
//Show numbers
void show_t(int* arr, int N) {
    Sleep(500);
    system("cls");
    show(arr, N);
}

void show_n(int* arr, int N) {
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
}

//Selection sort
void selection(int* arr, int n, bool viz, bool viz_n) {
    int minendex, temp;
    for (int i = 0; i < n - 1; i++) {
        minendex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minendex]) minendex = j;
        }
        if (minendex != i) {
            temp = arr[i];
            arr[i] = arr[minendex];
            arr[minendex] = temp;
        }

        if (viz == 1) {
            show_t(arr, n);
            cout << endl;
        }

        if (viz_n == 1) {
            show_n(arr, n);
            cout << endl;
        }
    }
}

//Heap sort
void heapify(int* arr, int n, int i) {
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n, bool viz, bool viz_n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        if (viz_n == 1) {
            show_n(arr, n);
            cout << endl;
        }
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        if (viz == 1) {
            show_t(arr, n);
            cout << endl;
        }
        if (viz_n == 1) {
            show_n(arr, n);
            cout << endl;
        }

    }
}

//shaker sort
void shakerSort(int* A, int n, bool viz, bool viz_n) {
    int left = -1, right = n;
    bool flag = 1;

    while (left < right and flag == 1) {
        flag = 0;
        for (int i = left; i < right - 1; i++) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                flag = 1;
            }
        }
        right--;

        if (left == right or flag == 0)
            break;

        flag = 0;

        for (int i = right; i > left + 1; i--) {
            if (A[i - 1] > A[i]) {
                swap(A[i - 1], A[i]);
                flag = 1;
            }
        }
        left++;

        if (viz == 1) {
            show_t(A, n);
            cout << endl;
        }
        if (viz_n == 1) {
            show_n(A, n);
            cout << endl;
        }
    }
}

//Merge sort
void merge(int* arr, int low, int high, int mid)
{
    int i, j, k, c[50000];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }

}

void MergeSort(int* A, int low, int high, bool viz, int n, bool viz_n)
{
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        MergeSort(A, low, mid, viz, n, viz_n);
        MergeSort(A, mid + 1, high, viz, n, viz_n);
        merge(A, low, high, mid);
        if (viz == 1) {
            show_t(A, n);
            cout << endl;
        }
        if (viz_n == 1) {
            show_n(A, n);
            cout << endl;
        }
    }

}

//Inserction sort
void InserctionSort(int* A, int n, bool viz, bool viz_n) {
    int key, j;

    for (int i = 1; i < n; i++) {

        key = A[i];
        j = i - 1;
        while (j >= 0 and A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;

        if (viz == 1) {
            show_t(A, n);
            cout << endl;
        }
        if (viz_n == 1) {
            show_n(A, n);
            cout << endl;
        }
    }
}

//Exchange Sort
void ExchangeSort(int* A, int n, bool viz, bool viz_n) {
    bool flag;

    for (int i = 0; i < n - 1; i++) {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }

        if (viz == 1) {
            show_t(A, n);
            cout << endl;
        }
        if (viz_n == 1) {
            show_n(A, n);
            cout << endl;
        }
        if (flag == 0) break;
    }

}

//Quick sort by partition
int partition(int* A, int low, int high) {

    int pivot = A[high];
    int j = low;
    for (int i = low; i < high; i++) {
        if (A[i] <= pivot) {
            swap(A[i], A[j]);
            j++;
        }
    }

    swap(A[j], A[high]);
    return j;
}

void quickSort(int* A, int low, int high, int n, bool viz, bool viz_n) {

    if (low < high) {

        int pi = partition(A, low, high);

        quickSort(A, low, pi - 1, n, viz, viz_n);
        quickSort(A, pi + 1, high, n, viz, viz_n);
        if (viz_n == 1) {
            show_n(A, n);
            cout << endl;
        }
        if (viz == 1) {
            show_t(A, n);
            cout << endl;
        }

    }
}

//Counting sort
void CountingSort(int* A, int n, bool viz, bool viz_n) {

    int k = A[0];

    for (int i = 1; i < n; i++) {
        if (A[i] > k)
            k = A[i];
    }

    int* B = new int[n];
    int* C = new int[k];

    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
        if (viz == 1) {
            show_t(A, n);
            cout << endl;
        }
        if (viz_n == 1) {
            show_n(A, n);
            cout << endl;
        }
    }
}

//Input number by file
void input_file(int* A, int& i) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fin;
    string path;
    bool work = true;

    while (work == true) {
        cout << "\nEnter a file to fill the array: "; getline(cin, path);
        fin.open(path);

        if (!fin.is_open()) cout << "\nThe file was not found!\n";
        else {
            i = -1;
            while (fin) {
                i++;
                fin >> A[i];
            }
            work = false;
        }

        fin.close();
    }

}

//Output number in file
void output_file(int* A, int n, string path) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ofstream fout;

    bool work = true;

    while (work == true) {

        fout.open(path, fstream::out || ios::app);

        if (!fout.is_open()) {
            cout << "\nOutput file not found!\n";
            cout << "\nEnter the file path for outputting the array: "; getline(cin, path);
        }
        else {
            for (int i = 0; i < n; i++)
                fout << A[i] << " ";
            work = false;
            cout << "\nSorted array saved in file " << path << endl;
        }

        fout.close();
    }
}

int main() {

    const int N = 50000;
    int A[N], B[N];
    int n;
    bool viz = 0, viz_n = 1; //0 - visualization OFF
    bool work = true;
    int action, sort;
    bool flag_zapov = false;
    bool flag_out_file = 0;
    time_t t1;
    string path;



    while (work == true) {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        cout << "\n1. Fill the array with random numbers between 10-109";
        cout << "\n2. Fill the array using a file (limit of 50,000 characters)";
        cout << "\n3. Enter the file to output the array";
        cout << "\n4. Enable/Disable sorting visualization";
        cout << "\n5. Enable/Disable digit sorting visualization";
        cout << "\n6. Choose the sorting method";
        cout << "\n7. Exit the program";
        cout << "\nAction "; cin >> action;

        switch (action) {

        case 1: {
            cout << "\nEnter the number of array elements: "; cin >> n;
            zap(A, n);
            flag_zapov = true;
            cout << "\nThe array has been filled\n";
            break;
        }

        case 2: {
            input_file(A, n);
            flag_zapov = true;
            break;
        }

        case 3: {
            cout << "\nEnter a file to output the array: "; getline(cin, path);
            flag_out_file = 1;
            cout << endl;
            break;
        }

        case 4: {
            if (viz == 1) {
                viz = 0;
                cout << "\nVisualization off\n";
            }
            else {
                viz = 1;
                cout << "\nVisualization on\n";
            }
            break;
        }

        case 5: {
            if (viz_n == 1) {
                viz_n = 0;
                cout << "\nVisualization of numbers off\n";
            }
            else {
                viz_n = 1;
                cout << "\nVisualization of numbers on\n";
            }
            break;
        }

        case 6: {
            if (flag_zapov == true) {
                cout << "\n1. Selection sort";
                cout << "\n2. Heap sort";
                cout << "\n3. Shaker sort";
                cout << "\n4. Merge sort";
                cout << "\n5. Insertion sort";
                cout << "\n6. Bubble sort";
                cout << "\n7. Quick sort";
                cout << "\n8. Counting sort";
                cout << "\nPerform sorting under the number "; cin >> sort;
                if (viz_n == 1) {
                    show_n(A, n);
                    cout << endl;
                }
                t1 = clock();
                switch (sort)
                {
                case 1: {
                    selection(A, n, viz, viz_n);
                    t1 = clock() - t1;
                    cout << "\ntime: " << t1 << endl;
                    break;
                }

                case 2: {
                    heapSort(A, n, viz, viz_n);
                    t1 = clock() - t1;
                    cout << "\ntime: " << t1 << endl;
                    break;
                }

                case 3: {
                    shakerSort(A, n, viz, viz_n);
                    t1 = clock() - t1;
                    cout << "\ntime: " << t1 << endl;
                    break;
                }

                case 4: {
                    MergeSort(A, 0, n - 1, viz, n, viz_n);
                    t1 = clock() - t1;
                    cout << "\ntime: " << t1 << endl;
                    break;
                }

                case 5: {
                    InserctionSort(A, n, viz, viz_n);
                    t1 = clock() - t1;
                    cout << "\ntime: " << t1 << endl;
                    break;
                }

                case 6: {
                    ExchangeSort(A, n, viz, viz_n);
                    t1 = clock() - t1;
                    cout << "\ntime: " << t1 << endl;
                    break;
                }

                case 7: {
                    quickSort(A, 0, n - 1, n, viz, viz_n);
                    t1 = clock() - t1;
                    cout << "\ntime: " << t1 << endl;
                    break;
                }

                case 8: {
                    CountingSort(A, n, viz, viz_n);
                    t1 = clock() - t1;
                    cout << "\ntime: " << t1 << endl;
                    break;
                }

                default:
                    cout << "\nThere is no such sorting in the list";
                    break;
                }
                if (flag_out_file) output_file(A, n, path);
            }
            else cout << "\nYou have not filled the array. Perform action 1 or 2\n";
            break;
        }

        case 7: {
            cout << "\nGoodbye";
            return 0;
            break;
        }

        default:
            cout << "\nThere is no such action";
            break;
        }

    }

}
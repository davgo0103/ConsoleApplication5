// ConsoleApplication5.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;
int get_key(int a, int pass, int m) {
    a = a / pow(m, pass);
    a = a % m;
    return a;
}
void Radix_Sort(int a[], int b[], int n, int m, int k) {
    int i, j, d, pass;
    
    for (pass = 0; pass < k; pass++) {
        int count[10] = { 0 };
        
        for (i = 0; i < n; i++)
        {
            d = get_key(a[i], pass, m);
            count[d]++;
        }
        for (j = 1; j < m; j++)
            count[j] += count[j - 1];
        for (i = n - 1; i >= 0; i--) {
            d = get_key(a[i], pass, m);
            b[count[d] - 1] = a[i];
            count[d]--;
        }
        for (i = 0; i < n; i++)
            a[i] = b[i];
        cout << "-------------------------\n";
        for (j = 0; j < m; j++)
            cout << a[j] << " ";
        cout << endl;
    }
    
}

void distribute(int a[], int b[], int n, int m) {
    int i, j;
    int count[10] = { 0 };
    for (i = 0; i < n; i++) 
        count[a[i]]++;
    for (i = 0; i < m; i++)
        cout << count[i] << " ";
    cout << endl;

    for (j = 1; j < m; j++)
        count[j] += count[j - 1];
    for (i = 0; i < m; i++)
        cout << count[i] << " ";
    cout << endl;

    for (i = n - 1; i >= 0; i--) {
        b[count[a[i]] - 1] = a[i];
        count[a[i]] --;

        cout << "------------------------------\n";
        for (j = 0; j < n; j++)
            cout << b[j] << " ";
        cout << endl;

        for (j = 0; j < m; j++)
            cout << count[j] << " ";
        cout << endl;
    }
    for (i = 0; i < n; i++)
        a[i] = b[i];


}

int a[] = { 985,852,210,320,23,410,420,733,888,552,71,8 };
int b[12] = { 0 };
int main()
{
    Radix_Sort(a,b,12,10,3);
    //distribute(a, b, 12, 10);

    std::cout << "Hello World!\n";
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

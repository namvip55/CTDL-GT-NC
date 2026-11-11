#include <iostream>
#include <string>

using namespace std;

#define TRUE 1
#define FALSE 0
#define VOCUNG 10000000

struct Graph
{
    int N;        // so luong cac dinh cua do thi
    int **A;      // ma tran trong so
};

struct Dijsktra
{
    Graph graph;
    int start;    // dinh dau
    int end;      // dinh cuoi
    int *truoc;   // mang danh dau duong di
    int *dist;    // mang danh dau khoang cach
    int *T;       // mang danh dau dinh da duoc gan nhan
};

void FreeDijsktra(Dijsktra &d)
{
    if (d.graph.N > 0 && d.graph.A != NULL)
    {
        for (int i = 0; i < d.graph.N; i++)
        {
            delete[] d.graph.A[i];
        }
        delete[] d.graph.A;
        d.graph.A = NULL;
    }
    if (d.truoc != NULL) { delete[] d.truoc; d.truoc = NULL; }
    if (d.dist != NULL) { delete[] d.dist; d.dist = NULL; }
    if (d.T != NULL) { delete[] d.T; d.T = NULL; }
}

void Nhap(Dijsktra &d, string filename = "Grap.txt")
{
    FILE* f = freopen(filename.c_str(), "r", stdin);
    if (!f)
    {
        f = freopen("INPUT.txt", "r", stdin);
    }
    if (!f)
    {
        cout << "Khong the mo file " << filename << " hoac INPUT.txt!" << endl;
        d.graph.N = 0;
        return;
    }

    // nhap so dinh cua do thi
    cin >> d.graph.N;
    cout << "So dinh : " << d.graph.N << endl;

    // nhap dinh dau va dinh cuoi cua do thi
    cin >> d.start >> d.end;

    // nhap ma tran cua do thi
    d.graph.A = new int*[d.graph.N];
    for (int i = 0; i < d.graph.N; i++)
    {
        d.graph.A[i] = new int[d.graph.N];
        for (int j = 0; j < d.graph.N; j++)
        {
            cin >> d.graph.A[i][j];
            if (d.graph.A[i][j] == 0) d.graph.A[i][j] = VOCUNG;
        }
    }

    fclose(f);
}

/// Cau 3
void HienThi(Dijsktra d)
{
    cout << "Do thi vua nhap la:" << endl;
    cout << "- So dinh cua do thi: " << d.graph.N << endl;
    cout << "- Ma tran trong so cua do thi:" << endl;
    for (int i = 0; i < d.graph.N; i++)
    {
        for (int j = 0; j < d.graph.N; j++)
        {
            if (d.graph.A[i][j] == VOCUNG)
                cout << 0 << "\t";
            else cout << d.graph.A[i][j] << "\t";
        }
        cout << endl;
    }
}
// Het Cau 3

string GetName(int v)
{
    switch (v)
    {
        case 0:
            return "A";
        case 1:
            return "B";
        case 2:
            return "C";
        case 3:
            return "D";
        case 4:
            return "E";
        case 5:
            return "G";
        case 6:
            return "H";
        default:
            return "Unknown";
    }
}

void HienThiDuongDiNganNhat(Dijsktra d)
{
    int dinhcuoi = d.end;    // Dien dinh cuoi theo dau bai

    cout << "Duong di ngan nhat tu " << GetName(d.start)
         << " den " << GetName(dinhcuoi) << " la" << endl;
    cout << GetName(dinhcuoi) << "<=";    // in dinh cuoi duoi dang char

    int i = d.truoc[dinhcuoi];

    while (i != d.start && i != -1)
    {
        cout << GetName(i) << "<="; // in ra ket qua duoi dang char
        i = d.truoc[i];
    }
    cout << GetName(d.start);    // in dinh dau duoi dang char
    cout << endl << "Do dai duong di la : " << d.dist[dinhcuoi] << endl;
}

bool CheckFullT(Dijsktra d)
{
    for (int i = 0; i < d.graph.N; i++)
    {
        if (!d.T[i]) return 0;
    }
    return 1;
}

void RunDijsktra(Dijsktra &d)
{
    d.truoc = new int[d.graph.N];
    d.dist = new int[d.graph.N];
    d.T = new int[d.graph.N];

    int s = d.start;
    for (int v = 0; v < d.graph.N; v++)
    {
        d.dist[v] = VOCUNG;
        d.truoc[v] = -1;
        d.T[v] = FALSE;
    }
    d.dist[s] = 0;

    while (!CheckFullT(d))
    {
        int u = -1, minp = VOCUNG;
        for (int v = 0; v < d.graph.N; v++)
        {
            if (!d.T[v] && d.dist[v] < minp)
            {
                u = v;
                minp = d.dist[v];
            }
        }

        if (u == -1 || minp == VOCUNG) break;

        d.T[u] = TRUE;

        for (int v = 0; v < d.graph.N; v++)
        {
            if (!d.T[v] && d.graph.A[u][v] != VOCUNG
                && (d.dist[u] + d.graph.A[u][v] <= d.dist[v]))
            {
                d.dist[v] = d.dist[u] + d.graph.A[u][v];
                d.truoc[v] = u;
            }
        }
    }
}

int main()
{
    Dijsktra d;
    d.truoc = NULL;
    d.dist = NULL;
    d.T = NULL;
    d.graph.A = NULL;

    Nhap(d, "Grap.txt");
    if (d.graph.N == 0) return 1;

    // Mac dinh cho Bai 12: A (0) -> H (6)
    if (d.start < 0 || d.start >= d.graph.N) d.start = 0;
    if (d.end < 0 || d.end >= d.graph.N) d.end = 6;

    HienThi(d);
    RunDijsktra(d);
    HienThiDuongDiNganNhat(d);

    FreeDijsktra(d);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

template <size_t N>
class Matrix {
public:
    vector<bitset<N>> A;
    int r, c;

    Matrix(int r, int c) {
        this->r = r;
        this->c = c;
        A.assign(r, bitset<N>(0));
    }

    Matrix(int n) {
        this->r = this->c = n;
        A.assign(n, bitset<N>(0));
        for (int i = 0; i < n; i++) {
            A[i][i] = 1;
        }
    }

    Matrix operator * (const Matrix<N>& B) {
        assert(c == B.r);

        Matrix<N> C(r, B.c);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < B.c; j++) {
                C[i][j] = (A[i] & B[j]).count() % 2;
            }
        }

        return C;
    }
    
    Matrix<N> operator ^ (long long n) {
        assert(r == c);

        Matrix<N> result(r, c);
        Matrix<N> base(*this);

        for (int i = 0; i < r; i++) {
            result.A[i][i] = 1;
        }

        while (n > 0) {
            if (n & 1) result = result * base;
            base = base * base;
            n >>= 1;
        }

        return result;
    }
    
    bitset<N>& operator [] (int i) {
        return A[i];
    }

    const bitset<N>& operator [] (int i) const {
        return A[i];
    }
};

int h, w;
bool grid[1005][1005], ans[1005][1005] = {0};

void toggle(int x, int y) {
	grid[x][y] ^= 1;
	if (x > 0) grid[x - 1][y] ^= 1;
	if (y > 0) grid[x][y - 1] ^= 1;
	if (x < h) grid[x + 1][y] ^= 1;
	if (y < w) grid[x][y + 1] ^= 1;
	ans[x][y] ^= 1;
}

void chase() {
	for (int i = 0; i < h - 1; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j]) toggle(i + 1, j);
		}
	}
}

void gauss(Matrix<1005> mat) {
	vector<int> where(w, -1);
    for (int col = 0, row = 0; col < w && row < w; col++) {
        for (int i = row; i < w; i++)
            if (mat[i][col]) {
                swap(mat[i], mat[row]);
                break;
            }
        if (!mat[row][col])
            continue;
        where[col] = row;

        for (int i = 0; i < w; i++)
            if (i != row && mat[i][col])
                mat[i] ^= mat[row];
        row++;
    }
    
    for (int i = 0; i < w; ++i)
        if (where[i] != -1)
            if(mat[where[i]][w]) toggle(0, i);
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char ch; cin >> ch;
			grid[i][j] = ch == '1';
		}
	}
	
	chase();

    Matrix<2005> finalMatrix(2 * w, 2 * w);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
			if (i == j || i == j + 1 || i == j - 1) finalMatrix[i][j] = 1;
			if (i == j) finalMatrix[i][j + w] = 1, finalMatrix[i + w][j] = 1;
        }
    }
    
    finalMatrix = finalMatrix ^ h;
	
	Matrix<1005> augmented(w, w + 1);
	for (int i = 0; i < w; i++)
		for (int j = 0; j < w; j++)
			augmented[i][j] = finalMatrix[i][j];
	for (int i = 0; i < w; i++)
		augmented[i][w] = grid[h - 1][i];
	
	gauss(augmented);
	
	chase();
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
}

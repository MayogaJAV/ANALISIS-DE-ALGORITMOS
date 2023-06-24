//Matriz Strassen
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	int n = A.size();
	vector<vector<int>> C(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	
	return C;
}

vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	int n = A.size();
	vector<vector<int>> C(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	
	return C;
}
vector<vector<int>> multiplicarStrassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
	int n = A.size();
	if (n == 1) {
		vector<vector<int>> C(1, vector<int>(1));
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	
	int nuevaDimension = n / 2;
	vector<vector<int>> A11(nuevaDimension, vector<int>(nuevaDimension));
	vector<vector<int>> A12(nuevaDimension, vector<int>(nuevaDimension));
	vector<vector<int>> A21(nuevaDimension, vector<int>(nuevaDimension));
	vector<vector<int>> A22(nuevaDimension, vector<int>(nuevaDimension));
	
	vector<vector<int>> B11(nuevaDimension, vector<int>(nuevaDimension));
	vector<vector<int>> B12(nuevaDimension, vector<int>(nuevaDimension));
	vector<vector<int>> B21(nuevaDimension, vector<int>(nuevaDimension));
	vector<vector<int>> B22(nuevaDimension, vector<int>(nuevaDimension));
	
	for (int i = 0; i < nuevaDimension; i++) {
		for (int j = 0; j < nuevaDimension; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][j + nuevaDimension];
			A21[i][j] = A[i + nuevaDimension][j];
			A22[i][j] = A[i + nuevaDimension][j + nuevaDimension];
			
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][j + nuevaDimension];
			B21[i][j] = B[i + nuevaDimension][j];
			B22[i][j] = B[i + nuevaDimension][j + nuevaDimension];
		}
	}
	vector<vector<int>> P1 = multiplicarStrassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
	vector<vector<int>> P2 = multiplicarStrassen(sumarMatrices(A21, A22), B11);
	vector<vector<int>> P3 = multiplicarStrassen(A11, restarMatrices(B12, B22));
	vector<vector<int>> P4 = multiplicarStrassen(A22, restarMatrices(B21, B11));
	vector<vector<int>> P5 = multiplicarStrassen(sumarMatrices(A11, A12), B22);
	vector<vector<int>> P6 = multiplicarStrassen(restarMatrices(A21, A11), sumarMatrices(B11, B12));
	vector<vector<int>> P7 = multiplicarStrassen(restarMatrices(A12, A22), sumarMatrices(B21, B22));
	vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(P1, P4), P5), P7);
	vector<vector<int>> C12 = sumarMatrices(P3, P5);
	vector<vector<int>> C21 = sumarMatrices(P2, P4);
	vector<vector<int>> C22 = sumarMatrices(restarMatrices(sumarMatrices(P1, P3), P2), P6);
	vector<vector<int>> C(n, vector<int>(n));
	
	for (int i = 0; i < nuevaDimension; i++) {
		for (int j = 0; j < nuevaDimension; j++) {
			C[i][j] = C11[i][j];
			C[i][j + nuevaDimension] = C12[i][j];
			C[i + nuevaDimension][j] = C21[i][j];
			C[i + nuevaDimension][j + nuevaDimension] = C22[i][j];
		}
	}
	
	return C;
}

void imprimirMatriz(const vector<vector<int>>& matriz) {
	int n = matriz.size();
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cout << "Ingrese la dimension de las matrices: ";
	cin >> n;
	vector<vector<int>> matrizA(n, vector<int>(n));
	cout << "Ingrese los elementos de la matriz A:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrizA[i][j];
		}
	}
	
	vector<vector<int>> matrizB(n, vector<int>(n));
	cout << "Ingrese los elementos de la matriz B:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrizB[i][j];
		}
	}
	vector<vector<int>> matrizC = multiplicarStrassen(matrizA, matrizB);
	cout << "Matriz resultante:" << endl;
	imprimirMatriz(matrizC);
	
	return 0;
}

#include <iostream>

using namespace std;
const int M = 3;
const int N = 3;
void genererVecteur(int v[], int n, int r) {
	for (int i = 0; i < n; ++i) {
		v[i] = 1 + i * r;
	}

}

void afficherTableau(const int v[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}
void inverserVecteur(int v[], int n) {
	for (int i = 0; i < n / 2; ++i)
	{
		int temp = v[i];
		v[i] = v[n - i - 1];
		v[n - i - 1] = temp;
	}
}
void genererMatrice(int mat[][M], int n, int r) {
	for (int i = 0; i < n; i++) {
		genererVecteur(mat[i], M, r++);
	}
}
void afficherMatrice(int mat[][M], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < M; j++) {
			cout << mat[i][j] << " ";

		}
		cout << endl;
	}
}

void transposeMatrice(int mat[][M], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < M; j++) {
			int temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}
}

void tournerMatrice(int mat[][M], int n) {
	transposeMatrice(mat, n);
	for (int i = 0; i < n; i++) {
		inverserVecteur(mat[i], M);
	}
}
int main() {
	// Partie 1 : Generer et inverser un tableau
	int tailleVecteur = M;
	int raisonVecteur = 2;
	int vec[M];
	genererVecteur(vec, tailleVecteur, raisonVecteur);
	cout << "Tableau genere : ";
	afficherTableau(vec, tailleVecteur);
	inverserVecteur(vec, tailleVecteur);
	cout << "Tableau inverse : ";
	afficherTableau(vec, tailleVecteur);
	// Partie 2 : Generer et faire une rotation d'une matrice
	int tailleMatrice = N;
	int raisonMatrice = 2;
	int matrix[N][M];
	genererMatrice(matrix, tailleMatrice, raisonMatrice);
	cout << "Matrice generee : " << endl;
	afficherMatrice(matrix, tailleMatrice);
	//transposeMatrice(matrix, tailleMatrice);
	cout << "Transpose" << endl;
	afficherMatrice(matrix, tailleMatrice);
	tournerMatrice(matrix, tailleMatrice);
	cout << "Rotation de 90 degres" << endl;
	afficherMatrice(matrix, tailleMatrice);

	return 0;
}
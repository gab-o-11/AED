#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class SegmentTree2D {
private:
    int n, m; // Dimensiones de la matriz
    vector<vector<int>> tree; // Árbol de segmentos 2D
    vector<vector<int>> matrix; // Matriz original

    // Construcción del Segment Tree para la dimensión Y
    void buildY(int nodeX, int startX, int endX, int nodeY, int startY, int endY) {
        if (startY == endY) {
            if (startX == endX) {
                tree[nodeX][nodeY] = matrix[startX][startY];
            } else {
                tree[nodeX][nodeY] = tree[2 * nodeX + 1][nodeY] + tree[2 * nodeX + 2][nodeY];
            }
        } else {
            int midY = (startY + endY) / 2;
            buildY(nodeX, startX, endX, 2 * nodeY + 1, startY, midY);
            buildY(nodeX, startX, endX, 2 * nodeY + 2, midY + 1, endY);
            tree[nodeX][nodeY] = tree[nodeX][2 * nodeY + 1] + tree[nodeX][2 * nodeY + 2];
        }
    }

    // Construcción del Segment Tree para la dimensión X
    void buildX(int nodeX, int startX, int endX) {
        if (startX != endX) {
            int midX = (startX + endX) / 2;
            buildX(2 * nodeX + 1, startX, midX);
            buildX(2 * nodeX + 2, midX + 1, endX);
        }
        buildY(nodeX, startX, endX, 0, 0, m - 1);
    }

    // Actualización del Segment Tree en la dimensión Y
    void updateY(int nodeX, int startX, int endX, int nodeY, int startY, int endY, int x, int y, int value) {
        if (startY == endY) {
            if (startX == endX) {
                tree[nodeX][nodeY] = value;
            } else {
                tree[nodeX][nodeY] = tree[2 * nodeX + 1][nodeY] + tree[2 * nodeX + 2][nodeY];
            }
        } else {
            int midY = (startY + endY) / 2;
            if (y <= midY) {
                updateY(nodeX, startX, endX, 2 * nodeY + 1, startY, midY, x, y, value);
            } else {
                updateY(nodeX, startX, endX, 2 * nodeY + 2, midY + 1, endY, x, y, value);
            }
            tree[nodeX][nodeY] = tree[nodeX][2 * nodeY + 1] + tree[nodeX][2 * nodeY + 2];
        }
    }

    // Actualización en la dimensión X
    void updateX(int nodeX, int startX, int endX, int x, int y, int value) {
        if (startX != endX) {
            int midX = (startX + endX) / 2;
            if (x <= midX) {
                updateX(2 * nodeX + 1, startX, midX, x, y, value);
            } else {
                updateX(2 * nodeX + 2, midX + 1, endX, x, y, value);
            }
        }
        updateY(nodeX, startX, endX, 0, 0, m - 1, x, y, value);
    }

    // Consulta en la dimensión Y
    int queryY(int nodeX, int nodeY, int startY, int endY, int y1, int y2) {
        if (y1 > endY || y2 < startY) {
            return 0;
        }
        if (y1 <= startY && endY <= y2) {
            return tree[nodeX][nodeY];
        }
        int midY = (startY + endY) / 2;
        int left_sum = queryY(nodeX, 2 * nodeY + 1, startY, midY, y1, y2);
        int right_sum = queryY(nodeX, 2 * nodeY + 2, midY + 1, endY, y1, y2);
        return left_sum + right_sum;
    }

    // Consulta en la dimensión X
    int queryX(int nodeX, int startX, int endX, int x1, int x2, int y1, int y2) {
        if (x1 > endX || x2 < startX) {
            return 0;
        }
        if (x1 <= startX && endX <= x2) {
            return queryY(nodeX, 0, 0, m - 1, y1, y2);
        }
        int midX = (startX + endX) / 2;
        int left_sum = queryX(2 * nodeX + 1, startX, midX, x1, x2, y1, y2);
        int right_sum = queryX(2 * nodeX + 2, midX + 1, endX, x1, x2, y1, y2);
        return left_sum + right_sum;
    }

public:
    SegmentTree2D(const vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        matrix = mat;
        tree.resize(4 * n, vector<int>(4 * m, 0));
        buildX(0, 0, n - 1);
    }
    void update(int x, int y, int value) {
        updateX(0, 0, n - 1, x, y, value);
    }
    int query(int x1, int y1, int x2, int y2) {
        return queryX(0, 0, n - 1, x1, x2, y1, y2);
    }
};


void parseMatrix(const string& input, vector<vector<int>>& matrix) {
    istringstream iss(input);
    int n, m;
    iss >> n >> m;
    matrix.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            iss >> matrix[i][j];
}

int main() {
    SegmentTree2D* st = nullptr; // Segment Tree global (apuntador)
    string operation;

    while (true) {
        getline(cin, operation);

        if (operation == "BUILD") {
            string input;
            getline(cin, input);

            vector<vector<int>> matrix;
            parseMatrix(input, matrix);
            st = new SegmentTree2D(matrix); // Construye el árbol y asigna a `st`

            cout << "OK" << endl; // Responde al frontend que la construcción fue exitosa
        } else if (operation == "QUERY") {
            if (st == nullptr) {
                cout << "ERROR: Segment Tree not built yet." << endl;
                continue;
            }

            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cin.ignore(); // Limpia el buffer de entrada
            cout << st->query(x1, y1, x2, y2) << endl;
        } else if (operation == "UPDATE") {
            if (st == nullptr) {
                cout << "ERROR: Segment Tree not built yet." << endl;
                continue;
            }

            int x, y, value;
            cin >> x >> y >> value;
            cin.ignore(); // Limpia el buffer de entrada
            st->update(x, y, value);
            cout << "UPDATED" << endl; // Notifica al frontend
        } else if (operation == "EXIT") {
            break; // Sale del bucle y finaliza el programa
        } else {
            cout << "ERROR: Unknown operation." << endl;
        }
    }

    delete st; // Libera la memoria del árbol antes de salir
    return 0;
}

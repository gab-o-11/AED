class SegmentTree2D:
    def __init__(self, matrix):
        self.n = len(matrix)
        self.m = len(matrix[0])
        self.matrix = matrix
        self.tree = [[0] * (4 * self.m) for _ in range(4 * self.n)]
        self.build_x(0, 0, self.n - 1)

    def build_y(self, node_x, start_x, end_x, node_y, start_y, end_y):
        if start_y == end_y:
            if start_x == end_x:
                self.tree[node_x][node_y] = self.matrix[start_x][start_y]
            else:
                self.tree[node_x][node_y] = self.tree[2 * node_x + 1][node_y] + self.tree[2 * node_x + 2][node_y]
        else:
            mid_y = (start_y + end_y) // 2
            self.build_y(node_x, start_x, end_x, 2 * node_y + 1, start_y, mid_y)
            self.build_y(node_x, start_x, end_x, 2 * node_y + 2, mid_y + 1, end_y)
            self.tree[node_x][node_y] = self.tree[node_x][2 * node_y + 1] + self.tree[node_x][2 * node_y + 2]

    def build_x(self, node_x, start_x, end_x):
        if start_x != end_x:
            mid_x = (start_x + end_x) // 2
            self.build_x(2 * node_x + 1, start_x, mid_x)
            self.build_x(2 * node_x + 2, mid_x + 1, end_x)
        self.build_y(node_x, start_x, end_x, 0, 0, self.m - 1)

    def update_y(self, node_x, start_x, end_x, node_y, start_y, end_y, x, y, value):
        if start_y == end_y:
            if start_x == end_x:
                self.tree[node_x][node_y] = value
            else:
                self.tree[node_x][node_y] = self.tree[2 * node_x + 1][node_y] + self.tree[2 * node_x + 2][node_y]
        else:
            mid_y = (start_y + end_y) // 2
            if y <= mid_y:
                self.update_y(node_x, start_x, end_x, 2 * node_y + 1, start_y, mid_y, x, y, value)
            else:
                self.update_y(node_x, start_x, end_x, 2 * node_y + 2, mid_y + 1, end_y, x, y, value)
            self.tree[node_x][node_y] = self.tree[node_x][2 * node_y + 1] + self.tree[node_x][2 * node_y + 2]

    def update_x(self, node_x, start_x, end_x, x, y, value):
        if start_x != end_x:
            mid_x = (start_x + end_x) // 2
            if x <= mid_x:
                self.update_x(2 * node_x + 1, start_x, mid_x, x, y, value)
            else:
                self.update_x(2 * node_x + 2, mid_x + 1, end_x, x, y, value)
        self.update_y(node_x, start_x, end_x, 0, 0, self.m - 1, x, y, value)

    def query_y(self, node_x, node_y, start_y, end_y, y1, y2):
        if y1 > end_y or y2 < start_y:
            return 0
        if y1 <= start_y and end_y <= y2:
            return self.tree[node_x][node_y]
        mid_y = (start_y + end_y) // 2
        left_sum = self.query_y(node_x, 2 * node_y + 1, start_y, mid_y, y1, y2)
        right_sum = self.query_y(node_x, 2 * node_y + 2, mid_y + 1, end_y, y1, y2)
        return left_sum + right_sum

    def query_x(self, node_x, start_x, end_x, x1, x2, y1, y2):
        if x1 > end_x or x2 < start_x:
            return 0
        if x1 <= start_x and end_x <= x2:
            return self.query_y(node_x, 0, 0, self.m - 1, y1, y2)
        mid_x = (start_x + end_x) // 2
        left_sum = self.query_x(2 * node_x + 1, start_x, mid_x, x1, x2, y1, y2)
        right_sum = self.query_x(2 * node_x + 2, mid_x + 1, end_x, x1, x2, y1, y2)
        return left_sum + right_sum

    def update(self, x, y, value):
        self.update_x(0, 0, self.n - 1, x, y, value)

    def query(self, x1, y1, x2, y2):
        return self.query_x(0, 0, self.n - 1, x1, x2, y1, y2)


matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
segment_tree = SegmentTree2D(matrix)

# Realizar una consulta
result = segment_tree.query(1, 1, 2, 2)
print("Query result:", result)

# Actualizar un valor
segment_tree.update(1, 1, 10)

# Realizar otra consulta
result = segment_tree.query(1, 1, 2, 2)
print("Query result after update:", result)

class Matrix:
    def __init__(self, rows, cols):
        self.matrix = [[0 for j in range(cols)] for i in range(rows)]

    def getData(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                self.matrix[i][j] = int(input(f"Enter matrix[{i}][{j}] element : "))

    def __add__(self, other):
        if len(self.matrix) != len(other.matrix) or len(self.matrix[0]) != len(other.matrix[0]):
            raise ValueError("Matrix Can't be added because size is different")

        addition = Matrix(len(self.matrix), len(self.matrix[0]))
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                addition.matrix[i][j] = self.matrix[i][j] + other.matrix[i][j]
        return addition

    def __sub__(self, other):
        if len(self.matrix) != len(other.matrix) or len(self.matrix[0]) != len(other.matrix[0]):
            raise ValueError("Matrix Can't be subtracted because size is different")

        subtraction = Matrix(len(self.matrix), len(self.matrix[0]))
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                subtraction.matrix[i][j] = self.matrix[i][j] - other.matrix[i][j]
        return subtraction

    def __mul__(self, other):
        if len(self.matrix[0]) != len(other.matrix):
            raise ValueError("Matrix Can't be multiplied because size is different")
        multiplication = Matrix(len(self.matrix), len(other.matrix[0]))
        for i in range(len(self.matrix)):
            for j in range(len(other.matrix[0])):
                for k in range(len(self.matrix[0])):
                    multiplication.matrix[i][j] = (self.matrix[i][k] * other.matrix[k][j]) + multiplication.matrix[i][j]

        return multiplication

    def __neg__(self):
        transpose = Matrix(len(self.matrix),len(self.matrix[0]))
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                transpose.matrix[j][i] = self.matrix[i][j]
        return transpose

    def print(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[0])):
                print(f"{self.matrix[i][j]} ", end="")
            print()


matrix1 = Matrix(2, 2)
matrix1.getData()
matrix2 = Matrix(2, 2)
matrix2.getData()
matrix = matrix1 * matrix2
matrix.print()
matrix = -matrix
matrix.print()

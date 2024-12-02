import tkinter as tk
from tkinter import messagebox, simpledialog
from TwoDSegmentTree import SegmentTree2D  # Importa tu implementación de TwoDSegmentTree

# Instancia global del Segment Tree 2D
segment_tree = None

# Función para construir el Segment Tree
def build():
    global segment_tree
    try:
        input_matrix = simpledialog.askstring(
            "Input Matrix",
            "Enter the matrix (rows separated by commas, elements separated by spaces):"
        )
        if not input_matrix:
            return

        # Convert input string to matrix
        rows = input_matrix.split(",")
        matrix = [list(map(int, row.split())) for row in rows]

        # Crear el Segment Tree 2D
        segment_tree = SegmentTree2D(matrix)
        messagebox.showinfo("Success", "Segment Tree built successfully!")
    except Exception as e:
        messagebox.showerror("Error", str(e))

# Función para realizar consultas
def query():
    global segment_tree
    if not segment_tree:
        messagebox.showerror("Error", "Segment Tree not built yet!")
        return

    try:
        coords = simpledialog.askstring("Query", "Enter coordinates (x1 y1 x2 y2):")
        if not coords:
            return

        # Parsear las coordenadas
        x1, y1, x2, y2 = map(int, coords.split())

        # Realizar la consulta en el Segment Tree
        result = segment_tree.query(x1, y1, x2, y2)
        messagebox.showinfo("Query Result", f"Result: {result}")
    except Exception as e:
        messagebox.showerror("Error", str(e))

# Función para actualizar el Segment Tree
def update():
    global segment_tree
    if not segment_tree:
        messagebox.showerror("Error", "Segment Tree not built yet!")
        return

    try:
        update_data = simpledialog.askstring("Update", "Enter update data (x y value):")
        if not update_data:
            return

        # Parsear los datos de la actualización
        x, y, value = map(int, update_data.split())

        # Realizar la actualización en el Segment Tree
        segment_tree.update(x, y, value)
        messagebox.showinfo("Success", "Value updated successfully!")
    except Exception as e:
        messagebox.showerror("Error", str(e))

# Crear la ventana principal
root = tk.Tk()
root.title("Segment Tree Manager")

# Crear botones
build_button = tk.Button(root, text="Build Segment Tree", command=build, width=30)
build_button.pack(pady=10)

query_button = tk.Button(root, text="Query Segment Tree", command=query, width=30)
query_button.pack(pady=10)

update_button = tk.Button(root, text="Update Segment Tree", command=update, width=30)
update_button.pack(pady=10)

# Ejecutar la aplicación
root.mainloop()

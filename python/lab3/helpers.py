from tkinter import messagebox

def draw_image(canvas, colors, shape, counter = 0):
    match shape:
        case 1: 
            canvas.create_oval(3, 3, 200, 200, fill=colors[counter],  outline='black', width=3)
        case 2:
            canvas.create_rectangle(3, 50, 200, 150, fill=colors[counter],  outline='black', width=3)
        case 3: 
            canvas.create_rectangle(3, 3, 200, 200, fill=colors[counter],  outline='black', width=3)

def input_validation(shape, dimensions):
    if dimensions is None:
        messagebox.showerror(title="Validation Error", message="Value must be a number")
        return False
    
    if not dimensions: 
        messagebox.showerror(title="Validation Error", message="Value cannot be an empty string")
        return False

    if shape == 2 and len(dimensions) != 2:
        messagebox.showerror(title="Validation Error", message="For a rectangle, enter two numbers separated by a space")
        return False
   
    if shape != 2 and len(dimensions) > 1:
        messagebox.showerror(title="Validation Error", message="Enter just one number to calculate the area and perimeter of a square or circle.")
        return False

    for num in dimensions:
        if num <= 0:
            messagebox.showerror(title="Validation Error", message="Value must be a positive number")
            return False
    
    return True

def format_dimensions(dimensions):
    formatted_dimensions = []
    for num in dimensions:
        num = num.replace(",", ".")
        try:
            formatted_dimensions.append(float(num))
        except ValueError:
            return None
    return formatted_dimensions
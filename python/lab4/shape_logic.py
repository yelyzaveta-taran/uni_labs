from tkinter import *
from tkinter import messagebox
from shapes import  Circle, Rectangle, Square

def input_validation(shape, dimensions, parameters):
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

    for param in parameters:
        if param == "":
            field = ""
            idx = parameters.index(param)

            match idx:
                case 0: 
                    field = "image color"
                case 1: 
                    field = "border color"
                case 3: 
                    field = "border width"

            messagebox.showerror(title="Validation Error", message=f"Missing {field} value")
            return False
    
    return True

def draw_shape(canvas, color, shape, border_width, border_color):
    match shape:
        case 1: 
            canvas.create_oval(20, 20, 180, 180, fill=color,  outline=border_color, width=border_width)
        case 2:
            canvas.create_rectangle(20, 50, 190, 150, fill=color,  outline=border_color, width=border_width)
        case 3: 
            canvas.create_rectangle(20, 20, 180, 180, fill=color,  outline=border_color, width=border_width)

def format_dimensions(dimensions):
    formatted_dimensions = []
    for num in dimensions:
        num = num.replace(",", ".")
        try:
            formatted_dimensions.append(float(num))
        except ValueError:
            return None
    return formatted_dimensions

def create_shape(shape_type, dimensions, parameters):
    match shape_type:
        case 1:
            return Circle(*dimensions, *parameters)
        case 2:
            return Rectangle(*dimensions, *parameters)
        case 3:
            return Square(*dimensions, *parameters)
        case _:
            raise Exception("Invalid type of shape")

    

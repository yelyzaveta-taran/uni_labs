from tkinter import *
from main import Circle, Rectangle, Square

def display_elements():
    selected_shape = shape_int.get()
    placeholder = "Number"
    if selected_shape == 1:
        dimensions_label.config(text="Enter the radius value:")
    elif selected_shape == 2:
        dimensions_label.config(text="Enter the width and height values:")
        placeholder = "Two numbers separated by a space"
    elif selected_shape == 3:
        dimensions_label.config(text="Enter the side length:")
    
    dimensions_input.delete(0, END)
    dimensions_input.grid(row=3, column=0, columnspan=2, padx=(15, 5), pady=10, sticky=W)
    dimensions_input.insert(0, placeholder)

    submit_button.grid(row=3, column=2, padx=(5, 15), pady=10, sticky=W)

def format_dimensions(dimensions):
    formatted_dimensions = []
    for num in dimensions:
        num = num.replace(",", ".")
        try:
            formatted_dimensions.append(float(num))
        except ValueError:
            return None
    return formatted_dimensions

def input_validation(shape, dimensions):
    if dimensions is None:
        validation_label.config(text="Value must be a number", foreground="red")
        return False
    
    if not dimensions: 
        validation_label.config(text="Value cannot be an empty string", foreground="red")
        return False

    if shape == 2 and len(dimensions) != 2:
        validation_label.config(text="For a rectangle, enter two numbers separated by a space", foreground="red")
        return False

    for num in dimensions:
        if num <= 0:
            validation_label.config(text="Value must be a positive number", foreground="red")
            return False
    

    validation_label.config(text="")
    return True

def do_on_btn_submit():
    selected_shape = shape_int.get()
    str_dimensions = dimensions_input.get().split()

    dimensions = format_dimensions(str_dimensions)

    shape = {}

    if input_validation(selected_shape, dimensions):
        match selected_shape:
            case 1:
                shape = Circle(dimensions[0])
            case 2: 
                shape = Rectangle(dimensions[0], dimensions[1])
            case 3:
                shape = Square(dimensions[0])
            case _:
                raise Exception("Invalid type of shape")
    
    print(shape)
        

root = Tk()
root.title("Graphic program in Python")

w = 500 
h = 250

ws = root.winfo_screenwidth() 
hs = root.winfo_screenheight() 

x = (ws/2) - (w/2)
y = (hs/2) - (h/2)

root.geometry('%dx%d+%d+%d' % (w, h, x, y))

shapes = [("Circle", 1), ("Rectangle", 2), ("Square", 3)]

header = Label(text="Choose a shape:", padx=15, pady=10, font=14)
header.grid(row=0, column=0, columnspan=3, sticky=W)

shape_int = IntVar()
column = 0

for txt, val in shapes:
    Radiobutton(text=txt, value=val, borderwidth=4, variable=shape_int, padx=15, pady=10, command=display_elements).grid(row=1, column=column, sticky=W)
    column += 1

dimensions_label = Label(padx=15, pady=10, font=14)
dimensions_label.grid(row=2, column=0, columnspan=3, sticky=W)

dimensions_value = StringVar()
dimensions_input = Entry(textvariable=dimensions_value, width=28, font=12)

submit_button = Button(text="Submit", command=do_on_btn_submit)

validation_label = Label(padx=15, pady=5, font=14)
validation_label.grid(row=4, column=0, columnspan=3, sticky=W)

shape_label = Label(padx=15, pady=5, font=14)
shape_label.grid(row=5, column=0)

root.mainloop()


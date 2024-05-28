from tkinter import *
from main import Circle, Rectangle, Square

def display_elements():
    validation_label.config(text="")
    shape_label.config(text="")

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
    dimensions_input.grid(row=3, column=0, columnspan=4, padx=(15, 5), pady=10, sticky=W)
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
    shape_label.config(text="")
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

def on_btn_submit():
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
    

    if shape: shape_label.config(text=str(shape))

def on_btn_click():
    selected_shape = shape_int.get()
    colors = ["d6ff79", "b0ff92", "5f00ba"]
    btn_text = previous_button.cget('text')



root = Tk()
root.title("Graphic program in Python")

w = 450
h = 500

ws = root.winfo_screenwidth() 
hs = root.winfo_screenheight() 

x = (ws/2) - (w/2)
y = (hs/2) - (h/2)

root.geometry('%dx%d+%d+%d' % (w, h, x, y))

for i in range(4):
    root.grid_columnconfigure(i, weight=1)

shapes = [("Circle", 1), ("Rectangle", 2), ("Square", 3)]

header = Label(text="Choose a shape:", padx=15, pady=10, font=14)
header.grid(row=0, column=0, columnspan=4, sticky=W)

shape_int = IntVar()
column = 0

for txt, val in shapes:
    Radiobutton(text=txt, value=val, borderwidth=4, variable=shape_int, padx=15, pady=10, command=display_elements).grid(row=1, column=column, sticky=W)
    column += 1

dimensions_label = Label(padx=15, pady=10, font=14)
dimensions_label.grid(row=2, column=0, columnspan=5, sticky=W)

dimensions_value = StringVar()
dimensions_input = Entry(textvariable=dimensions_value, width=28, font=12)

submit_button = Button(text="Submit", command=on_btn_submit)

validation_label = Label(padx=15, font=14)
validation_label.grid(row=4, column=0, columnspan=5, sticky=W)

shape_label = Label(padx=5, pady=5, font=("Calibri", 14, "bold"))
shape_label.grid(row=5, column=0, columnspan=5, sticky="s")

canvas = Canvas(root, width=200, height=200)
canvas.grid(row=6, column=0, columnspan=5, pady=20, sticky="s")

# canvas.create_rectangle(3, 3, 200, 200, fill='lightpink',  outline='black',
#                    width=3,
#                    activedash=(5, 4)) 

# canvas.create_rectangle(3, 50, 200, 150, fill='lightpink',  outline='black',
#                    width=3,
#                    activedash=(5, 4))

# canvas.create_oval(3, 3, 200, 200, fill='lightpink',  outline='black',
#                    width=3,
#                    activedash=(5, 4))

previous_button  = Button(text="Previous", command=on_btn_click)
previous_button.grid(row=7, column=0)
root.mainloop()


from tkinter import *
from tkinter import messagebox
from main import Circle, Rectangle, Square

root = Tk()
root.title("Graphic program in Python")

w = 500
h = 600

ws = root.winfo_screenwidth() 
hs = root.winfo_screenheight() 

x = (ws/2) - (w/2)
y = (hs/2) - (h/2)

root.geometry('%dx%d+%d+%d' % (w, h, x, y))

for i in range(5):
    root.grid_columnconfigure(i, weight=1)


counter = 0
colors = ["yellow", "lawn green", "medium orchid"]
shapes = [("Circle", 1), ("Rectangle", 2), ("Square", 3)]


def display_elements():
    shape_label.grid_forget()
    canvas.grid_forget()
    prev_button.grid_forget()
    next_button.grid_forget()

    dimensions_label.grid(row=2, column=0, padx=15, pady=15, columnspan=5, sticky=W)

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
    dimensions_input.grid(row=3, column=0, columnspan=3, padx=(15, 5), pady=10, sticky="we")
    dimensions_input.insert(0, placeholder)

    submit_button.grid(row=3, column=3, padx=(5, 15), pady=10, sticky="we")

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

def on_btn_submit():
    global counter 
    counter = 0

    shape_label.grid_forget()
    canvas.grid_forget()
    prev_button.grid_forget()
    next_button.grid_forget()

    canvas.delete("all")

    selected_shape = shape_int.get()
    str_dimensions = dimensions_input.get().split()

    dimensions = format_dimensions(str_dimensions)

    shape = {}

    if input_validation(selected_shape, dimensions):
        canvas.grid(row=6, column=0, columnspan=5, pady=20, sticky="s")
        match selected_shape:
            case 1:
                shape = Circle(dimensions[0])
                canvas.create_oval(3, 3, 200, 200, fill=colors[0],  outline='black', width=3, activedash=(5, 4))
            case 2: 
                shape = Rectangle(dimensions[0], dimensions[1])
                canvas.create_rectangle(3, 50, 200, 150, fill=colors[0],  outline='black', width=3, activedash=(5, 4))
            case 3:
                shape = Square(dimensions[0])
                canvas.create_rectangle(3, 3, 200, 200, fill=colors[0],  outline='black', width=3, activedash=(5, 4))
            case _:
                raise Exception("Invalid type of shape")    

    if shape:
        shape_label.grid(row=4, column=0, columnspan=5, sticky="s")
        shape_label.config(text=str(shape))
        prev_button.grid(row=0, column=1, padx=(0, 10), sticky="we")
        prev_button.config(state="disabled")
        next_button.grid(row=0, column=2, padx=(10, 0), sticky="we")
        next_button.config(state="normal")

def on_btn_click(btn_text):
    global counter, colors

    selected_shape = shape_int.get()

    if btn_text == "Next":
        counter += 1
    else:
        counter -= 1

    if counter == 0:
        prev_button.config(state="disabled")
    elif counter > 0 and counter != 2: 
        prev_button.config(state="normal")
        next_button.config(state="normal")
    elif counter == 2:
        next_button.config(state="disabled")

    match selected_shape:
        case 1: 
            canvas.create_oval(3, 3, 200, 200, fill=colors[counter],  outline='black', width=3, activedash=(5, 4))
        case 2:
            canvas.create_rectangle(3, 50, 200, 150, fill=colors[counter],  outline='black', width=3, activedash=(5, 4))
        case 3: 
            canvas.create_rectangle(3, 3, 200, 200, fill=colors[counter],  outline='black', width=3, activedash=(5, 4))

header = Label(text="Choose a shape:", font=14)
header.grid(row=0, column=0, padx=15, pady=15, columnspan=5, sticky=W)

shape_int = IntVar()
column = 1

for txt, val in shapes:
    Radiobutton(text=txt, value=val,  variable=shape_int, command=display_elements).grid(row=1, padx=15, pady=10, column=column, sticky="w")
    column += 1

dimensions_label = Label(font=14)

dimensions_value = StringVar()
dimensions_input = Entry(textvariable=dimensions_value, width=28, font=12)

submit_button = Button(text="Submit", command=on_btn_submit)

shape_label = Label(padx=5, pady=5, font=("Calibri", 14, "bold"))

canvas = Canvas(root, width=200, height=200)

button_frame = Frame(root)
button_frame.grid(row=7, column=0, columnspan=5, sticky="we")
button_frame.grid_columnconfigure(0, weight=1)
button_frame.grid_columnconfigure(1, weight=1)
button_frame.grid_columnconfigure(2, weight=1)
button_frame.grid_columnconfigure(3, weight=1)


prev_button = Button(button_frame, text="Previous", command=lambda: on_btn_click(prev_button.cget("text")), state="disabled")
next_button = Button(button_frame, text="Next", command=lambda: on_btn_click(next_button.cget("text")))


root.mainloop()


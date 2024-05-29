from tkinter import *
from tkinter import ttk
from shapes import Circle, Rectangle, Square
from helpers import *

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
            case 2: 
                shape = Rectangle(dimensions[0], dimensions[1])
            case 3:
                shape = Square(dimensions[0])
            case _:
                raise Exception("Invalid type of shape")    

    if shape:
        shape_label.grid(row=4, column=0, columnspan=5, sticky="s")
        shape_label.config(text=str(shape))

        draw_image(canvas, colors, selected_shape)

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

    draw_image(canvas, colors, selected_shape, counter)

root = Tk()
root.title("GUI in Python")

w = 700
h = 550

ws = root.winfo_screenwidth() 
hs = root.winfo_screenheight() 

x = (ws/2) - (w/2)
y = (hs/2) - (h/2)

root.geometry('%dx%d+%d+%d' % (w, h, x, y))

for i in range(5):
    root.grid_columnconfigure(i, weight=1)

header = Label(text="Choose a shape:", font=14)
header.grid(row=0, column=0, padx=15, pady=15, columnspan=5, sticky=W)

radio_frame = Frame(root)
radio_frame.grid(row=1, column=0, columnspan=5, sticky="we")
for i in range(4):
    radio_frame.grid_columnconfigure(i, weight=1)

shape_int = IntVar()
column = 1
for txt, val in shapes:
    ttk.Radiobutton(radio_frame, text=txt, value=val,  variable=shape_int, command=display_elements).grid(row=1, padx=15, pady=10, column=column, sticky="we")
    column += 1

dimensions_label = Label(font=14)

dimensions_value = StringVar()
dimensions_input = ttk.Entry(textvariable=dimensions_value, width=28, font=12)

submit_button = ttk.Button(text="Submit", command=on_btn_submit)

shape_label = Label(padx=5, pady=5, font=("Calibri", 14, "bold"))

canvas = Canvas(root, width=200, height=200)

button_frame = Frame(root)
button_frame.grid(row=7, column=0, columnspan=5, sticky="we")
for i in range(4):
    button_frame.grid_columnconfigure(i, weight=1)

prev_button = ttk.Button(button_frame, text="Previous", command=lambda: on_btn_click(prev_button.cget("text")), state="disabled")
next_button = ttk.Button(button_frame, text="Next", command=lambda: on_btn_click(next_button.cget("text")))


root.mainloop()


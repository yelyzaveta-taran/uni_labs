from tkinter import *
from shape_logic import *
from helpers import *
from tkinter import ttk
from shapes import Shape

fixed_shape = Shape()

colors = fixed_shape.colors
border_values = fixed_shape.border_values
fav_img_colors = fixed_shape.fav_img_colors
fav_brd_colors = fixed_shape.fav_brd_colors

shapes = [("Circle", 1), ("Rectangle", 2), ("Square", 3)]


def display_elements():

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

    color_label.grid(row=0, column=0, padx=(10, 10), sticky=W)

    colors_listbox.pack(side=LEFT, fill=BOTH, expand=True)
    scrollbar.pack(side=LEFT, fill=Y, padx=(0, 70))

    brd_color_label.grid(row=0, column=0, padx=(10, 10), sticky=W)

    brd_colors_listbox.pack(side=LEFT, fill=BOTH, expand=True)
    brd_scrollbar.pack(side=LEFT, fill=Y, padx=(0, 70))

    brd_width_label.grid(row=9, column=0, padx=(10, 10), sticky=W)
    brd_width_frame.grid(row=10, column=0, columnspan=4, sticky="we")

    submit_button.grid(row=11, column=0, columnspan=5, padx=(5, 15), pady=10, sticky="we")

def on_listbox_select(event):
    listbox = event.widget  

    try:
        selected_index = listbox.curselection()[0] 
    except IndexError:
        return
 
    if listbox == colors_listbox:   
        color_var.set(listbox.get(selected_index))
        append_color(fav_img_colors, color_var.get())
    elif listbox == fav_colors_listbox:
        fav_color_var.set(listbox.get(selected_index))
        color_var.set("")
        brd_color_var.set("")
    elif listbox == brd_colors_listbox:
        brd_color_var.set(listbox.get(selected_index))
        append_color(fav_brd_colors, brd_color_var.get())
    elif listbox == brd_fav_colors_listbox:
        fav_brd_color_var.set(listbox.get(selected_index))
        color_var.set("")
        brd_color_var.set("")

def update_fav_color_listboxes():
    fav_colors_listbox.delete(0, END)
    brd_fav_colors_listbox.delete(0, END)

    for color in fav_img_colors:
        fav_colors_listbox.insert(END, color)

    for color in fav_brd_colors:
        brd_fav_colors_listbox.insert(END, color)

    if fav_img_colors:
        fav_color_label.grid(row=0, column=1, padx=(10, 10), sticky=W)
        fav_colors_listbox.pack(side=LEFT, fill=BOTH, expand=True)
        img_btn_frame.pack(side=LEFT, padx=10)

    if fav_brd_colors:
        brd_fav_color_label.grid(row=0, column=1, padx=(10, 10), sticky=W)
        brd_fav_colors_listbox.pack(side=LEFT, fill=BOTH, expand=True)
        brd_btn_frame.pack(side=LEFT, padx=10)

def on_btn_submit():
    selected_shape = shape_int.get()
    str_dimensions = dimensions_input.get().split()

    dimensions = format_dimensions(str_dimensions)

    selected_color = color_var.get()
    selected_brd_color = brd_color_var.get()
    selected_brd_width = width_int.get()

    if selected_color == "":
        selected_color = fav_color_var.get()

    if selected_brd_color == "":
        selected_brd_color = fav_brd_color_var.get()

    parameters = (selected_color, selected_brd_color, selected_brd_width)

    if input_validation(selected_shape, dimensions, parameters):
        open_shape_window(selected_shape, dimensions, parameters) 

    update_fav_color_listboxes()

def open_shape_window(shape_type, dimensions, parameters):
    shape_window = Toplevel(root)
    shape_window.title("Shape Overview")

    shape_label = Label(shape_window, padx=5, pady=5, font=("Calibri", 14, "bold")) 
    shape_label.pack()

    shape_canvas = Canvas(shape_window, width=200, height=200)
    shape_canvas.pack()

    shape = create_shape(shape_type, dimensions, parameters)
    
    if shape:
        shape_label.config(text=str(shape))
        draw_shape(shape_canvas, shape.color, shape_type, shape.border_width, shape.border_color)

def open_input_window(fav_colors, color_var, operation):
    def get_input_and_close():
        user_input = entry.get()
        color = validate_color(colors, user_input)
        if color:
            operate_color(fav_colors, color_var, operation, color)
            update_fav_color_listboxes()
        input_window.destroy()

    input_window = Toplevel(root)
    input_window.title("Input Window")

    label = Label(input_window, text="Enter the color:")
    label.pack(padx=10, pady=10)

    entry = Entry(input_window)
    entry.pack(padx=10, pady=(0, 10))

    submit_button = ttk.Button(input_window, text="Submit", command=get_input_and_close)
    submit_button.pack(padx=10, pady=10)

def on_lsbx_btn_click(label, frame):
    fav_colors = []
    color_var = ""

    if frame == img_btn_frame:
        fav_colors = fav_img_colors
        color_var = fav_color_var
    else:
        fav_colors = fav_brd_colors
        color_var = fav_brd_color_var

    match label:
            case "Add": 
                open_input_window(fav_colors, color_var, label)
            case "Update":
                open_input_window(fav_colors, color_var, label)
            case "Sort":
                fav_colors.sort()
            case "Delete":
                operate_color(fav_colors, color_var, label)
                color_var.set("")
            case "Reverse":
                fav_colors.sort(reverse=True)
    
    update_fav_color_listboxes()

#__________ROOT__________

root = Tk()
root.title("GUI in Python")

w = 700
h = 800

ws = root.winfo_screenwidth() 
hs = root.winfo_screenheight() 

x = (ws/2) - (w/2)
y = (hs/2) - (h/2)

root.geometry('%dx%d+%d+%d' % (w, h, x, y))

for i in range(5):
    root.grid_columnconfigure(i, weight=1)


#____HEADER_LABEL____
header = Label(text="Choose a shape:", font=14)
header.grid(row=0, column=0, padx=15, pady=15, columnspan=5, sticky=W)

#____SHAPE_RADIO_BTN___
radio_frame = Frame(root)
radio_frame.grid(row=1, column=0, columnspan=5, sticky="we")
for i in range(4):
    radio_frame.grid_columnconfigure(i, weight=1)

shape_int = IntVar()
column = 1
for txt, val in shapes:
    ttk.Radiobutton(radio_frame, text=txt, value=val,  variable=shape_int, command=display_elements).grid(row=1, padx=15, pady=10, column=column, sticky="we")
    column += 1

#___DIMENSIONS__ELEMENTS___
dimensions_label = Label(font=14)

dimensions_value = StringVar()
dimensions_input = ttk.Entry(textvariable=dimensions_value, width=28, font=12)


#_____COLOR_LABELS____
#__IMG_COLOR_LABEL__
color_labels_frame = Frame(root)
color_labels_frame.grid(row=5,column=0, columnspan=5, sticky="we")
for i in range(4):
    color_labels_frame.grid_columnconfigure(i, weight=1)

color_label = Label(color_labels_frame,text="Choose a color of the image:",padx=5, pady=5, font=("Calibri", 14))
fav_color_label = Label(color_labels_frame,text="Favorite colors:", padx=5, pady=5, font=("Calibri", 14))

#__BRD__COLOR__LABELS__
brd_color_labels_frame = Frame(root)
brd_color_labels_frame.grid(row=7,column=0, columnspan=5, sticky="we")
for i in range(4):
    brd_color_labels_frame.grid_columnconfigure(i, weight=1)

brd_color_label = Label(brd_color_labels_frame,text="Choose a color of the border:",padx=5, pady=5, font=("Calibri", 14))
brd_fav_color_label = Label(brd_color_labels_frame,text="Favorite colors:", padx=5, pady=5, font=("Calibri", 14))

#__BRD_WIDTH_LABEL
brd_width_label = Label(text="Choose a value of the border's width:",padx=5, pady=5, font=("Calibri", 14))

#____PARAMETERS_LISTBOXES____
#__IMG_COLORS_LISTBOXES__
color_var = StringVar()
fav_color_var = StringVar()

img_colors_listbox_frame = Frame(root)
img_colors_listbox_frame.grid(row=6, column=0, padx=15, pady=15, columnspan=5, sticky=W)

colors_listbox = Listbox(img_colors_listbox_frame, width=40)
fav_colors_listbox = Listbox(img_colors_listbox_frame, width=40)

colors_listbox.bind("<<ListboxSelect>>", on_listbox_select)

for color in colors:
    colors_listbox.insert(END, color)

scrollbar = Scrollbar(img_colors_listbox_frame, orient=VERTICAL, command=colors_listbox.yview)
colors_listbox.config(yscrollcommand=scrollbar.set)

#__BRD_COLORS_LISTBOXES__
brd_color_var = StringVar()
fav_brd_color_var = StringVar()

brd_colors_listbox_frame = Frame(root)
brd_colors_listbox_frame.grid(row=8, column=0, padx=15, pady=15, columnspan=5, sticky=W)

brd_colors_listbox = Listbox(brd_colors_listbox_frame, width=40)
brd_fav_colors_listbox = Listbox(brd_colors_listbox_frame, width=40)

for color in colors:
    brd_colors_listbox.insert(END, color)

brd_scrollbar = Scrollbar(brd_colors_listbox_frame, orient=VERTICAL, command=brd_colors_listbox.yview)
brd_colors_listbox.config(yscrollcommand=brd_scrollbar.set)

#__BRD_WIDTH_BTNS
brd_width_var = StringVar()

brd_width_frame = Frame(root)
for i in range(4):
    brd_width_frame.grid_columnconfigure(i, weight=1)

width_int = IntVar()
column = 1
for val in border_values:
    ttk.Radiobutton(brd_width_frame, text=val, value=val,  variable=width_int).grid(row=0, padx=15, pady=10, column=column, sticky="nsew")
    column += 1

#__SUBMIT_BTN__
submit_button = ttk.Button(text="Submit", command=on_btn_submit)

#__EVENT_HANDLERS_BINDING__
colors_listbox.bind("<<ListboxSelect>>", on_listbox_select)
fav_colors_listbox.bind("<<ListboxSelect>>", on_listbox_select)
brd_colors_listbox.bind("<<ListboxSelect>>", on_listbox_select)
brd_fav_colors_listbox.bind("<<ListboxSelect>>", on_listbox_select)

# __LISTBOX__BUTTON__FRAME__
img_btn_frame = Frame(img_colors_listbox_frame) 

for i in range(5):
    labels = ["Add", "Update", "Sort", "Reverse", "Delete"]
    img_button = ttk.Button(img_btn_frame, text=labels[i], width=10, command=lambda label=labels[i], frame=img_btn_frame: on_lsbx_btn_click(label, frame))  
    img_button.pack(fill=X, pady=3) 

brd_btn_frame = Frame(brd_colors_listbox_frame)
for i in range(5):
    labels = ["Add", "Update", "Sort", "Reverse", "Delete"]
    brd_button = ttk.Button(brd_btn_frame, text=labels[i], width=10, command=lambda label=labels[i], frame=brd_btn_frame: on_lsbx_btn_click(label, frame))  
    brd_button.pack(fill=X, pady=3) 

root.mainloop()

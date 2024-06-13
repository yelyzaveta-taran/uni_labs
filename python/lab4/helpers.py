from tkinter import messagebox

def append_color(fav_colors, selected_color): 
    if selected_color not in fav_colors:
        if len(fav_colors) >= 5:
            fav_colors.pop()
        fav_colors.insert(0, selected_color)

def validate_color(colors, color):
    if colors.count(color) > 0:
        return color
    else:
         messagebox.showerror(title="Validation Error", message=f"Color {color} can not be applied")
         return False

def operate_color(fav_colors, color_var, operation, color=""):
    match operation:
        case "Add":
            append_color(fav_colors, color)
        case "Update":
            if color_var.get():
                idx = fav_colors.index(color_var.get())
                fav_colors[idx] = color 
            else:
                messagebox.showerror(title="Validation Error", message=f"Choose color to update")
                return  
        case "Delete":
            if color_var.get():
                idx = fav_colors.index(color_var.get())
                del fav_colors[idx]
            else:
                messagebox.showerror(title="Validation Error", message=f"Choose color to delete")
                return  
            

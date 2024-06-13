from math import pi
from constants import COLORS

class Shape:

    def __init__(self, name = "", color="", border_color = "", border_width=0):
        self.name = name
        self.color = color
        self.border_width = border_width
        self.border_color = border_color
        self.fav_img_colors = []
        self.fav_brd_colors = []
        self.__colors = COLORS
        self.__border_values = (0, 2, 4, 6)
    
    @property
    def colors(self):
        return self.__colors
    
    @property
    def border_values(self):
        return self.__border_values
    

    def area(self):
        raise NotImplementedError("This method should be overridden by subclasses")

    def perimeter(self):
        raise NotImplementedError("This method should be overridden by subclasses")

    def __str__(self):
        return f"{self.name} with area {self.area()} and perimeter {self.perimeter()}"

class Circle(Shape): 
    def __init__(self, radius, color, border_color, border_width):
        super().__init__("Circle", color, border_color, border_width)
        self.radius = radius

    def area(self):
        return round(pi * self.radius ** 2, 1)

    def perimeter(self):
        return round(2 * pi * self.radius, 1)

class Rectangle(Shape):
    def __init__(self, length, width, color, border_color, border_width): 
        super().__init__("Rectangle", color, border_color, border_width)
        self.length = length
        self.width = width
    
    def area(self): 
        return round(self.length * self.width, 1)
    
    def perimeter(self): 
        return round(2 * (self.length + self.width), 1)

class Square(Rectangle):
    def __init__(self, side, color, border_color, border_width):
        super().__init__(side, side, color, border_color, border_width)
        self.name = "Square"




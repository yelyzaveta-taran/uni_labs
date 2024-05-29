from math import pi

class Shape:
    def __init__(self, name):
        self.name = name

    def area(self):
        raise NotImplementedError("This method should be overridden by subclasses")

    def perimeter(self):
        raise NotImplementedError("This method should be overridden by subclasses")

    def __str__(self):
        return f"{self.name} with area {self.area()} and perimeter {self.perimeter()}"

class Circle(Shape): 
    def __init__(self, radius):
        super().__init__("Circle")
        self.radius = radius

    def area(self):
        return round(pi * self.radius ** 2, 1)

    def perimeter(self):
        return round(2 * pi * self.radius, 1)

class Rectangle(Shape):
    def __init__(self, length, width): 
        super().__init__("Rectangle")
        self.length = length
        self.width = width
    
    def area(self): 
        return round(self.length * self.width, 1)
    
    def perimeter(self): 
        return round(2 * (self.length + self.width), 1)

class Square(Rectangle):
    def __init__(self, side):
        super().__init__(side, side)
        self.name = "Square"




package lab7;

import javax.swing.*;
import java.awt.*;
import java.awt.geom.Rectangle2D;
import java.util.Scanner;

public class SquaresRelationApp extends JPanel {

    Rectangle2D square1;
    Rectangle2D square2;
    String relationText;

    public SquaresRelationApp(Rectangle2D square1, Rectangle2D square2) {
        this.square1 = square1;
        this.square2 = square2;
        this.relationText = determineRelation();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        setBackground(Color.WHITE);
        Graphics2D g2 = (Graphics2D) g;

        g2.setStroke(new BasicStroke(2));

        g2.setColor(Color.BLUE);
        g2.draw(square1);
        g2.drawString("Квадрат 1", (int) square1.getX(), (int) square1.getY() - 5);

        g2.setColor(Color.RED);
        g2.draw(square2);
        g2.drawString("Квадрат 2", (int) square2.getX(), (int) square2.getY() - 5);

        g2.setColor(Color.BLACK);
        g2.drawString("Завдання: Задано координати двох квадратів. Визначити їхнє взаємне розташування.", 20, 20);
        g2.drawString("Відповідь: " + relationText, 20, 40);
    }

    private String determineRelation() {
        if (square1.intersects(square2)) {
            if (square1.contains(square2)) return "Другий квадрат повністю всередині першого.";
            else if (square2.contains(square1)) return "Перший квадрат повністю всередині другого.";
            else return "Квадрати частково перетинаються.";
        } else {
            return "Квадрати не перетинаються.";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введіть координати верхнього лівого кута та сторону першого квадрата:");
        System.out.print("x1 = ");
        int x1 = scanner.nextInt();
        System.out.print("y1 = ");
        int y1 = scanner.nextInt();
        System.out.print("Сторона 1 = ");
        int side1 = scanner.nextInt();

        System.out.println("Введіть координати верхнього лівого кута та сторону другого квадрата:");
        System.out.print("x2 = ");
        int x2 = scanner.nextInt();
        System.out.print("y2 = ");
        int y2 = scanner.nextInt();
        System.out.print("Сторона 2 = ");
        int side2 = scanner.nextInt();

        Rectangle2D square1 = new Rectangle2D.Double(x1, y1, side1, side1);
        Rectangle2D square2 = new Rectangle2D.Double(x2, y2, side2, side2);

        JFrame frame = new JFrame("Взаємне розташування квадратів");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.add(new SquaresRelationApp(square1, square2));
        frame.setSize(600, 600);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}

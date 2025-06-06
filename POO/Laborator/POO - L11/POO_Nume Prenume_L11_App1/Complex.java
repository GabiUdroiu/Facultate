import java.util.Scanner;

public class Complex {
    private int r, i;

    public Complex() {
        r = 0; i = 0;
    }

    public Complex(int r, int i) {
        this.r = r; this.i = i;
    }

    public void read(Scanner sc) {
        r = sc.nextInt();
        i = sc.nextInt();
    }

    public void afis() {
        System.out.println(r + " + " + i + "i");
    }

    public Complex adunare(Complex other) {
        return new Complex(r + other.r, i + other.i);
    }

    public void increment() {
        r += 1;
    }

    public Complex adunareCuConstanta(int val) {
        return new Complex(r + val, i);
    }

    public double modul() {
        return Math.sqrt(r * r + i * i);
    }

    public boolean esteMaiMareDecat(Complex other) {
        return this.modul() > other.modul();
    }
}
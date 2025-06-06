import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Complex c1 = new Complex();
        Complex c2 = new Complex();

        c1.read(sc);
        c2.read(sc);

        c1.afis();
        c2.afis();

        Complex suma = c1.adunare(c2);
        suma.afis();

        c1.increment();
        c2.increment();
        c1.afis();
        c2.afis();

        Complex sumaConst = c1.adunareCuConstanta(5);
        sumaConst.afis();

        if (c1.esteMaiMareDecat(c2)) System.out.println("c1 mai mare");
        else if (c2.esteMaiMareDecat(c1)) System.out.println("c2 mai mare");
        else System.out.println("egale");

        sc.close();
    }
}

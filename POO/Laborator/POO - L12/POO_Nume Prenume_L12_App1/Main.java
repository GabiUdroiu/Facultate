public class Main {
    public static void main(String[] args) {
        Operatii op = new Operatii(10);

        op.plus(5);
        System.out.println("plus 5: " + op.getNumber());

        op.minus(3);
        System.out.println("minus 3: " + op.getNumber());

        op.mult(2);
        System.out.println("mult 2: " + op.getNumber());

        op.div(0);
        System.out.println("div 0: " + op.getNumber());

        op.div(4);
        System.out.println("div 4: " + op.getNumber());
    }
}
public class SequentialPrimeFinder extends AbstractPrimeFinder {
    public int countPrimes(final int number){
        return countPrimesInRange(1,number);

    }

    public static void main(final String[] args) {
        new SequentialPrimeFinder().timeAndCompute(Integer.parseInt((args.length==0?"10000000":args[0])));

    }

}

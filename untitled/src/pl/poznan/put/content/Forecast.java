package pl.poznan.put.content;

public interface Forecast {
    int temperature();
    final class Fake implements Forecast{
        @Override
        public int temperature(){
            return 12;
        }
    }
}

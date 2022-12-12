package pl.poznan.put.content;

public class Weather implements Forecast {
private final int numberOfCelsius;

    public Weather(int numberOfCelsius) {
        this.numberOfCelsius = numberOfCelsius;
    }

    public int temperature() {
        return numberOfCelsius;
    }
}

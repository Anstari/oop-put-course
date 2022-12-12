import pl.poznan.put.content.Forecast;
import pl.poznan.put.content.Weather;

public class Main {
    public static void main(String[] args) {

        Forecast forecast = new Forecast.Fake();
        Weather weather1 = new Weather(0);
        assert "12".equals(forecast.temperature().toString);
    }
}
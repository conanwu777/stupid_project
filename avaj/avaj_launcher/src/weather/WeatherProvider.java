package weather;

import simulator.vehicles.Coordinates;

import java.util.Random;

public class WeatherProvider {
    static private WeatherProvider weatherProvider;
    private String[] weather = {"🌧", "☁️", "☀️", "❄️"};
    public int r;
    private WeatherProvider() {
        Random rand = new Random();
        weatherProvider = this;
        this.r = rand.nextInt(4);
    }
    public static WeatherProvider getProvider() {
        if (weatherProvider == null) {
            weatherProvider = new WeatherProvider();
        }
        return (weatherProvider);
    }
    public String getCurrentWeather(Coordinates co) {
        int t = (co.getLongitude() + co.getLatitude() + this.r) % 4;
        return (this.weather[t]);
    }
}

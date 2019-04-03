package simulator.vehicles;

import simulator.WeatherTower;
import weather.Coordinates;

public class JetPlane extends Aircraft implements Flyable{
    JetPlane(String name, Coordinates co) {
        super(name, co);
    }
    public void updateConditions() {
        w = this.wt.getWeather(this.coordinates);
        int lo = this.coordinates.getLongitude();
        int la = this.coordinates.getLatitude();
        int h = this.coordinates.getHeight();
        Logger.log("\uD83D\uDEE9 " + this.name + "(" + this.id + "): " + w);
        switch (w) {
            case "🌧":
                Logger.log(" No big deal, just a bit wet️\n");
                la += 5;
                break;
            case "☀️":
                Logger.log("️ No big deal, just a bit hot️️\n");
                la += 10;
                h += 2;
                if (h >= 100)
                    h = 100;
                break;
            case "☁️":
                Logger.log("️️ No big deal, I can still see\n");
                la += 1;
                break;
            case "❄️":
                Logger.log("️ No big deal, just a bit of snow\n");
                h -= 7;
                break;
        }
        if (h <= 0) {
            Logger.log("No big deal, just going a tiny bit lower\n");
            Logger.log("\uD83D\uDDFC \uD83D\uDEE9 " + this.name + "(" + this.id + ") ");
            this.wt.unregister(this);
        }

        else {
            Coordinates n;
            n = new Coordinates(lo, la, h);
            this.coordinates = n;
        }
    }
    public void registerTower(WeatherTower wt) {
        Logger.log("\uD83D\uDEE9️️ " + this.name + " Unique id: " + this.id);
        this.wt = wt;
    }
    public void printHeight() {
        Logger.log(this.name + "(" + this.id + ")");
        for (int i = 0; i <= 100; i++)
            if (i == coordinates.getHeight())
                Logger.log("\uD83D\uDEE9");
            else
                Logger.log("-");
        Logger.log(w + "\n");
    }
}

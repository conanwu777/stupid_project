package simulator.vehicles;

import weather.Coordinates;

public class AircraftFactory {
    public static Flyable newAircraft (String type, String name, int lo, int la, int h) {
        Coordinates co;
        co = new Coordinates(lo, la, h);
        switch (type) {
            case "Baloon":
                return (new Baloon(name, co));
            case "JetPlane":
                return (new JetPlane(name, co));
            case "Helicopter":
                return (new Helicopter(name, co));
            default:
                System.out.print("Airplane type not found >.<\n");
                System.exit(1);
        }
        return (null);
    }
}

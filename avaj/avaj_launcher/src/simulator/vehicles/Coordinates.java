package simulator.vehicles;

public class Coordinates {
    private int longitude;
    private int latitude;
    private int height;

    Coordinates (int lo, int la, int h) {
        this.longitude = lo;
        this.latitude = la;
        if (h > 100)
            h = 100;
        this.height = h;
    }
    public int getLongitude() {
        return (longitude);
    }
    public int getLatitude() {
        return (latitude);
    }
    public int getHeight() {
        return (height);
    }
}

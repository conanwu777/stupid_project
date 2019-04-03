OUT = simulation.txt
IN = scenario.txt
IN2 = scenario2.txt

MAIN = simulator.Simulator

SRC = simulator/Simulator.java simulator/Tower.java simulator/WeatherTower.java \
weather/Coordinates.java weather/WeatherProvider.java\
simulator/vehicles/Aircraft.java simulator/vehicles/Flyable.java simulator/vehicles/AircraftFactory.java \
simulator/vehicles/Baloon.java simulator/vehicles/Helicopter.java simulator/vehicles/JetPlane.java \
simulator/vehicles/Logger.java

OBJ = $(SRC:.java=.class)

all:
	javac $(SRC)

run:
	java $(MAIN) $(IN)
	open $(OUT)

run2:
	java $(MAIN) $(IN2)
	open $(OUT)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUT)

re:	fclean all

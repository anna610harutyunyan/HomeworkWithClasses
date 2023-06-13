#include <iostream>
#include <string>

class Car
{
	int horse_power;
	int year;
	std::string model;
	std::string colour;
	std::string engine_type;

public:
	Car(int horse_power, int year, std::string model, std::string colour, std::string engine_type)
	{
		this->horse_power = horse_power;
		this->year = year;
		this->model = model;
		this->colour = colour;
		this -> engine_type = engine_type;
	}

	int getHorse_power()const
	{
		return horse_power;
	}
	void setHorse_power(int newHorse_power)
	{
		horse_power = newHorse_power;
	}
	int getYear()const
	{
		return year;
	}
	void setYear(int newYear)
	{
		year = newYear;
	}
	std::string getModel()const
	{
		return model;
	}
	void setModel(std::string newModel)
	{
		model = newModel;
	}
	std::string getColour()const
	{
		return colour;
	}
	void setMsetColourodel(std::string newColour)
	{
		colour = newColour;
	}
	std::string getEngine_type()const
	{
		return engine_type;
	}
	void setEngine_type(std::string newEngine_type)
	{
		engine_type = newEngine_type;
	}
};

class Parking
{
	int price;
	int capacity;
	Car* obj;
	int parking_spot;

public:
	Parking(int newParking_spot, Car* newObj)

	{
		this->parking_spot = newParking_spot;
		this->obj = newObj;
	}

	int getParking_spot()const
	{
	   return parking_spot;
	}
		

	Car* getObj()const
	{
		return obj;
	}
	
	
};


int main(int argc, char** aargv)
{
	Car myCar(157, 2015, "Mustang", "black", "petrol");
	Parking myParking(3, & myCar);

	std::cout << "Parking spot " << myParking.getParking_spot() << std::endl;
	std::cout << "The moedel of the car is " << myCar.getModel() << std::endl;

	return 0;
}
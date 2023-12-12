#include <iostream>
using namespace std;

class Transport
{
protected:
	string Price = "";
	string MaxWeight = "";
	string MaxFuel = "";
	string MaxDistance = "";
public:
	virtual void SetPrice() = 0;
	virtual void SetMaxWeight() = 0;
	virtual void SetMaxFuel() = 0;
	virtual void SetMaxDistance() = 0;
	void ShowTransport()
	{
		cout << "Price: " + Price + "\nMaxWeight: "
			+ MaxWeight + "\nMaxFuel: " + MaxFuel + "\nMaxDistance: "
			+ MaxDistance;
	}
};

class Truck : public Transport
{
	void SetPrice()override
	{
		Price = "5000$";
	}
	void SetMaxWeight()override
	{
		MaxWeight = "3000 kg";
	}
	void SetMaxFuel()override
	{
		MaxFuel = "90 L";
	}
	void SetMaxDistance()override
	{
		MaxDistance = "700 km";
	}
};

class Ship : public Transport
{
	void SetPrice()override
	{
		Price = "15000$";
	}
	void SetMaxWeight()override
	{
		MaxWeight = "20 T";
	}
	void SetMaxFuel()override
	{
		MaxFuel = "200000 L";
	}
	void SetMaxDistance()override
	{
		MaxDistance = "2000 km";
	}
};

class Delivery
{
public:
	virtual Transport* FactoryMethod() = 0;
};

class TruckDelivery : public Delivery
{
public: 
	Transport* FactoryMethod()
	{
		Transport* trn = new Truck();
		trn->SetMaxDistance();
		trn->SetMaxFuel();
		trn->SetMaxWeight();
		trn->SetPrice();
		return trn;
	}
};

class ShipDelivery : public Delivery
{
public:
	Transport* FactoryMethod()override
	{
		Transport* trn = new Ship();
		trn->SetMaxDistance();
		trn->SetMaxFuel();
		trn->SetMaxWeight();
		trn->SetPrice();
		return trn;
	}
};

void Factory(Delivery** deliverys, int size)
{
	for (int i = 0; i < size; i++)
	{
		Transport* trn = deliverys[i]->FactoryMethod();
		trn->ShowTransport();
		cout << "\n--------------------------------------------" << endl;
	}
}


int main()
{
	Delivery* deliverys[2];
	deliverys[0] = new ShipDelivery();
	deliverys[1] = new TruckDelivery();
	Factory(deliverys, 2);

	return 0;
}
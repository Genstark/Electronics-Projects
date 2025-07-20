#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

const char vibratorMotor = 3;
const char led = 4;
const char buzzer = 5;

void setup()
{
	Serial.begin(9600);
	Wire.begin();

	mpu.initialize();

	if (mpu.testConnection())
	{
		Serial.println("MPU6050 connection successful");
	}
	else
	{
		Serial.println("MPU6050 connection failed");
	}

	pinMode(vibratorMotor, OUTPUT);
	pinMode(led, OUTPUT);
	pinMode(buzzer, OUTPUT);
}

void loop()
{
	int16_t ax, ay, az;
	int16_t gx, gy, gz;

	mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

	if (abs(gx) > 5000 || abs(gy) > 5000 || abs(gz) > 5000)
	{
		digitalWrite(vibratorMotor, HIGH);
		digitalWrite(led, HIGH);
		digitalWrite(buzzer, HIGH);
	}
	else
	{
		Serial.println("No significant motion.");
		digitalWrite(vibratorMotor, LOW);
		digitalWrite(led, LOW);
		digitalWrite(buzzer, LOW);
	}

	//  Serial.print("Gyro X: "); Serial.print(gx);
	//  Serial.print(" | Y: "); Serial.print(gy);
	//  Serial.print(" | Z: "); Serial.println(gz);

	delay(100);
}

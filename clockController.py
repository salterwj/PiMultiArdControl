import serial

if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM0',9600, timeout=1)
    ser.flush()
    
    while True:

        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            tempFile = open("/var/www/html/data.txt","w")
            tempFile.write(line)
            tempFile.close()
            
            print("***")

            lightFile = open("/var/www/html/clockStatus.txt","r")
            command = lightFile.read()
            lightFile.close()
            
            print(line)
            if command == 'scene change':
                ser.write(b"scene change\n")
                print(command)
            elif command == 'standard rotation':
                ser.write(b"standard rotation\n")
                print(command)
            else:
                print("Neutral")
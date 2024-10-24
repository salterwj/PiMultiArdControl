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

            fanFile = open("/var/www/html/fanStatus.txt","r")
            command = fanFile.read()
            fanFile.close()
            
            print(line)
            if command == 'on':
                ser.write(b"on\n")
                print(command)
            elif command == 'off':
                ser.write(b"off\n")
                print(command)
            else:
                print("error")
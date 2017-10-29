#coding utf-8
import serial
import re
import urllib.request, json
import requests

def main():
    with serial.Serial('COM4',9600,timeout=2) as ser:

       while True:
            c = ser.readline().decode().strip('\r\n')
            print(c)
            response = requests.post(
                "http://192.168.2.29:9000/collect",
                c,
                headers={'Content-Type': 'application/json'})
        ser.close()

if __name__=="__main__":
    main()

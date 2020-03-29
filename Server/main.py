#
#      _______________________________________________________________
#     |         ___                   ___          __                 |
#     |        / _ \__ _____ ____    / _ \___ ____/ /_____ ____       |
#     |       / , _/ // / _ `/ _ \  / // / -_) __/  '_/ -_) __/       |
#     |      /_/|_|\_, /\_,_/_//_/ /____/\__/\__/_/\_\\__/_/          |
#     |           /___/                                               |
#     |_______________________________________________________________|
#
#

from flask import Flask
from flask_ask import statement, question, session, Ask
import serial
import time

app = Flask(__name__)
ask = Ask(app, "/WineSlave")


@app.route('/')
def homepage():
    return "Hey there buddy"


@ask.launch
def start_skill():
    return statement("You are amazing")


@ask.intent("pour")
def pour_glass():
    with serial.Serial('COM4', 9600, serial.EIGHTBITS, timeout=0, parity=serial.PARITY_NONE, rtscts=1) as ser:
        time.sleep(2)
        ser.write(b'L')
        ser.close()
    return statement("The wine slave will take care of that right away sir")


if __name__ == '__main__':
    app.run(debug=True)

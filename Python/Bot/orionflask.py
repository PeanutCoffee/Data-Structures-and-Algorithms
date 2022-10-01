from flask import Flask
from threading import Thread

app = Flask('')

@app.route('/')
def home():
    return "Yo bro, i am alive , XD!!"

def run():
  app.run(host='0.0.0.0',port=8080)

def keep_alivelol():
    t = Thread(target=run)
    t.start()
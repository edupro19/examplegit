import  pywhatkit
import speech_recognition as sr
import pyttsx3
name='sauro'
listener=sr.Recognizer()
engine=pyttsx3.init()
voices=engine.getProperty('voices')
engine.setProperty('voice',voices[1].id)
def talk(text):
   engine.say( text)
   engine.runAndWait()

def listen():
    try:

        with sr.Microphone()  as source:
            print("Escuchando...:v")
            voice=listener.listen(source)   
            rec = listener.recognize_google(voice)
            rec=rec.lower()
            if name in rec:
                rec=rec.replace (name, '')
                print(rec) 
    except:
        pass 
    return rec
def run():
    rec=listen()
    if 'reproduce' in rec:
        music=rec.replace('reproduce', '')
        talk('reproduciendo'+music)
        pywhatkit.playonyt(music)
run()


import speech_recognition as sr
import pyttsx3 
  

r = sr.Recognizer() 
  

def SpeakText(command):
      
 
    engine = pyttsx3.init()
    engine.say(command) 
    engine.runAndWait()
      
flag=True      

while(flag):    
      
   
    try:
          
        
        with sr.Microphone() as source2:
           
            r.adjust_for_ambient_noise(source2, duration=0.2)
            print("Do you have any diseases")  
            SpeakText("Do you have any diseases")
            audio2 = r.listen(source2)
            MyText = r.recognize_google(audio2)
            MyText = MyText.lower()
            print("Did you say "+MyText+" Say yes if correct and no to rerecord")
            SpeakText("Did you say "+MyText+" Say yes if correct and no to rerecord")
            audio3=r.listen(source2)
            Text = r.recognize_google(audio2)
            Text = Text.lower()
            
            if Text=="yes":
                a=input(MyText)
                print(MyText)
                flag=0
            if Text=="no":
                exit()
    except sr.RequestError as e:
        print("Could not request results; {0}".format(e))
          
    except sr.UnknownValueError:
        print("unknown error occured")
    
  
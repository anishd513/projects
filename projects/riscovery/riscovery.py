# Natural Language Processing
import csv
import speech_recognition as sr
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
def audio_to_text(file):
    # Initialize recognizer class (for recognizing the speech)
    r = sr.Recognizer()
    
    # Reading Audio file as source
    # listening the audio file and store in audio_text variable
    
    with sr.AudioFile('audio_files/'+file) as source:
        
        audio_text = r.listen(source)
        
    # recoginize_() method will throw a request error if the API is unreachable, hence using exception handling
        try:
            
            # using google speech recognition
            text = r.recognize_google(audio_text)
            print('Converting audio transcripts into text ...')
            print(text)
            return text
         
        except:
             print('Sorry.. run again...')
def create_file(output_file,text):
    with open(output_file, 'wt') as out_file:
        tsv_writer = csv.writer(out_file, delimiter='\t')
        tsv_writer.writerow(["textinput" ,"value"])
        tsv_writer.writerow([text])

# Importing the libraries


# Importing the dataset


# Cleaning the texts
import re
import nltk
nltk.download('stopwords')
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer
def extract_words(dataset):
    corpus = []
    for i in range(0,len(dataset)):
      review = re.sub('[^a-zA-Z]', ' ', dataset['textinput'][i])
      review = review.lower()
      review = review.split()
      ps = PorterStemmer()
      all_stopwords = stopwords.words('english')
      all_stopwords.remove('not')
      review = [ps.stem(word) for word in review if not word in set(all_stopwords)]
      review = ' '.join(review)
      corpus.append(review)
    return corpus
if __name__=='__main__':
    file="a1.wav"
    output_file='./trial2.tsv'
    text=audio_to_text(file)
    create_file(output_file,text)
    dataset = pd.read_csv(output_file, delimiter = '\t', quoting = 3)
    print(extract_words(dataset))
    
     
          
    
    

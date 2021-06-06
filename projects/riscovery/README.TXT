We are team Clickbait
The first question of the problem statement involves taking speech input from the user wherein they say the diseases that they're diagnosed with. For this, we use SpeechRecognition module alone with PyAudio and pyttxs3. The ML model is trained to only recognise the diseases such as "thyroid", "cancer", "diabetes" and the nagative words such as "don't" , "no"
The second part of the question consists of taking the speech input of the user regarding their salary. It is compared against a pre-defined list containing the salary brackets as elements and the input salary is matched with the list.
The third part of the question consists of taking DOB from the user which can be in any date format and returning their DOB in ['dd/mm/yy'] format. 

The client part of the code is stored in riscovery.py
The server part of the code is put in separate files which are then linked together
The web-based API is hosted on jotform. The input from the user are stored in a spreadsheet. The values in the spreadsheet are downloaded via a python script which is then linked to the original python file. 

https://form.jotform.com/211556378546060

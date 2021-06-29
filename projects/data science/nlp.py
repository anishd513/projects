import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('col_rev.tsv', delimiter = '\t', quoting = 3)# -*- coding: utf-8 -*-

import re
import nltk
nltk.download('stopwords')
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer

dataset['word_count'] = dataset['Review'].apply(lambda x: len(str(x).split(" ")))
dataset[['Review','word_count']].head()
from nltk.corpus import stopwords
stop = stopwords.words('english')

dataset['stopwords'] = dataset['Review'].apply(lambda x: len([x for x in x.split() if x in stop]))
dataset[['Review','stopwords']].head()
dataset['upper'] = dataset['Review'].apply(lambda x: len([x for x in x.split() if x.isupper()]))
dataset[['Review','upper']].head()
dataset['Review'] = dataset['Review'].apply(lambda x: " ".join(x.lower() for x in x.split()))
dataset['Review'].head()
dataset['Review'] = dataset['Review'].str.replace('[^\w\s]','')
dataset['Review'].head()
from nltk.corpus import stopwords
stop = stopwords.words('english')
dataset['Review'] = dataset['Review'].apply(lambda x: " ".join(x for x in x.split() if x not in stop))
dataset['Review'].head()
freq = pd.Series(' '.join(dataset['Review']).split()).value_counts()[:10]
freq
from nltk.stem import PorterStemmer
corpus =[]
st = PorterStemmer()
review = dataset['Review'][:5].apply(lambda x: " ".join([st.stem(word) for word in x.split()]))
corpus.append(review)

print(corpus)
from textblob import TextBlob
dataset['Review'][:5].apply(lambda x: TextBlob(x).sentiment)
dataset['sentiment'] = dataset['Review'].apply(lambda x: TextBlob(x).sentiment[0] )
dataset[['Review','sentiment']].head()
text_blob_object = TextBlob(dataset['Review'][50])
print(text_blob_object.sentiment)
def find_pol(review):
    return TextBlob(review).sentiment.polarity
dataset['Sentiment_Polarity'] = dataset['Review'].apply(find_pol)
dataset.head()
import seaborn as sns
import matplotlib.pyplot as plt
sns.distplot(dataset['Sentiment_Polarity'])
most_negative = dataset[dataset.Sentiment_Polarity == -1].Review.head()
print(most_negative)
most_positive = dataset[dataset.Sentiment_Polarity == 1].Review.head()
print(most_positive)
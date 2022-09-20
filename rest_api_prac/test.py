import requests
import json

res = requests.get('https://api.stackexchange.com/2.3/questions?order=desc&sort=activity&site=stackoverflow')
# print(res.json()['items'])

for data in res.json()['items']:
    if(data['answer_count']==0):
        print(data['title'])
        print(data['link'])
        print()

import requests

base_url = "http://127.0.0.1:5000"

response_site = requests.get(base_url + '/helloworld/Aryan')
print(response_site.json())
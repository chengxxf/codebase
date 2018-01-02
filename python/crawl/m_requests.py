import requests



print(requests.certs.where())
url="https://www.baidu.com"

resp=requests.get(url,verify=False)
#resp=requests.get(url)

resp.encoding='utf-8'
data=resp.text
print(data)

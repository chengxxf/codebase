import urllib.request
from urllib import request

def getHtml(url):
    page=urllib.request.urlopen(url)
    html=page.read()
    return html



if __name__=='__main__':
    
    #urllib.request.install_opener(opener)
    #html=getHtml("https://www.baidu.com")
    #print(html)a
    url="https://www.baidu.com"
    agent_str1="Mozilla/5.0 (X11; Linux x86_64; rv:17.0) Gecko/20131029 Firefox/17.0"
    agent_str2="Mozilla/4.0 (compatible; MSIE 7.0; Trident/5.0)"
    headers = {"User-Agent": agent_str1}


    request=urllib.request.Request(url,headers=headers)
    
    print(request.header_items())
    response=urllib.request.urlopen(request)
    data=response.read()
    
    data=data.decode('utf-8')
    
    print(data)

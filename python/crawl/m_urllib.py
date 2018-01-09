import urllib.request
from urllib import request
from bs4 import BeautifulSoup
import ssl

def getHtml(url):
    page=urllib.request.urlopen(url)
    html=page.read()
    return html

dlCount=0

def downloadA(url,prefix,headers,depth):

    if depth>=3 :
        return
    if not url:
        return
    global dlCount
    if url.startswith('/'):
        url=prefix+url
    print(url)
    request=urllib.request.Request(url,headers=headers)
    response=urllib.request.urlopen(request)
    data=response.read()
    data=data.decode('utf-8')
    dlCount+=1
    
    soup=BeautifulSoup(data)
    for k in soup.find_all('a'):
        if k is None:
            return

        #print(depth)
        if k.get('href') is None:
            continue
        dlCount+=1

        try:
            if k.get('href').startswith('/'):
                downloadA(k.get('href'),url,headers,depth+1)
            elif k.get('href').startswith('https'):
                #print(k['href'])
                1
            elif k.get('href').endswith('png'):
                #print(k['href'])
                None
            else:
                downloadA(k.get('href'),url,headers,depth+1)
        except :
            #print(k)
            None


def downloadOne(url,headers):
    request=urllib.request.Request(url,headers=headers)
    response=urllib.request.urlopen(request)
    data=response.read()
    data=data.decode('utf-8')
    
    print(data)



if __name__=='__main__':
    
    #urllib.request.install_opener(opener)
    #html=getHtml("https://www.baidu.com")
    #print(html)a
    url="http://docs.scala-lang.org/tour/tour-of-scala.html"
    agent_str1="Mozilla/5.0 (X11; Linux x86_64; rv:17.0) Gecko/20131029 Firefox/17.0"
    agent_str2="Mozilla/4.0 (compatible; MSIE 7.0; Trident/5.0)"
    headers = {"User-Agent": agent_str1}
    try:
        _create_unverified_https_context = ssl._create_unverified_context
    except AttributeError:
    # Legacy Python that doesn't verify HTTPS certificates by default
        pass
    else:
    # Handle target environment that doesn't support HTTPS verification
        ssl._create_default_https_context = _create_unverified_https_context
    dlCount=0
    downloadA(url,'',headers,1)
    #downloadOne("https://atom.io/",headers)
    #downloadOne("https://www.baidu.com",headers)

'''
    request=urllib.request.Request(url,headers=headers)
    
    print(request.header_items())
    response=urllib.request.urlopen(request)
    data=response.read()
    
    data=data.decode('utf-8')
    
    soup=BeautifulSoup(data)
    
    array = [[]]
    first_a=[]
    for k in soup.find_all('a'):
      #  print(k)
      #  print(k['href'])
        first_a.append(k['href'])

    array[0]=first_a
''' 

import scrapy
from scrapy.http.request import Request

class BrickSetSpider(scrapy.Spider):
    handle_httpstatus_list = [403, 404]
    name="sssssssssss"
    start_urls=['http://www.baidu.com']
    #headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2687.0 Safari/537.36'}

    #start_urls=['https://book.douban.com/subject/26805083/']

    def start_requests(self):
        headers= {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:48.0) Gecko/20100101 Firefox/48.0'}
        for url in self.start_urls:
            yield Request(url, headers=headers,meta={'proxy':'proxy.tellabs.com'})

    def parse(self,response):
        SET_SELECTOR='.set'
        for brickset in response.css(SET_SELECTOR):
            NAME_SELECTOR='h1 a ::text'
            yield{
                'name':brickset.css(NAME_SELECTOR).extract_first(),
            }

        filename=response.url.split("/")[-1]+'.html'
        with open(filename,'wb') as f:
            f.write(response.body)

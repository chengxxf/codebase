#-*-coding:utf-8 -*-

import jieba
from sklearn.feature_extraction.text import TfidfVectorizer
# need python version 3.x>3.4






if __name__=='__main__':
    print("start ")

    str1="你好1在\n"
    print(len(str1))
    print(len(str1.encode('utf-8')))
    jieba.suggest_freq('沙瑞金',True)
    jieba.suggest_freq('易学习',True)
    jieba.suggest_freq('王大路',True)
    jieba.suggest_freq('京州',True)
    
    stpwrdpath="stop_words.linux"
    stpwrd_dic=open(stpwrdpath,'rb')
    stpwrd_content=stpwrd_dic.read()

    stpwrdlst=stpwrd_content.splitlines()
    stpwrd_dic.close()
    with open("nlp_test0.txt") as f:
        document=f.read()
        
        #document_decode=document.decode('utf-8')
        document_cut=jieba.cut(document)
        result=' '.join(document_cut)
        #result=result.encode('utf-8')
        with open("cut.txt",'w') as f2:
            f2.write(result)
    f.close()
    f2.close()

    with open('cut.txt') as f3:
        res1=f3.read()


    corpus=[res1]
    vector=TfidfVectorizer(stop_words=stpwrdlst)
    tfidf=vector.fit_transform([res1])
    print(tfidf)

    wordlist=vector.get_feature_names()#获取词袋模型中的所有词
#tf-id 矩阵 元素a[i][j]表示j词在i类文本的tf-idf 权重
    weightlist=tfidf.toarray()

    for i in range(len(weightlist)):
        print("第 %d 段文本词语tf-idf 权重" % (i))
        for j in range(len(wordlist)):
            print("%s\t\t %s "%(wordlist[j],weightlist[i][j]))
























if __name__=='__main__':
    print("start ")

    str1="你好1在\n"
    print(len(str1))
    print(len(str1.encode('utf-8')))
    f=open("test.txt","r")
    #f.readline()

    D2={}
    D2['name']='Bob'
    print(D2)
    dict={}
    for line in f:
        for w in line:
            if dict.get(w) is None:
                dict[w]=1
            else:
                dict[w]+=1

    i=0
    for key in dict:
        print("%s=%d "%(key,dict[key]) )
        i+=1
    print(i)

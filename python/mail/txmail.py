# -*- coding:UTF-8 -*-
import time
import datetime
import smtplib
import email.mime.multipart

from email.mime.text import MIMEText
from email.header import Header

mail_host="smtp.163.com"

mail_user="chengxyd"
mail_pass="SdSqmq1w2"

mail_postfix="163.com"



sender='chengxyd@163.com'
receivers=['981081992@qq.com']



if __name__=='__main__':
    print("start")
    f=open('test2.txt','r')
    mail_body=f.read()
    f.close()

    message=email.mime.text.MIMEText(mail_body)
    me="hello"+"<"+mail_user+"@"+mail_postfix+">"
    message['Date']=datetime.datetime.now().strftime('%a ,%d %b %Y %H:%M:%S +0800')
    subject='haha'
    message['From']="chengxyd@163.com"
    message['To']="".join(receivers)
    message['Subject']='haha'
    message['Message-ID']="<5a61985b.vJdUF8Y15xJbd/yb%chengxyd@163.com>"
    message['User-Agent']="Heirloom mailx 12.4 7/29/08"
    #email.encoders.encode_7or8bit(message)

    try:
        smtpObj=smtplib.SMTP()
        smtpObj.connect(mail_host,25)
        #smtpObj.helo("pvmcc")
        print(message)
        #exit(1)
        #smtpObj=smtplib.SMTP_SSL(mail_host,465)
        smtpObj.set_debuglevel(1)
        smtpObj.login(mail_user,mail_pass)
        smtpObj.sendmail(sender,receivers,message.as_string())
        print("邮件发送成功")
        smtpObj.quit()
    except smtplib.SMTPException as e:
        print("Error: 无法发送邮件")
        print(e)









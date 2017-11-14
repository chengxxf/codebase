1.create a new repository on the command line <br>
>git init<br>
>git add README.md<br>
>git commit -t "first commit"<br>
>git remote add origin https://github.com/chengxxf/pthbase.git<br>
>git push -u origin master<br>


2.push an existing repository from the command line<br>
>git remote add origin https://github.com/chengxxf/pthbase.git<br>
>git push -u origin master<br>

#################stackoverflow###################<br>
To definitely be able to login using https protocol, you should first set your authentication credential to the git Remote URI:<br>

git remote set-url origin https://yourusername@github.com/user/repo.git<br>
Then you'll be asked for a password when trying to git push.<br>

In fact, this is on the http authentication format. You could set a password too:<br>

https://youruser:password@github.com/user/repo.git<br>
You should be aware that if you do this, your github password will be stored in plaintext in your .git directory, which is obviously<br> undesirable.
###################################################<br>

#########################<br>
Changing a remote's URL<br>
https://help.github.com/articles/changing-a-remote-s-url/<br>
########################<br>

QUESTION:  git produces Gtk-WARNING: cannot open display<br>
ANSWER:    unset SSH_ASKPASS<br>

#######rebase branches to master##############<br>
>git checkout master<br>
>git pull<br>
>git checkout local_branch_name<br>
>git rebase master<br>
>git push --force # force required if you've already pushed<br>

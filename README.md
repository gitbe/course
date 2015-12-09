Create git repository
---------------------
A) existing from server:
   1) create empty directory
   2) git clone git://github.com/gitbe/course.git
B) from existing files on your computer:
   1) create directory and files and do git init

Generate ssh key
----------------
1. generate key: ssh-keygen -t rsa -b 4096 -C "XXX@hotmail.com"
   => saved in /root/.ssh/id_rsa.pub
   (upload on github under profile - personal settings, SSH Keys)
2. authenticate: ssh -T git@github.com
   (only necessary with HTTPS, not with git site (git@github.com:gitbe/course.git)

git remote -v: check user and git@github.com

Add files
---------
git add filename (git add .., git add ., git add *)
    git add -p (add partial update of a file)

Check difference
----------------
git status -s (short version of status)
  2 columns:
    (1) staging area (A, M, AM, MM, ...)
    (2) working directory

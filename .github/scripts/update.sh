#!/bin/sh
do_merge() {
    git rm $(git diff --name-only --diff-filter=U .github)
    git commit --no-edit
}
git config --global user.name 'Nyikos Zoltán'
git config --global user.email 'nyikoszoltan0@gmail.com'
git remote add upstream https://github.com/qmk/qmk_firmware
git fetch upstream
git merge upstream/master || do_merge
git push

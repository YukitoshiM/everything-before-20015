# -*- coding: utf-8 -*-
"""
Created on Sun May 17 10:57:32 2015

@author: woolon
"""

# 文字列オブジェクト作成とプリント
s = 'I am tired!'
print s
# 文字列の長さの取得
print len(s)

# 文字列の一つのインデックスから一文字を取得
print s[0]

# 文字列の一部を取得するスライシングで以下はすべて同じ行為をする
print s[5:11]
print s[5:]
print s[0]

# 文字列をコピーして内容の一部を変更する(新しく生成された二つの
# 文字列オブジェクトを連結させ手一つの文字列オブジェクトを作成)
print s[:5] + 'fine!'
s = s[:5] + 'fine!'
print s
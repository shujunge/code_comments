# code_comments
=======
## Doxygen for c++
* 注释风格
```
/**
 * @brief 对两个数做加法
 *
 * @param y是int类型
 * @param x为int类型
 *
 * @return 无返回
 *
 */
void   add(int x,int y);
```

* 中文文档生成
```
>>>cd ./doxygen-chinese
>>>doxygen Doxyfile
>>>cd ./out/latex
>>>vi  refman.tex

将
\begin{document} 
替换为
\usepackage{CJKutf8}
\begin{document}
\begin{CJK}{UTF8}{gbsn}


将\end{document}
替换为
\end{CJK}
\end{document}

>>> make

```
* 英文文档生成
```
>>>cd ./doxygen-english
>>>doxygen Doxyfile
>>>cd ./out/latex
>>>make
```

## sphinx for python
```
>>> cd ./sphinx/source
>>> sphinx-apidoc -o ./source ../srcs/
>>> make html

```
* 删除文件
```
>>> rm ./sphinx/source/build/doctrees/*.doctree ##只保留index.doctree
>>> rm ./sphinx/source/build/html
>>> rm  srcs/.doctrees/*.doctree ##只保留index.doctree
重新编译
>>> sphinx-apidoc -o ./source ../srcs/
>>> make html
生成pdf
>>> make latex

修改文件
>>> cd ./sphinx/source/build/latex/*.tex

>>> make 
```


# code_comments
=======
## Doxygen for c++
* [demo](https://github.com/shujunge/code_comments/tree/master/doxygen-cmake/docs/html/index.html)

* [注释风格](https://blog.csdn.net/czyt1988/article/details/8901191)

```
c语言注释风格
/**
 * @brief 对两个数做加法
 *
 * @param y是int类型
 * @param x为int类型
 *
 * @return 无
 *
 */
void   add(int x,int y);


c++语言注释风格
/// \brief 对一个二维的vector<vector<double>>的
/// list进行按照每一个vector<double>的第２个元素进行升序
/// \param list是vector<vector<double>>类型
/// \param temp为int类型
/// \return 无
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
def add(x1,x2,x3):
    '''
    this is a add function!

    :param x1:
    :param x2: 
    :param x3: 
    :return:
    '''
    pass
    
```
```
"""
`Model` groups layers into an object with training and inference features.
There are two ways to instantiate a `Model`:

Arguments:
    optimizer: String (name of optimizer) or optimizer instance.
        See [optimizers](/optimizers).
    loss: String (name of objective function) or objective function.
        See [losses](/losses).
        If the model has multiple outputs, you can use a different loss
        on each output by passing a dictionary or a list of losses.
        The loss value that will be minimized by the model
        will then be the sum of all individual losses.  

Returns:
    A tuple of 3 lists: input arrays, target arrays, sample-weight arrays.
        If the model's input and targets are symbolic, these lists are empty
        (since the model takes no user-provided data, instead the data comes
        from the symbolic inputs/targets).

Raises:
    ValueError: In case of invalid arguments for
        `optimizer`, `loss`, `metrics` or `sample_weight_mode`.


Examples:
  >>> import tensorflow as tf
  >>> inputs = tf.keras.Input(shape=(3,))
  >>> x = tf.keras.layers.Dense(4, activation=tf.nn.relu)(inputs)
  >>> outputs = tf.keras.layers.Dense(5, activation=tf.nn.softmax)(x)
  >>> model = tf.keras.Model(inputs=inputs, outputs=outputs)


Examples:
  >>> import tensorflow as tf
  >>> class MyModel(tf.keras.Model):
  >>> def __init__(self):
  >>>   self.dense1 = tf.keras.layers.Dense(4, activation=tf.nn.relu)
  >>>   self.dense2 = tf.keras.layers.Dense(5, activation=tf.nn.softmax)
  >>>   def call(self, inputs):
  >>>   x = self.dense1(inputs)
  >>>   return self.dense2(x)
  >>>
  >>> model = MyModel()

   """
```
## 编译生成文档
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


#[travis-ci](https://travis-ci.org/)</br>

travis_ci注册和github帐号关联</br>

* [python](travis_ci/travis_ci_python)

* [c++](travis_ci/travis_ci_c++)


#[Codecov](https://codecov.io/)</br>


## 代码测试框架

* python: unittest,nosetest
* c++: googletest





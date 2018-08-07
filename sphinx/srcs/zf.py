# import test
# import nose
#
# import unittest
#
# class TruthTest(unittest.TestCase):
#
#     def test_assert_true(self):
#         self.assertTrue(True)
#
#     def test_assert_false(self):
#         self.assertFalse(False)
#
# if __name__ == '__main__':
#     unittest.main()


def multiply(a, b):
  """
  hello ,this a multiply function!
  
  
  test:
    >>> multiply(4, 3)
    12
    >>> multiply('a', 3)
    'aaa'
  
    """
  return a * b


if __name__ == '__main__':
  """调用multiply函数"""
  print(multiply(3,4))
 


#String Manipulation
##String is immutable in Java
 - in c++, string is mutable

```
    string s = "hello";
    s[0] = 'j';
    cout << s << endl;
```

##String concatenation in Java
 - use StringBuilder, which is a mutable object (avoid new string allocating and copy)
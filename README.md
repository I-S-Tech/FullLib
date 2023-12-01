# EPITECH MyLib

---

This is my entire C Lib from Epitech.

It contains all (I mean, all the _usefull_) functions asked by the school (like my_strcmp, my_strdup...) as well as some updates.

On the most notable (and usefull) updates I made, we can see :

- my_debug : Used to debug any type of data with a high level syntax : symply use `my_debug(lvalue)` to display the variable (depending on it's type), as well as the line and filename where it's called.
- my_printf : Rework version of the default printf funxtion, this one use a syntax a little more complex (`%type;formaters%`) to display any type of variable, and let you customise them with a lot of formaters (reversing a string, writing an int in a specific base...)
- my_box : Sample structure containing all the informations about a variable (name, size, type...) used on some of my other features, and can be used manually to store usefull informations about a variable
- my_list : Double linked list pointing to `void*`, so store any type of data in a list (might want to use a my_box here ;)). Also wrote some of the most common functions encountered when dealing with linked lists (append, prepend, delete, destroy...)
- strings operations : my_str_find, my_str_split, my_str_join... Most of the Python (cool) string functions. And no memleaks ;)

Feel free to use this lib in any of your projects.

This comes with no warrenty of work, and I do not take any responsability in any illegal use that might involve, at any point, this lib.

Also, If you are a tech1, you might not want to copy this lib. Feel free to inspire yourself, but be aware that if you steal any of the code, you might end up gitting cought.

Enjoy ;)

Encryption logic:

1) We find the amount of bytes that file consists of
   2) Generate key to different numbers that will decide the amount of symbols in single line with which we will perform encryption
       EXAMPLE:
           file.txt = "Hello World! How are you?" k =10K7s4Q4l
           we will work with such lines as: 
                    1 - "Hello Worl"
                    2 - "d! How "
                    3 - "are "
                    4 - "you?" 
   3) 
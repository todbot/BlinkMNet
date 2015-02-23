
# BlinkMNet -- A network of Ardiuno-connected BlinkMs

```
Operation:
- Receive command from Serial or NSS from upstream Arduino or PC
- Perform command
- Relay command via NSS to downstream Arduino
 
Command format:
                0       1         2          3     4     5     6
- 7 bytes - startbye, addr, blinkm_cmdbyte, arg1, arg2, arg3, chksum
- startbyte = 0x85
- cmdbyte == 'c', 'f', 'o', etc.
- chksum = xor sum of array
 
 
Arduinos and BlinkMs are connected like:
  >--+   +---------+   +---------+   +--------> ...
  rx |   | tx   rx |   | tx   rx |   | tx
   +-v---+--+   +--v---+--+   +--v---+--+
   | Arduino |   | Arduino |   | Arduino |
   +---+-----+   +---+-----+   +---+-----+
       |             |             |
       |             |             |
    +--v----+     +--v----+     +--v----+
    |BlinkM1|     |BlinkM3|     |BlinkM5|
    +--+----+     +--+----+     +--+----+
       |             |             |
    +--v----+     +--v----+     +--v----+
    |BlinkM1|     |BlinkM4|     |BlinkM6|
    +--+----+     +--+----+     +--+----+
       |             |             |
      ...           ...           ... 
 
 ```
 
2011 - Tod E. Kurt - http://todbot.com/blog/

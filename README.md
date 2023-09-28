Usage:
====================
Clone the repo.



Connection:
====================
BTS7960 -> ESP
╔═════════╦═════════╗
║  BTS7960║ ESP32S3 ║
╠═════════╬═════════╣
║   R_IS  ║    6    ║
║   L_IS  ║    7    ║
║   R_EN  ║    2    ║
║   L_EN  ║    4    ║
║  R_PWM  ║    3    ║
║  L_PWM  ║    5    ║
║    5V   ║   VCC   ║
║   GND   ║   GND   ║
╚═════════╩═════════╝


BTS7960 -> Motor, Battery
╔══════════════════════════╗
║         BTS7960          ║
╠══════════════════════════╣
║   B+    ║   Battery +    ║
║   B-    ║   Battery -    ║
║   M+    ║   Motor +      ║
║   M-    ║   Motor -      ║
╚═════════╩════════════════╝

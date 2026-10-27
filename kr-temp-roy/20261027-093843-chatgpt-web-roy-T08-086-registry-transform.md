# T08 086 — Registry and transform (GitHub evidence summary)
BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
Original full note retained in local artifact with same filename.

0x007B7DA0 initializes dynamically allocated 0x2C registry via 0x007DC3D0, stores pointer into 0x00FE173C. 0x007B7E90 uses 0x007B7EF0 to clean and zero registry.

    007B7DC7 push 2Ch
    007B7DC9 call 00891268
    007B7DDE call 007DC3D0
    007B7DEE mov ds:0FE173Ch,eax
    007B7E91 mov esi,[0FE173Ch]

0x007BE150 builds multiple numeric transform sets using 0x00790DC0, 0x00790E90, 0x00790F60, 0x00780890. Exact matrix/rotation semantics pending. Separate adjacent global 0x00FE1740 investigated in 087.

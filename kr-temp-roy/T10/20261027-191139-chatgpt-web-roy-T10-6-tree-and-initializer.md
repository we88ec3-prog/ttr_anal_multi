# KR T10-6 — Mapping tree and initialization

BIN identity: 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91, PE32 x86, .text base 0x401000, raw 0x400. Static assembly only.

0x6D43F0 has the characteristics of ordered tree lookup with insertion on a missing key. [EBP+8] supplies the tree, 0x6D4420 reads its root, node+0x21 is used as a sentinel byte. 0x6D4430 compares node+0x0C against the search key and advances using child pointers. The not-found path calls 0x4FCAE0 at 0x6D4472 and 0x6D48A0 at 0x6D447F; 0x6D4497 returns an address inside the found/inserted node at offset +0x10. The formal type and value payload remain unknown.

    6d441a mov edx,[ebp+0x8]
    6d441d mov ecx,[edx+0x4]
    6d4420 mov eax,[ecx+0x4]
    6d4427 cmp BYTE PTR [eax+0x21],bl
    6d4430 cmp DWORD PTR [eax+0xc],ecx
    6d4435 mov eax,[eax+0x8]
    6d443a mov esi,eax
    6d443c mov eax,[eax]
    6d4472 call 0x4fcae0
    6d447f call 0x6d48a0
    6d4497 lea eax,[esi+0x10]

0x6D1DA0 is a broader mapping-container initializer, not an identified key event. It invokes an element constructor using 0xFDF3F4, element size 0x10 and count 3, followed by allocation of 0x0C and 0x18 byte records. Pointers 0xFDF624, 0xFDF634, 0xFDF644 and 0xFDF654 participate in container initialization.

    6d1dd2 push 0x3
    6d1dd4 push 0x10
    6d1dd8 push 0xfdf3f4
    6d1dea call 0x892003
    6d1df2 push 0xc
    6d1dfa call 0x891268
    6d1e21 push 0x18
    6d1e29 call 0x891268

Provisional pseudocode: Value* lookupOrCreate(Tree& t, Key key) { Node* n=lowerBound(t,key); if (!exact(n,key)) n=insertNode(t,key); return &n->value; } This is not the original signature and has not been proved for every path.

Do not merge this tree with the separate T10-1 0x54F4E0 tree merely because of similar offsets. Confirmed: pointers, allocation calls, observed traversal and initialization; possible: map get-or-create; unknown: exact key/value definitions, relation to runtime Z. T10-7 proceeds to the controller input merge.
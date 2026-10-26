
void FUN_008df110(void)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  void *unaff_ESI;
  int unaff_EDI;
  
  _memset(unaff_ESI,0,0xc4);
  bVar1 = *(byte *)(unaff_EDI + 0xb0);
  *(byte *)((int)unaff_ESI + 8) = bVar1;
  uVar4 = (uint)bVar1;
  if (bVar1 != 0) {
    puVar2 = (undefined2 *)((int)unaff_ESI + 0xc);
    puVar3 = (undefined2 *)(unaff_EDI + 0xb4);
    do {
      *puVar2 = *puVar3;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 2;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  bVar1 = *(byte *)(unaff_EDI + 0xb1);
  *(byte *)((int)unaff_ESI + 9) = bVar1;
  uVar4 = (uint)bVar1;
  if (bVar1 != 0) {
    puVar2 = (undefined2 *)((int)unaff_ESI + 0x28);
    puVar3 = (undefined2 *)(unaff_EDI + 0xec);
    do {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 2;
      puVar2 = puVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  bVar1 = *(byte *)(unaff_EDI + 0xb2);
  *(byte *)((int)unaff_ESI + 10) = bVar1;
  uVar4 = (uint)bVar1;
  if (bVar1 != 0) {
    puVar2 = (undefined2 *)((int)unaff_ESI + 0x3c);
    puVar3 = (undefined2 *)(unaff_EDI + 0x114);
    do {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 2;
      puVar2 = puVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  bVar1 = *(byte *)(unaff_EDI + 0xb3);
  *(byte *)((int)unaff_ESI + 0xb) = bVar1;
  uVar4 = (uint)bVar1;
  if (bVar1 != 0) {
    puVar2 = (undefined2 *)((int)unaff_ESI + 0x58);
    puVar3 = (undefined2 *)(unaff_EDI + 0x14c);
    do {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 2;
      puVar2 = puVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  *(undefined4 *)((int)unaff_ESI + 0x6c) = *(undefined4 *)(unaff_EDI + 0x174);
  *(undefined4 *)((int)unaff_ESI + 0x70) = *(undefined4 *)(unaff_EDI + 0x178);
  *(undefined4 *)((int)unaff_ESI + 0x74) = *(undefined4 *)(unaff_EDI + 0x17c);
  *(undefined2 *)((int)unaff_ESI + 0x78) = *(undefined2 *)(unaff_EDI + 0x180);
  *(undefined2 *)((int)unaff_ESI + 0x7a) = *(undefined2 *)(unaff_EDI + 0x184);
  bVar1 = *(byte *)(unaff_EDI + 0x188);
  *(byte *)((int)unaff_ESI + 0x7c) = bVar1;
  uVar4 = (uint)bVar1;
  if (bVar1 != 0) {
    puVar2 = (undefined2 *)((int)unaff_ESI + 0x80);
    puVar3 = (undefined2 *)(unaff_EDI + 0x18c);
    do {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 2;
      puVar2 = puVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  bVar1 = *(byte *)(unaff_EDI + 0x189);
  *(byte *)((int)unaff_ESI + 0x7d) = bVar1;
  uVar4 = (uint)bVar1;
  if (bVar1 != 0) {
    puVar2 = (undefined2 *)((int)unaff_ESI + 0x9a);
    puVar3 = (undefined2 *)(unaff_EDI + 0x1c0);
    do {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 2;
      puVar2 = puVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  *(undefined1 *)((int)unaff_ESI + 0x7e) = *(undefined1 *)(unaff_EDI + 500);
  *(undefined4 *)((int)unaff_ESI + 0xb8) = *(undefined4 *)(unaff_EDI + 0x200);
  *(undefined4 *)((int)unaff_ESI + 4) = *(undefined4 *)(unaff_EDI + 0x1fc);
  return;
}


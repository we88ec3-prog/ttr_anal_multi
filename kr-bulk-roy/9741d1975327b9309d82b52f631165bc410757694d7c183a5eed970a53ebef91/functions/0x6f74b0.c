
undefined4 * FUN_006f74b0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = _realloc((void *)0x0,0x178);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = 0;
  *(undefined1 *)(puVar1 + 1) = 8;
  *(undefined1 *)(puVar1 + 0x23) = 0x21;
  puVar1[4] = puVar1 + 0x1e;
  puVar1[8] = 0;
  puVar1[0xb] = 0;
  puVar1[0x1c] = 0;
  puVar1[0x11] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x1a] = 0;
  puVar1[0xc] = 0;
  *(undefined4 *)((int)puVar1 + 0x36) = 0x1000000;
  *(undefined2 *)((int)puVar1 + 5) = 0x61;
  puVar1[5] = 0;
  puVar1[10] = 0;
  puVar1[6] = 0;
  puVar1[0x1d] = 0;
  puVar1[0x14] = 0;
  *(undefined2 *)(puVar1 + 0xd) = 0;
  puVar1[0x40] = puVar1 + 0x3c;
  puVar1[0x41] = puVar1 + 0x3c;
  puVar1[0x21] = FUN_006f7170;
  puVar1[0x22] = 0;
  puVar1[0x3a] = puVar1;
  puVar1[0x2e] = 0;
  puVar1[0x20] = 0;
  puVar1[0x1f] = 0;
  puVar1[0x1e] = 0;
  *(undefined4 *)(puVar1[4] + 0x68) = 0;
  puVar1[0x25] = puVar1;
  puVar1[0x2b] = 0;
  puVar1[0x2d] = 0;
  puVar1[0x34] = 0;
  *(undefined1 *)((int)puVar1 + 0x8d) = 0;
  puVar1[0x24] = 0;
  puVar1[0x27] = 0;
  puVar1[0x28] = 0;
  puVar1[0x29] = 0;
  puVar1[0x2a] = 0;
  puVar1[0x2f] = 0x178;
  puVar1[0x31] = 0;
  puVar1[0x26] = puVar1 + 0x25;
  puVar1[0x32] = 200;
  puVar1[0x33] = 200;
  puVar1[0x44] = 0;
  puVar1[0x45] = 0;
  puVar1[0x46] = 0;
  puVar1[0x47] = 0;
  puVar1[0x48] = 0;
  puVar1[0x49] = 0;
  puVar1[0x4a] = 0;
  puVar1[0x4b] = 0;
  puVar1[0x4c] = 0;
  iVar2 = FUN_006fdba0(puVar1,FUN_006f7280,0);
  if (iVar2 != 0) {
    FUN_006f7300();
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}



void FUN_0072cf00(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(in_EAX + 0x16bc);
  *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | 2 << ((byte)iVar2 & 0x1f);
  if (iVar2 < 0xe) {
    *(int *)(in_EAX + 0x16bc) = iVar2 + 3;
  }
  else {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b8);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b9);
    iVar2 = *(int *)(in_EAX + 0x16bc);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(int *)(in_EAX + 0x16bc) = iVar2 + -0xd;
    *(ushort *)(in_EAX + 0x16b8) = 2 >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar2 = *(int *)(in_EAX + 0x16bc);
  *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | 0 << ((byte)iVar2 & 0x1f);
  if (iVar2 < 10) {
    *(int *)(in_EAX + 0x16bc) = iVar2 + 7;
  }
  else {
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b8);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b9);
    iVar2 = *(int *)(in_EAX + 0x16bc);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(int *)(in_EAX + 0x16bc) = iVar2 + -9;
    *(ushort *)(in_EAX + 0x16b8) = 0 >> (0x10U - (char)iVar2 & 0x1f);
  }
  iVar1 = FUN_0072d7e0();
  iVar2 = *(int *)(iVar1 + 0x16bc);
  if ((*(int *)(iVar1 + 0x16b4) - iVar2) + 0xb < 9) {
    *(ushort *)(iVar1 + 0x16b8) = *(ushort *)(iVar1 + 0x16b8) | 2 << ((byte)iVar2 & 0x1f);
    if (iVar2 < 0xe) {
      *(int *)(iVar1 + 0x16bc) = iVar2 + 3;
    }
    else {
      *(undefined1 *)(*(int *)(iVar1 + 8) + *(int *)(iVar1 + 0x14)) =
           *(undefined1 *)(iVar1 + 0x16b8);
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      *(undefined1 *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) =
           *(undefined1 *)(iVar1 + 0x16b9);
      iVar2 = *(int *)(iVar1 + 0x16bc);
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      *(int *)(iVar1 + 0x16bc) = iVar2 + -0xd;
      *(ushort *)(iVar1 + 0x16b8) = 2 >> (0x10U - (char)iVar2 & 0x1f);
    }
    iVar2 = *(int *)(iVar1 + 0x16bc);
    *(ushort *)(iVar1 + 0x16b8) = *(ushort *)(iVar1 + 0x16b8) | 0 << ((byte)iVar2 & 0x1f);
    if (9 < iVar2) {
      *(undefined1 *)(*(int *)(iVar1 + 8) + *(int *)(iVar1 + 0x14)) =
           *(undefined1 *)(iVar1 + 0x16b8);
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      *(undefined1 *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) =
           *(undefined1 *)(iVar1 + 0x16b9);
      iVar2 = *(int *)(iVar1 + 0x16bc);
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      *(int *)(iVar1 + 0x16bc) = iVar2 + -9;
      *(ushort *)(iVar1 + 0x16b8) = 0 >> (0x10U - (char)iVar2 & 0x1f);
      iVar2 = FUN_0072d7e0();
      *(undefined4 *)(iVar2 + 0x16b4) = 7;
      return;
    }
    *(int *)(iVar1 + 0x16bc) = iVar2 + 7;
    iVar1 = FUN_0072d7e0();
  }
  *(undefined4 *)(iVar1 + 0x16b4) = 7;
  return;
}


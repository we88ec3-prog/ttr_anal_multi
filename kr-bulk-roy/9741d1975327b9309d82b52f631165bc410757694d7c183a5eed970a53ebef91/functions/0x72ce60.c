
void FUN_0072ce60(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  ushort in_CX;
  
  iVar1 = *(int *)(in_EAX + 0x16bc);
  if (0xd < iVar1) {
    *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | in_CX << ((byte)iVar1 & 0x1f);
    *(undefined1 *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =
         *(undefined1 *)(in_EAX + 0x16b8);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(undefined1 *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =
         *(undefined1 *)(in_EAX + 0x16b9);
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;
    *(ushort *)(in_EAX + 0x16b8) = in_CX >> (0x10U - (char)*(int *)(in_EAX + 0x16bc) & 0x1f);
    *(int *)(in_EAX + 0x16bc) = *(int *)(in_EAX + 0x16bc) + -0xd;
    FUN_0072d8c0(param_2);
    return;
  }
  *(int *)(in_EAX + 0x16bc) = iVar1 + 3;
  *(ushort *)(in_EAX + 0x16b8) = *(ushort *)(in_EAX + 0x16b8) | in_CX << ((byte)iVar1 & 0x1f);
  FUN_0072d8c0(param_2);
  return;
}


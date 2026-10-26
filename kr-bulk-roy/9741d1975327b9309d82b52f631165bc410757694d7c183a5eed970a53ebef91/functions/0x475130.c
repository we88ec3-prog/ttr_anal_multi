
void FUN_00475130(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_007459c0();
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00475170;
    iVar2 = FUN_00745c20();
  }
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) && ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)
     ) {
    FUN_0074a010(iVar2);
  }
LAB_00475170:
  iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar2 != 0) {
    *(uint *)(in_ECX + 0x118) = (uint)*(ushort *)(iVar2 + 0x88);
    FUN_004751e0(in_ECX);
  }
  *(undefined4 *)(in_ECX + 0x11c) = 1;
  FUN_00476020();
  iVar1 = DAT_00fb1318;
  iVar2 = *(int *)(DAT_00fb1318 + 0xbfe8);
  *(undefined4 *)(iVar2 + 0x78) = 1;
  *(undefined1 *)(iVar2 + 0x80) = 1;
  iVar2 = *(int *)(iVar1 + 0xbfe8);
  *(undefined4 *)(iVar2 + 0x7c) = 0x42340000;
  *(undefined4 *)(iVar2 + 0xb0) = 1;
  return;
}


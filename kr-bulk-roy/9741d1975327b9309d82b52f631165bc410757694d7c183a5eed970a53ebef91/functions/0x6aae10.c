
void FUN_006aae10(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_007459c0();
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_006aae5f;
    iVar1 = FUN_00745c20();
  }
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) && ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)
     ) {
    FUN_0074a010(iVar1);
  }
LAB_006aae5f:
  iVar1 = *(int *)(in_ECX + 0xf4);
  if (*(char *)(iVar1 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar1 + 0x168) = 0;
  *(undefined4 *)(iVar1 + 0x160) = 0;
  *(undefined4 *)(iVar1 + 0x164) = 0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  FUN_006aa7f0(in_ECX);
  return;
}


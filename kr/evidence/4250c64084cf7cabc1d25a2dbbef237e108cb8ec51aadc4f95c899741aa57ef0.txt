
undefined4 FUN_00548cb0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  if ((*(int *)(in_ECX + 4) == 0) || (*(int *)(in_ECX + 0xdc) == 0)) {
    return 0;
  }
  uVar1 = FUN_005452c0();
  if (*(int *)(in_ECX + 0xc) == 0) {
    return 0;
  }
  iVar2 = FUN_00444960();
  if (*(char *)(iVar2 + 0x7e1) == '\x01') {
    uVar3 = 1;
    FUN_00434250(1);
    FUN_00544a00(uVar3);
    return uVar1;
  }
  uVar3 = 0;
  FUN_00434250(0);
  FUN_00544a00(uVar3);
  return uVar1;
}


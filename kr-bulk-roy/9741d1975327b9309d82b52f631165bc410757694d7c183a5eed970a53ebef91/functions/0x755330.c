
void FUN_00755330(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar1 = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8);
  iVar2 = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc);
  if ((0 < iVar1) && (0 < iVar2)) {
    FUN_00755370(*(undefined4 *)(in_ECX + 0x84),*(undefined4 *)(in_ECX + 0x88),iVar1,iVar2,param_1,
                 param_2);
  }
  return;
}


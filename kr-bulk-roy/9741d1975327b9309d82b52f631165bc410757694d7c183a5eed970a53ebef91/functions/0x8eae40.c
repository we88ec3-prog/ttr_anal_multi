
int FUN_008eae40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = FUN_008b97e0(iVar1,param_3);
  if (iVar2 == 0) {
    iVar2 = FUN_008babe0(iVar1,param_4);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 200) = *(undefined4 *)(iVar1 + 0x20);
      *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(iVar1 + 0x24);
      iVar2 = 0;
    }
  }
  return iVar2;
}


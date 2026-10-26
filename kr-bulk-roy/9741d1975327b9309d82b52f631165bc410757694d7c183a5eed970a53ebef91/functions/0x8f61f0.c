
int FUN_008f61f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_008f4360(param_2);
  if ((iVar2 == 0) &&
     (((*(byte *)(param_1 + 100) & 1) != 0 || (iVar2 = FUN_008f5890(), iVar2 == 0)))) {
    if ((*(byte *)(param_1 + 100) & 2) == 0) {
      iVar2 = FUN_008f5890();
      if (iVar2 != 0) {
        return iVar2;
      }
      FUN_008f58b0(param_1,param_3);
      iVar2 = 0;
    }
    iVar3 = 0;
    do {
      if (iVar3 == 0) {
        bVar1 = *(byte *)(param_1 + 100) & 1;
joined_r0x008f6265:
        if (bVar1 == 0) {
          FUN_008f5d00(param_1,iVar3);
          FUN_008f47f0();
          FUN_008f48c0(iVar3);
          FUN_008f4c20(iVar3);
        }
      }
      else if (iVar3 == 1) {
        bVar1 = *(byte *)(param_1 + 100) & 2;
        goto joined_r0x008f6265;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    FUN_008f47a0();
  }
  return iVar2;
}


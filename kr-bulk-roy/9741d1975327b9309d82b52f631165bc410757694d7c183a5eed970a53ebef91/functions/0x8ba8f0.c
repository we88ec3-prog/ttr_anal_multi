
int FUN_008ba8f0(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 local_8;
  
  iVar3 = *(int *)(param_2 + 0x48);
  iVar2 = 0;
  if (iVar3 != 0x62697473) {
    local_8 = 0;
    bVar1 = false;
    if (iVar3 == 0x6f75746c) {
      iVar3 = *(int *)(param_1 + 0x9c);
      local_8 = *(undefined4 *)(param_1 + 0x94);
    }
    else {
      iVar3 = FUN_008b8e90(param_1,iVar3,&local_8);
    }
    iVar2 = 7;
    if (iVar3 != 0) {
      while (iVar2 = (**(code **)(iVar3 + 0x3c))(iVar3,param_2,param_3,0), iVar2 != 0) {
        if ((char)iVar2 != '\x13') {
          return iVar2;
        }
        iVar3 = FUN_008b8e90(param_1,*(undefined4 *)(param_2 + 0x48),&local_8);
        bVar1 = true;
        if (iVar3 == 0) {
          return iVar2;
        }
      }
      iVar2 = 0;
      if (bVar1) {
        FUN_008ba850(param_1,iVar3,0,0);
      }
    }
  }
  return iVar2;
}


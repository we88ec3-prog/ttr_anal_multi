
int FUN_008db560(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = param_1;
  uVar3 = *(undefined4 *)(param_1 + 100);
  param_1 = 0;
  iVar2 = (**(code **)(param_2 + 0x24))(param_2);
  if (*(int *)(iVar1 + 0x130) == 0) {
    uVar3 = FUN_008bc7d0(uVar3,0xfc,0,iVar2,0,&param_1);
    *(undefined4 *)(iVar1 + 0x130) = uVar3;
    if (param_1 == 0) {
      iVar4 = 0;
      *(int *)(iVar1 + 300) = iVar2;
      if (0 < iVar2) {
        iVar2 = 0;
        do {
          *(undefined4 *)(*(int *)(iVar1 + 0x130) + 4 + iVar2) = 4;
          iVar4 = iVar4 + 1;
          iVar2 = iVar2 + 0xfc;
        } while (iVar4 < *(int *)(iVar1 + 300));
      }
    }
  }
  return param_1;
}


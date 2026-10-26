
int FUN_008c3330(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = param_2;
  uVar4 = *(undefined4 *)(param_2 + 0x1c);
  param_2 = (**(code **)(param_1 + 0x1fc))(param_1,0x67617370,param_2,0);
  if ((param_2 == 0) && (param_2 = FUN_008babe0(iVar2,4), param_2 == 0)) {
    uVar3 = FUN_008b9960(iVar2);
    *(undefined2 *)(param_1 + 0x21c) = uVar3;
    uVar3 = FUN_008b9960(iVar2);
    *(undefined2 *)(param_1 + 0x21e) = uVar3;
    FUN_008baca0(iVar2);
    if (1 < *(ushort *)(param_1 + 0x21c)) {
      *(undefined2 *)(param_1 + 0x21e) = 0;
      return 8;
    }
    uVar5 = (uint)*(ushort *)(param_1 + 0x21e);
    uVar4 = FUN_008bc7d0(uVar4,4,0,uVar5,0,&param_2);
    *(undefined4 *)(param_1 + 0x220) = uVar4;
    if ((param_2 == 0) && (param_2 = FUN_008babe0(iVar2,uVar5 * 4), param_2 == 0)) {
      iVar1 = *(int *)(param_1 + 0x220);
      uVar6 = 0;
      if (uVar5 != 0) {
        do {
          uVar3 = FUN_008b9960(iVar2);
          *(undefined2 *)(iVar1 + uVar6 * 4) = uVar3;
          uVar3 = FUN_008b9960(iVar2);
          *(undefined2 *)(iVar1 + 2 + uVar6 * 4) = uVar3;
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar5);
      }
      FUN_008baca0(iVar2);
    }
  }
  return param_2;
}


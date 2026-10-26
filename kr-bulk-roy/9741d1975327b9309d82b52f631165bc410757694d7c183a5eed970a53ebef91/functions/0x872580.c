
void FUN_00872580(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_2 == 0) || ((param_1[0x18] & param_2) == param_1[0x18])) {
    FUN_0077f890();
  }
  uVar4 = 0;
  iVar1 = (**(code **)(*param_1 + 0x34))();
  if (iVar1 != 0) {
    do {
      uVar3 = uVar4;
      uVar2 = (**(code **)(*param_1 + 0x30))(uVar4,param_2);
      FUN_00872580(uVar2,uVar3);
      uVar4 = uVar4 + 1;
      uVar3 = (**(code **)(*param_1 + 0x34))();
    } while (uVar4 < uVar3);
  }
  return;
}


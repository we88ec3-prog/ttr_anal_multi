
int FUN_008f19c0(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  uVar1 = param_2;
  piVar5 = param_1;
  iVar2 = *param_1;
  iVar3 = 0;
  if ((*(byte *)(iVar2 + 8) & 2) != 0) {
    iVar3 = (**(code **)(*(int *)(iVar2 + 0x214) + 0x68))(iVar2,param_2,&param_1);
    if (iVar3 == 0) {
      iVar2 = FUN_008f1960(piVar5,param_1);
      return iVar2;
    }
    piVar5[0x1c] = -1;
  }
  FUN_008b8800(*piVar5,uVar1);
  if ((*(byte *)(*piVar5 + 8) & 1) != 0) {
    iVar3 = FUN_008ebc60(piVar5);
    piVar4 = piVar5 + 0xb;
    piVar5 = piVar5 + 3;
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
  }
  return iVar3;
}


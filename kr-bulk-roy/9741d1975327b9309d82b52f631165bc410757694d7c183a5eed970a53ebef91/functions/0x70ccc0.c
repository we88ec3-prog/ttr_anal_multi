
void FUN_0070ccc0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *local_10;
  int iStack_c;
  
  iVar3 = FUN_006fee90(&local_10,4);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  piVar4 = local_10;
  if ((int)local_10 < 0) {
    FUN_0070cc10();
    piVar4 = param_1;
  }
  if ((int)piVar4 + 1U < 0x40000000) {
    iStack_c = *param_1;
    iVar1 = (int)piVar4 * 4;
    iVar2 = *(int *)(iStack_c + 0x10);
    iVar3 = (**(code **)(iVar2 + 0xc))(*(undefined4 *)(iVar2 + 0x10),0,0,iVar1);
    if ((iVar3 == 0) && (iVar1 != 0)) {
      iVar3 = FUN_006fdb40(iStack_c,4);
    }
    *(int *)(iVar2 + 0x44) = *(int *)(iVar2 + 0x44) + iVar1;
    piVar4 = local_10;
  }
  else {
    FUN_006f8b60(*param_1,"memory allocation error: block too big");
    iVar3 = 0;
  }
  *(int *)(param_2 + 0xc) = iVar3;
  *(int **)(param_2 + 0x2c) = piVar4;
  iVar3 = FUN_006fee90(iVar3,(int)piVar4 * 4);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  return;
}


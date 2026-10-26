
int FUN_007040b0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  if ((iVar3 == 0) && (param_2 != 0)) {
    iVar3 = 1;
  }
  uVar1 = *(undefined4 *)(param_1 + 8);
  iVar2 = FUN_006f5170();
  if (iVar2 == 0) {
    FUN_006f5f30(uVar1,"stack overflow (%s)","too many captures");
  }
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      FUN_00703fd0(param_2,param_3);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return iVar3;
}


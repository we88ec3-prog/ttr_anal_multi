
void FUN_006390e0(void)

{
  int *piVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  
  (**(code **)(*in_EAX + 8))();
  (**(code **)(*(int *)in_EAX[4] + 0x94))(1);
  piVar1 = in_EAX + 0x2c;
  FUN_0075d790();
  if (in_EAX[0x30] == 0) {
    FUN_0075d470(piVar1,0);
  }
  else if (in_EAX[0x30] == 1) {
    FUN_0075d540(piVar1,0);
  }
  iVar2 = in_EAX[2];
  if (*(int **)in_EAX[0x2d] != (int *)in_EAX[0x2d]) {
    iVar3 = (*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc)) + -0x3c;
    iVar4 = FUN_0075d610(iVar3);
    FUN_00749a00(((*(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 8)) - iVar4) + -0x14,iVar3);
    if (in_EAX[0x30] == 0) {
      FUN_0075d470(piVar1,0);
      return;
    }
    if (in_EAX[0x30] == 1) {
      FUN_0075d540(piVar1,0);
    }
  }
  return;
}


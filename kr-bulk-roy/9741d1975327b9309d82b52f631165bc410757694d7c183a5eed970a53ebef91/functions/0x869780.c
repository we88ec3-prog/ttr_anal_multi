
void FUN_00869780(int *param_1)

{
  char cVar1;
  int *in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (in_EAX != param_1) {
    iVar2 = *in_EAX;
    uVar4 = param_1[1] - *param_1 >> 4;
    if (uVar4 == 0) {
      if (iVar2 != in_EAX[1]) {
        iVar2 = FUN_008698b0();
        in_EAX[1] = iVar2;
        return;
      }
    }
    else {
      uVar3 = in_EAX[1] - iVar2 >> 4;
      if (uVar4 <= uVar3) {
        FUN_008698b0();
        in_EAX[1] = (param_1[1] - *param_1 & 0xfffffff0U) + *in_EAX;
        return;
      }
      if (uVar4 <= (uint)(in_EAX[2] - iVar2 >> 4)) {
        iVar2 = *param_1;
        FUN_008698b0();
        iVar2 = FUN_008698f0(iVar2 + uVar3 * 0x10,param_1);
        in_EAX[1] = iVar2;
        return;
      }
      if (iVar2 != 0) {
        FUN_0089120c(iVar2);
      }
      cVar1 = FUN_00869870();
      if (cVar1 != '\0') {
        iVar2 = FUN_008698f0(*param_1,param_1);
        in_EAX[1] = iVar2;
      }
    }
  }
  return;
}


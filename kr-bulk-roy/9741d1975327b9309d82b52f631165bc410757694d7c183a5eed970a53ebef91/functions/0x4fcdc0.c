
/* WARNING: Removing unreachable block (ram,0x004fcdf4) */

void FUN_004fcdc0(int *param_1)

{
  int iVar1;
  char cVar2;
  int *in_EAX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (in_EAX != param_1) {
    iVar4 = *param_1;
    uVar3 = param_1[1] - iVar4 >> 3;
    if (uVar3 == 0) {
      if (*in_EAX != in_EAX[1]) {
        in_EAX[1] = *in_EAX;
        return;
      }
    }
    else {
      iVar1 = *in_EAX;
      uVar5 = in_EAX[1] - iVar1 >> 3;
      if (uVar3 <= uVar5) {
        FUN_00520540(iVar1);
        in_EAX[1] = *in_EAX + (param_1[1] - *param_1 >> 3) * 8;
        return;
      }
      if (uVar3 <= (uint)(in_EAX[2] - iVar1 >> 3)) {
        FUN_00520540(iVar1);
        iVar4 = FUN_006d1d70(iVar4 + uVar5 * 8,uVar5);
        in_EAX[1] = iVar4;
        return;
      }
      if (iVar1 != 0) {
        FUN_0089120c(iVar1);
      }
      cVar2 = FUN_004bb3e0();
      if (cVar2 != '\0') {
        iVar4 = FUN_006d1d70(*param_1,uVar5);
        in_EAX[1] = iVar4;
      }
    }
  }
  return;
}


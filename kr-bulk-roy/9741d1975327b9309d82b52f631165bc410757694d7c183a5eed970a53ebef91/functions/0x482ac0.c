
/* WARNING: Removing unreachable block (ram,0x00482af4) */

void FUN_00482ac0(int *param_1)

{
  int iVar1;
  char cVar2;
  int *in_EAX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (in_EAX != param_1) {
    iVar4 = *param_1;
    iVar1 = *in_EAX;
    uVar3 = param_1[1] - iVar4 >> 2;
    if (uVar3 == 0) {
      if (iVar1 != in_EAX[1]) {
        in_EAX[1] = iVar1;
        return;
      }
    }
    else {
      uVar5 = in_EAX[1] - iVar1 >> 2;
      if (uVar3 <= uVar5) {
        FUN_00482e50(iVar1);
        in_EAX[1] = *in_EAX + (param_1[1] - *param_1 >> 2) * 4;
        return;
      }
      if (uVar3 <= (uint)(in_EAX[2] - iVar1 >> 2)) {
        FUN_00482e50(iVar1);
        iVar4 = FUN_00552ec0(iVar4 + uVar5 * 4,uVar5);
        in_EAX[1] = iVar4;
        return;
      }
      if (iVar1 != 0) {
        FUN_0089120c(iVar1);
      }
      cVar2 = FUN_00447ad0();
      if (cVar2 != '\0') {
        iVar4 = FUN_00552ec0(*param_1,uVar5);
        in_EAX[1] = iVar4;
      }
    }
  }
  return;
}


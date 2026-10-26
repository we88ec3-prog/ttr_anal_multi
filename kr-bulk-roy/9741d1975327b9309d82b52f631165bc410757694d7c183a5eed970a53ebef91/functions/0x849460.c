
void FUN_00849460(int param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  iVar2 = (param_2 - param_1) / 100;
  iVar1 = (in_EAX - param_1) / 100;
  iVar5 = iVar1;
  local_8 = iVar2;
  while (iVar3 = iVar5, iVar3 != 0) {
    iVar5 = local_8 % iVar3;
    local_8 = iVar3;
  }
  if ((local_8 < iVar2) && (0 < local_8)) {
    iVar2 = local_8 * 100 + param_1;
    do {
      iVar5 = iVar2 + iVar1 * 100;
      iVar3 = iVar2;
      iVar4 = param_1;
      if (iVar5 != param_2) {
        iVar4 = iVar5;
      }
      do {
        FUN_00849600(iVar3,iVar4);
        iVar5 = (param_2 - iVar4) / 100;
        if (iVar1 < iVar5) {
          iVar5 = iVar4 + iVar1 * 100;
        }
        else {
          iVar5 = (iVar1 - iVar5) * 100 + param_1;
        }
        iVar3 = iVar4;
        iVar4 = iVar5;
      } while (iVar5 != iVar2);
      iVar2 = iVar2 + -100;
      local_8 = local_8 + -1;
    } while (0 < local_8);
  }
  return;
}


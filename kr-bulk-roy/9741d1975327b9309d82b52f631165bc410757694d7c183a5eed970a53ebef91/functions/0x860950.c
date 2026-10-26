
void FUN_00860950(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = param_2 - param_1 >> 2;
  iVar5 = in_EAX - param_1 >> 2;
  iVar3 = iVar5;
  iVar4 = iVar2;
  while (iVar1 = iVar3, iVar1 != 0) {
    iVar3 = iVar4 % iVar1;
    iVar4 = iVar1;
  }
  if ((iVar4 < iVar2) && (0 < iVar4)) {
    iVar3 = param_1 + iVar4 * 4;
    do {
      iVar2 = iVar3 + iVar5 * 4;
      if (iVar2 == param_2) {
        iVar2 = param_1;
      }
      do {
        FUN_008609f0(iVar2);
        iVar1 = param_2 - iVar2 >> 2;
        if (iVar5 < iVar1) {
          iVar2 = iVar2 + iVar5 * 4;
        }
        else {
          iVar2 = param_1 + (iVar5 - iVar1) * 4;
        }
      } while (iVar2 != iVar3);
      iVar3 = iVar3 + -4;
      iVar4 = iVar4 + -1;
    } while (0 < iVar4);
  }
  return;
}


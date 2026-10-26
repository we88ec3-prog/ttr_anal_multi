
int FUN_006f93c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_c;
  int local_8;
  
  iVar1 = 1;
  iVar6 = 0;
  local_8 = 0;
  local_c = 1;
  iVar3 = 1;
  do {
    iVar2 = *(int *)(param_1 + 0x1c);
    iVar4 = 0;
    if (iVar2 < iVar3) {
      if (iVar2 < iVar1) {
        return local_8;
      }
LAB_006f93f2:
      piVar5 = (int *)(*(int *)(param_1 + 0xc) + -8 + iVar1 * 0x10);
      iVar2 = (iVar2 - local_c) + 1;
      iVar1 = local_c + iVar2;
      do {
        if (*piVar5 != 0) {
          iVar4 = iVar4 + 1;
        }
        piVar5 = piVar5 + 4;
        iVar2 = iVar2 + -1;
        local_c = iVar1;
      } while (iVar2 != 0);
    }
    else {
      iVar2 = iVar3;
      if (iVar1 <= iVar3) goto LAB_006f93f2;
    }
    piVar5 = (int *)(param_2 + iVar6 * 4);
    *piVar5 = *piVar5 + iVar4;
    local_8 = local_8 + iVar4;
    iVar6 = iVar6 + 1;
    iVar3 = iVar3 * 2;
    if (0x1a < iVar6) {
      return local_8;
    }
  } while( true );
}


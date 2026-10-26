
int * FUN_0080f030(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  undefined1 local_8 [4];
  
  iVar2 = 0;
  *param_3 = 0;
  if (unaff_EDI < 1) {
    return param_3;
  }
  do {
    piVar1 = (int *)ov_read(*(undefined4 *)(param_1 + 8),iVar2 + param_2,unaff_EDI - iVar2,0,2,1,
                            local_8);
    if ((int)piVar1 < 1) {
      if ((int)piVar1 < 0) {
        return piVar1;
      }
      break;
    }
    iVar2 = iVar2 + (int)piVar1;
  } while (iVar2 < unaff_EDI);
  if (iVar2 != 0) {
    *param_3 = iVar2;
  }
  return piVar1;
}


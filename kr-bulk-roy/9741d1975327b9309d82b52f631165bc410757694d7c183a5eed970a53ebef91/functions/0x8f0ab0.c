
int FUN_008f0ab0(uint *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  int *in_EAX;
  int iVar4;
  int iVar5;
  uint local_14;
  int local_8;
  
  iVar4 = 0x10000;
  local_8 = 0x10000;
  local_14 = 0;
  if (*param_1 == 0) {
    return 0x10000;
  }
  param_3 = param_3 - (int)in_EAX;
  param_4 = param_4 - (int)in_EAX;
  do {
    iVar1 = *in_EAX;
    if (iVar1 != 0) {
      iVar5 = *(int *)(param_1[1] + local_14 * 4);
      if (((iVar5 == 0) || ((iVar5 < 0 && (0 < iVar1)))) || ((0 < iVar5 && (iVar1 < 0)))) {
        return 0;
      }
      if ((param_2 & 0x4000) == 0) {
        if (iVar5 < 1) {
          iVar5 = -iVar5;
        }
        lVar3 = (longlong)local_8 * (longlong)iVar5 +
                (ulonglong)((int)((longlong)local_8 * (longlong)iVar5 >> 0x3f) + 0x8000);
        iVar4 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
        local_8 = iVar4;
      }
      else {
        if (iVar5 <= *(int *)(param_3 + (int)in_EAX)) {
          return 0;
        }
        if (*(int *)(param_4 + (int)in_EAX) <= iVar5) {
          return 0;
        }
        if (iVar5 < iVar1) {
          iVar2 = *(int *)(param_3 + (int)in_EAX);
          iVar4 = FUN_008b7dc0(iVar4,iVar5 - iVar2,iVar1 - iVar2);
          local_8 = iVar4;
        }
        else {
          iVar2 = *(int *)(param_4 + (int)in_EAX);
          iVar4 = FUN_008b7dc0(iVar4,iVar2 - iVar5,iVar2 - iVar1);
          local_8 = iVar4;
        }
      }
    }
    local_14 = local_14 + 1;
    in_EAX = in_EAX + 1;
    if (*param_1 <= local_14) {
      return iVar4;
    }
  } while( true );
}


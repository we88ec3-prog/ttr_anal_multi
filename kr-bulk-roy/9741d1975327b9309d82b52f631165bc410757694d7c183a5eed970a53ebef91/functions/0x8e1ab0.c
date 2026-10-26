
void FUN_008e1ab0(int param_1,int param_2,int *param_3,int *param_4)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  int *unaff_EDI;
  undefined4 uVar2;
  int local_8;
  
  local_8 = in_ECX - param_2;
  param_1 = in_EAX - param_1;
  if (*(char *)(*unaff_EDI + 0xc0) != '\0') {
    param_1 = -param_1;
    local_8 = -local_8;
  }
  *param_4 = 0;
  *param_3 = 0;
  if (*(char *)((int)unaff_EDI + 0x2d92) != '\0') {
    iVar1 = FUN_008e0e60();
    *(int *)(unaff_EDI[1] + 0x10) = *(int *)(unaff_EDI[1] + 0x10) + iVar1;
    if (-1 < param_1) {
      if (local_8 < 0) {
        if (local_8 * -2 < param_1) {
          *param_3 = 0;
          *param_4 = 0;
          return;
        }
        if (param_1 * -2 != local_8 && param_1 * 2 <= -local_8) {
          *param_3 = -unaff_EDI[0xb6a];
          *param_4 = unaff_EDI[0xb6b];
          return;
        }
        iVar1 = FUN_008b7f10(0xffff4cce,unaff_EDI[0xb6a]);
        *param_3 = iVar1;
        iVar1 = FUN_008b7f10(0x4ccd,unaff_EDI[0xb6b]);
        *param_4 = iVar1;
        return;
      }
      if (local_8 * 2 < param_1) {
        *param_3 = 0;
        *param_4 = 0;
        return;
      }
      if (local_8 <= param_1 * 2) {
        iVar1 = FUN_008b7f10(0xb333,unaff_EDI[0xb6a]);
        *param_3 = iVar1;
        iVar1 = FUN_008b7f10(0x4ccd,unaff_EDI[0xb6b]);
        *param_4 = iVar1;
        return;
      }
LAB_008e1b42:
      *param_3 = unaff_EDI[0xb6a];
      *param_4 = unaff_EDI[0xb6b];
      return;
    }
    if (local_8 < 0) {
      if (local_8 * 2 != param_1 && local_8 * -2 <= -param_1) goto LAB_008e1c20;
      if (param_1 * 2 != local_8 && param_1 * -2 <= -local_8) {
        *param_3 = -unaff_EDI[0xb6a];
        *param_4 = unaff_EDI[0xb6a];
        return;
      }
      iVar1 = unaff_EDI[0xb6a];
      uVar2 = 0xffff4cce;
    }
    else {
      if (local_8 * -2 != param_1 && local_8 * 2 <= -param_1) {
LAB_008e1c20:
        *param_3 = 0;
        *param_4 = unaff_EDI[0xb6b] * 2;
        return;
      }
      if (param_1 * -2 < local_8) goto LAB_008e1b42;
      iVar1 = unaff_EDI[0xb6a];
      uVar2 = 0xb333;
    }
    iVar1 = FUN_008b7f10(uVar2,iVar1);
    *param_3 = iVar1;
    iVar1 = FUN_008b7f10(0x1b333,unaff_EDI[0xb6b]);
    *param_4 = iVar1;
  }
  return;
}


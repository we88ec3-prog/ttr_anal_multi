
int FUN_008ba520(undefined4 param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *unaff_ESI;
  int *unaff_EDI;
  int local_c;
  int local_8;
  
  *unaff_EDI = 0;
  *unaff_ESI = 0;
  *param_3 = 0;
  iVar1 = FUN_008b9c00(param_1,&local_8);
  if (local_8 != 0) {
    return local_8;
  }
  if (iVar1 != 0x74797031) {
    return 2;
  }
  uVar2 = FUN_008b9ab0(param_1,&local_8);
  if ((local_8 == 0) && (local_8 = FUN_008b9820(param_1,6), local_8 == 0)) {
    *param_3 = 0;
    iVar1 = -1;
    local_c = 0;
    local_8 = 0;
    if ((uVar2 & 0xffff) != 0) {
      do {
        iVar3 = FUN_008b9c00(param_1,&local_8);
        if (local_8 != 0) {
          return local_8;
        }
        local_8 = FUN_008b9820(param_1,4);
        if (local_8 != 0) {
          return local_8;
        }
        iVar4 = FUN_008b9c00(param_1,&local_8);
        *unaff_EDI = iVar4;
        if (local_8 != 0) {
          return local_8;
        }
        iVar4 = FUN_008b9c00(param_1,&local_8);
        *unaff_ESI = iVar4;
        if (local_8 != 0) {
          return local_8;
        }
        if (iVar3 == 0x43494420) {
          *unaff_EDI = *unaff_EDI + 0x16;
          *unaff_ESI = *unaff_ESI + -0x16;
          *param_3 = 1;
joined_r0x008ba65b:
          iVar1 = iVar1 + 1;
          if (param_2 < 0) {
            return 0;
          }
LAB_008ba665:
          if (iVar1 == param_2) {
            return 0;
          }
        }
        else {
          if (iVar3 == 0x54595031) {
            *unaff_EDI = *unaff_EDI + 0x18;
            *unaff_ESI = *unaff_ESI + -0x18;
            *param_3 = 0;
            goto joined_r0x008ba65b;
          }
          if (-1 < param_2) goto LAB_008ba665;
        }
        local_c = local_c + 1;
      } while (local_c < (int)(uVar2 & 0xffff));
    }
    local_8 = 0x8e;
  }
  return local_8;
}


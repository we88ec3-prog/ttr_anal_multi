
void FUN_008ead70(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  int local_18 [3];
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = *(int **)(*(int *)(*unaff_ESI + 0x80) + 0x30);
  if ((piVar1 != (int *)0x0) && (*(int *)(*piVar1 + 8) != 0)) {
    local_18[2] = unaff_ESI[0xe];
    local_18[0] = unaff_ESI[0xd];
    local_18[1] = 0;
    local_c = 0;
    piVar1 = *(int **)(*(int *)(*unaff_ESI + 0x80) + 0x30);
    iVar2 = (**(code **)(*piVar1 + 8))(piVar1[1],param_1,0,local_18);
    if (iVar2 == 0) {
      unaff_ESI[0xd] = (int)(short)local_18[0];
      unaff_ESI[0xe] = local_18[2] & 0xffffU;
      unaff_ESI[0x2c] = 0;
      unaff_ESI[0x2d] = 0;
      if ((char)unaff_ESI[0x10] == '\0') {
        *(undefined1 *)(unaff_ESI + 0x10) = 1;
        unaff_ESI[0xf] = local_18[2] & 0xffffU;
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


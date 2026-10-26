
void FUN_0049fe30(int *param_1)

{
  int iVar1;
  int *unaff_ESI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *param_1;
  if (unaff_ESI != (int *)0x0) {
    if (iVar1 != 0) {
      if (*(int **)(iVar1 + 8) != (int *)0x0) {
        (**(code **)(**(int **)(iVar1 + 8) + 0x24))();
      }
      *(undefined4 *)(iVar1 + 0xc) = 1;
    }
    *param_1 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    iVar1 = (**(code **)(*unaff_ESI + 0x10))(&local_14,1);
    if (iVar1 != 0) {
      unaff_ESI[0xd] = 0;
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *param_1 = iVar1;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


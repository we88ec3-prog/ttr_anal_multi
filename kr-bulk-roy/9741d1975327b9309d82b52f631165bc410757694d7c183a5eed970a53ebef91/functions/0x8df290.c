
void FUN_008df290(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int local_dc;
  int local_d4;
  int local_d0;
  undefined1 local_cc [196];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_d4 = 0;
  puVar1 = (undefined4 *)FUN_008df080();
  if (puVar1 != (undefined4 *)0x0) {
    local_d0 = *(int *)(*param_1 + 0x290);
    iVar2 = FUN_008baee0(*(undefined4 *)(*param_1 + 100),0x404,&local_d4);
    if (local_d4 != 0) goto LAB_008df3e4;
    FUN_008df110();
    local_d4 = (*(code *)*puVar1)(*(undefined4 *)(*param_1 + 100),local_cc,iVar2);
    if (local_d4 != 0) goto LAB_008df3e4;
    iVar3 = *(int *)(local_d0 + 0x768);
    if (iVar3 != 0) {
      local_dc = iVar2 + iVar3 * 4;
      local_d0 = local_d0 + 0x768 + iVar3 * 4;
      do {
        local_d4 = 0;
        FUN_008df110();
        local_d4 = (*(code *)*puVar1)(*(undefined4 *)(*param_1 + 100),local_cc,local_dc);
        if (local_d4 != 0) goto LAB_008df3e4;
        local_d0 = local_d0 + -4;
        local_dc = local_dc + -4;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    param_1[10] = iVar2;
  }
  param_1[0xb] = -1;
LAB_008df3e4:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


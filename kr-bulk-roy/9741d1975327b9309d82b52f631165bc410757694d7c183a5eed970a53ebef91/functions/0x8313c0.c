
void FUN_008313c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int in_EDX;
  int *unaff_ESI;
  int *unaff_EDI;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_28 = in_ECX + 1;
  local_2c = param_4;
  iVar2 = unaff_EDI[3];
  local_30 = param_1;
  local_24 = in_EDX;
  FUN_00835c70(&local_30);
  iVar3 = local_20;
  if (local_20 != *(int *)(iVar2 + 4)) {
    FUN_00835c70(&local_24);
    iVar2 = local_20;
    if ((local_20 != *(int *)(iVar3 + 0x14)) &&
       (piVar1 = (int *)(local_20 + 0x10), piVar1 != (int *)0x0)) {
      local_20 = local_28;
      local_28 = *piVar1;
      FUN_0052ced0(&local_28);
      if (local_24 != *(int *)(*unaff_EDI + 4)) {
        local_24 = local_24 + 0x10;
        FUN_0052ced0(&local_20);
        if ((local_28 != *(int *)(local_24 + 4)) && ((int *)(local_28 + 0x10) != (int *)0x0)) {
          *unaff_ESI = *(int *)(local_28 + 0x10);
          unaff_ESI[1] = *(int *)(local_28 + 0x14);
          unaff_ESI[2] = *(int *)(local_28 + 0x18);
          unaff_ESI[3] = *(int *)(local_28 + 0x1c);
          local_1c = 0;
          local_18 = 0;
          local_14 = 0;
          local_10 = 0;
          local_c = 0;
          unaff_ESI[4] = *(int *)(local_28 + 0x20);
          FUN_00836680(*(undefined4 *)(iVar2 + 0x1c),param_3,&local_1c,local_2c);
          *unaff_ESI = *unaff_ESI + local_1c;
          unaff_ESI[2] = unaff_ESI[2] + local_14;
          unaff_ESI[1] = unaff_ESI[1] + local_18;
          unaff_ESI[3] = unaff_ESI[3] + local_10;
          unaff_ESI[4] = unaff_ESI[4] + local_c;
          FUN_00834e80(*(undefined4 *)(iVar2 + 0x14),param_2,local_2c);
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


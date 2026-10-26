
void FUN_008d34d0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_ESI;
  undefined4 *puVar5;
  int local_3c;
  int local_38;
  int local_34 [3];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = unaff_ESI[2];
  piVar1 = (int *)(iVar2 + 0x20);
  local_38 = -1;
  iVar3 = FUN_008d3490(piVar1);
  if (iVar3 == 0) {
    if (*piVar1 != 0) {
      uVar4 = FUN_008bc7d0(*unaff_ESI,0x14,0,*piVar1,0,local_34);
      *(undefined4 *)(iVar2 + 0x1c) = uVar4;
      if (local_34[0] != 0) goto LAB_008d35f5;
    }
    iVar3 = FUN_008d1210(1,local_34);
    if (iVar3 != 0) {
      local_3c = -0x14;
LAB_008d3551:
      uVar4 = FUN_008d12a0();
      switch(uVar4) {
      case 0x14:
      case 0x15:
      case 0x17:
        *piVar1 = local_38 + 1;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      default:
        break;
      case 0x38:
        goto switchD_008d356e_caseD_38;
      case 0x4b:
        goto switchD_008d356e_caseD_4b;
      }
    }
  }
switchD_008d356e_caseD_16:
LAB_008d35f5:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
switchD_008d356e_caseD_38:
  local_3c = local_3c + 0x14;
  local_38 = local_38 + 1;
  if (*piVar1 <= local_38) goto switchD_008d356e_caseD_16;
  puVar5 = (undefined4 *)(*(int *)(iVar2 + 0x1c) + local_3c);
  local_34[1] = 3;
  local_28 = 2;
  local_20 = 2;
  local_18 = 2;
  local_10 = 2;
  iVar3 = FUN_008d3350();
  if (iVar3 != 5) goto switchD_008d356e_caseD_16;
  *puVar5 = local_34[2];
  puVar5[1] = local_24;
  puVar5[2] = local_1c;
  puVar5[3] = local_14;
  puVar5[4] = local_c;
switchD_008d356e_caseD_4b:
  iVar3 = FUN_008d1210(1,local_34);
  if (iVar3 == 0) goto switchD_008d356e_caseD_16;
  goto LAB_008d3551;
}


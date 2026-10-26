
void FUN_008d3670(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  undefined4 *puVar4;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
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
  iVar3 = unaff_ESI[2];
  local_34 = -1;
  local_2c = iVar3;
  iVar1 = FUN_008d3490((int *)(iVar3 + 0x28));
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar3 + 0x28);
    if (iVar1 != 0) {
      uVar2 = FUN_008bc7d0(*unaff_ESI,0x10,0,iVar1,0,&local_30);
      *(undefined4 *)(iVar3 + 0x24) = uVar2;
      if (local_30 != 0) goto LAB_008d37ad;
    }
    iVar3 = FUN_008d1210(1,&local_30);
    if (iVar3 != 0) {
      local_38 = -0x10;
LAB_008d36f0:
      iVar3 = FUN_008d12a0();
      switch(iVar3) {
      case 0x14:
      case 0x15:
      case 0x16:
        *(size_t *)(local_2c + 0x28) = local_34 + 1U;
        _qsort(*(void **)(local_2c + 0x24),local_34 + 1U,0x10,FUN_008e9b40);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      default:
        break;
      case 0x22:
      case 0x24:
      case 0x25:
        goto switchD_008d370f_caseD_22;
      case 0x4b:
        goto switchD_008d370f_caseD_4b;
      }
    }
  }
switchD_008d370f_caseD_17:
LAB_008d37ad:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
switchD_008d370f_caseD_22:
  local_38 = local_38 + 0x10;
  local_34 = local_34 + 1;
  if (*(int *)(local_2c + 0x28) <= local_34) goto switchD_008d370f_caseD_17;
  puVar4 = (undefined4 *)(*(int *)(local_2c + 0x24) + local_38);
  local_28 = 5;
  local_20 = 5;
  local_18 = 3;
  local_10 = 3;
  iVar1 = FUN_008d3350();
  if (iVar1 < 3) goto switchD_008d370f_caseD_17;
  *puVar4 = local_24;
  puVar4[1] = local_1c;
  if (iVar3 == 0x25) {
    puVar4[2] = 0;
    uVar2 = local_14;
  }
  else {
    puVar4[2] = local_14;
    if ((iVar3 != 0x22) || (uVar2 = local_c, iVar1 != 4)) {
      uVar2 = 0;
    }
  }
  puVar4[3] = uVar2;
switchD_008d370f_caseD_4b:
  iVar3 = FUN_008d1210(1,&local_30);
  if (iVar3 == 0) goto switchD_008d370f_caseD_17;
  goto LAB_008d36f0;
}


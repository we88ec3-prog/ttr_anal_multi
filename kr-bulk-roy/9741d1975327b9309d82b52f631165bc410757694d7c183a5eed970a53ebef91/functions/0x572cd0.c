
void FUN_00572cd0(int *param_1,undefined4 ****param_2)

{
  undefined1 *puVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  char *pcVar5;
  undefined1 **ppuVar6;
  int iVar7;
  undefined1 local_10c [16];
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 local_d8;
  char *local_d4;
  undefined4 ***pppuStack_d0;
  uint uStack_cc;
  undefined1 *local_8c;
  undefined1 *local_88;
  undefined4 ***local_84;
  int local_80;
  undefined4 local_7c;
  uint local_68;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b170;
  local_10 = ExceptionList;
  uStack_cc = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pppuStack_d0 = (undefined4 ***)0x0;
  local_d4 = (char *)0x0;
  local_d8 = 0;
  uStack_dc = 0;
  uStack_e0 = 0;
  local_84 = param_2;
  local_88 = local_10c;
  local_f0 = 0;
  local_ec = 0;
  local_e8 = 0;
  local_f8 = 0xf;
  local_fc = 0;
  local_e4 = 0;
  local_10c[0] = 0;
  local_14 = uStack_cc;
  FUN_00402a70(&DAT_00bf2375,0);
  FUN_005750f0();
  local_8 = 0;
  pppuStack_d0 = (undefined4 ***)0x572d68;
  FUN_00572f70();
  local_8 = 0xffffffff;
  if (0xf < local_68) {
    pppuStack_d0 = (undefined4 ***)local_7c;
    local_d4 = (char *)0x572d82;
    FUN_0089120c();
  }
  pppuStack_d0 = local_84;
  local_d4 = (char *)0x572d97;
  FUN_00542210();
  local_d4 = (char *)0x572da4;
  piVar3 = (int *)FUN_0050b4b0();
  iVar7 = 0;
  if ((int *)*piVar3 != (int *)0x0) {
    iVar7 = *(int *)*piVar3;
  }
  uVar4 = piVar3[2];
  if (*(uint *)(iVar7 + 8) <= uVar4) {
    uVar4 = uVar4 - *(uint *)(iVar7 + 8);
  }
  pppuStack_d0 = *(undefined4 ****)(*(int *)(iVar7 + 4) + uVar4 * 4);
  if (0xf < *(uint *)((int)pppuStack_d0 + 0x14)) {
    pppuStack_d0 = (undefined4 ***)*pppuStack_d0;
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  pcVar5 = (char *)pppuStack_d0;
  do {
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  local_d4 = (char *)0x572df3;
  FUN_0040b310();
  local_8 = 1;
  iVar7 = *param_1;
  pppuStack_d0 = local_30;
  local_d4 = (char *)0x572e07;
  local_8c = (undefined1 *)FUN_006cf160();
  if (local_8c != *(undefined1 **)(iVar7 + 4)) {
    pppuStack_d0 = (undefined4 ****)0x572e1d;
    cVar2 = FUN_005436a0();
    if (cVar2 == '\0') {
      ppuVar6 = &local_8c;
      goto LAB_00572e38;
    }
  }
  local_88 = *(undefined1 **)(iVar7 + 4);
  ppuVar6 = &local_88;
LAB_00572e38:
  puVar1 = *ppuVar6;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    pppuStack_d0 = local_30[0];
    local_d4 = (char *)0x572e50;
    FUN_0089120c();
  }
  iVar7 = local_80;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  if (puVar1 != *(undefined1 **)(*param_1 + 4)) {
    pppuStack_d0 = (undefined4 ***)0x572e77;
    FUN_00572aa0();
    if (*(int *)(iVar7 + 0x34) == 6) {
      pppuStack_d0 = (undefined4 ***)0x572e88;
      local_d4 = (char *)FUN_00573fc0();
      if (0xf < *(uint *)(local_d4 + 0x14)) {
        local_d4 = *(char **)local_d4;
      }
      pcVar5 = local_d4;
      do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      pppuStack_d0 = (undefined4 ***)((int)pcVar5 - (int)(local_d4 + 1));
      local_d8 = 0x572eb2;
      FUN_00402a70();
    }
    pppuStack_d0 = local_84;
    local_d4 = (char *)0x572ec6;
    FUN_00542210();
    local_d4 = (char *)0x572ed3;
    piVar3 = (int *)FUN_0050b4b0();
    if ((int *)*piVar3 == (int *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)*piVar3;
    }
    uVar4 = (uint)piVar3[2] >> 1;
    if (*(uint *)(iVar7 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar7 + 8);
    }
    pppuStack_d0 = local_84;
    *(undefined4 *)(local_80 + 0x3c) =
         *(undefined4 *)(*(int *)(*(int *)(iVar7 + 4) + uVar4 * 4) + (piVar3[2] & 1U) * 8);
    local_d4 = (char *)0x572f12;
    FUN_00542210();
    local_d4 = (char *)0x572f1f;
    piVar3 = (int *)FUN_0050b4b0();
    if ((int *)*piVar3 == (int *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)*piVar3;
    }
    uVar4 = (uint)piVar3[2] >> 1;
    if (*(uint *)(iVar7 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(iVar7 + 8);
    }
    *(undefined4 *)(local_80 + 0x40) =
         *(undefined4 *)(*(int *)(*(int *)(iVar7 + 4) + uVar4 * 4) + 4 + (piVar3[2] & 1U) * 8);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


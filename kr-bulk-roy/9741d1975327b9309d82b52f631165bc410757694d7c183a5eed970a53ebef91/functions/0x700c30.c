
void FUN_00700c30(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  char *local_70;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  if (((puVar2 < *(undefined4 **)(param_1 + 8)) && (puVar2 != &DAT_00c0bfc8)) && (puVar2[2] == 8)) {
    iVar8 = 1;
  }
  else {
    iVar8 = 0;
  }
  puVar2 = (undefined4 *)FUN_006f50f0();
  if ((puVar2 == &DAT_00c0bfc8) || ((int)puVar2[2] < 1)) {
    local_70 = "flnSu";
  }
  else {
    local_70 = (char *)FUN_006f6210(param_1);
  }
  iVar3 = FUN_006f50f0();
  if ((*(int *)(iVar3 + 8) == 3) ||
     ((*(int *)(iVar3 + 8) == 4 && (iVar3 = FUN_006f7760(), iVar3 != 0)))) {
    FUN_006f5370();
    iVar3 = FUN_006f7dd0();
    if (iVar3 == 0) {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else {
    puVar2 = (undefined4 *)FUN_006f50f0();
    iVar3 = iVar8 + 1;
    if ((puVar2 == &DAT_00c0bfc8) || (puVar2[2] != 6)) goto LAB_00700f5c;
    FUN_006f5580(param_1,&DAT_00c42f34,local_70);
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(iVar3 + -8) == 4) {
LAB_00700d97:
      local_70 = (char *)(*(int *)(iVar3 + -0x10) + 0x10);
    }
    else {
      iVar3 = FUN_006fb5d0();
      if (iVar3 != 0) {
        if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)
           ) {
          FUN_006fb3a0();
        }
        iVar3 = *(int *)(param_1 + 8);
        goto LAB_00700d97;
      }
      local_70 = (char *)0x0;
    }
    puVar4 = (undefined4 *)FUN_006f50f0();
    puVar2 = *(undefined4 **)(param_1 + 8);
    *puVar2 = *puVar4;
    puVar2[1] = puVar4[1];
    puVar2[2] = puVar4[2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006f51d0();
  }
  iVar5 = FUN_006f8180(local_70);
  iVar3 = iVar8 + 2;
  if (iVar5 != 0) {
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    puVar2 = *(undefined4 **)(param_1 + 8);
    uVar6 = FUN_006f99a0(param_1,0,2);
    *puVar2 = uVar6;
    puVar2[2] = 5;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    pcVar7 = _strchr(local_70,0x53);
    if (pcVar7 != (char *)0x0) {
      FUN_00700b00("source");
      FUN_00700b00("short_src");
      FUN_00709600(local_50);
      FUN_00709600(local_4c);
      FUN_00700b00(&DAT_00c42f8c);
    }
    pcVar7 = _strchr(local_70,0x6c);
    if (pcVar7 != (char *)0x0) {
      FUN_00709600(local_58);
    }
    pcVar7 = _strchr(local_70,0x75);
    if (pcVar7 != (char *)0x0) {
      FUN_00709600(local_54);
    }
    pcVar7 = _strchr(local_70,0x6e);
    if (pcVar7 != (char *)0x0) {
      FUN_00700b00(&DAT_00bed1d4);
      FUN_00700b00("namewhat");
    }
    pcVar7 = _strchr(local_70,0x4c);
    if (pcVar7 != (char *)0x0) {
      FUN_00700b70("activelines");
    }
    pcVar7 = _strchr(local_70,0x66);
    if (pcVar7 != (char *)0x0) {
      FUN_00700b70(&DAT_00c42fc0);
    }
    __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_00700f5c:
  FUN_006f5da0(iVar3);
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


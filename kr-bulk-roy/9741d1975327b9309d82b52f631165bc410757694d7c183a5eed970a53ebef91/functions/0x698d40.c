
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00698d40(void)

{
  undefined1 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *in_ECX;
  uint uVar7;
  undefined1 uVar8;
  int iVar9;
  undefined2 local_1018;
  int local_1010;
  undefined4 local_100c;
  undefined2 uStack_1008;
  undefined1 local_1006 [4090];
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar7 = 2;
  local_c = 2;
  if (*(int *)(in_ECX[0x3d] + 0xcc) == 0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = (undefined4 *)(*(int *)(in_ECX[0x3d] + 0xcc) + 0xa8);
  }
  piVar6 = (int *)*puVar4;
  piVar2 = (int *)puVar4[1];
  local_1010 = 0;
  do {
    if (piVar6 == piVar2) {
      local_100c._0_2_ = 0xac;
      if (2 < uVar7) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_100c,uVar7);
      }
      (**(code **)(*in_ECX + 0x90))(0);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_100c._0_2_ = 0xac;
    iVar5 = *piVar6;
    iVar9 = *(int *)(*(int *)(iVar5 + 0x24c) + 0x24c);
    puVar4 = *(undefined4 **)(iVar5 + 0x25c);
    if (iVar9 == 0) {
LAB_00698dfb:
      iVar9 = -1;
    }
    else {
      iVar9 = *(int *)(iVar9 + 0xcc);
      if (iVar9 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = *(int *)(iVar9 + 0xdc);
      }
      if (iVar9 == 0) goto LAB_00698dfb;
      iVar9 = *(int *)(iVar9 + 0x20);
    }
    iVar5 = *(int *)(*(int *)(iVar5 + 0x250) + 0x24c);
    if (iVar5 == 0) {
LAB_00698e2b:
      iVar5 = -1;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0xcc);
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(iVar5 + 0xdc);
      }
      if (iVar5 == 0) goto LAB_00698e2b;
      iVar5 = *(int *)(iVar5 + 0x20);
    }
    uVar3 = *puVar4;
    puVar1 = (undefined1 *)(puVar4[0x15] + iVar5 * 0xc);
    local_1018 = CONCAT11(puVar1[4],*puVar1);
    if (iVar9 == -1) {
      uVar8 = 0;
    }
    else {
      uVar8 = *(undefined1 *)(puVar4[0x19] + iVar9 * 0x18);
    }
    if (8 < local_1010) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_100c,uVar7);
      uVar7 = 2;
      local_c = 2;
      local_1010 = 0;
    }
    if (uVar7 + 7 < 0x1001) {
      *(undefined4 *)((int)&local_100c + uVar7) = uVar3;
      *(undefined2 *)((int)&uStack_1008 + uVar7) = local_1018;
      local_1006[uVar7] = uVar8;
      uVar7 = local_c + 7;
      local_c = uVar7;
    }
    local_1010 = local_1010 + 1;
    piVar6 = piVar6 + 1;
  } while( true );
}


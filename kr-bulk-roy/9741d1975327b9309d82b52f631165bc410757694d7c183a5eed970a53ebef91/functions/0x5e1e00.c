
void FUN_005e1e00(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_e0;
  int local_dc;
  undefined4 local_d8 [5];
  uint local_c4;
  undefined1 local_bc [28];
  undefined1 local_a0 [28];
  undefined1 local_84 [28];
  undefined1 local_68 [28];
  undefined1 local_4c [28];
  undefined4 local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091a891;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == 0xf) {
    uVar2 = FUN_005e92c0(local_d8,L"<#CCCCCC>");
    local_8 = 0;
    FUN_00402800(uVar2);
    local_30[0] = local_d8[0];
    local_1c = local_c4;
joined_r0x005e2018:
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  else {
    switch(param_2) {
    case 0:
      uVar2 = 0x1bc;
      FUN_00585620(0x1bc);
      uVar2 = FUN_00585330(uVar2);
      uVar2 = FUN_005e92c0(local_84,uVar2);
      local_8 = 1;
      FUN_00402800(uVar2);
      FUN_004fa440();
      break;
    case 1:
      uVar2 = 0x1c4;
      FUN_00585620(0x1c4);
      uVar2 = FUN_00585330(uVar2);
      uVar2 = FUN_005e92c0(local_4c,uVar2);
      local_8 = 2;
      FUN_00402800(uVar2);
      FUN_004fa440();
      break;
    case 2:
      uVar2 = 0x1bd;
      FUN_00585620(0x1bd);
      uVar2 = FUN_00585330(uVar2);
      uVar2 = FUN_005e92c0(local_68,uVar2);
      local_8 = 3;
      FUN_00402800(uVar2);
      FUN_004fa440();
      break;
    case 3:
      uVar2 = 0x1be;
      FUN_00585620(0x1be);
      uVar2 = FUN_00585330(uVar2);
      uVar2 = FUN_005e92c0(local_a0,uVar2);
      local_8 = 4;
      FUN_00402800(uVar2);
      FUN_004fa440();
      break;
    case 4:
      uVar2 = 0x1bf;
      FUN_00585620(0x1bf);
      uVar2 = FUN_00585330(uVar2);
      uVar2 = FUN_005e92c0(local_bc,uVar2);
      local_8 = 5;
      FUN_00402800(uVar2);
      FUN_004fa440();
      break;
    default:
      local_e0 = 0x1c0;
      iVar3 = FUN_00585620(local_14);
      FUN_005740f0(&local_e0);
      if (local_dc == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar4 = (undefined4 *)(local_dc + 0x10);
      if (7 < *(uint *)(local_dc + 0x24)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      uVar2 = FUN_005e92c0(local_30,puVar4);
      local_8 = 6;
      FUN_00402800(uVar2);
      goto joined_r0x005e2018;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}



void FUN_00601130(undefined *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined1 *in_EDX;
  int iVar5;
  undefined1 auStack_9c [20];
  undefined4 uStack_88;
  undefined2 *puStack_84;
  undefined1 auStack_80 [16];
  undefined4 uStack_70;
  undefined *puStack_6c;
  int iStack_68;
  int iStack_64;
  undefined1 *local_4c;
  undefined1 *local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00946dbc;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_4c;
  ExceptionList = &local_14;
  local_48 = in_EDX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    iStack_64 = 0x60119d;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_2 != 1) || (DAT_00f94300 + 0x16f8 == 0)) {
    iStack_64 = param_2;
    puStack_6c = &DAT_00c25e00;
    uStack_70 = 0x6011d5;
    FUN_006edb60();
    goto switchD_006012b7_caseD_1;
  }
  if ((undefined1 *)0x63 < in_EDX + -1) {
    iStack_64 = 0x60121f;
    FUN_006edb60();
LAB_00601200:
    iStack_64 = param_2;
    puStack_6c = &DAT_00c25e2c;
    uStack_70 = 0x60120d;
    FUN_006edb60();
    goto switchD_006012b7_caseD_1;
  }
  iVar5 = (int)in_EDX * 0x20 + DAT_00f94300 + 0x16f8;
  if (((*(int *)(iVar5 + 0xc) == 0) || (*(int *)(iVar5 + 8) == 0)) || (iVar5 == 0))
  goto LAB_00601200;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 1;
    FUN_0051c120();
    iStack_64 = 0x60124b;
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_3c = *(undefined4 *)(iVar5 + 0xc);
  iStack_64 = 0x601270;
  FUN_008438c0();
  if (((local_40 == DAT_00f8d91c) || (*(int *)(local_40 + 0x10) == 0)) ||
     (iVar1 = *(int *)(*(int *)(local_40 + 0x10) + 0x54), iVar1 == 0))
  goto switchD_006012b7_caseD_1;
  iStack_64 = *(int *)(iVar5 + 0x10);
  iStack_68 = *(int *)(iVar5 + 0xc);
  puStack_6c = param_1;
  uStack_70 = 0x6012ab;
  uVar2 = FUN_005e06b0();
  switch(uVar2) {
  case 0:
    if ((*(int *)(iVar1 + 8) - 1U < 0x2b) && (iVar5 = FUN_00520f40(), iVar5 != 0)) {
      FUN_0040b3c0();
      local_c = 5;
      FUN_0040b3f0();
      iStack_64 = 0x60141c;
      piVar3 = (int *)FUN_0080ab00();
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x14))();
      }
      local_c = 0xffffffff;
      FUN_007cf450();
      FUN_00414680();
      iStack_64 = param_2;
      puStack_6c = param_1;
      uStack_70 = 0x60144f;
      iStack_68 = iVar5;
      FUN_004a3840();
      iStack_64 = 0x601456;
      puVar4 = (undefined4 *)FUN_00891268();
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf42ac;
        *puVar4 = FoxUI::FXUIEventI1::vftable;
        puVar4[5] = local_44;
      }
      FUN_004072a0();
    }
    break;
  case 5:
    FUN_004054c0();
    iStack_64 = 0;
    local_48 = auStack_80;
    puStack_84 = &DAT_00bed1fc;
    uStack_88 = 0x601344;
    FUN_00402250();
    local_4c = auStack_9c;
    uVar2 = 0xf8;
    local_c = 3;
    FUN_005854b0(0xf8);
    FUN_00585330(uVar2);
    FUN_004068f0();
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
    break;
  case 6:
    FUN_004054c0();
    iStack_64 = 0;
    local_48 = auStack_80;
    puStack_84 = &DAT_00bed1fc;
    uStack_88 = 0x6012da;
    FUN_00402250();
    local_4c = auStack_9c;
    uVar2 = 0xf7;
    local_c = 2;
    FUN_005854b0(0xf7);
    FUN_00585330(uVar2);
    FUN_004068f0();
    goto LAB_0060130b;
  case 8:
    FUN_004054c0();
    iStack_64 = 0;
    local_48 = auStack_80;
    puStack_84 = &DAT_00bed1fc;
    uStack_88 = 0x6013ae;
    FUN_00402250();
    puStack_84 = (undefined2 *)0xff;
    local_c = 4;
    uStack_88 = 0x6013c0;
    FUN_005854b0();
    uStack_88 = 0x6013c7;
    uVar2 = FUN_00585330();
    local_4c = auStack_9c;
    FUN_00402250(uVar2);
LAB_0060130b:
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
  }
switchD_006012b7_caseD_1:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_4c);
  return;
}


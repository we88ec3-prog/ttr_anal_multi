
void FUN_004098a0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *local_ac;
  uint uStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  undefined1 auStack_8c [56];
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009421e2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_ac;
  ExceptionList = &local_14;
  iVar1 = param_1[4];
  if (iVar1 == 0x578) {
    if (param_1[2] == *(int *)(in_ECX[0x3e] + 0x20)) {
      FUN_0040a3c0(DAT_00d61f20 ^ (uint)&stack0xffffff48);
    }
  }
  else if (iVar1 == 0xf442d) {
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    if (param_1[5] == 0x6a7) {
      (**(code **)(*in_ECX + 0x16c))(0);
      FUN_0040a0d0();
    }
  }
  else if (iVar1 == 0xf442e) {
    local_ac = in_ECX;
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    if (param_1[5] == 0x6a7) {
      FUN_0040afc0();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      puVar3 = (undefined4 *)0x0;
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[3] = 0;
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[4] = 0xf442d;
        puVar3 = puVar2;
      }
      uVar4 = 0x196;
      FUN_005854b0(0x196);
      uVar4 = FUN_00585330(uVar4);
      FUN_007572f0(uVar4);
      uVar4 = 0x1db;
      uStack_c = 0;
      FUN_005854b0(0x1db);
      FUN_00585330(uVar4);
      uVar4 = FUN_004068f0();
      uStack_c._0_1_ = 1;
      FUN_007574a0(uVar4);
      uStack_c._0_1_ = 2;
      FUN_00407330(0xcf,auStack_8c,auStack_54,puVar3,local_ac);
      uStack_c = CONCAT31(uStack_c._1_3_,1);
      FUN_00757640(auStack_8c);
      if (7 < uStack_94) {
        FUN_0089120c(uStack_a8);
      }
      uStack_94 = 7;
      uStack_98 = 0;
      uStack_a8 = uStack_a8 & 0xffff0000;
      uStack_c = 0xffffffff;
      FUN_00757640(auStack_54);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_ac);
  return;
}


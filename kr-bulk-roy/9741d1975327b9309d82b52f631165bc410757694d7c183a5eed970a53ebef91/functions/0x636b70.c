
void FUN_00636b70(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  undefined4 uVar5;
  undefined4 *local_90;
  undefined1 local_8c [56];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00948997;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_90;
  ExceptionList = &local_14;
  if (*(uint *)(unaff_EDI + 0xac) < 2) {
    iVar1 = *(int *)(unaff_EDI + 0x90);
    if (iVar1 == 0) {
      FUN_00636d20();
    }
    else if (iVar1 == 1) {
      puVar2 = (undefined4 *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xffffff68);
      puVar4 = (undefined4 *)0x0;
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[3] = 0;
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[4] = 0xf4402;
        puVar4 = puVar2;
      }
      FUN_007574a0(*(int *)(unaff_EDI + 0x88) + 0x4c);
      uVar5 = 0x1f;
      local_c = 0;
      FUN_005854b0(0x1f);
      uVar5 = FUN_00585330(uVar5);
      FUN_007572f0(uVar5);
      local_c._0_1_ = 1;
      FUN_00407330(0xcf,local_8c,local_54,puVar4);
      local_c = (uint)local_c._1_3_ << 8;
      FUN_00757640(local_8c);
      local_c = 0xffffffff;
      FUN_00757640(local_54);
    }
    else if ((iVar1 == 3) && (*(undefined4 **)(unaff_EDI + 0x88) != (undefined4 *)0x0)) {
      uVar5 = **(undefined4 **)(unaff_EDI + 0x88);
      FUN_0040f930();
      uVar3 = FUN_005007d0(uVar5);
      if ((uVar3 & 0xffff) != 0) {
        local_90 = (undefined4 *)FUN_00891268(0x18);
        if (local_90 == (undefined4 *)0x0) {
          local_90 = (undefined4 *)0x0;
        }
        else {
          local_90[1] = 0xffffffff;
          local_90[2] = 0xffffffff;
          local_90[3] = 0;
          local_90[4] = 0xf438a;
          *local_90 = FoxUI::FXUIEventI1::vftable;
          local_90[5] = uVar3 & 0xffff;
        }
        FUN_00404aa0();
        FUN_00804260(&local_90);
      }
    }
  }
  else {
    FUN_00636d60();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_90);
  return;
}


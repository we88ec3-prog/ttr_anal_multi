
void FUN_0045b4c0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 local_d4;
  undefined1 local_d0 [24];
  undefined4 local_b8;
  uint local_a4;
  undefined1 local_78 [20];
  undefined4 local_64;
  undefined4 uStack_60;
  uint uStack_4c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = -1;
  puStack_10 = &LAB_00945153;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_d4;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff20;
  ExceptionList = &local_14;
  local_d4 = in_EDX;
  cVar3 = FUN_0045b110(in_ECX);
  if (cVar3 != '\0') {
    FUN_0045b670(local_78,in_ECX);
    local_c = 0;
    FUN_0045a6a0(*(undefined4 *)(param_1 + 0x108),local_64);
    puVar5 = (undefined4 *)FUN_00891268(0x1c,uVar4);
    if (puVar5 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x2a4);
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x2a0);
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf4369;
      *puVar5 = FoxUI::FXUIEventI2::vftable;
      puVar5[5] = uVar2;
      puVar5[6] = uVar1;
    }
    FUN_004072a0();
    puVar5 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf4368;
      *puVar5 = FoxUI::FXUIEventI2::vftable;
      puVar5[5] = in_ECX;
      puVar5[6] = local_d4;
    }
    FUN_004072a0();
    FUN_0045b670(local_d0,in_ECX);
    local_c._0_1_ = 1;
    FUN_0045d560();
    local_c = (uint)local_c._1_3_ << 8;
    if (7 < local_a4) {
      FUN_0089120c(local_b8);
    }
    FUN_0045b380();
    if (7 < uStack_4c) {
      FUN_0089120c(uStack_60);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_d4);
  return;
}


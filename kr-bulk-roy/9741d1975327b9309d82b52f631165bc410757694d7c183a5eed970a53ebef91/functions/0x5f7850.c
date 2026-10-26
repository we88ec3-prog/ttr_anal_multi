
void FUN_005f7850(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *in_ECX;
  undefined1 auStack_4c [4];
  int iStack_48;
  int iStack_44;
  int *local_40;
  undefined4 *puStack_3c;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ee66;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_4c;
  ExceptionList = &local_14;
  local_40 = in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f94300 != -0x23a0) {
    iVar3 = *(int *)(DAT_00f94300 + 0x50b8);
    iVar2 = (**(code **)(*local_40 + 0x1ac))();
    if (iVar2 + iVar3 < 0x1e1) {
      puStack_3c = (undefined4 *)FUN_00891268(0x14);
      if (puStack_3c == (undefined4 *)0x0) {
        puStack_3c = (undefined4 *)0x0;
      }
      else {
        *puStack_3c = FoxUI::FXUIEvent::vftable;
        puStack_3c[1] = 0xffffffff;
        puStack_3c[2] = 0xffffffff;
        puStack_3c[3] = 0;
        puStack_3c[4] = 0xf43a3;
      }
      iStack_48 = 0x1c6;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&iStack_48);
      if (iStack_44 == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar4 = (undefined4 *)FUN_005f9080();
      local_c = 1;
      iStack_44 = 0x196;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&iStack_44);
      if (iStack_48 == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar5 = (undefined4 *)(iStack_48 + 0x10);
      if (7 < *(uint *)(iStack_48 + 0x24)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      if (7 < (uint)puVar4[5]) {
        puVar4 = (undefined4 *)*puVar4;
      }
      FUN_00404b10(0xcf,puVar4,puVar5,puStack_3c,local_40);
      if (7 < uStack_24) {
        FUN_0089120c(uStack_38);
      }
    }
    else {
      iStack_44 = 0x1c7;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&iStack_44);
      if (iStack_48 == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar4 = (undefined4 *)(iStack_48 + 0x10);
      if (7 < *(uint *)(iStack_48 + 0x24)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      FUN_00404b10(0xca,puVar4,&DAT_00bed1fc,0,0);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_4c);
  return;
}


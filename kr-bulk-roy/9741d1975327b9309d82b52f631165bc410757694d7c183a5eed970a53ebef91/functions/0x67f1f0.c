
/* WARNING: Removing unreachable block (ram,0x0067f2d4) */

void FUN_0067f1f0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00932cf8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar5 = param_1 * 0x58 + in_ECX;
  if ((*(int *)(iVar5 + 0x178) != -1) && (*(int *)(iVar5 + 0x17c) != -1)) {
    puVar4 = (undefined4 *)FUN_00891268(0x1c,uVar3);
    if (puVar4 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(iVar5 + 0x174);
      uVar2 = *(undefined4 *)(iVar5 + 0x170);
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4369;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = uVar2;
      puVar4[6] = uVar1;
    }
    FUN_004072a0();
    local_8 = 0;
    FUN_0045d560();
  }
  local_8 = 0xffffffff;
  FUN_0067f310();
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad270(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  undefined4 *local_24;
  int iStack_20;
  int aiStack_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f9392c != 9) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_24 = (undefined4 *)0x31;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_24,4);
    }
    ExceptionList = local_14;
    return;
  }
  if (in_ECX != (int *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 4))();
    if (iVar2 == 0x105c4) goto LAB_005ad306;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_005ad306:
  if ((char)in_ECX[5] == '\0') {
    FUN_00596e00(param_1,*(undefined4 *)(param_1 + 0x23c));
    ExceptionList = local_14;
    return;
  }
  local_24 = (undefined4 *)FUN_00891268(0x14);
  if (local_24 == (undefined4 *)0x0) {
    local_24 = (undefined4 *)0x0;
  }
  else {
    *local_24 = FoxUI::FXUIEvent::vftable;
    local_24[1] = 0xffffffff;
    local_24[2] = 0xffffffff;
    local_24[3] = 0;
    local_24[4] = 0xf43a1;
  }
  iStack_20 = 0x196;
  iVar2 = FUN_005854b0();
  FUN_005740f0(&iStack_20);
  if (aiStack_1c[0] == *(int *)(iVar2 + 4)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(uint *)(aiStack_1c[0] + 0x24) < 8) {
    iVar2 = aiStack_1c[0] + 0x10;
  }
  else {
    iVar2 = *(int *)(aiStack_1c[0] + 0x10);
  }
  aiStack_1c[0] = 0x1c0;
  iVar3 = FUN_005854b0();
  FUN_005740f0(aiStack_1c);
  if (iStack_20 == *(int *)(iVar3 + 4)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar4 = (undefined4 *)(iStack_20 + 0x10);
  if (7 < *(uint *)(iStack_20 + 0x24)) {
    puVar4 = (undefined4 *)*puVar4;
  }
  FUN_00404b10(0xd0,puVar4,iVar2,local_24,param_1);
  ExceptionList = local_14;
  return;
}


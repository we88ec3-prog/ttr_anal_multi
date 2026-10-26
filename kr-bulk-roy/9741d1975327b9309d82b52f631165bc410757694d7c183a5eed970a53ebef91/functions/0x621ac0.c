
void FUN_00621ac0(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  int *in_EDX;
  uint local_34;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922b32;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_EDX != (int *)0x0) {
    iVar3 = (**(code **)(*in_EDX + 4))(uVar2);
    if (iVar3 == 0x105bd) goto LAB_00621b19;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EDX = (int *)0x0;
LAB_00621b19:
  if (in_EDX[5] == 0x6a7) {
    local_34 = *(uint *)(*(int *)(in_ECX + 0x11c) + 0xc4);
    if (((int)local_34 < 1) || ((int)local_34 < 0x28)) {
      local_34 = local_34 & ((int)local_34 < 1) - 1;
    }
    else {
      local_34 = 0x28;
    }
    if ((DAT_00faaf7c & 1) == 0) {
      DAT_00faaf7c = DAT_00faaf7c | 1;
      local_8 = 0;
      FUN_0058d410();
      _atexit((_func_4879 *)&LAB_00bccdc0);
      local_8 = 0xffffffff;
    }
    puVar4 = (undefined4 *)FUN_0040ef80();
    local_8 = 1;
    if (7 < (uint)puVar4[5]) {
      puVar4 = (undefined4 *)*puVar4;
    }
    FUN_0058cd50(&DAT_00faaf84,puVar4);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 2;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8 = 0xffffffff;
    }
    if (DAT_00fb92fd == '\0') {
      puVar4 = (undefined4 *)FUN_00891268(0x18);
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf42b2;
        *puVar4 = FoxUI::FXUIEventB1::vftable;
        *(undefined1 *)(puVar4 + 5) = 0;
      }
    }
    else {
      puVar4 = (undefined4 *)FUN_00891268(0x18);
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf42b2;
        *puVar4 = FoxUI::FXUIEventB1::vftable;
        *(undefined1 *)(puVar4 + 5) = 1;
      }
    }
    FUN_004072a0();
    fVar1 = (float)(int)local_34 * 0.01 + 0.85;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 3;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_00589a20(fVar1,fVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}


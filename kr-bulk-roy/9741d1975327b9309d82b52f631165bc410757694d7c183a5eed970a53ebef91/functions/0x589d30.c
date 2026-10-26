
void FUN_00589d30(void)

{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 in_ECX;
  int in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091dbea;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_8 = 0xffffffff;
  if (DAT_00f95bd4 != 0) {
    FUN_00746b30();
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 1;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  FUN_005c6f00(in_ECX);
  FUN_005cb110(*(undefined4 *)(in_EDX + 0x38));
  (**(code **)(**(int **)(in_EDX + 0x30) + 0x1c))();
  puVar3 = (undefined4 *)FUN_00891268(0x28);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *(undefined1 *)(puVar3 + 1) = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    *puVar3 = Graphics::CImageSprite::vftable;
  }
  uVar1 = DAT_00fcde40 & 1;
  *(undefined4 **)(in_EDX + 0x154) = puVar3;
  if (uVar1 == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 2;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    local_8 = 0xffffffff;
  }
  cVar2 = FUN_007383e0("UI/Data/IMECandidate.eif");
  if (cVar2 == '\0') {
    FUN_006edb60(&DAT_00c10200);
  }
  ExceptionList = local_10;
  return;
}


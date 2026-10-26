
void FUN_0062f050(uint param_1)

{
  code *pcVar1;
  uint uVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar2 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093335c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 < (uint)(*(int *)(in_ECX + 0x118) - *(int *)(in_ECX + 0x114) >> 2)) {
    if ((*(uint *)(*(int *)(in_ECX + 0x124) + 0x28) >> 8 & 1) != 0) {
      cVar3 = FUN_00632cd0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      if (cVar3 != '\0') {
        FUN_00632ca0();
        iVar5 = *(int *)(in_ECX + 0x114);
        FUN_00414680();
        FUN_004a3960(**(undefined4 **)(iVar5 + uVar2 * 4));
        ExceptionList = local_10;
        return;
      }
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    param_1 = 0x196;
    FUN_005740f0(&param_1);
    if (in_ECX == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(in_ECX + 0x24) < 8) {
      iVar5 = in_ECX + 0x10;
    }
    else {
      iVar5 = *(int *)(in_ECX + 0x10);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    param_1 = 0x1c;
    FUN_005740f0(&param_1);
    if (in_ECX == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar4 = (undefined4 *)(in_ECX + 0x10);
    if (7 < *(uint *)(in_ECX + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    FUN_00404b10(0xca,puVar4,iVar5,0,0);
  }
  ExceptionList = local_10;
  return;
}



/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547960(void)

{
  int iVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092313c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = *(int *)(unaff_ESI + 0xb4);
  if (iVar1 == 0) {
    *(undefined4 *)(unaff_ESI + 0xb4) = 1;
  }
  else if (iVar1 == 1) {
    *(undefined4 *)(unaff_ESI + 0xb4) = 2;
  }
  else {
    if (iVar1 != 2) {
      FUN_006edb60("TransFormation: Invalid message %d",iVar1,DAT_00d61f20 ^ (uint)&stack0xfffffffc)
      ;
    }
    *(undefined4 *)(unaff_ESI + 0xb4) = 0;
  }
  if ((DAT_00fb7a20 & 1) == 0) {
    DAT_00fb7a20 = DAT_00fb7a20 | 1;
    local_8 = 0;
    FUN_00548da0();
    _atexit(FUN_00bcd370);
    local_8 = 0xffffffff;
  }
  _DAT_00fb7a94 = *(undefined4 *)(unaff_ESI + 0xb4);
  _DAT_00fb7a2c = 0;
  _DAT_00fb7a30 = 0;
  _DAT_00fb7a34 = 0;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058ab80(0xf4401,*(undefined4 *)(unaff_ESI + 0xb4));
  ExceptionList = local_10;
  return;
}


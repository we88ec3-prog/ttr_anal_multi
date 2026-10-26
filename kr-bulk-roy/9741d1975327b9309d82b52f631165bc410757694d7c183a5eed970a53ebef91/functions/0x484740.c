
void FUN_00484740(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00944f36;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)(in_ECX + 0xf8);
  if (*(char *)(iVar1 + 0x141) != '\0') {
    FUN_006edb10();
  }
  if (*(int *)(iVar1 + 0x118) != 0) {
    iVar1 = *(int *)(in_ECX + 0xf4);
    if (*(char *)(iVar1 + 0x141) != '\0') {
      FUN_006edb10();
    }
    if (*(int *)(iVar1 + 0x118) != 0) {
      iVar1 = *(int *)(in_ECX + 0xfc);
      if (*(char *)(iVar1 + 0x141) != '\0') {
        FUN_006edb10();
      }
      if (*(int *)(iVar1 + 0x118) != 0) {
        iVar1 = *(int *)(in_ECX + 0x100);
        if (*(char *)(iVar1 + 0x141) != '\0') {
          FUN_006edb10();
        }
        if (*(int *)(iVar1 + 0x118) != 0) {
          FUN_00761500();
          FUN_00761500();
          cVar2 = FUN_0044dd20();
          if (cVar2 != '\0') {
            FUN_006ee1f0();
            FUN_00761520();
            FUN_00761520();
            FUN_0044d680();
            FUN_006d66b0();
          }
          goto LAB_004848fc;
        }
      }
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_00402160();
  local_8 = 1;
  FUN_00402160(&DAT_00bfc77c,0xf);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
LAB_004848fc:
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}


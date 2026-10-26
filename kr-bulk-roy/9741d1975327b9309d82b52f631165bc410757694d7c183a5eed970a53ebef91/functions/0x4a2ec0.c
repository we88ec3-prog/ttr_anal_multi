
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_004a2ec0(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char *in_ECX;
  undefined4 uVar4;
  undefined1 auStack_c0c0 [4];
  undefined1 local_c0bc [28];
  undefined1 auStack_c0a0 [49284];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093a938;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_c0c0;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffff3f38;
  ExceptionList = &local_14;
  SetUnhandledExceptionFilter(FUN_0044c6e0);
  FUN_008932ca(&LAB_0044c9a0,uVar1);
  FUN_00891fdc(&LAB_0044c9c0);
  _setlocale(0,"kEnglish");
  CoInitialize((LPVOID)0x0);
  if (in_ECX != (char *)0x0) {
    iVar2 = __stricmp(in_ECX,"/version");
    if (iVar2 == 0) {
      iVar2 = FUN_00894fab("Version: %d.%d.%d\n",1,1,0x34);
      FUN_00893fe3(iVar2 + 0x20);
      goto LAB_004a309d;
    }
    iVar2 = __stricmp(in_ECX,"geproc");
    if (iVar2 == 0) goto LAB_004a309d;
  }
  __setmaxstdio(0x400);
  FUN_00444ad0();
  FUN_00498000();
  iVar2 = FUN_0048bd30();
  if (iVar2 == 0) {
    FUN_004a2da0();
    uVar4 = 0x193;
    FUN_005854b0(0x193);
    uVar4 = FUN_00585330(uVar4);
    FUN_00402250(uVar4);
    local_c = 0;
    FUN_0046f860();
    FUN_0046fac0(local_c0bc);
    FUN_004fa440();
  }
  else {
    if (DAT_00fba797 == '\0') {
      FUN_00585390();
    }
    FUN_00582ee0();
    FUN_00582870();
    piVar3 = (int *)FUN_0044d680();
    if (((int *)*piVar3 != (int *)0x0) &&
       (iVar2 = (**(code **)(*(int *)*piVar3 + 0x1c))(), iVar2 != 0)) {
      piVar3 = (int *)FUN_0044d680();
      if ((int *)*piVar3 != (int *)0x0) {
        (**(code **)(*(int *)*piVar3 + 4))();
      }
      FUN_0048ab70(auStack_c0a0);
      local_c = 1;
      FUN_006deb40();
      FUN_006dec40();
      FUN_006dec90();
      piVar3 = (int *)FUN_0044d680();
      if ((int *)*piVar3 != (int *)0x0) {
        (**(code **)(*(int *)*piVar3 + 0xc))();
      }
      CoUninitialize();
      local_c = 0xffffffff;
      FUN_0048b190(auStack_c0a0);
    }
  }
LAB_004a309d:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_c0c0);
  return;
}


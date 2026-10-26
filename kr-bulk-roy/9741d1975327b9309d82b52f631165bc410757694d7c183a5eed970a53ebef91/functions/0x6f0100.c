
void FUN_006f0100(void)

{
  uint uVar1;
  UINT UVar2;
  int iVar3;
  int *piVar4;
  undefined4 *unaff_EDI;
  undefined1 local_114;
  undefined1 local_113 [255];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915e6c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *unaff_EDI = 0;
  local_14 = uVar1;
  _setlocale(0,"kEnglish");
  UVar2 = GetPrivateProfileIntA("TYPE","LOG",1,"./LogSetting.ini");
  if (UVar2 == 2) {
    iVar3 = FUN_00891268(0x1d4,uVar1);
    local_8 = 0;
    if (iVar3 != 0) {
      piVar4 = (int *)FUN_006f0720(iVar3);
      goto LAB_006f01ac;
    }
  }
  else {
    iVar3 = FUN_00891268(0x13c,uVar1);
    local_8 = 1;
    if (iVar3 != 0) {
      piVar4 = (int *)FUN_006f0f90();
      goto LAB_006f01ac;
    }
  }
  piVar4 = (int *)0x0;
LAB_006f01ac:
  local_8 = 0xffffffff;
  *unaff_EDI = piVar4;
  (**(code **)(*piVar4 + 8))();
  local_114 = 0;
  _memset(local_113,0,0xff);
  FUN_004a0930("Log Started at %s\n","Sep 21 2017");
  (**(code **)(*(int *)*unaff_EDI + 4))(&local_114);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


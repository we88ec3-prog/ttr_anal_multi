
void FUN_00718020(int param_1,undefined1 param_2)

{
  int iVar1;
  int *piVar2;
  char *unaff_ESI;
  int unaff_EDI;
  char *_Src;
  char local_40c [4];
  char local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_408 = '\0';
  _memset(local_407,0,0x3ff);
  _strcat_s(&local_408,0x400,unaff_ESI);
  if (param_1 == 2) {
    _Src = "wb";
LAB_007180a3:
    _strcpy_s(local_40c,4,_Src);
  }
  else {
    if (param_1 == 1) {
      _Src = "rb";
      goto LAB_007180a3;
    }
    if (param_1 == 3) {
      _Src = "r+b";
      goto LAB_007180a3;
    }
  }
  *(undefined1 *)(unaff_EDI + 0x210) = param_2;
  iVar1 = FUN_00714770(&local_408,local_40c);
  if (iVar1 != 0) {
LAB_007180ce:
    *(int *)(unaff_EDI + 0xc) = iVar1;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (param_1 == 3) {
    piVar2 = (int *)FUN_00714770(&local_408,&DAT_00c059a4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
    }
    iVar1 = FUN_00714770(&local_408,local_40c);
    if (iVar1 != 0) goto LAB_007180ce;
  }
  *(undefined4 *)(unaff_EDI + 0xc) = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


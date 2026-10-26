
void FUN_007143b0(void)

{
  int iVar1;
  int *_Str2;
  char *in_ECX;
  char *_Ext;
  int *piVar2;
  int *unaff_EDI;
  char local_108;
  char local_107 [255];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_108 = '\0';
  _memset(local_107,0,0xff);
  _Ext = &local_108;
  __splitpath(in_ECX,(char *)0x0,(char *)0x0,(char *)0x0,_Ext);
  if (local_108 == '.') {
    _Ext = local_107;
  }
  iVar1 = __stricmp(_Ext,"stp");
  if (iVar1 == 0) {
LAB_0071441a:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  piVar2 = *(int **)*unaff_EDI;
  if (piVar2 != (int *)*unaff_EDI) {
    do {
      _Str2 = piVar2 + 2;
      if (0xf < (uint)piVar2[7]) {
        _Str2 = (int *)*_Str2;
      }
      iVar1 = __stricmp(_Ext,(char *)_Str2);
      if (iVar1 == 0) goto LAB_0071441a;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*unaff_EDI);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


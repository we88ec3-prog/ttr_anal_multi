
void FUN_0083b090(LPCSTR param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_30 [4];
  undefined4 local_2c;
  LPCSTR local_28;
  undefined1 local_24 [28];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_2c = param_2;
  local_28 = param_1;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x54))(local_30,param_1);
  *param_3 = *piVar1;
  iVar2 = D3DXGetImageInfoFromFileA(local_2c,local_24);
  if (((-1 < iVar2) && (*param_3 != 0)) && (iVar2 = FUN_0083eb10(), param_1 = local_28, iVar2 != 0))
  {
    iVar2 = in_ECX[0x3b];
    FUN_0083eb10(iVar2);
    iVar2 = FUN_00865190(iVar2);
    param_1 = local_28;
    if (iVar2 != 0) {
      OutputDebugStringA(&DAT_00c53d8c);
      OutputDebugStringA(local_28);
      OutputDebugStringA("\n");
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  OutputDebugStringA(&DAT_00c53db4);
  OutputDebugStringA(param_1);
  OutputDebugStringA("\n");
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


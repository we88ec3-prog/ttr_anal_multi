
undefined4 * FUN_007f7680(undefined4 *param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 *_Dst;
  char *pcVar3;
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091455b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 1;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  local_8 = 0;
  param_1[9] = param_3;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = in_ECX;
  _Dst = (undefined4 *)FUN_00891268(0x34,uVar2);
  if (_Dst == (undefined4 *)0x0) {
    _Dst = (undefined4 *)0x0;
  }
  else {
    _Dst[0xc] = 7;
    _memset(_Dst,0,0x34);
    _Dst[8] = 0x3f800000;
    _Dst[4] = 0x3f800000;
    *_Dst = 0x3f800000;
  }
  param_1[0x10] = _Dst;
  param_1[0x16] = 0xf;
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar3 - (int)(param_2 + 1));
  param_1[0x1d] = 0xf;
  param_1[0x1c] = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  param_1[1] = DAT_00fba848;
  DAT_00fba848 = DAT_00fba848 + 1;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  ExceptionList = local_10;
  return param_1;
}


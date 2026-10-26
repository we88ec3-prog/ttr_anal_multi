
undefined4 * FUN_00715270(undefined4 *param_1)

{
  char *_Dst;
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915ce1;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00717840(param_1);
  local_8 = 0;
  *param_1 = Package::CPackage::vftable;
  iVar3 = FUN_00891268(0x48,uVar2);
  local_8._0_1_ = 1;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_007184c0(iVar3);
  }
  param_1[0x4e] = uVar4;
  param_1[0x54] = 0xf;
  param_1[0x53] = 0;
  *(undefined1 *)(param_1 + 0x4f) = 0;
  param_1[0x5b] = 0xf;
  param_1[0x5a] = 0;
  *(undefined1 *)(param_1 + 0x56) = 0;
  _Dst = (char *)(param_1 + 3);
  local_8 = CONCAT31(local_8._1_3_,3);
  _strcpy_s(_Dst,0x100,"<root>");
  pcVar5 = _Dst;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(_Dst,(int)pcVar5 - ((int)param_1 + 0xd));
  ExceptionList = local_10;
  return param_1;
}


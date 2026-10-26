
void FUN_007a6ea0(int param_1,undefined4 param_2,short param_3)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short *psVar4;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = param_1;
  puStack_c = &LAB_0093915e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8 = 0;
    FUN_0079cf40(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdb80);
  }
  local_8 = 0xffffffff;
  param_1 = *(int *)(iVar2 + 0x18);
  FUN_00515790(&param_1);
  if (((local_14 == DAT_00fc0e94) ||
      (iVar1 = *(int *)(*(int *)(local_14 + 0x10) + 0x54), iVar1 == 0)) ||
     (*(int *)(iVar1 + 0xbc) != 0)) {
    FUN_007a0b10(&param_2);
    if ((param_1 == *(int *)(iVar2 + 0x50)) || (*(short *)(param_1 + 0xe) != param_3)) {
      FUN_007a15d0(&local_18,&param_2);
      FUN_004ca160(local_18,local_14);
      sVar3 = param_3;
      if (param_3 != 0) {
        psVar4 = (short *)FUN_007a0a90();
        *psVar4 = sVar3;
      }
      *(undefined1 *)(iVar2 + 0x28) = 1;
    }
  }
  ExceptionList = local_10;
  return;
}


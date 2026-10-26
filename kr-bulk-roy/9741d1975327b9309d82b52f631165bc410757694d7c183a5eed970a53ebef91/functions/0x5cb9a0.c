
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cb9a0(void)

{
  short sVar1;
  int *piVar2;
  short *psVar3;
  int in_ECX;
  short *psVar4;
  uint in_stack_00000010;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = *(int **)(*(int *)(in_ECX + 4) + 0x14);
  if (piVar2 != (int *)0x0) {
    if ((in_stack_00000010 & 8) != 0) {
      (**(code **)(*piVar2 + 0x1a4))(local_14);
    }
    if ((in_stack_00000010 & 0x800) != 0) {
      (**(code **)(*piVar2 + 0x19c))();
      if ((_DAT_00fc183c & 1) == 0) {
        _DAT_00fc183c = _DAT_00fc183c | 1;
        FUN_006f1ff0();
        DAT_00fc18d8 = 1;
        _atexit((_func_4879 *)&LAB_00bce3a0);
      }
      psVar4 = DAT_00fc1850;
      if (DAT_00fc1864 < 8) {
        psVar4 = (short *)&DAT_00fc1850;
      }
      local_1c = 7;
      local_20 = 0;
      local_30 = (uint)local_30._2_2_ << 0x10;
      psVar3 = psVar4;
      do {
        sVar1 = *psVar3;
        psVar3 = psVar3 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar4,(int)psVar3 - (int)(psVar4 + 1) >> 1);
      local_8 = 0;
      if ((_DAT_00fc183c & 1) == 0) {
        _DAT_00fc183c = _DAT_00fc183c | 1;
        FUN_006f1ff0();
        DAT_00fc18d8 = 1;
        _atexit((_func_4879 *)&LAB_00bce3a0);
      }
      _DAT_00fc1860 = 0;
      psVar4 = DAT_00fc1850;
      if (DAT_00fc1864 < 8) {
        psVar4 = (short *)&DAT_00fc1850;
      }
      *psVar4 = 0;
      (**(code **)(*piVar2 + 400))(&local_30);
      (**(code **)(*piVar2 + 0x1a0))();
      (**(code **)(*piVar2 + 0x1a4))();
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


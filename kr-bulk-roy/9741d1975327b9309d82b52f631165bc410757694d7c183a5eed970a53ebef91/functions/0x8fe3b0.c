
void FUN_008fe3b0(undefined4 param_1,int param_2,int *param_3,int *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 in_ECX;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921c68;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_008fdaa0(param_2,param_3);
  if ((DAT_00fe2878 & 1) == 0) {
    DAT_00fe2878 = DAT_00fe2878 | 1;
    local_8 = 0;
    FUN_0052b6c0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcf300);
    local_8 = 0xffffffff;
  }
  param_3 = param_4;
  FUN_008438c0(&param_3);
  if ((param_2 != DAT_00fe2884) && (*(int *)(param_2 + 0x10) != -0xc)) {
    FUN_005721c0();
    piVar3 = (int *)FUN_005721d0();
    piVar4 = param_3;
    if (param_3 != (int *)*piVar3) {
      do {
        puVar1 = (undefined4 *)*piVar4;
        FUN_008fe320(*puVar1,puVar1[1],*(undefined2 *)(puVar1 + 2));
        piVar4 = piVar4 + 1;
        piVar3 = (int *)FUN_005721d0();
      } while (piVar4 != (int *)*piVar3);
    }
  }
  FUN_008fd520(in_ECX);
  FUN_008fd370();
  ExceptionList = local_10;
  return;
}


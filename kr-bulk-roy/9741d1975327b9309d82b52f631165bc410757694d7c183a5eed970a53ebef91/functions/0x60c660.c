
int FUN_0060c660(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  int *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar3 = param_1;
  puStack_c = &LAB_0090cd7e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1094 & 1) == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 0;
    FUN_0052f7e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdc80);
  }
  local_8 = 0xffffffff;
  param_1 = uVar3;
  FUN_008438c0(&param_1);
  if (((in_ECX != DAT_00fc109c) && (*(int *)(in_ECX + 0x10) != 0)) &&
     (piVar1 = (int *)*unaff_EDI, piVar1 != (int *)0x0)) {
    pcVar2 = *(code **)(*piVar1 + 0x184);
    *(undefined2 *)((int)piVar1 + 0x162) = param_3;
    (*pcVar2)(uVar3,param_2);
    (**(code **)(*piVar1 + 0x188))();
    ExceptionList = local_10;
    return *unaff_EDI;
  }
  ExceptionList = local_10;
  return 0;
}


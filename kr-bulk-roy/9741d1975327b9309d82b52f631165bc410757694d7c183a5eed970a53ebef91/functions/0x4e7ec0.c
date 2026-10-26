
void FUN_004e7ec0(int *param_1)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d6fb;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = (int *)*param_1;
  if (piVar3 != (int *)param_1[1]) {
    do {
      iVar1 = *piVar3;
      if (iVar1 != 0) {
        local_8 = 0;
        if (*(int **)(iVar1 + 0x2c) != (int *)0x0) {
          (**(code **)(**(int **)(iVar1 + 0x2c) + 8))(uVar2);
          *(undefined4 *)(iVar1 + 0x2c) = 0;
        }
        local_8 = 0xffffffff;
        if (7 < *(uint *)(iVar1 + 0x1c)) {
          FUN_0089120c(*(undefined4 *)(iVar1 + 8));
        }
        *(undefined4 *)(iVar1 + 0x1c) = 7;
        *(undefined4 *)(iVar1 + 0x18) = 0;
        *(undefined2 *)(iVar1 + 8) = 0;
        FUN_0089120c(iVar1);
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != (int *)param_1[1]);
  }
  _Dst = (void *)*param_1;
  if (_Dst != (void *)param_1[1]) {
    FID_conflict__memcpy(_Dst,(void *)param_1[1],0);
    param_1[1] = (int)_Dst;
  }
  ExceptionList = local_10;
  return;
}


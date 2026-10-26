
void FUN_007a79c0(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091882e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = (int *)FUN_007a7800(param_2);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x40))(uVar2);
    if ((DAT_00fe1770 & 1) == 0) {
      DAT_00fe1770 = DAT_00fe1770 | 1;
      local_8 = 0;
      FUN_007b7da0();
      _atexit((_func_4879 *)&LAB_00bce790);
      local_8 = 0xffffffff;
    }
    piVar3 = (int *)FUN_007b8180();
    if ((piVar3 != (int *)0x0) && (iVar1 = *piVar3, iVar1 != 0)) {
      if ((*(undefined4 **)(param_1 + 0x108) != (undefined4 *)0x0) &&
         (*(int *)**(undefined4 **)(param_1 + 0x108) == iVar1)) {
        FUN_007be5f0();
        FUN_007a6c30();
        ExceptionList = local_10;
        return;
      }
      piVar3 = *(int **)(param_1 + 0x10c);
      piVar4 = (int *)*piVar3;
      if (piVar4 != piVar3) {
        while (**(int **)piVar4[2] != iVar1) {
          piVar4 = (int *)*piVar4;
          if (piVar4 == piVar3) {
            ExceptionList = local_10;
            return;
          }
        }
        FUN_007be5f0();
        piVar3 = (int *)piVar4[3];
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x10))();
          (**(code **)(*piVar3 + 8))();
        }
        if (piVar4 != *(int **)(param_1 + 0x10c)) {
          *(int *)piVar4[1] = *piVar4;
          *(int *)(*piVar4 + 4) = piVar4[1];
          FUN_0089120c(piVar4);
          *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + -1;
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}


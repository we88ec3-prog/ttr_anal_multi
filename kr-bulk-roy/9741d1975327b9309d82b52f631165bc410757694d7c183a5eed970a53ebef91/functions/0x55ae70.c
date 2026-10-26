
int FUN_0055ae70(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar3 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a12b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  for (puVar1 = *(undefined4 **)*param_1; puVar1 != (undefined4 *)*param_1;
      puVar1 = (undefined4 *)*puVar1) {
    if (*(int *)puVar1[2] == in_ECX) {
      FUN_00559d60((int *)puVar1[2]);
      FUN_0055a260(puVar1[2]);
      ExceptionList = local_10;
      return puVar1[2];
    }
  }
  param_1 = (int *)FUN_00891268(0x104,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  iVar5 = 0;
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    iVar5 = FUN_00559b80(in_ECX);
  }
  local_8 = 0xffffffff;
  *(int *)(iVar5 + 0x100) = piVar3[param_3 + 5];
  param_1 = (int *)iVar5;
  FUN_00559d60(iVar5);
  FUN_0055a260(iVar5);
  *(int *)(iVar5 + 0x54) = piVar3[3];
  iVar2 = *piVar3;
  iVar4 = FUN_0074d700(iVar2,*(undefined4 *)(iVar2 + 4),&param_1);
  if (piVar3[1] != 0x3ffffffe) {
    piVar3[1] = piVar3[1] + 1;
    *(int *)(iVar2 + 4) = iVar4;
    **(int **)(iVar4 + 4) = iVar4;
    ExceptionList = local_10;
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}


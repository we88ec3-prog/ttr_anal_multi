
void FUN_00766260(int param_1,undefined4 param_2,undefined4 param_3,int param_4,char param_5)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int in_EDX;
  int iVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009157db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_5 == '\0') {
    FUN_00757c60(*(undefined4 *)(*(int *)(in_EDX + 0x110) + param_1 * 4),
                 *(undefined4 *)(*(int *)(in_EDX + 0x110) + in_ECX * 4),param_3,param_4,param_2);
  }
  else {
    iVar2 = FUN_00891268(0x38,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    iVar3 = 0;
    local_8 = 0;
    if (iVar2 != 0) {
      iVar3 = FUN_00757200(iVar2);
    }
    local_8 = 0xffffffff;
    piVar4 = (int *)(in_EDX + 0x110);
    FUN_00757c60(iVar3,*(undefined4 *)(in_ECX * 4 + *(int *)(in_EDX + 0x110)),param_3,param_4,
                 *(undefined4 *)(iVar3 + 0x10));
    iVar2 = *piVar4;
    iVar1 = *piVar4;
    if (*(int *)(in_EDX + 0x114) == *(int *)(in_EDX + 0x118)) {
      FUN_00797930();
    }
    if (*(int **)(in_EDX + 0x114) != (int *)0x0) {
      **(int **)(in_EDX + 0x114) = iVar3;
    }
    *(int *)(in_EDX + 0x114) = *(int *)(in_EDX + 0x114) + 4;
    iVar3 = *(int *)(in_EDX + 0x114);
    iVar2 = *piVar4 + ((iVar2 + in_ECX * 4 + 4) - iVar1 >> 2) * 4;
    if ((iVar2 != iVar3 + -4) && (iVar3 + -4 != iVar3)) {
      FUN_00474630(iVar2,iVar3);
    }
  }
  if (0 < param_4) {
    FUN_00757e40(param_4,param_3);
  }
  ExceptionList = local_10;
  return;
}


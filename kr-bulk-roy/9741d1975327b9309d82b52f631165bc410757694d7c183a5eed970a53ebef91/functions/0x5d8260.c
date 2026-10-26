
void FUN_005d8260(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x2b8) == -1) {
    FUN_00757710(uVar4);
    iVar2 = *(int *)(in_ECX + 0x2a4);
    if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
       (iVar5 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
      iVar2 = *(int *)(iVar2 + 0x94);
      iVar5 = *(int *)(iVar2 + 0x10);
      if (iVar5 != 0) {
        piVar3 = *(int **)(iVar5 + 8);
        if (piVar3 != (int *)0x0) {
          piVar1 = piVar3 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar3 + 0x28))();
          }
        }
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
    }
  }
  else {
    uVar6 = uVar4;
    FUN_00412df0();
    local_8 = 0;
    FUN_00757710(uVar6);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    iVar2 = *(int *)(in_ECX + 700);
    if (iVar2 == 1) {
      FUN_00403470();
      FUN_00745100();
    }
    else if (iVar2 == 3) {
      FUN_00403470();
      FUN_00745100();
    }
    else if (iVar2 == 4) {
      FUN_00403470();
      FUN_00745100();
    }
    else {
      FUN_00745100();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar4 ^ (uint)&stack0xfffffffc);
  return;
}


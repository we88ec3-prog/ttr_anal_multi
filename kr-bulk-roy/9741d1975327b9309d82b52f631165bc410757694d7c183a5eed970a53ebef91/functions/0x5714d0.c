
void FUN_005714d0(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  undefined4 local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int **)(unaff_ESI + 0xc) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x2c))(local_14);
    if (iVar1 == 0) {
      if (*(int *)(unaff_ESI + 0x10) == 0) {
        piVar2 = (int *)(unaff_ESI + 0x14);
        if (7 < *(uint *)(unaff_ESI + 0x28)) {
          piVar2 = (int *)*piVar2;
        }
        FUN_00402250(piVar2);
        puVar3 = local_30;
        local_8 = 0;
        FUN_0040f8c0(puVar3);
        FUN_004d6b30(puVar3);
        if (7 < local_1c) {
          FUN_0089120c(local_30[0]);
        }
      }
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
    else {
      (**(code **)(**(int **)(unaff_ESI + 0xc) + 0x14))();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


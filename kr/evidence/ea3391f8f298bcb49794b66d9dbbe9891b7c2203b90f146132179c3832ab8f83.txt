
void FUN_0079d610(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  int **ppiVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined4 in_stack_00000018;
  uint in_stack_0000001c;
  uint in_stack_00000024;
  undefined4 in_stack_00000034;
  uint in_stack_00000038;
  undefined4 in_stack_00000040;
  uint in_stack_00000054;
  undefined1 local_48 [4];
  int *local_44;
  int *local_40;
  int *local_3c;
  undefined1 local_38 [36];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009151f8;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  piVar2 = *(int **)(param_1 + 0x14);
  local_14 = uVar5;
  local_44 = (int *)FUN_007d0110(&param_2);
  if ((local_44 == *(int **)(param_1 + 0x14)) || (cVar4 = FUN_0049ae30(uVar5), cVar4 != '\0')) {
    local_3c = *(int **)(param_1 + 0x14);
    ppiVar6 = &local_3c;
  }
  else {
    ppiVar6 = &local_44;
  }
  if (*ppiVar6 == piVar2) {
    puVar7 = (undefined1 *)FUN_00891268(0x58);
    if (puVar7 == (undefined1 *)0x0) {
      puVar7 = (undefined1 *)0x0;
    }
    else {
      *(undefined4 *)(puVar7 + 0x10) = 0;
      *(undefined4 *)(puVar7 + 0x14) = 0xf;
      *puVar7 = 0;
      *(undefined4 *)(puVar7 + 0x30) = 0xf;
      *(undefined4 *)(puVar7 + 0x2c) = 0;
      puVar7[0x1c] = 0;
      *(undefined4 *)(puVar7 + 0x4c) = 0xf;
      *(undefined4 *)(puVar7 + 0x48) = 0;
      puVar7[0x38] = 0;
      *(undefined4 *)(puVar7 + 0x54) = 0;
    }
    local_40 = (int *)0x0;
    local_3c = (int *)0x0;
    FUN_007a3290(&local_40,puVar7);
    local_8._0_1_ = 3;
    FUN_00403040(&param_2,0,0xffffffff);
    FUN_00403040(&stack0x00000024,0,0xffffffff);
    FUN_00403040(&stack0x00000040,0,0xffffffff);
    uVar8 = FUN_007a25d0();
    local_8._0_1_ = 4;
    uVar8 = FUN_007a3330(uVar8);
    FUN_007a2b50(param_1 + 0x10,local_48,uVar8);
    local_8._0_1_ = 3;
    FUN_0079d840(local_38);
    piVar2 = local_3c;
    local_8 = CONCAT31(local_8._1_3_,2);
    if (local_3c != (int *)0x0) {
      LOCK();
      iVar3 = local_3c[1] + -1;
      local_3c[1] = iVar3;
      UNLOCK();
      if (iVar3 == 0) {
        (**(code **)*local_3c)();
        piVar1 = piVar2 + 2;
        LOCK();
        iVar3 = *piVar1 + -1;
        *piVar1 = iVar3;
        UNLOCK();
        if (iVar3 == 0) {
          (**(code **)(*piVar2 + 4))();
        }
      }
    }
    if (0xf < in_stack_0000001c) {
      FUN_0089120c(param_2);
    }
    in_stack_0000001c = 0xf;
    in_stack_00000018 = 0;
    param_2 = param_2 & 0xffffff00;
    if (0xf < in_stack_00000038) {
      FUN_0089120c(in_stack_00000024);
    }
    in_stack_00000038 = 0xf;
    in_stack_00000034 = 0;
    in_stack_00000024 = in_stack_00000024 & 0xffffff00;
    if (0xf < in_stack_00000054) {
      FUN_0089120c(in_stack_00000040);
    }
  }
  else {
    if (0xf < in_stack_0000001c) {
      FUN_0089120c(param_2);
    }
    in_stack_0000001c = 0xf;
    in_stack_00000018 = 0;
    param_2 = param_2 & 0xffffff00;
    if (0xf < in_stack_00000038) {
      FUN_0089120c(in_stack_00000024);
    }
    in_stack_00000038 = 0xf;
    in_stack_00000034 = 0;
    in_stack_00000024 = in_stack_00000024 & 0xffffff00;
    if (0xf < in_stack_00000054) {
      FUN_0089120c(in_stack_00000040);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


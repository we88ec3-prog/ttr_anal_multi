
int FUN_00843090(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined **local_2c [5];
  char *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00909188;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar3 = FUN_00891268(0x18,uVar2);
  if (iVar3 != 0) {
    *(int *)(param_1 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x15) = 1;
    local_8 = 0;
    _eh_vector_constructor_iterator_((void *)(param_1 + 0x10),0x10,8,FUN_00554050,FUN_00843020);
    local_8._0_1_ = 1;
    _eh_vector_constructor_iterator_((void *)(param_1 + 0x90),0x10,8,FUN_00554050,FUN_00843020);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (param_1 != param_2) {
      FUN_005540c0(**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
      FUN_005c7580(param_2);
    }
    local_14 = (undefined4 *)(param_2 + 0x90);
    puVar4 = (undefined4 *)(param_1 + 0x94);
    local_18 = (char *)0x8;
    do {
      if (puVar4 + -0x21 != local_14 + -0x20) {
        FUN_005540c0(*(undefined4 *)puVar4[-0x20],(undefined4 *)puVar4[-0x20]);
        FUN_005c7580(local_14 + -0x20);
      }
      if (puVar4 + -1 != local_14) {
        FUN_005540c0(*(undefined4 *)*puVar4,(undefined4 *)*puVar4);
        FUN_005c7580(local_14);
      }
      local_14 = local_14 + 4;
      puVar4 = puVar4 + 4;
      local_18 = local_18 + -1;
    } while (local_18 != (char *)0x0);
    piVar1 = *(int **)(param_2 + 0x110);
    *(int **)(param_1 + 0x110) = piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_2 + 0x114);
    *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_2 + 0x118);
    ExceptionList = local_10;
    return param_1;
  }
  local_18 = (char *)0x0;
  std::exception::exception((exception *)local_2c,&local_18);
  local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_2c,&DAT_00c857a8);
}


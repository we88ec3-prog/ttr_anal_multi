
undefined4 FUN_00535410(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  int *piVar6;
  int *piVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f3ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(*(undefined1 *)(in_ECX + 2)) {
  case 0:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 0;
    FUN_005854b0();
    uVar3 = FUN_00585330();
    goto LAB_00535566;
  case 1:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 2;
    break;
  case 2:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 3;
    break;
  case 3:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 4;
    break;
  case 4:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 1;
    break;
  case 5:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 5;
    break;
  default:
    goto switchD_00535447_default;
  }
  FUN_005854b0();
  uVar3 = FUN_00585330();
LAB_00535566:
  FUN_00402250(uVar3);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_00535447_default:
  if (((int)(uint)*(ushort *)(param_1 + 0x40) <= *(int *)(param_1 + 0x3c)) && (DAT_00fba798 == 0)) {
    (**(code **)(*DAT_00fba854 + 0x10))();
  }
  piVar4 = *(int **)(param_1 + 0x4c);
  *(undefined1 *)(param_1 + 0x48) = 1;
  if (piVar4 != *(int **)(param_1 + 0x50)) {
    do {
      if ((*(int *)(in_ECX + 3) == *piVar4) && (*(int *)(in_ECX + 7) == piVar4[1])) {
        piVar1 = *(int **)(param_1 + 0x50);
        piVar2 = piVar4;
        while (piVar2 = (int *)((int)piVar2 + 0x1f), piVar2 != piVar1) {
          piVar6 = piVar2;
          piVar7 = piVar4;
          for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
            *piVar7 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
          }
          *(short *)piVar7 = (short)*piVar6;
          piVar4 = (int *)((int)piVar4 + 0x1f);
          *(undefined1 *)((int)piVar7 + 2) = *(undefined1 *)((int)piVar6 + 2);
        }
        *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -0x1f;
        if ((DAT_00faadd4 & 1) == 0) {
          DAT_00faadd4 = DAT_00faadd4 | 1;
          local_8 = 6;
          FUN_00587480();
          _atexit((_func_4879 *)&LAB_00bcccc0);
          local_8 = 0xffffffff;
        }
        FUN_0058aad0();
        ExceptionList = local_10;
        return 0;
      }
      piVar4 = (int *)((int)piVar4 + 0x1f);
    } while (piVar4 != *(int **)(param_1 + 0x50));
  }
  ExceptionList = local_10;
  return 0;
}


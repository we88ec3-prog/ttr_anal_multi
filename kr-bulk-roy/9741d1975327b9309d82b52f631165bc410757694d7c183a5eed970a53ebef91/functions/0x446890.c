
void FUN_00446890(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  char unaff_BL;
  int *piVar5;
  int iStack_2c;
  int local_28;
  int iStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092a16c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb93cc & 1) == 0) {
    DAT_00fb93cc = DAT_00fb93cc | 1;
    local_c = 0;
    FUN_00445460(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bcd620);
  }
  local_c = 0xffffffff;
  uVar4 = DAT_00fb93d4 - DAT_00fb93d0 >> 2;
  uVar2 = 0;
  if (uVar4 != 0) {
    while (piVar1 = *(int **)(DAT_00fb93d0 + uVar2 * 4), *piVar1 != in_ECX) {
      uVar2 = uVar2 + 1;
      if (uVar4 <= uVar2) {
        ExceptionList = local_14;
        return;
      }
    }
    if (piVar1 != (int *)0x0) {
      local_28 = CONCAT31(local_28._1_3_,piVar1[3] != piVar1[4]);
      iVar3 = local_28;
      (**(code **)(**(int **)(param_1 + 0x100) + 0x94))(local_28);
      (**(code **)(**(int **)(param_1 + 0x108) + 0x94))(iVar3);
      iVar3 = *(int *)(*(int *)(param_1 + 0x108) + 0xcc);
      if (iVar3 != 0) {
        FUN_00408920(iVar3,piVar1[4] - piVar1[3] >> 3);
      }
      if ((unaff_BL != '\0') && (uVar2 = 0, piVar1[4] - piVar1[3] >> 3 != 0)) {
        do {
          iStack_24 = uVar2 * 8;
          piVar5 = (int *)(piVar1[3] + iStack_24);
          if ((DAT_00f8d9a4 & 1) == 0) {
            DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
            local_14 = (void *)0x1;
            FUN_0051c120();
            _atexit((_func_4879 *)&LAB_00bccc90);
            local_14 = (void *)0xffffffff;
          }
          iStack_2c = *piVar5;
          FUN_008438c0(&iStack_2c);
          if ((local_28 != DAT_00f8d91c) && (iStack_2c = *(int *)(local_28 + 0x10), iStack_2c != 0))
          {
            iVar3 = *(int *)(*(int *)(param_1 + 0x108) + 0xcc);
            if ((iVar3 == 0) ||
               ((((int)uVar2 < 0 ||
                 (*(int *)(iVar3 + 0xac) - *(int *)(iVar3 + 0xa8) >> 2 <= (int)uVar2)) ||
                (piVar5 = *(int **)(*(int *)(iVar3 + 0xa8) + uVar2 * 4), piVar5 == (int *)0x0)))) {
LAB_00446a8b:
              piVar5 = (int *)0x0;
            }
            else {
              iVar3 = (**(code **)(*piVar5 + 4))();
              if (iVar3 != 0x12d) {
                MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
                goto LAB_00446a8b;
              }
            }
            (**(code **)(*(int *)piVar5[0x92] + 0x19c))
                      (*(undefined4 *)(iStack_2c + 0x20),*(undefined4 *)(iStack_24 + piVar1[3]),0,0)
            ;
            (**(code **)(*(int *)piVar5[0x92] + 200))();
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < (uint)(piVar1[4] - piVar1[3] >> 3));
      }
      (**(code **)(**(int **)(param_1 + 0x100) + 200))();
      FUN_00749920(*(undefined4 *)(param_1 + 0x108));
      (**(code **)(**(int **)(param_1 + 0x108) + 200))();
    }
  }
  ExceptionList = local_14;
  return;
}



void FUN_0047cb00(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00947ed2;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fc0f64 & 1) == 0) {
    DAT_00fc0f64 = DAT_00fc0f64 | 1;
    local_c = 0;
    FUN_0047dce0(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit(FUN_00bcdaf0);
  }
  local_c = 0xffffffff;
  local_30 = param_2;
  FUN_008438c0(&local_30);
  if (local_2c == (int *)DAT_00fc0f6c) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)((int)local_2c + 0x10);
  }
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 1;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_c = 0xffffffff;
  }
  FUN_00503440(&DAT_00fab2a0,&local_28,iVar6 + 0x24);
  local_c = 2;
  iVar6 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
  if (iVar6 != 0) {
    FUN_00408920(iVar6,local_24 - local_28 >> 2);
  }
  uVar7 = 0;
  do {
    iVar6 = *(int *)(param_1 + 0xfc);
    if (*(int *)(iVar6 + 0xcc) == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(*(int *)(iVar6 + 0xcc) + 0xa8);
    }
    if ((uint)(piVar5[1] - *piVar5 >> 2) <= uVar7) {
      piVar5 = *(int **)(iVar6 + 0xd0);
      pcVar3 = *(code **)(*piVar5 + 0x128);
      piVar5[0x31] = 0;
      (*pcVar3)();
      (**(code **)(*piVar5 + 200))();
      piVar5 = *(int **)(param_1 + 0xfc);
      puVar1 = (undefined4 *)piVar5[0x19];
      local_2c = piVar5;
      for (puVar4 = (undefined4 *)*puVar1; puVar4 != puVar1; puVar4 = (undefined4 *)*puVar4) {
        iVar6 = puVar4[2];
        if ((*(int *)(iVar6 + 0x60) != 0) && ((*(int **)(iVar6 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar6 + 0x1c) + 0x30))(iVar6);
          piVar5 = local_2c;
        }
      }
      (**(code **)(*piVar5 + 0x128))();
      (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
      if (local_28 != 0) {
        FUN_0089120c(local_28);
      }
      ExceptionList = local_14;
      return;
    }
    iVar6 = *(int *)(iVar6 + 0xcc);
    if ((((iVar6 == 0) || ((int)uVar7 < 0)) ||
        (*(int *)(iVar6 + 0xac) - *(int *)(iVar6 + 0xa8) >> 2 <= (int)uVar7)) ||
       (piVar5 = *(int **)(*(int *)(iVar6 + 0xa8) + uVar7 * 4), piVar5 == (int *)0x0)) {
LAB_0047cc7c:
      piVar5 = (int *)0x0;
    }
    else {
      iVar6 = (**(code **)(*piVar5 + 4))();
      if (iVar6 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_0047cc7c;
      }
    }
    piVar2 = *(int **)(local_28 + uVar7 * 4);
    *(undefined1 *)(piVar5 + 0x9b) = 0;
    piVar5[0x92] = *piVar2;
    FUN_004026e0(piVar2 + 0x13,0,0xffffffff);
    FUN_00757800(piVar5 + 0x94);
    piVar5[0x93] = param_2;
    if ((uint)(local_24 - local_28 >> 2) <= uVar7) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid vector<T> subscript");
    }
    puVar1 = (undefined4 *)(local_28 + uVar7 * 4);
    if ((DAT_00fc0f64 & 1) == 0) {
      DAT_00fc0f64 = DAT_00fc0f64 | 1;
      local_c._0_1_ = 3;
      FUN_0047dce0();
      _atexit(FUN_00bcdaf0);
      local_c = CONCAT31(local_c._1_3_,2);
    }
    (**(code **)(*(int *)piVar5[0x9c] + 0x94))(*(int *)*puVar1 == DAT_00fc0f7c);
    (**(code **)(*(int *)piVar5[0x9c] + 200))();
    uVar7 = uVar7 + 1;
  } while( true );
}


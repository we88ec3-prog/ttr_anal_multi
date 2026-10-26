
void FUN_0047cdf0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927a5c;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar6 = 0;
  while( true ) {
    piVar7 = *(int **)(param_1 + 0xf8);
    if (piVar7[0x33] == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(piVar7[0x33] + 0xa8);
    }
    if ((uint)(piVar4[1] - *piVar4 >> 2) <= uVar6) break;
    iVar5 = piVar7[0x33];
    if (((iVar5 == 0) || ((int)uVar6 < 0)) ||
       ((*(int *)(iVar5 + 0xac) - *(int *)(iVar5 + 0xa8) >> 2 <= (int)uVar6 ||
        (piVar7 = *(int **)(*(int *)(iVar5 + 0xa8) + uVar6 * 4), piVar7 == (int *)0x0)))) {
LAB_0047ce9f:
      piVar7 = (int *)0x0;
    }
    else {
      iVar5 = (**(code **)(*piVar7 + 4))();
      if (iVar5 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_0047ce9f;
      }
    }
    iVar5 = piVar7[0x92];
    if ((DAT_00fc0f64 & 1) == 0) {
      DAT_00fc0f64 = DAT_00fc0f64 | 1;
      local_8 = 0;
      FUN_0047dce0();
      _atexit(FUN_00bcdaf0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*(int *)piVar7[0x9b] + 0x94))(iVar5 == DAT_00fc0f78);
    (**(code **)(*(int *)piVar7[0x9b] + 200))();
    uVar6 = uVar6 + 1;
  }
  puVar1 = (undefined4 *)piVar7[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar5 = puVar2[2];
    if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5,uVar3);
    }
  }
  (**(code **)(*piVar7 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
  uVar3 = 0;
  do {
    piVar7 = *(int **)(param_1 + 0xfc);
    if (piVar7[0x33] == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(piVar7[0x33] + 0xa8);
    }
    if ((uint)(piVar4[1] - *piVar4 >> 2) <= uVar3) {
      puVar1 = (undefined4 *)piVar7[0x19];
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        iVar5 = puVar2[2];
        if ((*(int *)(iVar5 + 0x60) != 0) && ((*(int **)(iVar5 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar5 + 0x1c) + 0x30))(iVar5);
        }
      }
      (**(code **)(*piVar7 + 0x128))();
      (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
      ExceptionList = local_10;
      return;
    }
    iVar5 = piVar7[0x33];
    if ((((iVar5 == 0) || ((int)uVar3 < 0)) ||
        (*(int *)(iVar5 + 0xac) - *(int *)(iVar5 + 0xa8) >> 2 <= (int)uVar3)) ||
       (piVar7 = *(int **)(*(int *)(iVar5 + 0xa8) + uVar3 * 4), piVar7 == (int *)0x0)) {
LAB_0047cfdf:
      piVar7 = (int *)0x0;
    }
    else {
      iVar5 = (**(code **)(*piVar7 + 4))();
      if (iVar5 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_0047cfdf;
      }
    }
    iVar5 = piVar7[0x92];
    if ((DAT_00fc0f64 & 1) == 0) {
      DAT_00fc0f64 = DAT_00fc0f64 | 1;
      local_8 = 1;
      FUN_0047dce0();
      _atexit(FUN_00bcdaf0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*(int *)piVar7[0x9c] + 0x94))(iVar5 == DAT_00fc0f7c);
    (**(code **)(*(int *)piVar7[0x9c] + 200))();
    uVar3 = uVar3 + 1;
  } while( true );
}


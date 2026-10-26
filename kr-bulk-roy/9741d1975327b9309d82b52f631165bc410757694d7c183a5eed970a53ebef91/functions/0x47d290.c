
void FUN_0047d290(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093414e;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar7 = *(int *)(*(int *)(param_1 + 0xf8) + 0xcc);
  if (iVar7 != 0) {
    FUN_00408920(iVar7,*(undefined4 *)(param_1 + 0x114));
  }
  puVar2 = *(undefined4 **)(param_1 + 0x110);
  puVar3 = (undefined4 *)*puVar2;
  local_14 = 0;
  do {
    if (puVar3 == puVar2) {
      piVar8 = *(int **)(param_1 + 0xf8);
      puVar2 = (undefined4 *)piVar8[0x19];
      for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
        iVar7 = puVar3[2];
        if ((*(int *)(iVar7 + 0x60) != 0) && ((*(int **)(iVar7 + 0x1c))[2] != 6)) {
          (**(code **)(**(int **)(iVar7 + 0x1c) + 0x30))(iVar7);
        }
      }
      (**(code **)(*piVar8 + 0x128))();
      (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
      ExceptionList = local_10;
      return;
    }
    iVar7 = *(int *)(*(int *)(param_1 + 0xf8) + 0xcc);
    if ((((iVar7 == 0) || (local_14 < 0)) ||
        (*(int *)(iVar7 + 0xac) - *(int *)(iVar7 + 0xa8) >> 2 <= local_14)) ||
       (piVar8 = *(int **)(*(int *)(iVar7 + 0xa8) + local_14 * 4), piVar8 == (int *)0x0)) {
LAB_0047d35c:
      piVar8 = (int *)0x0;
    }
    else {
      iVar7 = (**(code **)(*piVar8 + 4))(uVar6);
      if (iVar7 != 0x12d) {
        MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        goto LAB_0047d35c;
      }
    }
    local_14 = local_14 + 1;
    if (puVar3 != *(undefined4 **)(param_1 + 0x110)) {
      FUN_0047b2b0(piVar8);
      if ((DAT_00fc0f64 & 1) == 0) {
        DAT_00fc0f64 = DAT_00fc0f64 | 1;
        local_8 = 0;
        FUN_0047dce0();
        _atexit(FUN_00bcdaf0);
        local_8 = 0xffffffff;
      }
      (**(code **)(*(int *)piVar8[0x9b] + 0x94))(puVar3[3] == DAT_00fc0f78);
      (**(code **)(*(int *)piVar8[0x9b] + 200))();
    }
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  } while( true );
}



void FUN_00485470(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  int *piVar10;
  undefined1 local_5c [4];
  undefined4 *local_58;
  undefined1 local_4c [4];
  undefined4 *local_48;
  int local_44;
  undefined **local_3c [7];
  char *local_20;
  int *local_1c;
  undefined1 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910b50;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00485810(*(undefined4 *)(*(int *)(param_1 + 0x14) + 4));
  *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(int *)(*(int *)(param_1 + 0x14) + 8) = *(int *)(param_1 + 0x14);
  uVar4 = DAT_00fb11a8 & 1;
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (uVar4 == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(uVar6);
    _atexit((_func_4879 *)&LAB_00bccec0);
    local_8 = 0xffffffff;
  }
  piVar10 = (int *)*DAT_00fb11b0;
  local_1c = DAT_00fb11b0;
  piVar9 = DAT_00fb11b0;
  if (piVar10 != DAT_00fb11b0) {
    do {
      if ((piVar10[4] != 0) && (*(int *)(piVar10[4] + 8) != 1)) {
        puVar2 = (undefined1 *)piVar10[3];
        local_44 = 0;
        local_18 = puVar2;
        puVar7 = (undefined4 *)FUN_00891268(0x14);
        if (puVar7 == (undefined4 *)0x0) {
          local_20 = (char *)0x0;
          std::exception::exception((exception *)local_3c,&local_20);
          local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_3c,&DAT_00c857a8);
        }
        *puVar7 = puVar7;
        puVar7[1] = puVar7;
        puVar7[2] = puVar7;
        *(undefined1 *)(puVar7 + 4) = 1;
        *(undefined1 *)((int)puVar7 + 0x11) = 1;
        local_8 = 1;
        local_48 = puVar7;
        FUN_004856f0(puVar2,local_4c);
        if (local_44 != 0) {
          uVar8 = FUN_00486090();
          local_8._0_1_ = 2;
          uVar8 = FUN_00486490(uVar8);
          FUN_004861b0(param_1 + 0x10,uVar8);
          local_18 = local_5c;
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_004ca160(*local_58,local_58);
          FUN_0089120c(local_58);
        }
        local_8 = 4;
        FUN_004ca160(*local_48,local_48);
        local_8 = 0xffffffff;
        FUN_0089120c(local_48);
        piVar9 = local_1c;
      }
      if (*(char *)((int)piVar10 + 0x15) == '\0') {
        piVar3 = (int *)piVar10[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar10 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar10 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar10[1] + 0x15);
          piVar5 = (int *)piVar10[1];
          piVar3 = piVar10;
          while ((piVar10 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar10[2]))) {
            cVar1 = *(char *)(piVar10[1] + 0x15);
            piVar5 = (int *)piVar10[1];
            piVar3 = piVar10;
          }
        }
      }
    } while (piVar10 != piVar9);
  }
  ExceptionList = local_10;
  return;
}


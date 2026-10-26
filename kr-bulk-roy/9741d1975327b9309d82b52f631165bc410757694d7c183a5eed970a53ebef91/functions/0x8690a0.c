
undefined4 FUN_008690a0(int param_1)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uStack_54;
  uint *puStack_50;
  uint *puStack_4c;
  undefined4 uStack_48;
  void *pvStack_44;
  int iStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009203bb;
  local_14 = ExceptionList;
  uStack_34 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  uStack_38 = 0x8690d9;
  FUN_00781ea0();
  pvStack_44 = *(void **)(param_1 + 0x84);
  uStack_38 = 0;
  uStack_3c = 4;
  iStack_40 = in_ECX + 0x2c;
  uStack_48 = 0x8690ed;
  FUN_006ddcc0();
  uStack_54 = *(undefined4 *)(param_1 + 0x84);
  uStack_48 = 0;
  puStack_4c = (uint *)0x4;
  puStack_50 = (uint *)(in_ECX + 0x28);
  FUN_006ddcc0();
  uVar10 = *(uint *)(param_1 + 0x84);
  puVar1 = (uint *)(in_ECX + 0x30);
  FUN_006ddcc0(uVar10,puVar1,4,0);
  uVar2 = *puVar1;
  uVar6 = -(uint)((int)((ulonglong)uVar2 * 0x58 >> 0x20) != 0) | (uint)((ulonglong)uVar2 * 0x58);
  puStack_50 = (uint *)FUN_0087dc3d(-(uint)(0xfffffffb < uVar6) | uVar6 + 4);
  uStack_3c = 0;
  if (puStack_50 == (uint *)0x0) {
    puStack_4c = (uint *)0x0;
  }
  else {
    *puStack_50 = uVar2;
    puStack_4c = puStack_50 + 1;
    _eh_vector_constructor_iterator_
              (puStack_4c,0x58,uVar2,(_func_void_void_ptr *)&LAB_00868bb0,FUN_00868c00);
  }
  iVar9 = 0;
  uStack_3c = 0xffffffff;
  *(uint **)(in_ECX + 0x34) = puStack_4c;
  puStack_4c = (uint *)0x0;
  if (0 < (int)*puVar1) {
    do {
      puVar7 = (undefined4 *)(*(int *)(in_ECX + 0x34) + iVar9);
      uStack_54 = 0;
      FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&uStack_54,4,0);
      if (uVar10 != 0) {
        if ((uint)puVar7[4] < uVar10) {
          FUN_00429630(uVar10 - puVar7[4],0);
        }
        else {
          FUN_00402c80(uVar10,0xffffffff);
        }
        if (0xf < (uint)puVar7[5]) {
          puVar7 = (undefined4 *)*puVar7;
        }
        if (uVar10 != 0) {
          FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),puVar7,uVar10,0);
        }
      }
      (**(code **)(*(int *)(iVar9 + 0x34 + *(int *)(in_ECX + 0x34)) + 0x14))(param_1);
      FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar9 + 0x1c + *(int *)(in_ECX + 0x34),4,0);
      uVar2 = *(uint *)(iVar9 + 0x1c + *(int *)(in_ECX + 0x34));
      if (uVar2 != 0) {
        lVar3 = (ulonglong)uVar2 * 4;
        uVar4 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar3 >> 0x20) != 0) | (uint)lVar3);
        *(undefined4 *)(iVar9 + 0x20 + *(int *)(in_ECX + 0x34)) = uVar4;
        uVar2 = *(uint *)(iVar9 + 0x1c + *(int *)(in_ECX + 0x34));
        lVar3 = (ulonglong)uVar2 * 0xc;
        iVar5 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar3 >> 0x20) != 0) | (uint)lVar3);
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar8 = uVar2 - 1;
          if (-1 < iVar8) {
            puVar7 = (undefined4 *)(iVar5 + 8);
            do {
              puVar7[-2] = 0;
              iVar8 = iVar8 + -1;
              puVar7[-1] = 0;
              *puVar7 = 0;
              puVar7 = puVar7 + 3;
            } while (-1 < iVar8);
          }
        }
        *(int *)(iVar9 + 0x24 + *(int *)(in_ECX + 0x34)) = iVar5;
        iVar5 = *(int *)(iVar9 + 0x1c + *(int *)(in_ECX + 0x34));
        iVar8 = *(int *)(iVar9 + *(int *)(in_ECX + 0x34) + 0x20);
        if (0 < iVar5) {
          do {
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar8,4,0);
            iVar8 = iVar8 + 4;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        iVar5 = *(int *)(iVar9 + 0x1c + *(int *)(in_ECX + 0x34));
        iVar8 = *(int *)(iVar9 + *(int *)(in_ECX + 0x34) + 0x24);
        if (0 < iVar5) {
          do {
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar8,0xc,0);
            iVar8 = iVar8 + 0xc;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
      FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar9 + 0x28 + *(int *)(in_ECX + 0x34),4,0);
      uVar2 = *(uint *)(iVar9 + 0x28 + *(int *)(in_ECX + 0x34));
      if (uVar2 != 0) {
        lVar3 = (ulonglong)uVar2 * 4;
        uVar4 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar3 >> 0x20) != 0) | (uint)lVar3);
        *(undefined4 *)(iVar9 + 0x2c + *(int *)(in_ECX + 0x34)) = uVar4;
        uVar2 = *(uint *)(iVar9 + 0x28 + *(int *)(in_ECX + 0x34));
        lVar3 = (ulonglong)uVar2 * 0x10;
        iVar5 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar3 >> 0x20) != 0) | (uint)lVar3);
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar8 = uVar2 - 1;
          if (-1 < iVar8) {
            puVar7 = (undefined4 *)(iVar5 + 8);
            do {
              iVar8 = iVar8 + -1;
              puVar7[-2] = 0;
              puVar7[-1] = 0;
              *puVar7 = 0;
              puVar7[1] = 0x3f800000;
              puVar7 = puVar7 + 4;
            } while (-1 < iVar8);
          }
        }
        *(int *)(iVar9 + 0x30 + *(int *)(in_ECX + 0x34)) = iVar5;
        puVar1 = *(uint **)(iVar9 + 0x28 + *(int *)(in_ECX + 0x34));
        iVar5 = *(int *)(iVar9 + *(int *)(in_ECX + 0x34) + 0x2c);
        if (0 < (int)puVar1) {
          do {
            puStack_50 = puVar1;
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar5,4,0);
            iVar5 = iVar5 + 4;
            puStack_50 = (uint *)((int)puStack_50 + -1);
            puVar1 = puStack_50;
          } while (puStack_50 != (uint *)0x0);
        }
        puVar1 = *(uint **)(iVar9 + 0x28 + *(int *)(in_ECX + 0x34));
        iVar5 = *(int *)(iVar9 + *(int *)(in_ECX + 0x34) + 0x30);
        if (0 < (int)puVar1) {
          do {
            puStack_50 = puVar1;
            FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),iVar5,0x10,0);
            iVar5 = iVar5 + 0x10;
            puStack_50 = (uint *)((int)puStack_50 + -1);
            puVar1 = puStack_50;
          } while (puStack_50 != (uint *)0x0);
        }
      }
      puStack_4c = (uint *)((int)puStack_4c + 1);
      iVar9 = iVar9 + 0x58;
    } while ((int)puStack_4c < *(int *)(in_ECX + 0x30));
  }
  ExceptionList = pvStack_44;
  return 1;
}


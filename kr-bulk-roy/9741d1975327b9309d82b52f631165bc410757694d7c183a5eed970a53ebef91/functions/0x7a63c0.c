
void FUN_007a63c0(void)

{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int **ppiVar5;
  int **ppiVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int in_ECX;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  uint uVar16;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bd76;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  if ((*(int *)(in_ECX + 0x1c) == 0) || (*(int *)(in_ECX + 0x124) == 0)) goto LAB_007a6689;
  iVar12 = 1;
  if ((*(int *)(in_ECX + 0xac) != 0) &&
     (iVar10 = (**(code **)(**(int **)(in_ECX + 0xac) + 0x2c))
                         (DAT_00d61f20 ^ (uint)&stack0xfffffffc), iVar10 == 0)) {
    iVar12 = 0;
  }
  piVar15 = *(int **)(in_ECX + 0x70);
  local_18 = (int *)*piVar15;
  while (local_18 != piVar15) {
    iVar10 = local_18[6];
    uVar14 = 0;
    if (*(int *)(iVar10 + 0x1c) - *(int *)(iVar10 + 0x18) >> 2 != 0) {
      do {
        iVar11 = (**(code **)(**(int **)(*(int *)(iVar10 + 0x18) + uVar14 * 4) + 0x30))();
        if (iVar11 == 0) {
          iVar12 = 0;
          break;
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < (uint)(*(int *)(iVar10 + 0x1c) - *(int *)(iVar10 + 0x18) >> 2));
    }
    FUN_0085e240();
    in_ECX = local_14;
  }
  if (iVar12 == 0) {
    uVar1 = *(undefined4 *)(in_ECX + 0xfc);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = iVar12;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    FUN_0079ab80(&DAT_00fb76a8,*(undefined4 *)(in_ECX + 0xec),*(undefined4 *)(in_ECX + 0xf0),
                 *(undefined4 *)(in_ECX + 0xf4),uVar1,0,0);
    ExceptionList = local_10;
    return;
  }
  FUN_008380b0();
  local_8 = 1;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_007a8220();
  iVar12 = local_14;
  (**(code **)(**(int **)(local_14 + 0x1c) + 8))();
  piVar3 = (int *)**(undefined4 **)(iVar12 + 0x70);
  while (piVar3 != piVar15) {
    (**(code **)(*(int *)piVar3[6] + 8))();
    if (*(char *)((int)piVar3 + 0x21) == '\0') {
      piVar4 = (int *)piVar3[2];
      if (*(char *)((int)piVar4 + 0x21) == '\0') {
        cVar2 = *(char *)(*piVar4 + 0x21);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
        while (cVar2 == '\0') {
          cVar2 = *(char *)(*piVar4 + 0x21);
          piVar3 = piVar4;
          piVar4 = (int *)*piVar4;
        }
      }
      else {
        cVar2 = *(char *)(piVar3[1] + 0x21);
        piVar9 = (int *)piVar3[1];
        piVar4 = piVar3;
        while ((piVar3 = piVar9, cVar2 == '\0' && (piVar4 == (int *)piVar3[2]))) {
          cVar2 = *(char *)(piVar3[1] + 0x21);
          piVar9 = (int *)piVar3[1];
          piVar4 = piVar3;
        }
      }
    }
  }
  if (*(int *)(iVar12 + 0x8c) != 0) {
    FUN_008380b0();
    iVar10 = DAT_00fba838;
    local_8 = CONCAT31(local_8._1_3_,3);
    ppiVar5 = *(int ***)(DAT_00fba838 + 0xb8);
    piVar15 = (int *)(iVar12 + 0xc);
    local_18 = piVar15;
    if (&local_18 < ppiVar5) {
      ppiVar6 = *(int ***)(DAT_00fba838 + 0xb4);
      if (&local_18 < ppiVar6) goto LAB_007a6632;
      if (ppiVar5 == *(int ***)(DAT_00fba838 + 0xbc)) {
        FUN_00797930();
      }
      if (*(undefined4 **)(iVar10 + 0xb8) != (undefined4 *)0x0) {
        **(undefined4 **)(iVar10 + 0xb8) =
             *(undefined4 *)(*(int *)(iVar10 + 0xb4) + ((int)&local_18 - (int)ppiVar6 >> 2) * 4);
      }
    }
    else {
LAB_007a6632:
      if (ppiVar5 == *(int ***)(DAT_00fba838 + 0xbc)) {
        FUN_00797930();
      }
      if (*(undefined4 **)(iVar10 + 0xb8) != (undefined4 *)0x0) {
        **(undefined4 **)(iVar10 + 0xb8) = piVar15;
      }
    }
    *(int *)(iVar10 + 0xb8) = *(int *)(iVar10 + 0xb8) + 4;
    FUN_00837fd0();
    PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
  }
  local_8 = 0xffffffff;
  FUN_00837fd0();
  PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
LAB_007a6689:
  iVar12 = local_14;
  if (*(int *)(local_14 + 0x108) != 0) {
    FUN_007bdf40(*(int *)(local_14 + 0x108));
  }
  puVar7 = *(undefined4 **)(iVar12 + 0x10c);
  for (puVar8 = (undefined4 *)*puVar7; puVar8 != puVar7; puVar8 = (undefined4 *)*puVar8) {
    FUN_007bdf40(puVar8[2]);
  }
  uVar13 = 0;
  uVar14 = *(int *)(iVar12 + 0x150) - *(int *)(iVar12 + 0x14c) >> 3;
  if (uVar14 != 0) {
    do {
      iVar12 = *(int *)(*(int *)(iVar12 + 0x14c) + 4 + uVar13 * 8);
      uVar16 = 0;
      if (*(int *)(iVar12 + 0x60) - *(int *)(iVar12 + 0x5c) >> 2 != 0) {
        do {
          iVar10 = *(int *)(*(int *)(iVar12 + 0x5c) + uVar16 * 4);
          (**(code **)(**(int **)(iVar10 + 8) + 0x1c))(iVar10);
          uVar16 = uVar16 + 1;
        } while (uVar16 < (uint)(*(int *)(iVar12 + 0x60) - *(int *)(iVar12 + 0x5c) >> 2));
      }
      uVar13 = uVar13 + 1;
      iVar12 = local_14;
    } while (uVar13 < uVar14);
  }
  ExceptionList = local_10;
  return;
}


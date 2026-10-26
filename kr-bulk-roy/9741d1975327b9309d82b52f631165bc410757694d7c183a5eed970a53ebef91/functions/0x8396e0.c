
undefined4 FUN_008396e0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int unaff_EDI;
  undefined4 local_8;
  
  uVar3 = *(uint *)(unaff_EDI + 0x3c);
  uVar10 = 0;
  local_8 = 0;
  if (uVar3 != 0) {
    do {
      puVar4 = (undefined4 *)**(undefined4 **)(unaff_EDI + 0x38);
      uVar9 = 0;
      while (puVar4 != *(undefined4 **)(unaff_EDI + 0x38)) {
        if (uVar9 == uVar10) {
          piVar8 = (int *)puVar4[4];
          goto LAB_0083975f;
        }
        uVar9 = uVar9 + 1;
        if (*(char *)((int)puVar4 + 0x15) == '\0') {
          puVar5 = (undefined4 *)puVar4[2];
          if (*(char *)((int)puVar5 + 0x15) == '\0') {
            cVar2 = *(char *)((int)*puVar5 + 0x15);
            puVar4 = puVar5;
            puVar5 = (undefined4 *)*puVar5;
            while (cVar2 == '\0') {
              cVar2 = *(char *)((int)*puVar5 + 0x15);
              puVar4 = puVar5;
              puVar5 = (undefined4 *)*puVar5;
            }
          }
          else {
            cVar2 = *(char *)((int)puVar4[1] + 0x15);
            puVar6 = (undefined4 *)puVar4[1];
            puVar5 = puVar4;
            while ((puVar4 = puVar6, cVar2 == '\0' && (puVar5 == (undefined4 *)puVar4[2]))) {
              cVar2 = *(char *)((int)puVar4[1] + 0x15);
              puVar6 = (undefined4 *)puVar4[1];
              puVar5 = puVar4;
            }
          }
        }
      }
      piVar8 = (int *)0x0;
LAB_0083975f:
      iVar7 = (**(code **)(*piVar8 + 4))();
      if (*(int *)(iVar7 + 4) == -0x5de00000) {
        local_8 = 1;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar3);
  }
  *param_1 = *(float *)(unaff_EDI + 0x54);
  param_1[1] = *(float *)(unaff_EDI + 0x58);
  *param_2 = *(float *)(unaff_EDI + 0x5c);
  param_2[1] = *(float *)(unaff_EDI + 0x60);
  fVar1 = *(float *)(unaff_EDI + 100);
  *param_3 = fVar1;
  if ((*param_1 == 0.0) && (param_1[1] == 0.0)) {
    if (*param_2 != 1.0) {
      return 1;
    }
    if ((param_2[1] == 1.0) && (fVar1 == 0.0)) {
      return local_8;
    }
  }
  return 1;
}


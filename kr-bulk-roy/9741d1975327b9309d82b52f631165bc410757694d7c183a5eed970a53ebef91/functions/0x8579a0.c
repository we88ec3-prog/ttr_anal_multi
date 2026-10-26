
undefined4 FUN_008579a0(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int in_EAX;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  uint local_8;
  
  iVar6 = FUN_00857b00(in_EAX,0);
  if (iVar6 == -1) {
    return 0;
  }
  piVar9 = (int *)param_1[4];
  do {
    if (piVar9 == (int *)param_1[5]) {
      return 0;
    }
    piVar7 = (int *)*piVar9;
    if (piVar7 != (int *)piVar9[1]) {
      do {
        if ((*piVar7 == in_EAX) && (piVar7[1] == 0)) {
          piVar1 = (int *)piVar9[1];
          piVar5 = piVar7;
          if (((int)piVar1 - *piVar9 & 0xfffffff8U) == 8) {
            FUN_008580b0(param_1 + 4,&local_8,piVar9);
            iVar10 = *param_1;
            iVar3 = param_1[1] - iVar10 >> 0x1f;
            iVar11 = 0;
            local_8 = 0;
            if ((param_1[1] - iVar10) / 0x14 + iVar3 != iVar3) {
              do {
                puVar2 = *(undefined4 **)(iVar11 + 4 + iVar10);
                puVar8 = (undefined4 *)(*(int *)(iVar11 + iVar10) + iVar6 * 0xc);
                puVar4 = puVar8;
                while (puVar4 = puVar4 + 3, puVar4 != puVar2) {
                  *puVar8 = *puVar4;
                  puVar8[1] = puVar4[1];
                  puVar8[2] = puVar4[2];
                  puVar8 = puVar8 + 3;
                }
                piVar9 = (int *)(iVar11 + 4 + iVar10);
                *piVar9 = *piVar9 + -0xc;
                iVar10 = *param_1;
                local_8 = local_8 + 1;
                iVar11 = iVar11 + 0x14;
              } while (local_8 < (uint)((param_1[1] - iVar10) / 0x14));
              return 1;
            }
          }
          else {
            while (piVar5 = piVar5 + 2, piVar5 != piVar1) {
              *piVar7 = *piVar5;
              piVar7[1] = piVar5[1];
              piVar7 = piVar7 + 2;
            }
            piVar9[1] = piVar9[1] + -8;
          }
          return 1;
        }
        piVar7 = piVar7 + 2;
      } while (piVar7 != (int *)piVar9[1]);
    }
    piVar9 = piVar9 + 4;
  } while( true );
}

